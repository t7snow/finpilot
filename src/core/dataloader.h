#ifndef DATALOADER_H
#define DATALOADER_H

#include <QObject>
#include <QList>
#include "financialtypes.h"
#include "financialdata.h"
class DataLoader : public QObject {

	Q_OBJECT

public: 
	DataLoader(FinancialData *data, QObject *parent = nullptr);
	~DataLoader();

	void parseExpenses(const QString &file_path);
	void parseIncome(const QString &file_path);
	void parsePortfolio(const QString &file_path);

private:
	FinancialData* m_data;
};

#endif

