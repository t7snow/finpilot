#ifndef FINPILOTENGINE_H
#define FINPILOTENGINE_H

#include <QObject>
#include <QString>
#include <QCoreApplication>
#include <QTimer>
#include <thread>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "src/ui/visuals.h"
#include "dataanalysis.h"
#include "datavisualization.h"
#include "financialdata.h"
#include "dataloader.h"

class FinPilotEngine : public QObject {
	Q_OBJECT

public: 
	FinPilotEngine(const QString &db_path, const QString &config_path, QObject *parent = nullptr);
	~FinPilotEngine();

public slots:
	
	void initialize(const QString &file_path);
	void loadData();
	void processAnalysis();
	void renderDashboard();	

private:
	QString m_db_path;
	QString m_config_path;
	FinancialData m_data;
	DataLoader m_loader;
	DataAnalysis m_analyzer;
	DataVisualization m_visualizer;
	DateRange m_active_date_range;

	ftxui::ScreenInteractive m_screen = ftxui::ScreenInteractive::Fullscreen();
	std::thread m_ui_thread;
	QTimer* m_refresh_timer = nullptr;
	ftxui::Component m_ui_root;

};

#endif

