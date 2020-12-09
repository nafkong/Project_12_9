#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcMat = imread("source.png");
//	Mat srcMat = imread("source1.png");
	Mat dstMat;
	srcMat.copyTo(dstMat);
	vector<Mat> channels;
	vector<Mat> dst;
	split(srcMat, channels);
	split(dstMat, dst);
	Mat B = channels.at(0);
	Mat G = channels.at(1);
	Mat R = channels.at(2);
//	cvtColor(srcMat, graMat, COLOR_BGR2GRAY);
	equalizeHist(B, dst.at(0));
	equalizeHist(G, dst.at(1));
	equalizeHist(R, dst.at(2));
	merge(dst, dstMat);
	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);


}