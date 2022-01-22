#include "quickopencvdemo.h"//����ͷ�ļ�

//���巽��ǰ�Ƚ���ʵ����
//���ǵ�һ��������ͼ���ɫ��ת����ͼƬ����
void quickdemo::color_Space_Convert(Mat & image)
{
	Mat gray, hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("HSV", hsv);
	imshow("Gray",gray);
	imwrite("F://opencv_Envir//opencv//hsv.jpg",hsv);
	imwrite("F://opencv_Envir//opencv//gray.jpg", gray);
	//imwrite("F://opencv_Envir//opencv//hsv.png", hsv);
	//imwrite("F://opencv_Envir//opencv//gray.png", gray);
}

//����ĵڶ���������
void quickdemo::mat_creation()
{
	/*
	Mat m1, m2;
	m2 = image.clone();//�Բ���image����clone
	image.copyTo(m2);//�Բ���image����copy
	*/
	//�����հ�ͼ��
	Mat m3 = Mat::zeros(Size(512, 512), CV_8UC3);//Size(8,8)��ʾͼ���С��CV_8UC1��ʾ8λ��U��ʾ�޷��ţ�1��ʾһ��ͨ��
	//m3 = 127;//Ĭ������һ����һ��ͨ��Ϊ127
	m3 = Scalar(0,0,255);
	//std::cout << "width= " << m3.cols << "height= " << m3.rows << "channels= " << m3.channels()<<std::endl;
	//std::cout << m3 << std::endl;
	//namedWindow("ͨ������", WINDOW_FREERATIO);
	//imshow("ͨ������", m3);


	//��ֵ������һ���ı䣬��һ��Ҳ�ı�
//	Mat m4 = m3;
//	m4 = Scalar(255, 0, 0);
//	imshow("m3", m3);
//	imshow("m4", m4);

	//��¡clone���Կ�¡���ֵ�޸Ĳ���Ӱ��ԭ����ֵ
//	Mat m4 = m3.clone();
//	m4 = Scalar(246, 0, 255);
//	imshow("m3",m3);
//	imshow("m4", m4);

	//����copy���Ը��ƺ��ֵ�޸Ĳ���ı�ԭ����ֵ
	Mat m4;
	m3.copyTo(m4);
	m4 = Scalar(65, 255, 90);
	imshow("m3",m3);
	imshow("m4", m4);

}