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
	

//Lesson 2:图像的读取与显示
//	namedWindow("显示图片", WINDOW_FREERATIO);
//	imshow("显示图片", src);//显示第一张原色图片
	

//Lesson 3:图片色彩转换与保存
//	quickdemo qk;//将头文件中定义的类进行实例化,命名为qk，使用qk.方法引用其色彩转换和图片保存方法
//	qk.color_Space_Convert(src);//引用方法，显示灰度和hsc图像并保存，所以马上将要显示三张图片并保存两种图片在F盘
	

//Lesson 4:图像对象的创建与辅助
//	quickdemo qk2;
//	qk2.mat_creation();


//Lesson 5:图像像素的操作（指针或者数组）
//	quickdemo qk3;//将类实例化
//	qk3.pixel_visit_demo_array(src);//引用方法并传入读取的照片


//Lesson 6:像素的算术操作
	quickdemo qk4;
	qk4.operators_demo(src);


	waitKey(0);//等待，以ms为单位
	destroyAllWindows();//销毁所有窗口
	return 0;
}