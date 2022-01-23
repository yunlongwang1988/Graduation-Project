#pragma once
#include<opencv2/opencv.hpp>//引入opencv库函数

using namespace cv;//引入名称空间

class quickdemo//定义一个新的类
{
public://定义全局方法
	void color_Space_Convert(Mat & image);//定义一个色彩转换的方法
	void mat_creation();//定义一个图像矩阵方法,括号里面为需要传入的参数，也可以没有
	void pixel_visit_demo_array(Mat & image);//Lesson 5：像素读写操作(使用数组)
	void pixel_visit_demo_pointer(Mat & image);//Lesson 5:像素读写操作(使用指针)
	void operators_demo(Mat & image);//Lesson 6:像素算术操作
};