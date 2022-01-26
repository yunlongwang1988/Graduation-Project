#include "quickopencvdemo.h"//����ͷ�ļ�

//���巽��ǰ�Ƚ���ʵ����
//Lesson 3:ͼƬɫ��ת���뱣��
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

//Lesson 4:ͼ�����Ĵ����븨��
void quickdemo::mat_creation()
{
	/*
	Mat m1, m2;
	m2 = image.clone();//�Բ���image����clone
	image.copyTo(m2);//�Բ���image����copy
	*/
	//�����հ�ͼ��
	Mat m3 = Mat::zeros(Size(512, 512), CV_8UC3);//Size(8,8)��ʾͼ���С��CV_8UC1��ʾ8λ��U��ʾ�޷��ţ�1��ʾһ��ͨ��
	//m3 = 127;//Ĭ������һ����һ��ͨ��Ϊ127
	m3 = Scalar(0,0,255);
	//std::cout << "width= " << m3.cols << "height= " << m3.rows << "channels= " << m3.channels()<<std::endl;
	//std::cout << m3 << std::endl;
	//namedWindow("ͨ������", WINDOW_FREERATIO);
	//imshow("ͨ������", m3);


	//��ֵ������һ���ı䣬��һ��Ҳ�ı�
//	Mat m4 = m3;
//	m4 = Scalar(255, 0, 0);
//	imshow("m3", m3);
//	imshow("m4", m4);

	//��¡clone���Կ�¡���ֵ�޸Ĳ���Ӱ��ԭ����ֵ
//	Mat m4 = m3.clone();
//	m4 = Scalar(246, 0, 255);
//	imshow("m3",m3);
//	imshow("m4", m4);

	//����copy���Ը��ƺ��ֵ�޸Ĳ���ı�ԭ����ֵ
	Mat m4;
	m3.copyTo(m4);
	m4 = Scalar(65, 255, 90);
	imshow("m3",m3);
	imshow("m4", m4);

}


//Lesson 5:���ض�д������ʹ�����飩
void quickdemo::pixel_visit_demo_array(Mat & image)
{
	int w = image.cols;//��ȡͼ��Ŀ�
	int h = image.rows;//��ȡͼ��ĸ�
	int c = image.channels();//��ȡͼ���ͨ����
//	namedWindow("ԭʼͼƬ",WINDOW_FREERATIO);
	imshow("ԭʼͼƬ", image);//��ʾԭʼͼƬ
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (c == 1)//ͨ����Ϊ1,�Ҷ�ͼ��
			{
				int pv = image.at<uchar>(row, col);//��ȡ���ص��ֵ��ת��Ϊint����
				image.at<uchar>(row, col) = 255 - pv;//�Ե�ͨ��������ֵ�����޸�
			}
			if (c == 3)//��ɫͼ��ͨ����Ϊ3
			{
				Vec3b bgr = image.at<Vec3b>(row, col);//bgr��һ������
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
//	namedWindow("ʹ�������޸�����ֵ", WINDOW_FREERATIO);
	imshow("ʹ�������޸�����ֵ", image);//��ʾ�������޸ĺ��ͼƬ
}

//Lesson 5:���ض�д������ʹ��ָ�룩
void quickdemo::pixel_visit_demo_pointer(Mat & image)
{
	int w = image.cols;
	int h = image.rows;
	int c = image.channels();
	for (int row = 0; row < h; row++)
	{
		uchar* current_row = image.ptr<uchar>(row);//����һ��ָ�룬uchar����
		for (int col = 0; col < w; col++)
		{
			if (c == 1)//�Ҷ�ͼ��
			{
				int pv = *current_row;
				*current_row++ = 255 - pv;//���������ƶ�
			}
			if (c == 3)//��ɫͼ��
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
	//�򵥼ӷ�---ʹ�ñ�������
//	Mat dst;
//	dst = image + Scalar(50, 50, 50);
//	imshow("ԭͼ", image);
//	imshow("�򵥼ӷ�",dst);

	//�ӷ���ʹ��add����
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 200);
//	add(image, m, dst);
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);

	//�ӷ�ԭ��
/*
	Mat dst = Mat::zeros(image.size(), image.type());//���ͼ��
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(200, 200, 200);
	int w = image.cols;
	int h = image.rows;
	int c = image.channels();
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			Vec3b p1 = image.at<Vec3b>(row, col);//��ȡ����1������ֵ
			Vec3b p2 = m.at<Vec3b>(row, col);//��ȡm������ֵ
			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
		}
	}
	imshow("ԭͼ", image);
	imshow("�ӷ�ԭ��",dst);

*/


	//������ʹ�ñ�������
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(100, 100, 100);
//	dst = image - m;
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);


	//������ʹ��subtract����
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(100, 100, 100);
//	subtract(image, m, dst);
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);


	//�˷���ʹ��multiply����
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(2, 2, 2);
//	multiply(image, m, dst);
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);


	//������ʹ�ñ�������
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 2);
//	dst = image/m;
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);


	//������ʹ��divide����
