# Lesson1:环境配置与搭建
- 完成VS2017的安装
- 完成OpenCV的安装
- 完成环境的搭建

# Lesson2:图片的读取和显示
## 代码解释
- 引入opencv包：

	```cpp
	#include<opencv2\opencv.hpp>
	#include<iostream>
	```

- 读取的图片是以矩阵`Mat`形式保存的

	```cpp
	Mat src = imread("C:/Users/12396/Desktop/Picture/OpenCV/face2.jpg");
	```
 - `imshow("input",src)`，，`input`是窗口名字，可以为任意名称，`src`是要读取的对象
 - `waitKey(0)`表示等待时间，以ms为计时单位，人眼低于三百ms无法分辨
 - `destroyAllWindows()`表示销毁以前的所有窗口
 - 当图片过大无法调整时，我们要新建一个可以任意调整的窗口：	



	
	```cpp
	namedWindow("你的窗口名称"，WINDOW_FREERATIO)；
	imshow("你的窗口名称"，读取对象)
	```
	![在这里插入图片描述](https://img-blog.csdnimg.cn/f6a058ee47b8414e92dad658c7a3a016.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_19,color_FFFFFF,t_70,g_se,x_16)



- 加载一张灰度图像：

	
	```cpp
	Mat src = imread("图片路径"，IMREAD_GRAYSCALE);`
	```	
	![在这里插入图片描述](https://img-blog.csdnimg.cn/1140fde3e4a74a0186b2f48714cadb07.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_19,color_FFFFFF,t_70,g_se,x_16)
- 使用`src.empty()`来检查是否读取到了图片

	```cpp
	if (src.empty())
	{
		printf("Image is not load....\n");
	}
	else
	{
		printf("Image load successfully!");
	}	
	```

	![在这里插入图片描述](https://img-blog.csdnimg.cn/dcf7fe414a454cf3aac7597bf3062d66.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 完整代码

```cpp
#include<opencv2\opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/12396/Desktop/Picture/OpenCV/face2.jpg",IMREAD_GRAYSCALE);
	if (src.empty())
	{
		printf("Image is not load....\n");
	}
	else
	{
		printf("Image load successfully!");
	}
	namedWindow("显示图片", WINDOW_FREERATIO);
	imshow("显示图片", src);
	waitKey(0);
	destroyAllWindows();
	return 0;

}
```





# Lesson 3:图片色彩转换与保存
## 预备知识
- 色彩空间转换函数：`cvColor`
	-  COLOR_BGR2GRAY = 6：彩色到灰度
	- COLOR_GRAY2BGR = 8：灰度到彩色
	- COLOR_BGR2HSV = 40：BGR到HSV
	- COLOR_HSV2BGR = 54：HSV到BGR

- 图像保存：`imwrite`(第一个参数，第二个参数)
	- 第一个参数是保存路径：有时候要用双斜杠
	- 第二个参数是保存对象




## 新建一个头文件：
![在这里插入图片描述](https://img-blog.csdnimg.cn/f2319dbce3434f1490d24e08bd7a759e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_11,color_FFFFFF,t_70,g_se,x_16)
在头文件中定义名称空间、类、方法：
```cpp
#pragma once
#include<opencv2/opencv.hpp>

using namespace cv;

class quickdemo 
{
public:
	void color_Space_Convert(Mat & image);
};

