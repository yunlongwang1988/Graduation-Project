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
}
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
		applyColorMap(image, dst, colormap[index%19]);
		index++;
		imshow("不断色彩转换", dst);
	}
}

void quickdemo::bitwise_demo(Mat & image)
{
	//画矩形操作
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100,80,80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);
	imshow("m1",m1);
	imshow("m2", m2);


	//and
	Mat dst;
	bitwise_and(m1,m2,dst);
	imshow("and", dst);

	//or
	bitwise_or(m1, m2, dst);
	imshow("or", dst);

	//not
	bitwise_not(image,dst);
	imshow("not", dst);

	//xor
	bitwise_xor(m1, m2, dst);
	imshow("xor", dst);
}

void quickdemo::channels_demo(Mat & image)
{
		//split通道分离
	std::vector<Mat>mv;//创建一个容器
	split(image, mv);//分离通道
//	imshow("通道分离0", mv[0]);
//	imshow("通道分离1", mv[1]);
//	imshow("通道分离2", mv[2]);

		//merge通道合并
	Mat dst;
	mv[0] = 128;
	mv[1] = 50;
	merge(mv,dst);
//	imshow("通道合并",dst);
	
		//通道混合
	int from_to[] = {0,2,1,1,2,0};
	mixChannels(&image, 1, &dst, 1, from_to, 3);
	imshow("通道混合",dst);
}
void quickdemo::inrange_demo(Mat & image)
{
	//色彩空间转换
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//过滤
	Mat masker;
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), masker);//过滤掉HSV图像中的某个通道，最大值最小值
	//将提取的轮廓取反，粘贴到另一张图片上
	Mat redback = Mat::zeros(image.size(),image.type());//放置人的轮廓
	redback = Scalar(40, 40, 200);
	imshow("提取的人像", masker);
	bitwise_not(masker,masker);//对提取的轮廓取反
	imshow("绿色背景原图",image);
	imshow("对提取的人像取反",masker);
	image.copyTo(redback, masker);
	imshow("ROI区域提取",redback);
}
void quickdemo::pixel_stata_demo(Mat & image)
{
	double mixv, maxv;//定义像素的最大值和最小值
	Point minLoc, maxLoc;//定义像素的最大最小值位置
	std::vector<Mat>mv;//定义一个容器，分离通道，因为只有单通道才能统计
	split(image, mv);
	for (int i = 0; i < mv.size(); i++)
	{
		minMaxLoc(mv[i], &mixv, &maxv, &minLoc, &maxLoc, Mat());
		std::cout << "通道：" << i <<std:: endl;
		std::cout << "mixv:" << mixv << "maxv:" << maxv << std::endl;
	}
	Mat mean, stddev;//定义均值和方差
	meanStdDev(image,mean,stddev);
	std::cout << "均值：" << mean << std::endl;
	std::cout << "方差：" << stddev << std::endl;
}
void quickdemo::drawing_demo(Mat & image)
{
	//绘制矩形
	Rect r;
	r.x = 100;
	r.y = 150;
	r.width = 100;
	r.height = 100;
	Mat dst = Mat::zeros(image.size(),image.type());
	rectangle(image,r,Scalar(255,0,255),2,8,0);

	//绘制圆
	circle(image, Point(200, 25), 50, Scalar(0, 255, 200), 2, 8, 0);

	//绘制直线
	line(image, Point(20, 50), Point(100, 200), Scalar(30, 25, 60), 2, 8, 0);

	//绘制椭圆
	RotatedRect e;
	e.center = Point(60,50);
	e.size = Size(20, 60);
	e.angle = 90;
	ellipse(image, e, Scalar(46, 97, 255), 2, 8);

	//合并两张图像
	Mat dst2;
	addWeighted(image, 0.7, dst, 0.3, 0, dst2);
	imshow("几何图形",dst2);
}
void quickdemo::randow_demo()
{
	Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
	int w = canvas.cols;
	int h = canvas.rows;
	RNG rng(12345);
	while (true)
	{
		int c = waitKey(10);
		if (c == 27)
		{
			break;
		}
		int x1 = rng.uniform(0, w);
		int y1 = rng.uniform(0, h);
		int x2 = rng.uniform(0, w);
		int y2 = rng.uniform(0, h);
		int b = rng.uniform(0, 255);
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);
		line(canvas, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 1, LINE_AA, 0);
		imshow("随机绘图演示",canvas);
	}
}
void quickdemo::polygon_demo()
{
	Mat canvas = Mat::zeros(Size(512,512),CV_8UC3);
	Point p1(100, 100);
	Point p2(350, 100);
	Point p3(450, 280);
	Point p4(320, 450);
	Point p5(80, 400);
	std::vector<Point>pts;
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);
//	polylines(canvas, pts, true, Scalar(0, 0, 255), 2, 8, 0);//普通绘制多边形的命令
	std::vector<std::vector<Point>>contours;//也是创建一个点集
	contours.push_back(pts);
	drawContours(canvas, contours, -1, Scalar(255, 0, 255), 2);
	//fillPoly(canvas,pts,Scalar(255,0,255),8,0);//多边形填充命令
	imshow("多边形绘制",canvas);
}
void quickdemo::type_convert(Mat & image)
{
	Mat dst;
	std::cout << "原始像素类型：" << image.type() << std::endl;//没有转化之前的数据类型
	image.convertTo(image, CV_32F);//转化为浮点类型
	std::cout << "转化之后像素类型：" << image.type() << std::endl;//转化之后的像素类型
	normalize(image, dst, 1, 0, NORM_MINMAX);
	std::cout << "归一化后的像素类型：" << dst.type() << std::endl;//归一化后的像素类型
	imshow("归一化图像",dst);

}
void quickdemo::interpolation_demo(Mat & image)
{
	Mat large, small;
	int w = image.cols;
	int h = image.rows;
	resize(image, large, Size(w*1.5, h*1.5), 0, 0, INTER_LINEAR);//放大
	imshow("放大",large);
	resize(image, small, Size(w/1.5, h/1.5), 0, 0, INTER_LINEAR);//缩小
	imshow("缩小", small);
}
void quickdemo::flip_demo(Mat & image)
{
	Mat dst;
	flip(image, dst, 0);//上下翻转
	imshow("上下翻转",dst);
	flip(image, dst, 1);//左右翻转
	imshow("左右翻转", dst);
	flip(image, dst, -1);//对角线
	imshow("对角线翻转", dst);
}
void quickdemo::rotate_demo(Mat & image)
{
	Mat dst, M;
	int w = image.cols;
	int h = image.rows;
	M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);//第一个参数位图像中心，第二个为旋转角度，第三个为缩放系数
	double cos = abs(M.at<double>(0, 0));//M矩阵的一行一列元素
	double sin = abs(M.at<double>(0, 1));//M矩阵的一行二列元素
	double nw = cos * w + sin * h;//新图像的宽
	double nh = sin * w + cos * h;//新图像的高
	M.at<double>(0, 2) += (nw / 2 - w / 2);
	M.at<double>(1, 2) += (nh / 2 - h / 2);
	warpAffine(image, dst, M, Size(nw, nh), INTER_LINEAR, 0, Scalar(255, 0, 0));
	imshow("旋转展示",dst);
}
void quickdemo::video_demo(Mat & image)
{
	VideoCapture capture(0);//为0则表示调用摄像头
	Mat frame;
	while (true)
	{
		capture.read(frame);
		if (frame.empty())//没有读取到图像，退出
		{
			break;
		}
		int c = waitKey(10);//等待键盘输入
		if (c == 27)//如果有ESC键按下，则退出
		{
			break;
		}
		imshow("摄像头", frame);//循环显示图像
	}
	capture.release();//释放摄像头占用资源
}

