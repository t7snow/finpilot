#ifndef VISUALS_H
#define VISUALS_H

#include <memory>  
#include <ftxui/component/component.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <QDate>
#include <stdlib.h> 
#include "src/core/dataanalysis.h"

using namespace ftxui;

namespace ui {

  ftxui::Component DateControlView(DateRange *range);

  ftxui::Element NetworthView(double networth);

}

#endif