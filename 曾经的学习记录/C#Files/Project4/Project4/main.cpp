#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

#define WINDOW_NAME1 "[ԭʼͼ����]"
#define WINDOW_NAME2 "[Ч��ͼ����]"

Mat g_srcImage;
Mat g_grayImage;
int g_nThresh = 50;//��ֵ
int g_nMaxThresh = 255;//��ֵ���ֵ
RNG g_rng(12345);//�����������

//����ȫ�ֺ���
void on_ContoursChange(int, void*);
static void ShowHelpText();

//main()����
int main(int argc, char** argv)
{

	//����3ͨ����ԭͼ��
	g_srcImage = imread("illust_73479784_20190303_113444.jpg",1);
	if (!g_srcImage.data)
	{
		printf("error!\n");
		return false;
	}

	//�õ�ԭͼ�ĻҶ�ͼ�񲢽���ƽ������
	cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
	blur(g_grayImage, g_grayImage, Size(3, 3));

	//����ԭʼͼ����ʾ
	namedWindow(WINDOW_NAME1, WINDOW_AUTOSIZE);
	imshow(WINDOW_NAME1, g_srcImage);

	//���ù�����������һ�λص�����
	createTrackbar("��ֵ:", WINDOW_NAME1,&g_nThresh,g_nMaxThresh, on_ContoursChange);
	on_ContoursChange(0, 0);

	waitKey(0);
	return 0;
}
void on_ContoursChange(int, void*)
{
	Mat threshold_output;
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;

	//ʹ��Threshold���
	threshold(g_grayImage, threshold_output, g_nThresh, 255, THRESH_BINARY);

	//�ҳ�����
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	//����αƽ�����+��ȡ���κ�Բ�α߽��
	vector<vector<Point>>contours_poly(contours.size());
	vector<Rect>boundRect(contours.size());
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());

	//һ��ѭ���������в��֣����б���������ĵĲ���
	for (unsigned int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);//��ָ�����ȱƽ����������
		boundRect[i] = boundingRect(Mat(contours_poly[i]));//����㼯��������(up-right)���α߽�
		minEnclosingCircle(contours_poly[i], center[i], radius[i]);//�Ը�����2D�㼯��Ѱ����С����İ�ΧԲ��
	}
	//���ƶ��������+��Χ�ľ��ο�+Բ�ο�
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int unsigned i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));
		drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);//���ƾ���
		circle(drawing, center[i], (int)radius[i], color, 2, 9, 0);//����Բ
	}

	//��ʾЧ��ͼ����
	namedWindow(WINDOW_NAME2, WINDOW_AUTOSIZE);
	imshow(WINDOW_NAME2, drawing);
}
