cmake_minimum_required (VERSION 2.6)
project (LatestIntelIPP DESCRIPTION "Wrapper For IPP 2021.6.2")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

set(INTEL_HEADER_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/INTEL_INC)
set(INTEL_LIBRARY_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/INTEL_LIB)

set(HEADERDIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(SOURCEDIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADER ${HEADERDIR}/IPP2021Wrapper.h)
set(SOURCE ${SOURCEDIR}/IPP2021Wrapper.cpp)

add_library(LatestIntelIPPSharedLIB SHARED ${HEADER} ${SOURCE})
target_include_directories(LatestIntelIPPSharedLIB PRIVATE ${INTEL_HEADER_DIRECTORY} ${HEADERDIR})
target_link_directories(LatestIntelIPPSharedLIB PRIVATE ${INTEL_LIBRARY_DIRECTORY})
target_link_libraries(LatestIntelIPPSharedLIB PRIVATE ippimt.lib ippsmt.lib ippcoremt.lib ippcvmt.lib ippvmmt.lib)