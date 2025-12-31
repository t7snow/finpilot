#include <QCoreApplication>
#include <QTimer>
#include <thread>
#include <ftxui/component/screen_interactive.hpp>

int main(int argc, char **argv) {
    QCoreApplication a(argc, argv);

   
    a.exec(); 

    // if (qt_thread.joinable()) qt_thread.join();
    
    return 0;
}