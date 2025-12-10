cmake_minimum_required(VERSION 3.16)

project(finpilot VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)
qt_standard_project_setup()

qt_add_executable(finpilot
	main.cpp
	app.cpp
	finpilotengine.cpp
	dataanalysis.cpp
	dataloader.cpp
	datavisualization.cpp
	expenseanalysis.cpp	
	financialdata.cpp
	incomeanalysis.cpp	
	portfolioanalysis.cpp
)

target_link_libraries(finpilot PRIVATE Qt6::Core Qt6::Widgets Qt6::Sql)


