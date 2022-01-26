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
	void tracking_bar_demo(Mat & image);//Lesson 7:调节亮度的滚动条
	void key_demo(Mat & image);//Lesson 8:键盘响应
	void color_table(Mat & image);//Lesson 9:颜色表转换
	void bitwise_demo(Mat & image);//Lesson 10:位操作
	void channels_demo(Mat & image);//Lesson 11:通道分离与混合
	void inrange_demo(Mat & image);//Lesson 12:图像色彩空间转换
	void pixel_stata_demo(Mat & image);//Lesson 13:图像像素统计：最大值最小值，均值，方差
	void drawing_demo(Mat & image);//Lesson 14：几何形状的绘制
	void randow_demo();//Lesson 15:随机图形绘制
	void polygon_demo();//Lesson 16:多边形的绘制和填充
	void type_convert(Mat & image);//Lesson 17:图像像素类型转化与归一化
	void interpolation_demo(Mat & image);//Lesson 18:图像放缩与插值
	void flip_demo(Mat & image);//Lesson 19:图像翻转
	void rotate_demo(Mat & image);//Lesson 20:图像旋转
	void video_demo(Mat & image);//Lesson 21:摄像头与视频文件的读取
	void video_write_demo(Mat & image);//Lesson 22:视频文件的保存
	void histogram_demo(Mat & image);//Lesson 23:图像直方图
	void histogram_2d_demo(Mat & image);//Lesson 24:二维直方图
	void equalize_demo(Mat & image);//Lesson 25:直方图均衡化
	void blur_demo(Mat & image);//Lesson 26:图像卷积
	void gaussian_demo(Mat & image);//Lesson 27:高斯模糊
	void bi_gaussian_demo(Mat & image);//Lesson 28:高斯双边模糊
};

