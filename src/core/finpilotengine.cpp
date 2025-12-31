#include <QObject>
#include <QString>
#include "finpilotengine.h"


FinPilotEngine::FinPilotEngine(const QString &db_path, const QString &config_path, QObject *parent) 
: QObject(parent), m_db_path(db_path), m_config_path(config_path), m_loader(&m_data, this), m_analyzer(&m_data), m_visualizer(&m_data)
{
}

FinPilotEngine::~FinPilotEngine()
{
	m_screen.Exit(); 
  if (m_ui_thread.joinable()) {
      m_ui_thread.join(); 
  }
}
//TODO: make it so the shits are member variables
void FinPilotEngine::initialize(const QString &file_path)
{

	m_loader.parseIncome(file_path);
	m_ui_root = ui::Dashboard(&m_analyzer);
	m_ui_thread = std::thread([this]() {
		m_screen.Loop(m_ui_root);
	});

	m_refresh_timer = new QTimer(this);
	connect(m_refresh_timer, &QTimer::timeout, this, [this]() {
        m_screen.Post(ftxui::Event::Custom); 
    });
  m_refresh_timer->start(16);


	// m_loader.parseIncome(file_path);	
	// DateRange date;
	// date.start = QDate(2021,12,31);
	// date.end = QDate(2030,12,31);
	// qInfo() << m_analyzer.income().getTotal(date, IncomeMetric::NetPay);
	// qInfo() << m_analyzer.income().getAverage(date, Granularity::Yearly, IncomeMetric::NetPay);
	// qInfo() << m_analyzer.income().getIncomeForRange(date);

	

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

