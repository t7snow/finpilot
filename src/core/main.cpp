#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include "app.h"

int main(int argc, char **argv)
{
	QCoreApplication a(argc, argv);

	QCoreApplication::setApplicationName("FinPilot");
	QCoreApplication::setApplicationVersion("0.1.0");
	
	App controller("../tests", "../config");
	controller.run();

	
	return a.exec();
	
}
