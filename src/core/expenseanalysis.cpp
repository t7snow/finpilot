#include "expenseanalysis.h"

ExpenseAnalysis::ExpenseAnalysis(FinancialData* data) : m_expense_data(data) {
}

double ExpenseAnalysis::getAverage(const DateRange& range, const std::string& category) const {
    return 0.0;
}

double ExpenseAnalysis::getTotalSpend(const DateRange& range, const std::string& category) const {
    return 0.0;
}

ExpenseEntry ExpenseAnalysis::getExpenses(size_t size, const DateRange& range, const std::string& category) const {
    return {};
}

std::vector<ExpenseEntry> ExpenseAnalysis::getExpensesForRange(const DateRange& range, const std::string& category) const {
    return {};
}

std::vector<ExpenseEntry> ExpenseAnalysis::getRangeAverage(const DateRange& range, const std::string& category) const {
    return {};
}

double ExpenseAnalysis::getBurnRate(const DateRange& range, const std::string& category) const {
    return 0.0;
}

std::vector<double> ExpenseAnalysis::getProjectedSpend(const DateRange& range, const std::string& category) const {
    return {};
}

double ExpenseAnalysis::getAccelerationRate(const DateRange& range, const std::string& category) const {
    return 0.0;
}

double ExpenseAnalysis::getSpendingVolatility(const DateRange& range, const std::string& category) const {
    return 0.0;
}

double ExpenseAnalysis::getRangeGrowth(const DateRange& range, const std::string& category) const {
    return 0.0;
}
