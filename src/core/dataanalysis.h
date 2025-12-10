#ifndef DATANALYSIS_H
#define DATANALYSIS_H


#include <QObject> 
#include "financialdata.h"
#include "expenseanalysis.h"
#include "portfolioanalysis.h"
#include "incomeanalysis.h"

class DataAnalysis  
{
public: 
	explicit DataAnalysis(FinancialData* data);
	~DataAnalysis();
	double getNetworth();
	double getSavingsRate();
	QList<double> getNetworthTrend();

private:
	FinancialData *m_data;
	ExpenseAnalysis m_expense;
	IncomeAnalysis m_income;
	PortfolioAnalysis m_portfolio;
	
};

#endif
