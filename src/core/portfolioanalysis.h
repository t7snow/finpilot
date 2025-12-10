#ifndef PORTFOLIOANALYSIS_H
#define PORTFOLIOANALYSIS_H

#include <vector>
#include <string>
#include <map>
#include "financialdata.h"

class PortfolioAnalysis {
public:
    explicit PortfolioAnalysis(FinancialData* data);

    double getTotalValue(const DateRange& range) const;
    double getReturnOnInvestment(const DateRange& range) const;
    double getCAGR(const DateRange& range) const;
    double getSharpeRatio(double riskFreeRate) const;
    
    std::map<std::string, double> getAssetAllocation() const;
    std::map<std::string, double> getSectorAllocation() const;
    
    double getDividendsReceived(const DateRange& range) const;
    double getBeta(const std::string& benchmarkTicker) const;

private:
    FinancialData* m_portfolio_data;
};

#endif
