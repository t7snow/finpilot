#include <QCoreApplication>
#include <QTimer>
#include <thread>
#include <ftxui/component/screen_interactive.hpp>
#include "src/core/finpilotengine.h"
int main(int argc, char **argv) {
    QCoreApplication a(argc, argv);


    // m_loader.parseIncome(file_path);	
	DateRange date;
	date.start = QDate(2021,12,31);
	date.end = QDate(2030,12,31);


    FinPilotEngine engine("~/home/projects/finpilot/tests", "/home/projects/finpilot/config/");
    engine.initialize("tests/income.csv");
    a.exec(); 

    // if (qt_thread.joinable()) qt_thread.join();
    
    return 0;
}