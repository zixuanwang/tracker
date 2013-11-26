LINK_DIRECTORIES("C:/Program Files/Microsoft SDKs/Kinect/v1.8/lib/amd64")

ADD_EXECUTABLE(fetch_kinect 
	fetch_kinect.cpp
	KinectHelper.h
	OpenCVFrameHelper.h OpenCVFrameHelper.cpp
	OpenCVHelper.h OpenCVHelper.cpp
	resource.h)

TARGET_INCLUDE_DIRECTORIES(fetch_kinect PUBLIC "C:/Program Files/Microsoft SDKs/Kinect/v1.8/inc")

TARGET_LINK_LIBRARIES(fetch_kinect libtracker Kinect10)