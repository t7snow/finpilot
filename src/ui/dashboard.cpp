#include "dashboard.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

namespace ui {
    using namespace ftxui;

    ftxui::Component Dashboard() {
        return Renderer([] {
            return vbox({
              hbox({
                window(text("networth"),text("$72,000")) | flex,
                window(text("controls"),text("Ctrl-C to quit, 1 to start, 2 to play, 3 to end")) | flex
              }),
              hbox({
                frame(window(text("test"),text("accounts")) | flex),
                frame(window(text("conaccountstrols"),text("accounts")) | flex)
              }),
          }) | border;
        });
    }
}