#include "portfolioanalysis.h"

PortfolioAnalysis::PortfolioAnalysis(FinancialData* data) : m_portfolio_data(data) {
}

double PortfolioAnalysis::getTotalValue(const DateRange& range) const {
    return 0.0;
}

double PortfolioAnalysis::getReturnOnInvestment(const DateRange& range) const {
    return 0.0;
}

double PortfolioAnalysis::getCAGR(const DateRange& range) const {
    return 0.0;
}

double PortfolioAnalysis::getSharpeRatio(double riskFreeRate) const {
    return 0.0;
}

std::map<std::string, double> PortfolioAnalysis::getAssetAllocation() const {
    return {};
}

std::map<std::string, double> PortfolioAnalysis::getSectorAllocation() const {
    return {};
}

double PortfolioAnalysis::getDividendsReceived(const DateRange& range) const {
    return 0.0;
}

double PortfolioAnalysis::getBeta(const std::string& benchmarkTicker) const {
    return 0.0;
}