//	Mat dst;
//	Mat m = Mat::zeros(image.size(), image.type());
//	m = Scalar(20, 200, 2);
//	divide(image, m, dst);
//	imshow("ԭͼ", image);
//	imshow("�˷�",dst);
}

static void on_lightness(int b, void* userdata)
{
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	addWeighted(image, 1.0, m, 0, b, dst);
	imshow("������Աȶ�",dst);
}
static void on_contrast(int b, void* userdata)
{
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	addWeighted(image,contrast,m,0.0,b,dst);
	imshow("������Աȶ�", dst);
}
void quickdemo::tracking_bar_demo(Mat & image)
{

	namedWindow("��������",WINDOW_AUTOSIZE);
	int lightness = 50;
	int max_value = 100;
	int contrast_value = 100;
	createTrackbar("Value Bar", "����������Աȶ�", &lightness, max_value, on_lightness,(&image));
	createTrackbar("Contrast Bar", "����������Աȶ�", &contrast_value, 200, on_contrast,(&image));
	on_lightness(50, &image);
}

void quickdemo::key_demo(Mat & image)
{
	Mat dst = Mat::zeros(image.size(), image.type());
	imshow("ԭͼ",image);
	while (true)
	{
		int c = waitKey(100);//�ȴ���������ת����ASCII��
		if (c == 27)
		{
			std::cout << "�˳�ѭ��" << std::endl;
			break;//ESC�����˳�ѭ��
		}
		if (c == 49)//��Ӧ����ֵ1
		{
			std::cout << "�������1" << std::endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);//תΪ�Ҷ�ͼ��
		}
		if (c == 50)//��Ӧ����ֵ2
		{
			std::cout << "�������2" << std::endl;
			cvtColor(image, dst, COLOR_BGR2HSV);//תΪHSVͼ��
		}
		if (c == 51)//��Ӧ����ֵ3
		{
			std::cout << "�������3" << std::endl;
			dst = Scalar(50,50,50);
			add(image, dst,dst);//ͼƬ���
		}
		imshow("������ʾ", dst);
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
		int c = waitKey(200);//�ȴ�����
		if (c == 27)
		{
			break;//ESC�˳�
		}
		applyColorMap(image, dst, colormap[index%19]);
		index++;
		imshow("����ɫ��ת��", dst);
	}
}

