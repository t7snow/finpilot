#include "incomeanalysis.h"

IncomeAnalysis::IncomeAnalysis(FinancialData* data) : m_income_data(data) {
}

double IncomeAnalysis::getTotalIncome(const DateRange& range, const QString& source) const {
	
	double total_income =0;
	for(IncomeEntry entry : m_income_data->getIncome())
	{
	
		qInfo() << entry.date;

		if(entry.date > range.end || entry.date < range.start){
			continue;
		}	
		total_income += entry.netpay;
	}
	return total_income;
}

double IncomeAnalysis::getTotalDeduction(const DateRange &range) const
{
	//TODO: set the default range to be all time for all of these.
	double total_deduction =0;
	for(IncomeEntry entry : m_income_data->getIncome())
	{
	
		qInfo() << entry.date;

		if(entry.date > range.end || entry.date < range.start){
			continue;
		}	
		total_deduction += entry.deduction;
	}
	return total_deduction;
}

double IncomeAnalysis::getTotalGrossIncome(const DateRange &range) const
{
	double total_gross_income =0;
	for(IncomeEntry entry : m_income_data->getIncome())
	{
		if(entry.date > range.end || entry.date < range.start){
			continue;
		}	
		total_gross_income += entry.gross_pay;
	}
	return total_gross_income;
}

double IncomeAnalysis::getYoYAverageIncome(const DateRange& range, const QString& source) const {
	double total_income = getTotalIncome(range, source);
	double avg_income = total_income / (range.start.daysTo(range.end) / 365);
	return avg_income;    
}

IncomeEntry IncomeAnalysis::getLargestPaycheck(const DateRange& range) const {
	double largest_netpay = 0;
	IncomeEntry largest_entry;
	for(IncomeEntry entry : m_income_data->getIncome())
	{
		if(entry.netpay >= largest_netpay){
			largest_netpay = entry.netpay;
			largest_entry = entry;	
		}else{
			continue;
		}
	}
	return largest_entry;
}

double IncomeAnalysis::getEffectiveTaxRate(const DateRange& range) const {
	double total_deduction = getTotalDeduction(range);
	double total_gross_income = getTotalGrossIncome(range);
	
	if (total_gross_income == 0) return 0.0; // Prevent division by zero

	double effective_tax_rate = (total_deduction / total_gross_income) * 100;
	return effective_tax_rate;
}


QList<double> IncomeAnalysis::getIncomeTrend(const DateRange& range, const QString& source) const {
    return {};
}

QList<double> IncomeAnalysis::getProjectedIncome(const DateRange& range, const QString& source) const {
    return {};
}

double IncomeAnalysis::getGrowthRate(const DateRange& range, const QString& source) const {
    return 0.0;
}

double IncomeAnalysis::getIncomeStabilityScore(const DateRange& range) const {
    return 0.0;
}

QList<IncomeEntry> IncomeAnalysis::getIncomeForRange(const DateRange& range, const QString& source) const {
    return {};
}
