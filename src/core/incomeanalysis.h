#ifndef INCOMEANALYSIS_H
#define INCOMEANALYSIS_H

#include <vector>
#include <string>
#include <utility>
#include "financialdata.h"

class IncomeAnalysis {
public:
    explicit IncomeAnalysis(FinancialData* data);

    double getTotalIncome(const DateRange& range, const std::string& source = "") const;
    double getAverageIncome(const DateRange& range, const std::string& source = "") const;
    
    IncomeEntry getLargestPaycheck(const DateRange& range) const;
    double getEffectiveTaxRate(const DateRange& range) const;
    
    std::pair<double, double> getGrossVsNet(const DateRange& range) const;
    
    std::vector<double> getIncomeTrend(const DateRange& range, const std::string& source = "") const;
    std::vector<double> getProjectedIncome(const DateRange& range, const std::string& source = "") const;
    
    double getGrowthRate(const DateRange& range, const std::string& source = "") const;
    double getIncomeStabilityScore(const DateRange& range) const;
    
    std::vector<IncomeEntry> getIncomeForRange(const DateRange& range, const std::string& source = "") const;

private:
    FinancialData* m_income_data;
};

#endif