```

## 新建一个cpp文件编写新的方法
在新建的`.cpp`文件中编写图像色彩转换、图片保存的方法，最后在`main.cpp`中将其实例化调用

![在这里插入图片描述](https://img-blog.csdnimg.cn/7940dd9167a64ee4b12b30e096e24691.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_10,color_FFFFFF,t_70,g_se,x_16)
在新建的`.cpp`文件中，我们想要引用刚才新建的头文件，但是发现没有找到路径：
![在这里插入图片描述](https://img-blog.csdnimg.cn/e45bcc17b690448b967281f98996333b.png)
在解决方案中包含路径，右击解决方案，点击属性：
![在这里插入图片描述](https://img-blog.csdnimg.cn/86ed1c48b8ab40b3972d43cb3ad79eb9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_19,color_FFFFFF,t_70,g_se,x_16)

![在这里插入图片描述](https://img-blog.csdnimg.cn/8df5cf140f9f4f2992917ebcda4926ff.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)

用双引号加入解压后课件的路径即可：
![在这里插入图片描述](https://img-blog.csdnimg.cn/80f4a4ff50ef4553bb7a4c37a9df3e79.png)

- 需要注意的是路径要加双斜杠，其一定要在路径的最后加上将要保存图片的名称，我这里将其保存为`hsv.png`
	```cpp
	imwrite("F://opencv_Envir//opencv//hsv.png",hsv);
	```
- 如果去掉`hsv.png`，将会报错，且内存溢出：
	```cpp
	imwrite("F://opencv_Envir//opencv",hsv);
	```
	![在这里插入图片描述](https://img-blog.csdnimg.cn/51786e5a45be4fdd833acef7fa213e78.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)


- 错误信息：

	0x00007FFEFF9B4F69 处(位于 opencv.exe 中)有未经处理的异常: Microsoft C++ 异常: cv::Exception，位于内存位置 0x0000005C97EFF2D0 处。


- 正确的代码：

	```cpp
	#include "quickopencvdemo.h"
	
	void quickdemo::color_Space_Convert(Mat & image)
	{
		Mat gray, hsv;
		cvtColor(image, hsv, COLOR_BGR2HSV);
		cvtColor(image, gray, COLOR_BGR2GRAY);
		imshow("HSV", hsv);
		imshow("Gray",gray);
		imwrite("F://opencv_Envir//opencv//hsv.png",hsv);
		imwrite("F://opencv_Envir//opencv//gray.png", gray);
	}
	
	```

## main.cpp显示三张图片并保存

```cpp
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
		printf("Image load successfully!");
	}
	namedWindow("显示图片", WINDOW_FREERATIO);
	imshow("显示图片", src);//显示第一张原色图片
	quickdemo qk;//将头文件中定义的类进行实例化,命名为qk，使用qk.方法引用其色彩转换和图片保存方法
	qk.color_Space_Convert(src);//引用方法，显示灰度和hsc图像并保存，所以马上将要显示三张图片并保存两种图片在F盘
	waitKey(0);
	destroyAllWindows();
	return 0;

}
```
最后我们在指定盘下面找到了保存的两张图片：灰度和HSV的
![在这里插入图片描述](https://img-blog.csdnimg.cn/50b58211205146b7a72bb712e06f4696.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)


## 注意事项
- `imread`读取的图像是八位
- `imshow`只能显示八位
- R、G、B三个通道各是八位，还有一个透明通道也是八位
- R、G、B三个通道三位读取的顺序是B、G、R
- H（0-180）、S（0-255）、V（0-255）：分别表示色相、饱和度、亮度





# Lesson 4 :图像对象的创建与赋值
## 上节回顾
- 在创建的头文件中引入opencv库，引入名称空间，定义public方法


	```cpp
	#pragma once
	#include<opencv2/opencv.hpp>//引入opencv库函数
	
	using namespace cv;//引入名称空间
	
	class quickdemo//定义一个新的类
	{
	public://定义全局方法
		void color_Space_Convert(Mat & image);//定义一个色彩转换的方法
		void mat_creation(Mat & image);//定义一个图像矩阵方法
	};
	```
- 在新建的.cpp文件对头文件中定义的类实例化，并编写方法以便于main.cpp引用。



## Mat基本结构
![在这里插入图片描述](https://img-blog.csdnimg.cn/c5ad75c0386a45328597688ce12d482a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_17,color_FFFFFF,t_70,g_se,x_16#pic_center)






## 克隆(clone)、复制(copy)、赋值(=)


- 赋值(=)：其中一个改变时，另外一个也改变


	```cpp
	m3 = Scalar(0,0,255);
	Mat m4 = m3;//赋值，其中一个改变，另一个也改变
	m4 = Scalar(255, 0, 0);
	imshow("m3", m3);
	imshow("m4", m4);
	```



	![在这里插入图片描述](https://img-blog.csdnimg.cn/5287916c818442c589c69a55164ab3d5.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)


- 克隆(clone)：对克隆后的值修改不会影响原来的值


	```cpp
	Mat m4 = m3.clone();
	m4 = Scalar(246, 0, 255);
	imshow("m3",m3);
	imshow("m4", m4);
	```
	![在这里插入图片描述](https://img-blog.csdnimg.cn/011540f94b234fa7b48a0b1d4e7b9403.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)

- 复制copy：对复制后的值修改不影响原来的值


	```cpp
	Mat m4;
	m3.copyTo(m4);
	m4 = Scalar(65, 255, 90);
	imshow("m3",m3);
	imshow("m4", m4);
	```
	![在这里插入图片描述](https://img-blog.csdnimg.cn/0ea5b5a4cd3c4d899fbf7d433debbb81.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)



## 创建空白图像

- 先创建变量：

	```cpp
	Mat m3 = Mat::zeros(Size(8,8),CV_8UC1)；
	```
	- Mat::zeros()表示创建全是0的矩阵
	- Size(8,8)表示矩阵大小
	- CV_8UC1中的8表示8位，UC表示无符号，1表示单个通道，也可以为三个

- 方法中可以没有需要传入的参数：

	```cpp
	void mat_creation(不传入参数);//定义一个图像矩阵方法,括号里面为需要传入的参数，也可以没有
	```

- 接着在`main.cpp`中实例化第二个类：

	```cpp
	quickdemo qk2;
	```

- 调用方法
在main.cpp中调用该方法，此时没有传入图片作为参数
	```cpp
	qk2.mat_creation();
	```

- 如果想要传入图片作为参数，要重新定义方法：要在头文件，方法文件，main.cpp都更改为

	```cpp
	mat_creation(Mat & image);
	```


- 打印输出：

	```cpp
	std::cout<<......<<std::endl;
	```
- 图像宽度:

	```cpp
	m3.width;
	```
- 图像高度：

	```cpp
	m3.height;
	```

- 图像通道数：此时要加括号

	```cpp
	m3.channels();
	```

- 打印一个通道：

	```cpp
	Mat m3 = Mat::zeros(Size(8, 8), CV_8UC1);//CV_8UC1表示8位，U表示无符号，1表示一个通道
	```
	![在这里插入图片描述](https://img-blog.csdnimg.cn/3b65ac9507384f86b69c6e97c5b0da91.png)


- 打印三个通道：将其改为`CV_8UC3`即可

	![在这里插入图片描述](https://img-blog.csdnimg.cn/8eb55ba1c2a64f58b7c71525d54f0c71.png)

- 第一个通道赋值为127：
	```cpp
	m3 = 127;//设置一个第一个通道为127
	```
	![在这里插入图片描述](https://img-blog.csdnimg.cn/cca04bc2fcbc435ea5f4d975936789dc.png)

- 使用`scalar()`函数将三个通道都赋值：此时显示红色，因为通道数显示顺序为B、G、R


	```cpp
	namedWindow("通道检验", WINDOW_FREERATIO);
	imshow("通道检验", m3);
	```



	![在这里插入图片描述](https://img-blog.csdnimg.cn/cb3b371a1aa2409183207b41ed3ade09.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/e971768c177c4b59bfb470495cda6fd7.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_15,color_FFFFFF,t_70,g_se,x_16)



# Lesson 5 :图像像素的读写操作

## 文件创建
- 在头文件中新定义一个全局方法：

	```cpp
	void pixel_visit_demo(Mat & image);
	```
- 在`quickdemo.cpp`中编写该方法

	```cpp
	void quickdemo::pixel_visit_demo(Mat & image)
	{
	
	}
	```
- 在`main.cpp`中创建一个实例化的类，引用该方法

	```cpp
	quickdemo qk3;
	qk3.pixel_visit_demo(Mat & image);
	```



## 基本知识
- 可以调整的窗口
	```cpp
	namedWindow("使用数组修改像素值", WINDOW_FREERATIO);
	```

- 获取图像像素的宽

	```cpp
	int w = image.cols;
	```

- 获取图像像素的高

	```cpp
	int h = image.rows;
	```

- 获取图像的通道数

	```cpp
	int c = image.channels();
	```
- 灰度图像通道数为1，像素的数据类型为`uchar`，将其转化成`int`类型
	```cpp
	int pv = image.at<uchar>(row,col);
	```

- 彩色图像通道数为3，像素的数据类型为`Vec3b`

	```cpp
	Vec3b bgr = image.at<Vec3b>(row,col);
	```



## 数组遍历
- 假如为灰度图像，通道数为1，则获取像素值后直接修改即可
	```cpp
	int pv = image.at<uchar>(row,col);
	image.at<uchar>(row,col) = 255 - pv;
	```


- 假如图像为彩色图像，要用数组对每个通道的值进行修改
	```cpp
	Vec3b bgr = image.at<Vec3b>(row,col);
	image.at<Vec3b>(row,col)[0] = 255 - bgr[0];
	image.at<Vec3b>(row,col)[1] = 255 - bgr[1];
	image.at<Vec3b>(row,col)[2] = 255 - bgr[2];
	```
- 头文件
	```cpp
	void pixel_visit_demo_array(Mat & image);//Lesson 5：像素读写操作(使用数组)
	```
- `quickdemo.cpp`
	```cpp
	//Lesson 5:像素读写操作（使用数组）
	void quickdemo::pixel_visit_demo_array(Mat & image)
	{
		int w = image.cols;//获取图像的宽
		int h = image.rows;//获取图像的高
		int c = image.channels();//获取图像的通道数
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
		imshow("使用数组修改像素值", image);//显示用数组修改后的图片
	}
	```

- `main.cpp`

	```cpp
	//Lesson 5:图像像素的操作（指针或者数组）
		quickdemo qk3;//将类实例化
		qk3.pixel_visit_demo_array(src);//引用方法并传入读取的照片
	```


- 原图：
		![在这里插入图片描述](https://img-blog.csdnimg.cn/176d1d4c87964e44b6718442c22cf4ba.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
- 数组遍历修改

	![在这里插入图片描述](https://img-blog.csdnimg.cn/b30152b9ebef460b922150c1e43286ce.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)




## 指针方式遍历


- 定义一个指针`uchar`类型，先遍历行再遍历列，挨个移动

- 头文件中定义新的方法

	```cpp
	void pixel_visit_demo_pointer(Mat & image);//Lesson 5:像素读写操作(使用指针)
	```

- `quickdemo.cpp`中编写该方法
	
	```cpp
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
	```

- `main.cpp`中引用
	```cpp
	//Lesson 5:图像像素的操作（指针或者数组）
		quickdemo qk3;//将类实例化
		qk3.pixel_visit_demo_array(src);//引用方法并传入读取的照片
	```




# Lesson 6:图像像素的算术操作


## 注意
- 对两张图片进行算术运算要保证大小和类型相同

	```cpp
	Mat dst;
	Mat m = Mat::zeros(image.size(), image.type());
	```
- `saturate_cast<数据类型>(判断内容)`：用来判断有没有溢出，超过则为范围的最大值，类似饱和函数


## 加法
- 简单的加法-----使用标量函数

	```cpp
	Mat dst;
	dst = image + Scalar(50, 50, 50);
	imshow("原图", image);
	imshow("简单加法",dst);
	```


- 使用加法函数`add`

 	- `add(输入1，输入2，输出)`



		```cpp
		//加法，使用add函数
		Mat dst;
		Mat m = Mat::zeros(image.size(), image.type());
		m = Scalar(20, 200, 200);
		add(image, m, dst);
		imshow("原图", image);
		imshow("乘法",dst);
		```


	- 原图
		![在这里插入图片描述](https://img-blog.csdnimg.cn/d4a036125b5f45cb838aa7157678857a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)





	- 加后的图
		![在这里插入图片描述](https://img-blog.csdnimg.cn/e0137487ec0a4073bb9757516caa75bd.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)







- **加法原理**

	- 像素值分通道相加

		```cpp
		//加法原理
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
		```

	 - 效果		![在这里插入图片描述](https://img-blog.csdnimg.cn/d4a036125b5f45cb838aa7157678857a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
		![在这里插入图片描述](https://img-blog.csdnimg.cn/8fd9d4904d9e4f18806355d34cbcb2ea.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)






## 减法

- 简单的减法----使用标量函数

	```cpp
	//减法，使用标量函数
	Mat dst;
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(100, 100, 100);
	dst = image - m;
	imshow("原图", image);
	imshow("乘法",dst);
	```


- 使用`subtract`函数

	 - `subtract(输入1，输入2，输出)`

		```cpp
			//减法，使用库函数
			Mat dst;
			Mat m = Mat::zeros(image.size(), image.type());
			m = Scalar(100, 100, 100);
			subtract(image, m, dst);
			imshow("原图", image);
			imshow("乘法",dst);
		```



	- 原图		![在这里插入图片描述](https://img-blog.csdnimg.cn/7a7356df1a6e4f348e0e068c24caf3d6.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
	- 减后的图
	![在这里插入图片描述](https://img-blog.csdnimg.cn/a620ad09a106402eae31ece63241e628.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)




## 乘法
- 简单的乘法(容易报错)----使用标量函数：要注意`A(m,n)`必须要乘以`B(n,m)`
- 使用`multiply`函数

	```cpp
	Mat dst;//创建一个图像
	Mat m = Mat::zeros(image.size(),image.type());//像素初值赋为0
	m = Scalar(2,2,2);//使用标量函数赋值为2
	multiply(image,m,dst);//输入的image和m相乘输出到dst中
	```
- 原图
	![在这里插入图片描述](https://img-blog.csdnimg.cn/7a7356df1a6e4f348e0e068c24caf3d6.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
- 乘后的图
	![在这里插入图片描述](https://img-blog.csdnimg.cn/aa26676ca818424b8415362fd09cc24a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)

## 除法

- 简单的除法----使用标量函数

	```cpp
	//除法，使用标量函数
	Mat dst;
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(20, 200, 2);
	dst = image/m;
	imshow("原图", image);
	imshow("乘法",dst);
	```


- 使用`divide`函数
	- `divide(输入1，输入2，输出)`


		```cpp
		//除法，使用divide函数
		Mat dst;
		Mat m = Mat::zeros(image.size(), image.type());
		m = Scalar(20, 200, 2);
		divide(image, m, dst);
		imshow("原图", image);
		imshow("乘法",dst);
		```


	- 原图
		![在这里插入图片描述](https://img-blog.csdnimg.cn/7a7356df1a6e4f348e0e068c24caf3d6.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)


	- 除后的图
![在这里插入图片描述](https://img-blog.csdnimg.cn/eeb4345857994e77a595fe36cdac0485.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)


# Lesson 7:一个调节亮度的滚动条

## 头文件

```cpp
void tracking_bar_demo(Mat & image);//Lesson 7:调节亮度的滚动条
```

## quickdemo.cpp

- 需要注意的是这里的变量是全局的




	```cpp
	Mat src, dst, m;
	int lightness = 50;
	static void on_track(int , void*)
	{
		m = Scalar(lightness, lightness, lightness);
		add(src, m, dst);
		imshow("亮度调整",dst);
	}
	void quickdemo::tracking_bar_demo(Mat & image)
	{
	
		namedWindow("调整亮度",WINDOW_AUTOSIZE);
		dst = Mat::zeros(image.size(), image.type());
		m = Mat::zeros(image.size(), image.type());
		src = image;
		int max_value = 100;
	
		createTrackbar("Value Bar", "调整亮度", &lightness, max_value, on_track);
	}
	```


## main.cpp中创建实例并调用




```cpp
//Lesson 7:滚动条调整亮度
	quickdemo qk5;
	qk5.tracking_bar_demo(src);
