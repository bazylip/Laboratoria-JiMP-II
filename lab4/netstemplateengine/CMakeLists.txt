
project(netstemplateengine)

set(HEDEAR_FILES NetsTemplateEngine.h)
set(SOURCE_FILES NetsTemplateEngine.cpp)

add_library(libnetstemplateengine STATIC ${SOURCE_FILES})
target_include_directories(libnetstemplateengine PUBLIC .)

add_executable(netstemplateengine ${SOURCE_FILES} main.cpp)

target_link_libraries(netstemplateengine libnetstemplateengine)