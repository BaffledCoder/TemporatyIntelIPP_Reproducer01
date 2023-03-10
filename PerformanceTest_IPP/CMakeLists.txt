cmake_minimum_required(VERSION 3.20)
project (PerformanceTestIPP DESCRIPTION "Performance Test For IPP")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

set(HEADERDIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/ipp/CurrentIPP/inc ${CMAKE_CURRENT_SOURCE_DIR}/ipp/LatestIPP/inc ${CMAKE_CURRENT_SOURCE_DIR}/ipp/LatestIPP_7/inc)
set(SOURCEDIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CURRENT_IPP_LIBRARY_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ipp/CurrentIPP/Release)
set(Latest_IPP_LIBRARY_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ipp/LatestIPP/Release)
set(Latest_IPP_7_LIBRARY_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ipp/LatestIPP_7/Release)

set(CURRENT_INTEL_HEADER_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ipp/CurrentIPP/INTEL_INC)
set(LATEST_INTEL_HEADER_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ipp/LatestIPP/INTEL_INC)
#set(LATEST_INTEL_7_HEADER_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ipp/LatestIPP_7/INTEL_INC)

set(SOURCE ${SOURCEDIR}/main.cpp)

add_executable(PerformanceTestIPPEXE ${SOURCE})
target_include_directories(PerformanceTestIPPEXE PRIVATE ${HEADERDIRECTORIES} ${CURRENT_INTEL_HEADER_DIRECTORY} ${LATEST_INTEL_HEADER_DIRECTORY})
target_link_directories(PerformanceTestIPPEXE PRIVATE ${CURRENT_IPP_LIBRARY_DIRECTORY} ${Latest_IPP_LIBRARY_DIRECTORY} ${Latest_IPP_7_LIBRARY_DIRECTORY})
target_link_libraries(PerformanceTestIPPEXE PRIVATE CurrentIntelIPPSharedLIB.lib LatestIntelIPPSharedLIB.lib LatestIntelIPPSharedLIB2021.7.lib)

file(COPY "${CURRENT_IPP_LIBRARY_DIRECTORY}/CurrentIntelIPPSharedLIB.dll" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/IPP_Release_x64/Release")
file(COPY "${Latest_IPP_LIBRARY_DIRECTORY}/LatestIntelIPPSharedLIB.dll" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/IPP_Release_x64/Release")
file(COPY "${Latest_IPP_7_LIBRARY_DIRECTORY}/LatestIntelIPPSharedLIB2021.7.dll" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/IPP_Release_x64/Release")