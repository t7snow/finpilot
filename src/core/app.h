#ifndef APP_H
#define APP_H

#include <FinPilotEngine>
class App : public QObject
{
	Q_OBJECT

public: 
	explicit App(QObject *parent = nullptr);
	~App();
	void run();

public slots:
	void displayMenu();
	void handleUserInput();

private:
	FinPilotEngine m_engine;

};

#endif
	
