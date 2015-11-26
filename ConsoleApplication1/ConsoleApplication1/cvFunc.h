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
	vector<KeyPoint> cvFunc::getDetectORB(Mat image, int pointNum);
	void cvFunc::getMatchORB(Mat bese, Mat match);
	void cvFunc::getMatchORB(Mat base, Mat match, int pointNum);
	void cvFunc::getMatchORB(Mat base, vector<KeyPoint> point1, Mat match, vector<KeyPoint> point2);


	void cvFunc::showKeyPoint(Mat image, vector<KeyPoint> point, char* windowName);

};

