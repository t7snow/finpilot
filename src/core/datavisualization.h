#ifndef DATAVISUALIZATION_H
#define DATAVISUALIZATION_H
#include "financialdata.h"


class DataVisualization
{
public:
	explicit DataVisualization(FinancialData* data);
	
private:
	FinancialData* m_data;
};

#endif