```

## 效果


![在这里插入图片描述](https://img-blog.csdnimg.cn/00082f8d16144ab9b86a89761066ebc7.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/1061b45542194a59b41408a2a8fce299.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
# Lesson 8:传递参数创建滚动条

```cpp
static void on_lightness(int b, void* userdata)
{
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	addWeighted(image, 1.0, m, 0, b, dst);
	imshow("亮度与对比度",dst);
}
static void on_contrast(int b, void* userdata)
{
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	addWeighted(image,contrast,m,0.0,b,dst);
	imshow("亮度与对比度", dst);
}
void quickdemo::tracking_bar_demo(Mat & image)
{

	namedWindow("调整亮度",WINDOW_AUTOSIZE);
	int lightness = 50;
	int max_value = 100;
	int contrast_value = 100;
	createTrackbar("Value Bar", "调整亮度与对比度", &lightness, max_value, on_lightness,(&image));
	createTrackbar("Contrast Bar", "调整亮度与对比度", &contrast_value, 200, on_contrast,(&image));
	on_lightness(50, &image);
}
```



# Lesson 8：键盘响应

## 原理说明
- 按1输出灰度值


	![在这里插入图片描述](https://img-blog.csdnimg.cn/2bb82caa1c344863a0f8a44733badf6f.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/b802c09a25324c3c8952d47d89ab5be0.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)





- 按2输出HSV图像
	
	![在这里插入图片描述](https://img-blog.csdnimg.cn/2febdf03c8c9417c9d789171322aee68.png)
	![在这里插入图片描述](https://img-blog.csdnimg.cn/72e073c7f83e4d2b97fe7cccbee0c81a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
- 按3像素相加


	![在这里插入图片描述](https://img-blog.csdnimg.cn/d87578ba565940f1937a0697e04fb13f.png)
	![在这里插入图片描述](https://img-blog.csdnimg.cn/bc76d79dc2564c788a20f7342dcdb277.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
- 按`ESC`退出

	![在这里插入图片描述](https://img-blog.csdnimg.cn/b1ea7fbfefa54e3b84468dddbdf535d4.png)

## 代码

- 等待键盘输入：`waitKey(时间)`，以`ms`为单位
- 输入转化为`ASCII`码保存
- 通过判断数字及字母对应的`ASCII`码来执行相应的程序


```cpp
void quickdemo::key_demo(Mat & image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	imshow("原图",image);
	while (true)
	{
		int c = waitKey(100);//等待键盘输入转化成ASCII码
		if (c == 27)
		{
			std::cout << "退出循环" << std::endl;
			break;//ESC键，退出循环
		}
		if (c == 49)//对应键盘值1
		{
			std::cout << "输入的是1" << std::endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);//转为灰度图像
		}
		if (c == 50)//对应键盘值2
		{
			std::cout << "输入的是2" << std::endl;
			cvtColor(image, dst, COLOR_BGR2HSV);//转为HSV图像
		}
		if (c == 51)//对应键盘值3
		{
			std::cout << "输入的是3" << std::endl;
			dst = Scalar(50,50,50);
			add(image, dst,dst);//图片相加
		}
		imshow("键盘显示", dst);
	}
