#ifndef FINANCIALTYPES_h
#define FINANCIALTYPES_h

#include <QDate> 

struct DateRange {
	QDate start;
	QDate end;
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
