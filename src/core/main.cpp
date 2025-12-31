#include <QCoreApplication>
#include <QTimer>
#include <thread>
#include <ftxui/component/screen_interactive.hpp>
#include "src/ui/dashboard.hpp"

int main(int argc, char **argv) {
    QCoreApplication a(argc, argv);

    auto screen = ftxui::ScreenInteractive::Fullscreen();
    auto root = ui::Dashboard();

    std::thread qt_thread([&]() {
        screen.Loop(root);
    });

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        screen.PostEvent(ftxui::Event::Custom); 
    });
    timer.start(1000);
    a.exec(); 
    a.quit();
    if (qt_thread.joinable()) qt_thread.join();
    
    return 0;
}