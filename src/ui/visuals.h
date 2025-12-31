#ifdef VISUALS_H
#define VISUALS_H


namespace ui {
  using namespace ftxui;

  ftxui::Component NetworthView(double networth){
    return Renderer([networth]{
      return window(text("Networth"), text("$" + std::to_string(networth)));
    });
  }

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