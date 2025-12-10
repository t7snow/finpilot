#include <QObject>
#include "app.h"

App::App(const QString &db_path, const QString &config_path, QObject *parent) : QObject(parent)
,m_engine(db_path, config_path, this)
{
}

App::~App() 
{
	qInfo() << "App killed";
}

void App::run()
{
	qInfo() << "app running";
	m_engine.initialize("~/test-data");
}

void App::displayMenu()
{
	qInfo() << "display menu";
}

void App::handleUserInput()
{
}