void quickdemo::bitwise_demo(Mat & image)
{
	//�����β���
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
		//splitͨ������
	std::vector<Mat>mv;//����һ������
	split(image, mv);//����ͨ��
//	imshow("ͨ������0", mv[0]);
//	imshow("ͨ������1", mv[1]);
//	imshow("ͨ������2", mv[2]);

		//mergeͨ���ϲ�
	Mat dst;
	mv[0] = 128;
	mv[1] = 50;
	merge(mv,dst);
//	imshow("ͨ���ϲ�",dst);
	
		//ͨ�����
	int from_to[] = {0,2,1,1,2,0};
	mixChannels(&image, 1, &dst, 1, from_to, 3);
	imshow("ͨ�����",dst);
}
void quickdemo::inrange_demo(Mat & image)
{
	//ɫ�ʿռ�ת��
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//����
	Mat masker;
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), masker);//���˵�HSVͼ���е�ĳ��ͨ�������ֵ��Сֵ
	//����ȡ������ȡ����ճ������һ��ͼƬ��
	Mat redback = Mat::zeros(image.size(),image.type());//�����˵�����
	redback = Scalar(40, 40, 200);
	imshow("��ȡ������", masker);
	bitwise_not(masker,masker);//����ȡ������ȡ��
	imshow("��ɫ����ԭͼ",image);
	imshow("����ȡ������ȡ��",masker);
	image.copyTo(redback, masker);
	imshow("ROI������ȡ",redback);
}
void quickdemo::pixel_stata_demo(Mat & image)
{
	double mixv, maxv;//�������ص����ֵ����Сֵ
	Point minLoc, maxLoc;//�������ص������Сֵλ��
	std::vector<Mat>mv;//����һ������������ͨ������Ϊֻ�е�ͨ������ͳ��
	split(image, mv);
	for (int i = 0; i < mv.size(); i++)
	{
		minMaxLoc(mv[i], &mixv, &maxv, &minLoc, &maxLoc, Mat());
		std::cout << "ͨ����" << i <<std:: endl;
		std::cout << "mixv:" << mixv << "maxv:" << maxv << std::endl;
	}
	Mat mean, stddev;//�����ֵ�ͷ���
	meanStdDev(image,mean,stddev);
	std::cout << "��ֵ��" << mean << std::endl;
	std::cout << "���" << stddev << std::endl;
}
void quickdemo::drawing_demo(Mat & image)
{
	//���ƾ���
	Rect r;
	r.x = 100;
	r.y = 150;
	r.width = 100;
	r.height = 100;
	Mat dst = Mat::zeros(image.size(),image.type());
	rectangle(image,r,Scalar(255,0,255),2,8,0);

	//����Բ
	circle(image, Point(200, 25), 50, Scalar(0, 255, 200), 2, 8, 0);

	//����ֱ��
	line(image, Point(20, 50), Point(100, 200), Scalar(30, 25, 60), 2, 8, 0);

	//������Բ
	RotatedRect e;
	e.center = Point(60,50);
	e.size = Size(20, 60);
	e.angle = 90;
	ellipse(image, e, Scalar(46, 97, 255), 2, 8);

	//�ϲ�����ͼ��
	Mat dst2;
	addWeighted(image, 0.7, dst, 0.3, 0, dst2);
	imshow("����ͼ��",dst2);
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
		imshow("�����ͼ��ʾ",canvas);
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
//	polylines(canvas, pts, true, Scalar(0, 0, 255), 2, 8, 0);//��ͨ���ƶ���ε�����
	std::vector<std::vector<Point>>contours;//Ҳ�Ǵ���һ���㼯
	contours.push_back(pts);
	drawContours(canvas, contours, -1, Scalar(255, 0, 255), 2);
	//fillPoly(canvas,pts,Scalar(255,0,255),8,0);//������������
	imshow("����λ���",canvas);
}
void quickdemo::type_convert(Mat & image)
{
	Mat dst;
	std::cout << "ԭʼ�������ͣ�" << image.type() << std::endl;//û��ת��֮ǰ����������
	image.convertTo(image, CV_32F);//ת��Ϊ��������
	std::cout << "ת��֮���������ͣ�" << image.type() << std::endl;//ת��֮�����������
	normalize(image, dst, 1, 0, NORM_MINMAX);
	std::cout << "��һ������������ͣ�" << dst.type() << std::endl;//��һ�������������
	imshow("��һ��ͼ��",dst);

}
void quickdemo::interpolation_demo(Mat & image)
{
	Mat large, small;
	int w = image.cols;
	int h = image.rows;
	resize(image, large, Size(w*1.5, h*1.5), 0, 0, INTER_LINEAR);//�Ŵ�
	imshow("�Ŵ�",large);
	resize(image, small, Size(w/1.5, h/1.5), 0, 0, INTER_LINEAR);//��С
	imshow("��С", small);
}
void quickdemo::flip_demo(Mat & image)
{
	Mat dst;
	flip(image, dst, 0);//���·�ת
	imshow("���·�ת",dst);
	flip(image, dst, 1);//���ҷ�ת
	imshow("���ҷ�ת", dst);
	flip(image, dst, -1);//�Խ���
	imshow("�Խ��߷�ת", dst);
}
void quickdemo::rotate_demo(Mat & image)
{
	Mat dst, M;
	int w = image.cols;
	int h = image.rows;
	M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);//��һ������λͼ�����ģ��ڶ���Ϊ��ת�Ƕȣ�������Ϊ����ϵ��
	double cos = abs(M.at<double>(0, 0));//M�����һ��һ��Ԫ��
	double sin = abs(M.at<double>(0, 1));//M�����һ�ж���Ԫ��
	double nw = cos * w + sin * h;//��ͼ��Ŀ�
	double nh = sin * w + cos * h;//��ͼ��ĸ�
	M.at<double>(0, 2) += (nw / 2 - w / 2);
	M.at<double>(1, 2) += (nh / 2 - h / 2);
	warpAffine(image, dst, M, Size(nw, nh), INTER_LINEAR, 0, Scalar(255, 0, 0));
	imshow("��תչʾ",dst);
}
void quickdemo::video_demo(Mat & image)
{
	VideoCapture capture(0);//Ϊ0���ʾ��������ͷ
	Mat frame;
	while (true)
	{
		capture.read(frame);
		if (frame.empty())//û�ж�ȡ��ͼ���˳�
		{
			break;
		}
		int c = waitKey(10);//�ȴ���������
		if (c == 27)//�����ESC�����£����˳�
		{
			break;
		}
		imshow("����ͷ", frame);//ѭ����ʾͼ��
	}
	capture.release();//�ͷ�����ͷռ����Դ
}

