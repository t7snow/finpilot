#include <QFile>
#include <QStringList>
#include <QByteArray>
#include <QDebug>
#include "dataloader.h"

DataLoader::DataLoader(FinancialData *data, QObject *parent) 
: m_data(data), QObject(parent)
{
}
DataLoader::~DataLoader()
{
}

void DataLoader::parseExpenses(const QString &file_path)
{
	QFile file(file_path);
	
	if(!file.open(QIODevice::ReadOnly))
	{
		qInfo() << file.errorString();
		return;	
	}
	
	QTextStream in(&file);
	
	while(!in.atEnd())
	{
		in.readLine();
	}
	
	auto cleanMoney = [](QString str) -> double {
		str.remove("$");
		str.remove(",");
		return str.toDouble();
	};
	
	while(!in.atEnd())
	{
		ExpenseEntry expense;

		QString full_line;
		in.readLineInto(&full_line);
		
		QStringList split_line;
		split_line = full_line.split(",");
		
		if(split_line.size() != 8)
		{
			qInfo() << "error";
		}		
		
		expense.date = QDate::fromString(split_line[0], "yyyy-MM-dd");		
		expense.item = split_line[1];
		expense.vendor = split_line[2];
		expense.category = split_line[3];
		expense.subcategory = split_line[4];
		expense.payment_method = split_line[5];
		expense.amount = cleanMoney(split_line[6]);
		expense.notes = split_line[7];

		m_data->addEntry(expense);
	}
	
}
void DataLoader::parseIncome(const QString &file_path)
{
	QFile file("/Users/tuckersnow/projects/finpilot/test-data/income.csv");
	if(!file.open(QIODevice::ReadOnly)){
		qInfo() << file.errorString();
		return;
	}
	
	QTextStream in(&file);
	
	if(!in.atEnd())
	{
		in.readLine();
	}
	

	auto cleanMoney = [](QString str) -> double {
		str.remove("$");
		str.remove(",");
		return str.toDouble();
	};
	
	while(!in.atEnd()) 
	{
		IncomeEntry income;
		
		QString full_line;
		in.readLineInto(&full_line);
		
		QStringList split_line;
		split_line = full_line.split(",");
		
		if(split_line.size() < 5){
			qInfo() << "Invalid line skipped (too short)";
			continue;
		}

		income.date = QDate::fromString(split_line[0], "yyyy-MM-dd");	
		income.source = split_line[1];
		income.gross_pay = cleanMoney(split_line[2]);
		income.deduction = cleanMoney(split_line[3]);
		income.netpay = cleanMoney(split_line[4]);
		
		qInfo() << income.gross_pay;	
		m_data->addEntry(income);
	}

	file.close();
}
void DataLoader::parsePortfolio(const QString &file_path)
{
}

