#ifndef FINANCIALDATA_H
#define FINANCIALDATA_H

#include <QList>
#include "financialtypes.h"

class FinancialData {
public:
 	QList<ExpenseEntry> expenses;
 	QList<IncomeEntry> income;
 	QList<PortfolioEntry> portfolio;
	
	void clear();
	void addEntry(const ExpenseEntry &entry);
	void addEntry(const IncomeEntry &entry);
	void addEntry(const PortfolioEntry &entry);
	
};

#endif 
