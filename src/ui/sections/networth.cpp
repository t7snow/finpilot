#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>


namespace ui {
  using namespace ftxui;
  ftxui::Component NetworthView(double networth){
    return Renderer([networth]{
      return window(text("Networth"), text("$" + std::to_string(networth)));
    });
  }
}