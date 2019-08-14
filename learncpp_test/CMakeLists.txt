cmake_minimum_required (VERSION 3.0)

project (learncpp_test)

set(SOURCES 
        "test.cpp"
        "object_relationship.cpp"
        )

set(HEADERS
        "header.h"
        "object_relationship.h"
        )

#assign_source_group(${SOURCES})
#assign_source_group(${HEADERS})

add_executable(learncpp_test ${SOURCES} ${HEADERS})
