SET(tracker_sources
	Camera.h Camera.cpp
	Room.h Room.cpp
)
ADD_LIBRARY(libtracker ${tracker_sources})

TARGET_LINK_LIBRARIES(libtracker ${Boost_LIBRARIES} ${CURL_LIBRARIES} ${OpenCV_LIBS})
