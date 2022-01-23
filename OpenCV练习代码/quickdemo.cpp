#include "quickopencvdemo.h"//引入头文件

//定义方法前先将类实例化
//Lesson 3:图片色彩转换与保存
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

//Lesson 4:图像对象的创建与辅助
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


//Lesson 5:像素读写操作（使用数组）
void quickdemo::pixel_visit_demo_array(Mat & image)
{
	int w = image.cols;//获取图像的宽
	int h = image.rows;//获取图像的高
	int c = image.channels();//获取图像的通道数
//	namedWindow("原始图片",WINDOW_FREERATIO);
	imshow("原始图片", image);//显示原始图片
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (c == 1)//通道数为1,灰度图像
			{
				int pv = image.at<uchar>(row, col);//获取像素点的值并转化为int类型
				image.at<uchar>(row, col) = 255 - pv;//对单通道的像素值进行修改
			}
			if (c == 3)//彩色图像，通道数为3
			{
				Vec3b bgr = image.at<Vec3b>(row, col);//bgr是一个数组
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
//	namedWindow("使用数组修改像素值", WINDOW_FREERATIO);
	imshow("使用数组修改像素值", image);//显示用数组修改后的图片
}

//Lesson 5:像素读写操作（使用指针）
void quickdemo::pixel_visit_demo_pointer(Mat & image)
{
	int w = image.cols;
	int h = image.rows;
	int c = image.channels();
	for (int row = 0; row < h; row++)
	{
		uchar* current_row = image.ptr<uchar>(row);//定义一个指针，uchar类型
		for (int col = 0; col < w; col++)
		{
			if (c == 1)//灰度图像
			{
				int pv = *current_row;
				*current_row++ = 255 - pv;//挨个往下移动
			}
			if (c == 3)//彩色图像
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
	//简单加法---使用标量函数
//	Mat dst;
//	dst = image + Scalar(50, 50, 50);
//	imshow("原图", image);
//	imshow("简单加法",dst);

	//加法，使用add函数
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 200);
//	add(image, m, dst);
//	imshow("原图", image);
//	imshow("乘法",dst);

	//加法原理
/*
	Mat dst = Mat::zeros(image.size(), image.type());//输出图像
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(200, 200, 200);
	int w = image.cols;
	int h = image.rows;
	int c = image.channels();
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			Vec3b p1 = image.at<Vec3b>(row, col);//读取输入1的像素值
			Vec3b p2 = m.at<Vec3b>(row, col);//读取m的像素值
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	imshow("原图", image);
	imshow("加法原理",dst);

*/


	//减法，使用标量函数
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(100, 100, 100);
//	dst = image - m;
//	imshow("原图", image);
//	imshow("乘法",dst);


	//减法，使用subtract函数
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(100, 100, 100);
//	subtract(image, m, dst);
//	imshow("原图", image);
//	imshow("乘法",dst);


	//乘法，使用multiply函数
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(2, 2, 2);
//	multiply(image, m, dst);
//	imshow("原图", image);
//	imshow("乘法",dst);


	//除法，使用标量函数
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 2);
//	dst = image/m;
//	imshow("原图", image);
//	imshow("乘法",dst);


	//除法，使用divide函数
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 2);
//	divide(image, m, dst);
//	imshow("原图", image);
//	imshow("乘法",dst);



}
