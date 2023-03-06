#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
	VideoCapture capture(0); //������ͷ��ȡ��Ƶ
	while (1)				 //ѭ��ÿһ֡
	{
		Mat frame;
		capture >> frame;						//��capture����Mat frameͼ����
		flip(frame, frame, 1);					//��y�ᷭתͼ��
		cvtColor(frame, frame, COLOR_BGR2GRAY); //��ͼ��ɻҶ�ͼ
		blur(frame, frame, Size(7, 7));			//����ģ������
		Canny(frame, frame, 0, 30, 3);			//canny��Ե���
		imshow("", frame);						//��ʾ����������ĵ�ǰ֡
		waitKey(30);							//延迟30ms
	}
	return 0;
}