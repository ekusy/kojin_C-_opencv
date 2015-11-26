#include "cvFunc.h"


cvFunc::cvFunc()
{
}


cvFunc::~cvFunc()
{
}

Mat cvFunc::getGray(Mat image){
	Mat gray;
	threshold(image, gray, 128, 255, THRESH_BINARY);
	normalize(gray, gray, 0, 255, NORM_MINMAX);
	return gray;
}

vector<KeyPoint> cvFunc::getDetectHarris(Mat image){
	Mat gray = getGray(image);
	vector<KeyPoint> point;
	//auto harris = FeatureDetector::create("HARRIS");
	//morphologyEx(gray, gray,MORPH_OPEN, Mat(), Point(-1, -1), 1);

	erode(gray, gray, Mat(), Point(-1, -1), 4); 
	dilate(gray, gray, Mat(), Point(-1, -1), 4);
	
	cvNamedWindow("base", CV_WINDOW_AUTOSIZE);
	imshow("base", image);
	
	cvNamedWindow("noise", CV_WINDOW_AUTOSIZE);
	imshow("noise", gray);
	
	GoodFeaturesToTrackDetector harris(4, 0.01, 1, 3, true, 0.04);
	harris.detect(gray, point);
	drawKeypoints(gray, point, gray, Scalar(0, 0, 255));

	cvNamedWindow("harris", CV_WINDOW_AUTOSIZE);
	imshow("harris", gray);

	return point;
}

vector<KeyPoint> cvFunc::getDetectEigen(Mat image){
	Mat gray = getGray(image);
	int max = 10;
	vector<Point2f> pt;
	vector<KeyPoint> point;
	goodFeaturesToTrack(gray, pt, max, 0.01, 5);
	KeyPoint::convert(point, pt);
	return point;
}

vector<KeyPoint> cvFunc::getDetectORB(Mat image){
	Mat gray = getGray(image);
	vector<KeyPoint> point;
	//auto harris = FeatureDetector::create("HARRIS");
	//morphologyEx(gray, gray,MORPH_OPEN, Mat(), Point(-1, -1), 1);

	erode(gray, gray, Mat(), Point(-1, -1), 4);
	dilate(gray, gray, Mat(), Point(-1, -1), 4); 
	
	OrbFeatureDetector detector(10);
	OrbDescriptorExtractor extractor;
	//vector<KeyPoint> point;
	detector.detect(gray, point);
	drawKeypoints(gray, point, gray, Scalar(0, 0, 255));
	cvNamedWindow("base", CV_WINDOW_AUTOSIZE);
	imshow("base", gray);
	return point;


}


/*
vector<KeyPoint> cvFunc::getDetectFAST(Mat image){
	Mat gray = getGray(image);

}
*/