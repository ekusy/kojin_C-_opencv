#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui_c.h>
#include <iostream>

using namespace std;
using namespace cv;

class cvFunc
{
public:
	cvFunc();
	~cvFunc();
	Mat getGray(Mat image);
	vector<KeyPoint> getDetectHarris(Mat image);
	vector<KeyPoint> getDetectEigen(Mat image);
	vector<KeyPoint> getDetectFAST(Mat image);
	vector<KeyPoint> cvFunc::getDetectORB(Mat image);
};

