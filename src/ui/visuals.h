#ifndef VISUALS_H
#define VISUALS_H


#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <string>
#include <QDate>
#include "src/core/dataanalysis.h"

using namespace ftxui;

namespace ui {

  ftxui::Element DateControlView(DateRange *range);

  ftxui::Element NetworthView(double networth);

}

#endif