cmake_minimum_required(VERSION 3.10)
project(helloworld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.1.0\\mingw81_64\\lib\\cmake")

find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(helloworld main.cpp domain/domain.cpp domain/domain.h repository/repository.cpp repository/repository.h service/service.cpp service/service.h ui/ui.cpp ui/ui.h)
target_link_libraries(helloworld Qt6::Widgets)