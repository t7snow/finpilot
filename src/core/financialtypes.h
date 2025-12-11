#ifndef FINANCIALTYPES_h
#define FINANCIALTYPES_h

#include <QDate> 

enum class Granularity {
	Daily,
	Weekly,
	Monthly,
	Yearly,	
	Quarterly
};

struct DateRange {
	QDate start;
	QDate end;
};

class TimeUtils {
public:
	static int getBucketCount(const DateRange &range, Granularity grain)
	{
		switch(grain){
			case Granularity::Daily:
				return (range.start.daysTo(range.end)) +1;
			case Granularity::Weekly:
				return (range.start.daysTo(range.end) / 7) + 1;
			case Granularity::Monthly:
				return (range.start.daysTo(range.end) / 30) + 1;
			case Granularity::Yearly:
				return (range.start.daysTo(range.end) / 365) + 1;
			default:
				return 1;
		}
		return 1;
	}
	static int getIndexForDate(const QDate &date, const QDate &start_date, Granularity grain)
	{	
		if(date < start_date) return -1;
		if (grain == Granularity::Monthly) {
             		return (date.year() - start_date.year()) * 12 + 
                    	(date.month() - start_date.month());
        	} 
        	else if (grain == Granularity::Weekly) {
             		return start_date.daysTo(date) / 7;
        	}
        	else if (grain == Granularity::Yearly) {
             		return date.year() - start_date.year();
        	}
		return start_date.daysTo(date);	
	}
};

struct ExpenseEntry {
	QDate date;
	QString item;
	QString vendor;
	QString category;
	QString subcategory;
	QString payment_method;
	double amount;
	QString notes;
};

struct IncomeEntry {
	QDate date;
	QString source;
	double gross_pay;
	double deduction;
	//add more here alter
	double netpay;
};

struct PortfolioEntry {
	QString brokerage;
	QString type;
	QString investment_type;
	QString general_type;
	QString ticker;
	QString full_ticker_name;
	QString georgraphic_type;
	double shares_owned;
	double current_price;
	double market_value;
	double change;
};

#endif