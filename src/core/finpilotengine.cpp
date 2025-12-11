#include <QObject>
#include <QString>
#include "finpilotengine.h"


FinPilotEngine::FinPilotEngine(const QString &db_path, const QString &config_path, QObject *parent) 
: QObject(parent), m_db_path(db_path), m_config_path(config_path), m_loader(&m_data, this), m_analyzer(&m_data), m_visualizer(&m_data)
{
}

FinPilotEngine::~FinPilotEngine()
{
}

void FinPilotEngine::initialize(const QString &file_path)
{
	m_loader.parseIncome(file_path);	
	DateRange date;
	date.start = QDate(2021,12,31);
	date.end = QDate(2030,12,31);
	qInfo() << m_analyzer.income().getTotalIncome(date, "test");
	qInfo() << m_analyzer.income().getYoYAverageIncome(date, "test");
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