void quickdemo::video_write_demo(Mat & image)
{
	VideoCapture capture("F:/opencv_Envir/exercise/GitLab.mp4");//为0则表示调用摄像头
	int w = capture.get(CAP_PROP_FRAME_WIDTH);
	int h = capture.get(CAP_PROP_FRAME_HEIGHT);
	int count = capture.get(CAP_PROP_FRAME_COUNT);
	double fps = capture.get(CAP_PROP_FPS);
	std::cout << "width:" << w << std::endl;
	std::cout << "height:" << h << std::endl;
	std::cout << "count:" << count << std::endl;
	std::cout << "fps:" << fps << std::endl;
	VideoWriter writer("F:/opencv_Envir/exercise/test.mp4", capture.get(CAP_PROP_FOURCC), fps, Size(w, h), true);
	Mat frame;
	while (true)
	{
		capture.read(frame);
		if (frame.empty())//没有读取到图像，退出
		{
			break;
		}
		int c = waitKey(10);//等待键盘输入
		if (c == 27)//如果有ESC键按下，则退出
		{
			break;
		}
		imshow("摄像头", frame);//循环显示图像
	}
	capture.release();//释放摄像头占用资源
	writer.release();
}
void quickdemo::histogram_demo(Mat & image)
{
	//三通道分离
	std::vector<Mat>bgr_plane;
	split(image, bgr_plane);
	//定义参数变量
	const int channels[1] = { 0 };
	const int bins[1] = { 256 };
	float hranges[2] = { 0,255 };
	const float* ranges[1] = {hranges};
	Mat b_hist;
	Mat g_hist;
	Mat r_hist;
	//计算BGR通道的直方图
	calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w/bins[0]);
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	//归一化数据
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//绘制直方图曲线
	for (int i = 1; i < bins[0]; i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),Point(bin_w*(i),hist_h-cvRound(b_hist.at<float>(i))),Scalar(255,0,0),2,8,0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
	}
	namedWindow("Hisogram", WINDOW_AUTOSIZE);
	imshow("Hisogram",histImage);
}
void quickdemo::histogram_2d_demo(Mat & image)
{
	Mat hsv, hs_hist;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	int hbins = 30, sbins = 32;
	int hist_bins[] = {hbins,sbins};
	float h_range[] = { 0,180 };
	float s_range[] = { 0,256 };
	const float* hs_range[] = { h_range,s_range };
	int hs_channels[] = { 0,1 };
	calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_range, true, false);
	double maxVal = 0;
	minMaxLoc(hs_hist, 0, &maxVal, 0, 0);
	int scale = 10;
	Mat hist2d_image = Mat::zeros(sbins*scale, hbins*scale, CV_8UC3);
	for (int h = 0; h < hbins; h++)
	{
		
		for (int s = 0; s < sbins; s++)
		{
			float binVal = hs_hist.at<float>(h, s);
			int intensity = cvRound(binVal * 255 / maxVal);
			rectangle(hist2d_image, Point(h*scale, s*scale), Point((h + 1)*scale - 1, (s + 1)*scale - 1), Scalar::all(intensity), -1);
		}
	}
	applyColorMap(hist2d_image, hist2d_image, COLORMAP_JET);
	imshow("H-S histogram",hist2d_image);
}
void quickdemo::equalize_demo(Mat & image)
{
	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("灰度图像", gray);
	Mat dst;
	equalizeHist(gray, dst);
	imshow("直方图均衡化",dst);
}
void quickdemo::blur_demo(Mat & image)
{
	Mat dst;
	blur(image, dst, Size(10, 10), Point(-1, -1));
	imshow("原图", image);
	imshow("图像模糊",dst);
}
void quickdemo::gaussian_demo(Mat & image)
{
	Mat dst;
	GaussianBlur(image, dst, Size(15, 15), 10);
	imshow("原图", image);
	imshow("高斯模糊", dst);
}
void quickdemo::bi_gaussian_demo(Mat & image)
{
	Mat dst;
	bilateralFilter(image, dst, 0,100,10);
	imshow("原图", image);
	imshow("高斯模糊", dst);
}