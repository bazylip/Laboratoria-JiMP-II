
project(lab)

set(HEDEAR_FILES Lab.h)
set(SOURCE_FILES Lab.cpp)

add_library(liblab STATIC ${SOURCE_FILES})
target_include_directories(liblab PUBLIC .)

add_executable(lab ${SOURCE_FILES} main.cpp)

target_link_libraries(lab liblab)