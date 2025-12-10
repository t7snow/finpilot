#ifndef FINPILOTENGINE_H
#define FINPILOTENGINE_H

#include <QObject>
#include <QString>
#include "dataloader.h"
#include "dataanalysis.h"
#include "datavisualization.h"
#include "financialdata.h"

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

};

#endif

