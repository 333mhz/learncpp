cmake_minimum_required (VERSION 3.0)

project (learncpp_test)

set(SOURCES 
        "main.cpp"
        )

set(HEADERS
        "header.h"
        )

#assign_source_group(${SOURCES})
#assign_source_group(${HEADERS})

add_executable(learncpp_test ${SOURCES} ${HEADERS})
