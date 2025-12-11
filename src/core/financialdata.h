#ifndef FINANCIALDATA_H
#define FINANCIALDATA_H

#include <QObject>
#include <QList>
#include "financialtypes.h"

class FinancialData : public QObject {
	Q_OBJECT

public:
	explicit FinancialData(QObject *parent = nullptr);
	
	void clear();
	void addEntry(const ExpenseEntry &entry);
	void addEntry(const IncomeEntry &entry);
	void addEntry(const PortfolioEntry &entry);

	const QList<ExpenseEntry>& getExpenses() const;
	const QList<IncomeEntry>& getIncome() const;
	const QList<PortfolioEntry> &getPortfolio() const;
signals:
	void dataChanged();

private:	
 	QList<ExpenseEntry> m_expenses;
 	QList<IncomeEntry> m_income;
 	QList<PortfolioEntry> m_portfolio;
};

#endif 
