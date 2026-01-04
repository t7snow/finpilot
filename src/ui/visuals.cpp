#include "src/ui/visuals.h"


namespace ui {

  using namespace ftxui;
    

  Component DateControlView(DateRange *range) {

  
      auto show_modal = std::make_shared<bool>(false);


      
      std::string end_y;
      std::string end_m;
      std::string end_d;

      std::string start_y;
      std::string start_m;
      std::string start_d;


      auto close_btn = Button("Close", [=, &start_d, &start_m, &start_y] { *show_modal = false; 
                                try {
                                  if (!start_y.empty() && !start_m.empty() && !start_d.empty()) {
                                      range->start.setDate(std::stoi(start_y), std::stoi(start_m), std::stoi(start_d));
                                  }
                                  } catch (const std::exception& e) {
                                  }
                                });
      InputOption date_option;

      auto input_end_y = Input(&end_y, "Y");
      auto input_end_m = Input(&end_m, "M");
      auto input_end_d = Input(&end_d, "D");

      auto input_start_y = Input(&start_y, "Y");
      auto input_start_m = Input(&start_m, "M");
      auto input_start_d = Input(&start_d, "D");


      
      auto modal_content = Container::Vertical({
        
        Container::Horizontal({
          input_end_y,
          input_end_m,
          input_end_d,
        }),
        Container::Horizontal({
          input_start_y,
          input_start_m,
          input_start_d,
        }),
        close_btn

      });

      // range->end.setDate(std::stoi(end_y), std::stoi(end_m), std::stoi(end_d));
      auto modal_renderer = Renderer(modal_content, [modal_content] {
        return window(text("Select Date"), modal_content->Render()) 
              | center ; 
      });

      auto btn_start = Button(range->start.toString("yyyy-MM-dd").toStdString(), 
                              [show_modal] { *show_modal = true; 
                                
                              
                              });
      
      auto btn_end = Button(range->end.toString("yyyy-MM-dd").toStdString(), 
                            [show_modal] { *show_modal = true; });

      auto main_container = Container::Horizontal({
        btn_start,
        btn_end
      });


      auto main_renderer = Renderer(main_container, [main_container] {
        return window(
          text("Date Range"),
          main_container->Render()
        );
      });

      return Modal(main_renderer, modal_renderer, show_modal.get());
    }

  

  ftxui::Element NetworthView(double networth) {
    return ftxui::window(
        ftxui::text("Networth"),
        ftxui::text("$" + std::to_string(networth))
    );
  }
}

