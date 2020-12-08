#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string window_name = "binaryMat";
int lowTh = 25, maxTh = 100;
Mat_<float>(inMat);
Mat_<float>(outMat);
//float gamma = 1.0;
void threshold_Mat(int, void*)
{
	for (int i = 0; i < inMat.rows; i++) {
		for (int j = 0; j < inMat.cols; j++) {
			outMat.at<float>(i, j) = pow(inMat.at<float>(i, j), lowTh/10) * 255;
		}
	}
	imshow(window_name, outMat);
}

int main()
{
	Mat srcMat = imread("source1.png");
	Mat graMat;
	cvtColor(srcMat, graMat, COLOR_BGR2GRAY);
	inMat = graMat / 255;
	outMat = graMat / 255;
	imshow("srcMat", srcMat);
	imshow("inMat", inMat);
	imshow(window_name, outMat);

	createTrackbar("threshold",
					window_name,
					&lowTh, maxTh,
					threshold_Mat);

	waitKey(0);

}