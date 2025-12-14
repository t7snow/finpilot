#ifndef INCOMEANALYSIS_H
#define INCOMEANALYSIS_H

#include <vector>
#include <string>
#include <utility>
#include "financialdata.h"
#include "financialtypes.h" // Added to see enums

class IncomeAnalysis {
public:
    explicit IncomeAnalysis(FinancialData* data);

    double getTotal(const DateRange& range, IncomeMetric metric) const;
    double getAverage(const DateRange& range, Granularity grain, IncomeMetric metric) const;
    
    IncomeEntry getLargestPaycheck(const DateRange& range) const;
    double getEffectiveTaxRate(const DateRange& range) const;
    
    QList<double> getIncomeTrend(const DateRange& range, Granularity grain, IncomeMetric metric) const;
    QList<double> getProjectedIncome(const DateRange& range) const;
    
    double getGrowthRate(const DateRange& range) const;
    double getIncomeStabilityScore(const DateRange& range) const;
    
    QList<IncomeEntry> getIncomeForRange(const DateRange& range) const;

private:
    FinancialData* m_income_data;
};

#endif