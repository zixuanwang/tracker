SET(tracker_sources
	Camera.h Camera.cpp
	CascadeDetector.h CascadeDetector.cpp
	Detector.h Detector.cpp
	Math.h Math.cpp
	ParticleFilter.h ParticleFilter.cpp
	Room.h Room.cpp
)
ADD_LIBRARY(libtracker ${tracker_sources})

TARGET_LINK_LIBRARIES(libtracker ${Boost_LIBRARIES} ${CURL_LIBRARIES} ${OpenCV_LIBS})
