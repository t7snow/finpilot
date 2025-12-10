#include "incomeanalysis.h"

IncomeAnalysis::IncomeAnalysis(FinancialData* data) : m_income_data(data) {
}

double IncomeAnalysis::getTotalIncome(const DateRange& range, const std::string& source) const {
    return 0.0;
}

double IncomeAnalysis::getAverageIncome(const DateRange& range, const std::string& source) const {
    return 0.0;
}

IncomeEntry IncomeAnalysis::getLargestPaycheck(const DateRange& range) const {
    return {};
}

double IncomeAnalysis::getEffectiveTaxRate(const DateRange& range) const {
    return 0.0;
}

std::pair<double, double> IncomeAnalysis::getGrossVsNet(const DateRange& range) const {
    return {};
}

std::vector<double> IncomeAnalysis::getIncomeTrend(const DateRange& range, const std::string& source) const {
    return {};
}

std::vector<double> IncomeAnalysis::getProjectedIncome(const DateRange& range, const std::string& source) const {
    return {};
}

double IncomeAnalysis::getGrowthRate(const DateRange& range, const std::string& source) const {
    return 0.0;
}

double IncomeAnalysis::getIncomeStabilityScore(const DateRange& range) const {
    return 0.0;
}

std::vector<IncomeEntry> IncomeAnalysis::getIncomeForRange(const DateRange& range, const std::string& source) const {
    return {};
}
