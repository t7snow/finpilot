#ifndef APP_H
#define APP_H

#include "finpilotengine.h"
#include <QObject>
 
class App : public QObject
{
	Q_OBJECT

public: 
	App(const QString &db_path, const QString &config_path, QObject *parent = nullptr);
	~App();
	void run();

public slots:
	void displayMenu();
	void handleUserInput();

private:
	FinPilotEngine m_engine;

};

#endif
	
