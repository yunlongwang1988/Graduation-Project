#include "quickopencvdemo.h"//����ͷ�ļ�

//���巽��ǰ�Ƚ���ʵ����
//Lesson 3:ͼƬɫ��ת���뱣��
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

//Lesson 4:ͼ�����Ĵ����븨��
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


//Lesson 5:���ض�д������ʹ�����飩
void quickdemo::pixel_visit_demo_array(Mat & image)
{
	int w = image.cols;//��ȡͼ��Ŀ�
	int h = image.rows;//��ȡͼ��ĸ�
	int c = image.channels();//��ȡͼ���ͨ����
//	namedWindow("ԭʼͼƬ",WINDOW_FREERATIO);
	imshow("ԭʼͼƬ", image);//��ʾԭʼͼƬ
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (c == 1)//ͨ����Ϊ1,�Ҷ�ͼ��
			{
				int pv = image.at<uchar>(row, col);//��ȡ���ص��ֵ��ת��Ϊint����
				image.at<uchar>(row, col) = 255 - pv;//�Ե�ͨ��������ֵ�����޸�
			}
			if (c == 3)//��ɫͼ��ͨ����Ϊ3
			{
				Vec3b bgr = image.at<Vec3b>(row, col);//bgr��һ������
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
//	namedWindow("ʹ�������޸�����ֵ", WINDOW_FREERATIO);
	imshow("ʹ�������޸�����ֵ", image);//��ʾ�������޸ĺ��ͼƬ
}

//Lesson 5:���ض�д������ʹ��ָ�룩
void quickdemo::pixel_visit_demo_pointer(Mat & image)
{
	int w = image.cols;
	int h = image.rows;
	int c = image.channels();
	for (int row = 0; row < h; row++)
	{
		uchar* current_row = image.ptr<uchar>(row);//����һ��ָ�룬uchar����
		for (int col = 0; col < w; col++)
		{
			if (c == 1)//�Ҷ�ͼ��
			{
				int pv = *current_row;
				*current_row++ = 255 - pv;//���������ƶ�
			}
			if (c == 3)//��ɫͼ��
			{
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
}

void quickdemo::operators_demo(Mat & image)
{
	//�򵥼ӷ�---ʹ�ñ�������
//	Mat dst;
//	dst = image + Scalar(50, 50, 50);
//	imshow("ԭͼ", image);
//	imshow("�򵥼ӷ�",dst);

	//�ӷ���ʹ��add����
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 200);
//	add(image, m, dst);
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);

	//�ӷ�ԭ��
/*
	Mat dst = Mat::zeros(image.size(), image.type());//���ͼ��
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(200, 200, 200);
	int w = image.cols;
	int h = image.rows;
	int c = image.channels();
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			Vec3b p1 = image.at<Vec3b>(row, col);//��ȡ����1������ֵ
			Vec3b p2 = m.at<Vec3b>(row, col);//��ȡm������ֵ
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	imshow("ԭͼ", image);
	imshow("�ӷ�ԭ��",dst);

*/


	//������ʹ�ñ�������
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(100, 100, 100);
//	dst = image - m;
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);


	//������ʹ��subtract����
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(100, 100, 100);
//	subtract(image, m, dst);
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);


	//�˷���ʹ��multiply����
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(2, 2, 2);
//	multiply(image, m, dst);
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);


	//������ʹ�ñ�������
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 2);
//	dst = image/m;
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);


	//������ʹ��divide����
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 2);
//	divide(image, m, dst);
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);



}
