#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat srcImage = imread("C:/Users/cheng/Pictures/Camera Roll/20190415_174346.jpg");
	Mat midImage, dstImage;

	Canny(srcImage, midImage, 50, 200, 3);
	cvtColor(midImage, dstImage, COLOR_GRAY2BGR);

	vector<Vec4i> lines;
	HoughLinesP(midImage, lines, 1, CV_PI / 180, 80, 50, 10);

	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 255, 0), 1, LINE_AA);
	}
	/*namedWindow("srcImage", WINDOW_NORMAL);
	imshow("srcImage", srcImage);*/
	namedWindow("midImage", WINDOW_NORMAL);
	imshow("midImage", midImage);
	namedWindow("dstImage", WINDOW_NORMAL);
	imshow("dstImage", dstImage);
	waitKey(0);
	return 0;
}