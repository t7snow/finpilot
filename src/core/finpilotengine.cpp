#include <QObject>
#include <QString>
#include "finpilotengine.h"


FinPilotEngine::FinPilotEngine(const QString &db_path, const QString &config_path, QObject *parent) 
: QObject(parent), m_db_path(db_path), m_config_path(config_path), m_loader(&m_data, this), m_analyzer(&m_data), m_visualizer(&m_data)
{
	m_active_date_range.start = QDate(2025, 1, 1);
  m_active_date_range.end   = QDate(2025, 12, 31);
}

FinPilotEngine::~FinPilotEngine()
{
	m_screen.Exit(); 
  if (m_ui_thread.joinable()) {
      m_ui_thread.join(); 
  }
}
//TODO: make it so the shits are member variables
void FinPilotEngine::initialize(const QString &file_path) {
  m_loader.parseIncome(file_path);

  auto date_controls = ui::DateControlView(&m_active_date_range);

  m_ui_root = ftxui::Renderer(date_controls, [this, date_controls] {
    
    auto nw_view = ui::NetworthView(m_analyzer.getNetworth());

    return ftxui::vbox({
      ftxui::hbox({
        nw_view | ftxui::flex,
        
        date_controls->Render() | ftxui::flex 
      }),
      ftxui::hbox({
        ftxui::window(ftxui::text("Accounts"), ftxui::text("Checking/Savings")) | ftxui::flex,
        ftxui::window(ftxui::text("Controls"), ftxui::text("Q: Quit | R: Refresh")) | ftxui::flex
      })
    }) | ftxui::border;
  });

  m_ui_thread = std::thread([this]() {
    m_screen.Loop(m_ui_root);
  });

  m_refresh_timer = new QTimer(this);
  connect(m_refresh_timer, &QTimer::timeout, this, [this]() {
    m_screen.Post(ftxui::Event::Custom); 
  });
  m_refresh_timer->start(16);
}

void FinPilotEngine::loadData()
{
}


void FinPilotEngine::processAnalysis()
{
}

void FinPilotEngine::renderDashboard()
{
}

