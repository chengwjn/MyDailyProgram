#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;



int otsu(const cv::Mat& img)//寻找最合理的阈值
{
	float histogram[256] = { 0 };
	for (int i = 0; i < img.rows; i++)
	{
		const unsigned char* p = (const unsigned char*)img.ptr(i);
		for (int j = 0; j < img.cols; j++)
		{
			histogram[p[j]]++;
		}
	}

	float avgValue = 0;
	int numPixel = img.cols * img.rows;
	for (int i = 0; i < 256; i++)
	{
		histogram[i] = histogram[i] / numPixel;
		avgValue += i * histogram[i];
	}

	int threshold = 0;
	float gmax = 0;
	float wk = 0, uk = 0;
	for (int i = 0; i < 256; i++) {

		wk += histogram[i];
		uk += i * histogram[i];

		float ut = avgValue * wk - uk;
		float g = ut * ut / (wk * (1 - wk));

		if (g > gmax)
		{
			gmax = g;
			threshold = i;
		}
	}
	return threshold;
}
//-------------------- -
//作者：Justin__Ko
//来源：CSDN
//原文：https ://blog.csdn.net/kfqcome/article/details/9528773 
//版权声明：本文为博主原创文章，转载请附上博文链接！

int main(int argc, char** argv)
{

	Mat srcImage = imread("C:/Users/cheng/Pictures/Camera Roll/20190415_174346.jpg");//读取原图
	 
	Mat grayImage;

	cvtColor(srcImage,grayImage , COLOR_BGR2GRAY);//转为灰度图像
	/*namedWindow("grayImage", 0);
	imshow("grayImage", grayImage);*/

	//图像降噪
	Mat blurImage;
	GaussianBlur(grayImage, blurImage, Size(5, 5),0,0,BORDER_DEFAULT);
	/*namedWindow("blurImage",WINDOW_NORMAL);
	imshow("blurImage", blurImage)*/;

	//形态学处理
	Mat openImage;
	morphologyEx(grayImage, openImage, MORPH_OPEN,getStructuringElement(MORPH_RECT,Size(5,5)));
	
	//Mat dilateImage;(废掉此三行)
	//erode(blurImage, erodeImage, getStructuringElement(MORPH_RECT,Size(2,2)));
	//dilate(erodeImage, dilateImage, getStructuringElement(MORPH_RECT, Size(2, 2)));
	/*namedWindow("openImage1", WINDOW_NORMAL);
	imshow("openImage1", openImage);*/

	//阈值分割(二值化)
	Mat thresholdImage;
	int thresh = otsu(openImage);
	cout << thresh << endl;
	thresh -= 30;//调整一下阈值
	threshold(openImage, thresholdImage, thresh,255,0);
	/*namedWindow("thresholdImage", WINDOW_NORMAL);
	imshow("thresholdImage", thresholdImage);*/

	

	//边缘检测
	Mat SobelXImage;
	Mat SobelXImageAbs;
	Mat SobelYImage;
	Mat SobelYImageAbs;
	Mat SobelImage;
	Sobel(thresholdImage, SobelXImage,CV_16U,1,0,3,1,1,BORDER_DEFAULT);
	convertScaleAbs(SobelXImage, SobelXImageAbs);
	/*namedWindow("SobelXImage", 0);
	imshow("SobelXImage", SobelXImageAbs);*/
	Sobel(thresholdImage, SobelYImage, CV_16U,0,1,3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(SobelYImage, SobelYImageAbs);
	/*namedWindow("SobelYImage", 0);
	imshow("SobelYImage", SobelYImageAbs);*/
	addWeighted(SobelXImageAbs, 0.5, SobelYImageAbs, 0.5, 0, SobelImage);
	/*namedWindow("SobelImage", 0);
	imshow("SobelImage", SobelImage);*/

	//沙雕霍夫变换(到底哪里错了啊！！！)
	/*Mat HoughImage;
	vector<Vec4i>lines;
	HoughLinesP(SobelImage, lines, 1, CV_PI / 180, thresh, 50, 10);
	for (int i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(HoughImage, Point(l[i], l[i+1]), Point(l[i+2], l[i+3]), Scalar(255), 1, LINE_AA);
	}
	namedWindow("HoughImage", 0);
	imshow("HoughImage", HoughImage);*/
	//图片边缘光滑处理
//size表示取均值的窗口大小，threshold表示对均值图像进行二值化的阈值
	

	
	//再一次降噪
	Mat blurImage2;
	GaussianBlur(SobelImage, blurImage2, Size(3, 3), 0, 0, BORDER_DEFAULT);
	/*namedWindow("blurImage2",WINDOW_NORMAL);
	imshow("blurImage2", blurImage2);*/
	//imwrite("C:/Users/cheng/Pictures/Camera Roll/blur2.jpg", blurImage2);

	////在进行一次形态学处理
	/*Mat openImage2;
	morphologyEx(blurImage2, openImage2, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(50, 50)));
	namedWindow("openImage2", WINDOW_NORMAL);
	imshow("openImage2", openImage2);*/
	Mat dilateImage;
	dilate(SobelImage, dilateImage, getStructuringElement(MORPH_RECT,Size(60,60)));
	erode(dilateImage, dilateImage, getStructuringElement(MORPH_RECT, Size(60,60)));
	
	erode(dilateImage, dilateImage, getStructuringElement(MORPH_RECT, Size(60, 60)));
	dilate(dilateImage, dilateImage, getStructuringElement(MORPH_RECT, Size(60, 60)));
	/*namedWindow("dilateImage",WINDOW_NORMAL);
	imshow("dilateImage", dilateImage);*/
    /*morphologyEx(openImage2, openImage2, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(3, 3)));
	namedWindow("closeImage", WINDOW_NORMAL);
	imshow("closeImage", openImage2);*/

	////在进行一次二值化
	Mat thresholdImage2;
	int thresh2 = otsu(dilateImage);
	threshold(dilateImage, thresholdImage2, thresh2, 255, 0);
	namedWindow("thresholdImage2", WINDOW_NORMAL);
	imshow("thresholdImage2", thresholdImage2);

	////平滑处理
	//Mat blurImage3;
	//imageblur(thresholdImage2, blurImage3, Size(40,40), thresh);
	//namedWindow("blurImage2", WINDOW_NORMAL);
	//imshow("blurImage2", blurImage3);
	
	////寻找轮廓

	//vector<vector<Point>> contours;
	///*vector<Vec4i>hierarchy;*/
	//findContours(thresholdImage2, contours,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	///*int index = 0;
	//for (; index >= 0; index = hierarchy[index][0])
	//{
	//	drawContours(thresholdImage2, contours, index, Scalar(255, 0, 0), FILLED, 8, hierarchy);
	//}*/
	//drawContours(thresholdImage2, contours, -1, Scalar(255,0,0), 1);
	//Mat RoiImage;
	//vector<Point>rectPoint;
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	Rect r = boundingRect(Mat(contours[i]));
	//	//RotatedRect r = minAreaRect(Mat(contours[i]));
	//	cout << "contours " << i << "  height = " << r.height << "  width = " << r.width << "rate = " << ((float)r.width / r.height) << endl;
	//	if ((float)r.width / r.height >= 2.2 && (float)r.width / r.height <= 3.6) {
	//		cout << "r.x = " << r.x << "  r.y  = " << r.y << endl;
	//		rectangle(thresholdImage2, r, Scalar(255, 0, 0), 2);
	//		for (int j = 0; j < contours[i].size(); j++) 
	//		{
	//			cout << "point = " << contours[i][j] << endl;
	//		}
	//		//rectangle(image, r, Scalar(0, 0, 255), 3);
	//		RoiImage = srcImage(r);
	//	}
	//}
	
	waitKey(0);
	return 0;
}
//图片边缘光滑处理
//size表示取均值的窗口大小，threshold表示对均值图像进行二值化的阈值
//void imageblur(Mat& src, Mat& dst, Size size, int threshold)
//{
//	int height = src.rows;
//	int width = src.cols;
//	blur(src, dst, size);
//	for (int i = 0; i < height; i++)
//	{
//		uchar* p = dst.ptr<uchar>(i);
//		for (int j = 0; j < width; j++)
//		{
//			if (p[j] < threshold)
//				p[j] = 0;
//			else p[j] = 255;
//		}
//	}
//}