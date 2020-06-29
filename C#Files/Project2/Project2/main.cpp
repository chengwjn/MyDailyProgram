#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	Mat srcImage = imread("xxxxxxx.jpg");
	imshow("[]", srcImage);
	Mat element = getStructuringElement(MORPH_RECT,Size(15, 15));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	imshow("",dstImage);
	waitKey(0);
	return 0;
}