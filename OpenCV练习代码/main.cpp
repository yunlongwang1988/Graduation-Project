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
//	quickdemo qk4;
//	qk4.operators_demo(src);


//Lesson 7:滚动条调整亮度
//	quickdemo qk5;
//	qk5.tracking_bar_demo(src);


//Lesson 8：键盘响应
//	quickdemo qk6;
//	qk6.key_demo(src);


//Lesson 9:色彩转换表

//	quickdemo qk7;
//	qk7.color_table(src);


//Lesson 10:位操作
//	quickdemo qk8;
//	qk8.bitwise_demo(src);


//Lesson 11:通道分离与合并
//	quickdemo qk9;
//	qk9.channels_demo(src);

//Lesson 12:通道分离与合并
//	quickdemo qk10;
//	qk10.inrange_demo(src);

//Lesson 13:通道分离与合并
//	quickdemo qk11;
//	qk10.pixel_stata_demo(src);


//Lesson 14:几何图形绘制
//	quickdemo qk12;
//	qk12.drawing_demo(src);


//Lesson 15:随机图形绘制
//	quickdemo qk13;
//	qk13.randow_demo();


//Lesson 16:多边形图形绘制与填充
//	quickdemo qk14;
//	qk14.polygon_demo();

//Lesson 17:图像像素类型转化与归一化
//	quickdemo qk15;
//	qk15.type_convert(src);

//Lesson 18:图像像素类型转化与归一化
//	quickdemo qk16;
//	qk16.interpolation_demo(src);

//Lesson 19:图像翻转
//	quickdemo qk17;
//	qk17.flip_demo(src);



//Lesson 20:图像旋转
//	quickdemo qk18;
//	qk18.rotate_demo(src);


//Lesson 21:摄像头、视频文件的读取与调用
//	quickdemo qk19;
//	qk19.video_demo(src);

//Lesson 22:视频文件的保存
//	quickdemo qk20;
//	qk20.video_write_demo(src);



//Lesson 23:图像直方图
//	quickdemo qk21;
//	qk21.histogram_demo(src);


//Lesson 24:二维直方图
//	quickdemo qk22;
//	qk22.histogram_2d_demo(src);

//Lesson 25:直方图均衡化
//	quickdemo qk23;
//	qk23.equalize_demo(src);

//Lesson 26:图像卷积
//	quickdemo qk24;
//	qk24.blur_demo(src);


//Lesson 27:高斯模糊
//	quickdemo qk25;
//	qk25.gaussian_demo(src);


//Lesson 28:高斯双边模糊
	quickdemo qk26;
	qk26.bi_gaussian_demo(src);

	waitKey(0);//等待，以ms为单位
	destroyAllWindows();//销毁所有窗口
	return 0;
}