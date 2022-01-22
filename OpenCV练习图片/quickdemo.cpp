#include "quickopencvdemo.h"//引入头文件

//定义方法前先将类实例化
//这是第一个方法：图像的色彩转换与图片保存
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

//定义的第二个方法：
void quickdemo::mat_creation()
{
	/*
	Mat m1, m2;
	m2 = image.clone();//对参数image进行clone
	image.copyTo(m2);//对参数image进行copy
	*/
	//创建空白图像
	Mat m3 = Mat::zeros(Size(512, 512), CV_8UC3);//Size(8,8)表示图像大小，CV_8UC1表示8位，U表示无符号，1表示一个通道
	//m3 = 127;//默认设置一个第一个通道为127
	m3 = Scalar(0,0,255);
	//std::cout << "width= " << m3.cols << "height= " << m3.rows << "channels= " << m3.channels()<<std::endl;
	//std::cout << m3 << std::endl;
	//namedWindow("通道检验", WINDOW_FREERATIO);
	//imshow("通道检验", m3);


	//赋值，其中一个改变，另一个也改变
//	Mat m4 = m3;
//	m4 = Scalar(255, 0, 0);
//	imshow("m3", m3);
//	imshow("m4", m4);

	//克隆clone：对克隆后的值修改不会影响原来的值
//	Mat m4 = m3.clone();
//	m4 = Scalar(246, 0, 255);
//	imshow("m3",m3);
//	imshow("m4", m4);

	//复制copy：对复制后的值修改不会改变原来的值
	Mat m4;
	m3.copyTo(m4);
	m4 = Scalar(65, 255, 90);
	imshow("m3",m3);
	imshow("m4", m4);

}