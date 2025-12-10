#include <QObject>
#include <QList>
#include "dataanalysis.h"

DataAnalysis::DataAnalysis(FinancialData *data) 
: m_data(data), m_expense(data), m_income(data), m_portfolio(data)
{
}

DataAnalysis::~DataAnalysis()
{
}

double DataAnalysis::getNetworth()
{
}

double DataAnalysis::getSavingsRate()
{
}

QList<double> DataAnalysis::getNetworthTrend()
{
}

