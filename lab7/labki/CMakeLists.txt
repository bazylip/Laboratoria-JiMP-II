project(labki)

set(HEDEAR_FILES Labki.h)
set(SOURCE_FILES Labki.cpp)

add_library(liblabki STATIC ${SOURCE_FILES})
target_include_directories(liblabki PUBLIC .)

add_executable(labki ${SOURCE_FILES} main.cpp)

target_link_libraries(labki liblabki)