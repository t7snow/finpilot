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
    return 27.0;
}

double DataAnalysis::getSavingsRate()
{
    return 0.0;
}

QList<double> DataAnalysis::getNetworthTrend()
{
    return QList<double>();
}

