#include <QList>
#include "financialdata.h"

FinancialData::FinancialData(QObject *parent) 
: QObject(parent)
{
}


void FinancialData::clear()
{
}

void FinancialData::addEntry(const ExpenseEntry &entry)
{
}

void FinancialData::addEntry(const IncomeEntry &entry)
{
	m_income.append(entry);
	emit dataChanged();
}

void FinancialData::addEntry(const PortfolioEntry &entry)
{
}

const QList<ExpenseEntry>& FinancialData::getExpenses() const { return m_expenses; }
const QList<IncomeEntry>& FinancialData::getIncome() const { return m_income; }
const QList<PortfolioEntry>& FinancialData::getPortfolio() const { return m_portfolio; }
