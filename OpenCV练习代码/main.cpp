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
	

//Lesson 2:ͼ��Ķ�ȡ����ʾ
//	namedWindow("��ʾͼƬ", WINDOW_FREERATIO);
//	imshow("��ʾͼƬ", src);//��ʾ��һ��ԭɫͼƬ
	

//Lesson 3:ͼƬɫ��ת���뱣��
//	quickdemo qk;//��ͷ�ļ��ж���������ʵ����,����Ϊqk��ʹ��qk.����������ɫ��ת����ͼƬ���淽��
//	qk.color_Space_Convert(src);//���÷�������ʾ�ҶȺ�hscͼ�񲢱��棬�������Ͻ�Ҫ��ʾ����ͼƬ����������ͼƬ��F��
	

//Lesson 4:ͼ�����Ĵ����븨��
//	quickdemo qk2;
//	qk2.mat_creation();


//Lesson 5:ͼ�����صĲ�����ָ��������飩
//	quickdemo qk3;//����ʵ����
//	qk3.pixel_visit_demo_array(src);//���÷����������ȡ����Ƭ


//Lesson 6:���ص���������
	quickdemo qk4;
	qk4.operators_demo(src);


	waitKey(0);//�ȴ�����msΪ��λ
	destroyAllWindows();//�������д���
	return 0;
}