#pragma once
#include<opencv2/opencv.hpp>//����opencv�⺯��

using namespace cv;//�������ƿռ�

class quickdemo//����һ���µ���
{
public://����ȫ�ַ���
	void color_Space_Convert(Mat & image);//����һ��ɫ��ת���ķ���
	void mat_creation();//����һ��ͼ����󷽷�,��������Ϊ��Ҫ����Ĳ�����Ҳ����û��
	void pixel_visit_demo_array(Mat & image);//Lesson 5�����ض�д����(ʹ������)
	void pixel_visit_demo_pointer(Mat & image);//Lesson 5:���ض�д����(ʹ��ָ��)
	void operators_demo(Mat & image);//Lesson 6:������������
};