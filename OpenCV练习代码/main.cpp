#include<opencv2\opencv.hpp>
#include<iostream>
#include "quickopencvdemo.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/12396/Desktop/Picture/OpenCV/face3.jpg");
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
//	quickdemo qk4;
//	qk4.operators_demo(src);


//Lesson 7:��������������
//	quickdemo qk5;
//	qk5.tracking_bar_demo(src);


//Lesson 8��������Ӧ
//	quickdemo qk6;
//	qk6.key_demo(src);


//Lesson 9:ɫ��ת����

//	quickdemo qk7;
//	qk7.color_table(src);


//Lesson 10:λ����
//	quickdemo qk8;
//	qk8.bitwise_demo(src);


//Lesson 11:ͨ��������ϲ�
//	quickdemo qk9;
//	qk9.channels_demo(src);

//Lesson 12:ͨ��������ϲ�
//	quickdemo qk10;
//	qk10.inrange_demo(src);

//Lesson 13:ͨ��������ϲ�
//	quickdemo qk11;
//	qk10.pixel_stata_demo(src);


//Lesson 14:����ͼ�λ���
//	quickdemo qk12;
//	qk12.drawing_demo(src);


//Lesson 15:���ͼ�λ���
//	quickdemo qk13;
//	qk13.randow_demo();


//Lesson 16:�����ͼ�λ��������
//	quickdemo qk14;
//	qk14.polygon_demo();

//Lesson 17:ͼ����������ת�����һ��
//	quickdemo qk15;
//	qk15.type_convert(src);

//Lesson 18:ͼ����������ת�����һ��
//	quickdemo qk16;
//	qk16.interpolation_demo(src);

//Lesson 19:ͼ��ת
//	quickdemo qk17;
//	qk17.flip_demo(src);



//Lesson 20:ͼ����ת
//	quickdemo qk18;
//	qk18.rotate_demo(src);


//Lesson 21:����ͷ����Ƶ�ļ��Ķ�ȡ�����
//	quickdemo qk19;
//	qk19.video_demo(src);

//Lesson 22:��Ƶ�ļ��ı���
//	quickdemo qk20;
//	qk20.video_write_demo(src);



//Lesson 23:ͼ��ֱ��ͼ
//	quickdemo qk21;
//	qk21.histogram_demo(src);


//Lesson 24:��άֱ��ͼ
//	quickdemo qk22;
//	qk22.histogram_2d_demo(src);

//Lesson 25:ֱ��ͼ���⻯
//	quickdemo qk23;
//	qk23.equalize_demo(src);

//Lesson 26:ͼ����
//	quickdemo qk24;
//	qk24.blur_demo(src);


//Lesson 27:��˹ģ��
//	quickdemo qk25;
//	qk25.gaussian_demo(src);


//Lesson 28:��˹˫��ģ��
	quickdemo qk26;
	qk26.bi_gaussian_demo(src);

	waitKey(0);//�ȴ�����msΪ��λ
	destroyAllWindows();//�������д���
	return 0;
}