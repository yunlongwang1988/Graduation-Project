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
	void tracking_bar_demo(Mat & image);//Lesson 7:�������ȵĹ�����
	void key_demo(Mat & image);//Lesson 8:������Ӧ
	void color_table(Mat & image);//Lesson 9:��ɫ��ת��
	void bitwise_demo(Mat & image);//Lesson 10:λ����
	void channels_demo(Mat & image);//Lesson 11:ͨ����������
	void inrange_demo(Mat & image);//Lesson 12:ͼ��ɫ�ʿռ�ת��
	void pixel_stata_demo(Mat & image);//Lesson 13:ͼ������ͳ�ƣ����ֵ��Сֵ����ֵ������
	void drawing_demo(Mat & image);//Lesson 14��������״�Ļ���
	void randow_demo();//Lesson 15:���ͼ�λ���
	void polygon_demo();//Lesson 16:����εĻ��ƺ����
	void type_convert(Mat & image);//Lesson 17:ͼ����������ת�����һ��
	void interpolation_demo(Mat & image);//Lesson 18:ͼ��������ֵ
	void flip_demo(Mat & image);//Lesson 19:ͼ��ת
	void rotate_demo(Mat & image);//Lesson 20:ͼ����ת
	void video_demo(Mat & image);//Lesson 21:����ͷ����Ƶ�ļ��Ķ�ȡ
	void video_write_demo(Mat & image);//Lesson 22:��Ƶ�ļ��ı���
	void histogram_demo(Mat & image);//Lesson 23:ͼ��ֱ��ͼ
	void histogram_2d_demo(Mat & image);//Lesson 24:��άֱ��ͼ
	void equalize_demo(Mat & image);//Lesson 25:ֱ��ͼ���⻯
	void blur_demo(Mat & image);//Lesson 26:ͼ����
	void gaussian_demo(Mat & image);//Lesson 27:��˹ģ��
	void bi_gaussian_demo(Mat & image);//Lesson 28:��˹˫��ģ��
};

