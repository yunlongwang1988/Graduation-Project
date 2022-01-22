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




