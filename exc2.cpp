#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcMat = imread("source.png");
	Mat dstMat;
	vector<Mat> channels;
	split(srcMat, channels);
	Mat dst_R, dst_G, dst_B;
	Mat B = channels.at(0);
	Mat G = channels.at(1);
	Mat R = channels.at(2);
//	cvtColor(srcMat, graMat, COLOR_BGR2GRAY);
	equalizeHist(B, dst_B);
	equalizeHist(G, dst_G);
	equalizeHist(R, dst_R);
	merge(channels, dstMat);
	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);


}