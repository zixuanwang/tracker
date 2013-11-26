#include "KinectHelper.h"
#include <memory>
#include "OpenCVFrameHelper.h"
#include "OpenCVHelper.h"
#include <opencv2/opencv.hpp>

using namespace Microsoft::KinectBridge;

int main(int argc, char* argv[]){
	std::vector<INuiSensor*> sensor_vector;
	std::vector<std::shared_ptr<OpenCVFrameHelper> > frame_helper_vector;
	OpenCVHelper opencv_helper;
	int sensor_count = 0;
	HRESULT hr;
	hr = NuiGetSensorCount(&sensor_count);
	for(int i = 0; i < sensor_count; ++i){
		INuiSensor* sensor = NULL;
		hr = NuiCreateSensorByIndex(i, &sensor);
		if(SUCCEEDED(hr)){
			sensor_vector.push_back(sensor);
			std::shared_ptr<OpenCVFrameHelper> frame_helper(new OpenCVFrameHelper);
			frame_helper->Initialize(sensor);
			frame_helper_vector.push_back(frame_helper);
		}
	}
	DWORD width, height;
	frame_helper_vector.back()->GetColorFrameSize(&width, &height);
	cv::Size size(width, height);
    cv::Mat image(size, CV_8UC4);
	cv::namedWindow("Kinect");
	NUI_IMAGE_RESOLUTION colorResolution = NUI_IMAGE_RESOLUTION_640x480;
    NUI_IMAGE_RESOLUTION depthResolution = NUI_IMAGE_RESOLUTION_320x240;
	//frame_helper_vector.back()->SetSkeletonTrackingFlag(NUI_SKELETON_TRACKING_FLAG_ENABLE_SEATED_SUPPORT, true);
	while(true){
		NUI_SKELETON_FRAME skeletonFrame;
		frame_helper_vector.back()->UpdateSkeletonFrame();
		frame_helper_vector.back()->GetSkeletonFrame(&skeletonFrame);
		frame_helper_vector.back()->UpdateColorFrame();
		frame_helper_vector.back()->GetColorImage(&image);
		hr = opencv_helper.DrawSkeletonsInColorImage(&image, &skeletonFrame, colorResolution, depthResolution);
		cv::imshow("Kinect", image);
		cv::waitKey(30);	
	}
	cv::destroyAllWindows();
	return 0;
}