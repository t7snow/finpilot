#include "src/ui/visuals.h"


namespace ui {

  ftxui::Element DateControlView(DateRange *range) {

    std::string start_str = range->start.toString("yyyy-MM-dd").toStdString();
    std::string end_str = range->end.toString("yyyy-MM-dd").toStdString();
    auto content = ftxui::vbox({
            ftxui::text("Start: " + start_str),
            ftxui::text("End:   " + end_str)
    });
    return ftxui::window(
      ftxui::text("Date Range"),
      content    
    );
  }

  ftxui::Element NetworthView(double networth) {
    return ftxui::window(
        ftxui::text("Networth"),
        ftxui::text("$" + std::to_string(networth))
    );
  }

}