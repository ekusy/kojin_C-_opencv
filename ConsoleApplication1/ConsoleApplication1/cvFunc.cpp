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

	GoodFeaturesToTrackDetector harris(4, 0.01, 1, 3, true, 0.04);
	harris.detect(gray, point);

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

	erode(gray, gray, Mat(), Point(-1, -1), 4);
	dilate(gray, gray, Mat(), Point(-1, -1), 4); 
	
	OrbFeatureDetector detector(10);
	//vector<KeyPoint> point;
	detector.detect(gray, point);
	imshow("base", gray);

	return point;
}

vector<KeyPoint> cvFunc::getDetectORB(Mat image, int pointNum){
	Mat gray = getGray(image);
	vector<KeyPoint> point;

	erode(gray, gray, Mat(), Point(-1, -1), 4);
	dilate(gray, gray, Mat(), Point(-1, -1), 4);

	OrbFeatureDetector detector(pointNum);
	OrbDescriptorExtractor extractor;
	//vector<KeyPoint> point;
	detector.detect(gray, point);
	imshow("base", gray);

	return point;
}

void cvFunc::getMatchORB(Mat base, Mat match){
	vector<KeyPoint> point1 = getDetectORB(base);
	vector<KeyPoint> point2 = getDetectORB(match);

	Mat description1, description2;
	OrbDescriptorExtractor extractor1, extractor2;
	extractor1.compute(base, point1, description1);
	extractor2.compute(match, point2, description2);

	vector<DMatch> matches;
	BFMatcher matcher(NORM_HAMMING, true);
	matcher.match(description1, description2, matches);
	Mat match_image;
	drawMatches(base, point1, match, point2, matches, match_image);
	imshow("マッチング結果", match_image);
}

void cvFunc::getMatchORB(Mat base, Mat match,int pointNum){
	vector<KeyPoint> point1 = getDetectORB(base, pointNum);
	vector<KeyPoint> point2 = getDetectORB(match, pointNum);

	Mat description1, description2;
	OrbDescriptorExtractor extractor1, extractor2;
	extractor1.compute(base, point1, description1);
	extractor2.compute(match, point2, description2);

	vector<DMatch> matches;
	BFMatcher matcher(NORM_HAMMING, true);
	matcher.match(description1, description2, matches);
	Mat match_image;
	drawMatches(base, point1, match, point2, matches, match_image);
	imshow("マッチング結果", match_image);


}

void cvFunc::getMatchORB(Mat base, vector<KeyPoint> point1, Mat match, vector<KeyPoint> point2){
	OrbDescriptorExtractor extractor1, extractor2;
	extractor1.compute(base, point1, base);
	extractor2.compute(match, point2, match);

	vector<DMatch> matches;
	BFMatcher matcher(NORM_HAMMING, true);
	matcher.match(base, match, matches);
	Mat match_image;
	drawMatches(base, point1, match, point2, matches, match_image);
	imshow("マッチング結果", match_image);
}

/*
vector<KeyPoint> cvFunc::getDetectFAST(Mat image){
	Mat gray = getGray(image);

}
*/

void cvFunc::showKeyPoint(Mat image, vector<KeyPoint> point,char* windowName){
	drawKeypoints(image, point, image, Scalar(255, 0, 0), 0);
	cvNamedWindow(windowName);
	imshow(windowName,image);

}