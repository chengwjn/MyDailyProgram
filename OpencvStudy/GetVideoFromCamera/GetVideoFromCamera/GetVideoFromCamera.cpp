#include<opencv2/opencv.hpp>
using namespace cv;
int main()
{
	VideoCapture capture(0);//从摄像头读取视频
	while (1)//循环每一帧
	{
		Mat frame;
		capture >> frame;//将capture传入Mat frame图像中
		flip(frame, frame, 1);//沿y轴翻转图像
		cvtColor(frame, frame, COLOR_BGR2GRAY);//将图像成灰度图
		blur(frame, frame, Size(7, 7));//进行模糊降噪
		Canny(frame, frame, 0, 30, 3);//canny边缘检测
		imshow("", frame);//显示经过处理后的当前帧
		waitKey(30);//延迟30ms
	}
	return 0;
}