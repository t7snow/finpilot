#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "dashboard.hpp"
#include "src/core/dataanalysis.h"
namespace ui {
    using namespace ftxui;

    ftxui::Component Dashboard(DataAnalysis *data_analyzer) {
        auto nw_view = ui::NetworthView(data_analyzer->getNetworth());
        return Renderer([nw_view] {
            return vbox({
              nw_view->Render(),
              hbox({
                frame(window(text("test"),text("accounts")) | flex),
                frame(window(text("conaccountstrols"),text("accounts")) | flex)
              }),
          }) | border;
        });
    }
}