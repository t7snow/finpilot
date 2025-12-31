#include "incomeanalysis.h"

IncomeAnalysis::IncomeAnalysis(FinancialData* data) : m_income_data(data) {
}

double IncomeAnalysis::getTotal(const DateRange& range, IncomeMetric metric) const 
{
	double total = 0.0;

	for(const IncomeEntry& entry : m_income_data->getIncome()) 
 	{
 		if(entry.date > range.end || entry.date < range.start) {
        	 	continue;
        	}

        	switch(metric) {
        		case IncomeMetric::NetPay:
                		total += entry.netpay;
                		break;
            		case IncomeMetric::GrossPay:
                		total += entry.gross_pay;
                		break;
            		case IncomeMetric::Deduction:
                		total += entry.deduction;
                		break;
            		default:
                		break;
        	}
	}
    return total;
}
//TODO: Not actually using the date range
double IncomeAnalysis::getAverage(const DateRange& range, Granularity grain, IncomeMetric metric) const {
	double total = getTotal(range, metric);
	int dividend = 0;
	if(grain == Granularity::Daily)
	{
		dividend = 1;
	}
	else if (grain == Granularity::Weekly)
	{
		dividend = 7;
	}
	else if (grain == Granularity::Monthly)
	{	
		dividend = 30;	
	}
	else if (grain == Granularity::Yearly)
	{
		dividend = 365;
	}
	
    int days = range.start.daysTo(range.end);
    if (days == 0) days = 1; 
	double avg = total / (days / (double)dividend); 
	return avg;    
}

IncomeEntry IncomeAnalysis::getLargestPaycheck(const DateRange& range) const {
	double largest_netpay = 0;
	IncomeEntry largest_entry = {}; 
	for(const IncomeEntry& entry : m_income_data->getIncome())
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
	double total_deduction = getTotal(range, IncomeMetric::Deduction);
	double total_gross_income = getTotal(range, IncomeMetric::GrossPay);
	
	if (total_gross_income == 0.0) { return 0.0; }
	double effective_tax_rate = (total_deduction / total_gross_income) * 100;
	return effective_tax_rate;
}


QList<double> IncomeAnalysis::getIncomeTrend(const DateRange& range, Granularity grain, IncomeMetric metric) const {
    return {};
}

QList<double> IncomeAnalysis::getProjectedIncome(const DateRange& range) const {
    return {};
}

double IncomeAnalysis::getGrowthRate(const DateRange& range) const {
    return 0.0;
}

double IncomeAnalysis::getIncomeStabilityScore(const DateRange& range) const {
    return 0.0;
}

QList<IncomeEntry> IncomeAnalysis::getIncomeForRange(const DateRange& range) const {
		
	QList<IncomeEntry> list;

	for(IncomeEntry entry : m_income_data->getIncome()){
			if(entry.date > range.end || entry.date < range.start) {
				list.append(entry);
			}
		}

		return list;
}
