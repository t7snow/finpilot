#ifndef INCOMEANALYSIS_H
#define INCOMEANALYSIS_H

#include <vector>
#include <string>
#include <utility>
#include "financialdata.h"

class IncomeAnalysis {
public:
    explicit IncomeAnalysis(FinancialData* data);

    double getTotalIncome(const DateRange& range, const QString& source = "") const;
    double getTotalDeduction(const DateRange& range) const;
    double getTotalGrossIncome(const DateRange& range) const;
    double getYoYAverageIncome(const DateRange& range, const QString& source = "") const;
    
    IncomeEntry getLargestPaycheck(const DateRange& range) const;
    double getEffectiveTaxRate(const DateRange& range) const;
    
    QList<double> getIncomeTrend(const DateRange& range, const QString& source = "") const;
    QList<double> getProjectedIncome(const DateRange& range, const QString& source = "") const;
    
    double getGrowthRate(const DateRange& range, const QString& source = "") const;
    double getIncomeStabilityScore(const DateRange& range) const;
    
    QList<IncomeEntry> getIncomeForRange(const DateRange& range, const QString& source = "") const;

private:
    FinancialData* m_income_data;
};

#endif
