#include<opencv2\opencv.hpp>
#include<iostream>
#include "quickopencvdemo.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/12396/Desktop/Picture/OpenCV/face2.jpg");
	if (src.empty())
	{
		printf("Image is not load....\n");
	}
	else
	{
		printf("Image load successfully!\n");
	}
	
	//namedWindow("��ʾͼƬ", WINDOW_FREERATIO);
	//imshow("��ʾͼƬ", src);//��ʾ��һ��ԭɫͼƬ
	
	//quickdemo qk;//��ͷ�ļ��ж���������ʵ����,����Ϊqk��ʹ��qk.����������ɫ��ת����ͼƬ���淽��
	//qk.color_Space_Convert(src);//���÷�������ʾ�ҶȺ�hscͼ�񲢱��棬�������Ͻ�Ҫ��ʾ����ͼƬ����������ͼƬ��F��
	
	//���ǵڶ�������ʵ����
	quickdemo qk2;
	qk2.mat_creation();

	waitKey(0);//�ȴ�����msΪ��λ
	destroyAllWindows();//�������д���
	return 0;

}