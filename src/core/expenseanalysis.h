#ifndef EXPENSEANALYSIS_H
#define EXPENSEANALYSIS_H

#include <vector>
#include <string>
#include "financialdata.h"

class ExpenseAnalysis {
public:
    explicit ExpenseAnalysis(FinancialData* data);

    double getAverage(const DateRange& range, const std::string& category = "") const;
    double getTotalSpend(const DateRange& range, const std::string& category = "") const;
    
    ExpenseEntry getExpenses(size_t size, const DateRange& range, const std::string& category = "") const;
    
    std::vector<ExpenseEntry> getExpensesForRange(const DateRange& range, const std::string& category = "") const;
    std::vector<ExpenseEntry> getRangeAverage(const DateRange& range, const std::string& category = "") const;
    
    double getBurnRate(const DateRange& range, const std::string& category = "") const;
    std::vector<double> getProjectedSpend(const DateRange& range, const std::string& category = "") const;
    
    double getAccelerationRate(const DateRange& range, const std::string& category = "") const;
    double getSpendingVolatility(const DateRange& range, const std::string& category = "") const;
    double getRangeGrowth(const DateRange& range, const std::string& category = "") const;

private:
    FinancialData* m_expense_data;
};

#endif