```


# Lesson 9：颜色表



## 颜色表数组：



```cpp
int colormap[] = 
{
		COLORMAP_AUTUMN,
		COLORMAP_BONE,
		COLORMAP_JET,
		COLORMAP_WINTER,
		COLORMAP_RAINBOW,
		COLORMAP_OCEAN,
		COLORMAP_SUMMER,
		COLORMAP_SPRING,
		COLORMAP_COOL,
		COLORMAP_PINK,
		COLORMAP_HOT,
		COLORMAP_PARULA,
		COLORMAP_MAGMA,
		COLORMAP_INFERNO,
		COLORMAP_PLASMA,
		COLORMAP_VIRIDIS,
		COLORMAP_CIVIDIS,
		COLORMAP_TWILIGHT,
		COLORMAP_TWILIGHT_SHIFTED
};
```


## quickdemo.cpp


- index++不断进行转换


	```cpp
	applyColorMap(image, dst, colormap[index]);	
	index++;
	```


- 但色彩数组里面只有18个数据，index不能一直加，与19**取模**可以将其限制在0-18


	```cpp
	applyColorMap(image, dst, colormap[index%19]);
	```

```cpp
void quickdemo::color_table(Mat & image)
{
	int colormap[] = {
		COLORMAP_AUTUMN,
		COLORMAP_BONE,
		COLORMAP_JET,
		COLORMAP_WINTER,
		COLORMAP_RAINBOW,
		COLORMAP_OCEAN,
		COLORMAP_SUMMER,
		COLORMAP_SPRING,
		COLORMAP_COOL,
		COLORMAP_PINK,
		COLORMAP_HOT,
		COLORMAP_PARULA,
		COLORMAP_MAGMA,
		COLORMAP_INFERNO,
		COLORMAP_PLASMA,
		COLORMAP_VIRIDIS,
		COLORMAP_CIVIDIS,
		COLORMAP_TWILIGHT,
		COLORMAP_TWILIGHT_SHIFTED
	};
	Mat dst;
	int index = 0;
	while (true)
	{
		int c = waitKey(200);//等待输入
		if (c == 27)
		{
			break;//ESC退出
		}
		applyColorMap(image, dst, colormap[index]);
		index++;
		imshow("不断色彩转换", dst);
	}
}
```


## 效果：色彩不断变换
![在这里插入图片描述](https://img-blog.csdnimg.cn/14f1efa089df47e1b58b50b8afa5b128.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)





![在这里插入图片描述](https://img-blog.csdnimg.cn/38fae63aebb74ff691563573198c0f33.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/7ad902ba373348d3a5d81af88d4399d1.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/72baade4af83440c97f36741191e83c5.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATXIuWXVuTG9uZw==,size_20,color_FFFFFF,t_70,g_se,x_16)

