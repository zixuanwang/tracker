PROJECT(tracker)

cmake_minimum_required(VERSION 2.8)
IF(MSVC)
        SET(CMAKE_CXX_FLAGS "/EHsc")
        ADD_DEFINITIONS( -DBOOST_ALL_NO_LIB )
ENDIF(MSVC)
find_package(Boost COMPONENTS filesystem system REQUIRED)
find_package(OpenCV REQUIRED)
find_package(CURL REQUIRED)

INCLUDE_DIRECTORIES(
${Boost_INCLUDE_DIRS}
${CURL_INCLUDE_DIR}
${OPENCV_INCLUDE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}
)
SET( LIBRARY_OUTPUT_PATH ${tracker_BINARY_DIR}/../lib CACHE PATH
     "Output directory for the tracker library" )
SET( EXECUTABLE_OUTPUT_PATH 
     ${tracker_BINARY_DIR}/../bin CACHE PATH
     "Output directory for the tracker executables" )

SUBDIRS(tracker/lib)
SUBDIRS(tracker/exe)
SUBDIRS(tracker/server)
SUBDIRS(tracker/kinect)