#include "main.h"


main::main()
{
}


main::~main()
{
}

void main(void){
	Mat image = cvLoadImage("../../sampleImage/noise-sample.png",0);
	Mat rect = cvLoadImage("../../sampleImage/rect.png", 0);
	cvFunc CV;
	if (image.cols == 0){
		cout << "read error : sample" << endl;
	}
	if (rect.cols == 0){
		cout << "read error : rect" << endl;
	}
	else{
		Mat image1;
		vector<KeyPoint> point1 = CV.getDetectORB(rect,20);
		vector<KeyPoint> point2 = CV.getDetectORB(image,20);

		CV.showKeyPoint(rect, point1, "rect");
		CV.showKeyPoint(image, point2, "sample");
		CV.getMatchORB(image, rect);

		/*
		Mat image2;
		vector<KeyPoint> point2 = CV.getDetectEigen(image);
		drawKeypoints(image, point2, image2, Scalar(0, 0, 255));
		*/


		/*
		cvNamedWindow("eigen", CV_WINDOW_AUTOSIZE);
		imshow("eigen", image2);
		*/
	}

	cvWaitKey();


}