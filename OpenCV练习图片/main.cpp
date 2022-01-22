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
	
	//namedWindow("显示图片", WINDOW_FREERATIO);
	//imshow("显示图片", src);//显示第一张原色图片
	
	//quickdemo qk;//将头文件中定义的类进行实例化,命名为qk，使用qk.方法引用其色彩转换和图片保存方法
	//qk.color_Space_Convert(src);//引用方法，显示灰度和hsc图像并保存，所以马上将要显示三张图片并保存两种图片在F盘
	
	//这是第二个将类实例化
	quickdemo qk2;
	qk2.mat_creation();

	waitKey(0);//等待，以ms为单位
	destroyAllWindows();//销毁所有窗口
	return 0;

}