void quickdemo::video_write_demo(Mat & image)
{
	VideoCapture capture("F:/opencv_Envir/exercise/GitLab.mp4");//Ϊ0���ʾ��������ͷ
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
		if (frame.empty())//û�ж�ȡ��ͼ���˳�
		{
			break;
		}
		int c = waitKey(10);//�ȴ���������
		if (c == 27)//�����ESC�����£����˳�
		{
			break;
		}
		imshow("����ͷ", frame);//ѭ����ʾͼ��
	}
	capture.release();//�ͷ�����ͷռ����Դ
	writer.release();
}
void quickdemo::histogram_demo(Mat & image)
{
	//��ͨ������
	std::vector<Mat>bgr_plane;
	split(image, bgr_plane);
	//�����������
	const int channels[1] = { 0 };
	const int bins[1] = { 256 };
	float hranges[2] = { 0,255 };
	const float* ranges[1] = {hranges};
	Mat b_hist;
	Mat g_hist;
	Mat r_hist;
	//����BGRͨ����ֱ��ͼ
	calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w/bins[0]);
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	//��һ������
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//����ֱ��ͼ����
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
	imshow("�Ҷ�ͼ��", gray);
	Mat dst;
	equalizeHist(gray, dst);
	imshow("ֱ��ͼ���⻯",dst);
}
void quickdemo::blur_demo(Mat & image)
{
	Mat dst;
	blur(image, dst, Size(10, 10), Point(-1, -1));
	imshow("ԭͼ", image);
	imshow("ͼ��ģ��",dst);
}
void quickdemo::gaussian_demo(Mat & image)
{
	Mat dst;
	GaussianBlur(image, dst, Size(15, 15), 10);
	imshow("ԭͼ", image);
	imshow("��˹ģ��", dst);
}
void quickdemo::bi_gaussian_demo(Mat & image)
{
	Mat dst;
	bilateralFilter(image, dst, 0,100,10);
	imshow("ԭͼ", image);
	imshow("��˹ģ��", dst);
}