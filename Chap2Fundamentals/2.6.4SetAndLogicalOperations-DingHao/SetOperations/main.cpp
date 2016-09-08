#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <time.h>

using namespace cv;
using namespace std;

int main(int argc , char *argv[])
{
	//输入语句报错
	if(argc != 2)
	{
		cout << "Wrong arguments input" << endl;
		cout << "usage:" << endl;
		cout << "\t" << argv[0] << "Image name" << endl;
		exit(1);
	}
	//读入图像
	string image = argv[1];
	Mat src = imread(image);
	//读入图像报错
  	if(!src.data )
	{
		cout << "Can't read image properly" << endl;
		exit(2);
	}
	//显示输入图像
	imshow("src" , src);
	//取反图像
	Mat opposite = Mat::zeros(src.rows , src.cols , CV_8UC3);
	for(int i = 0;i < src.rows;i ++)
	{	
		for(int j = 0;j < src.cols;j ++)
		{
			opposite.at<cv::Vec3b>(i,j)[0] = 255 - src.at<cv::Vec3b>(i,j)[0];
			opposite.at<cv::Vec3b>(i,j)[1] = 255 - src.at<cv::Vec3b>(i,j)[1];
			opposite.at<cv::Vec3b>(i,j)[2] = 255 - src.at<cv::Vec3b>(i,j)[2];
		}	
	}
	//求均值的三倍
	//constant = mean(src);
	CvScalar sum,avg;
	sum.val[0] = 0;
	sum.val[1] = 0;
	sum.val[2] = 0;
	for(int i = 0;i < src.rows;i ++)
	{	
		for(int j = 0;j < src.cols;j ++)
		{
			sum.val[0] = sum.val[0] + src.at<cv::Vec3b>(i,j)[0];
			sum.val[1] = sum.val[1] + src.at<cv::Vec3b>(i,j)[1];
			sum.val[2] = sum.val[2] + src.at<cv::Vec3b>(i,j)[2];
		}	
	}
	int all = src.rows * src.cols;
	avg.val[0] = sum.val[0] / all;
	avg.val[1] = sum.val[1] / all;
	avg.val[2] = sum.val[2] / all;
	avg.val[0] = avg.val[0] * 3;
	avg.val[1] = avg.val[1] * 3;
	avg.val[2] = avg.val[2] * 3;
	//并集运算
	Mat Union = Mat::zeros(src.rows , src.cols , CV_8UC3);
	for(int i = 0;i < src.rows;i ++)
	{	
		for(int j = 0;j < src.cols;j ++)
		{
			if(src.at<cv::Vec3b>(i,j)[0] > avg.val[0]) 
				Union.at<cv::Vec3b>(i,j)[0] = src.at<cv::Vec3b>(i,j)[0];
			else if(src.at<cv::Vec3b>(i,j)[0] <= avg.val[0]) 
				Union.at<cv::Vec3b>(i,j)[0] = avg.val[0];
			if(src.at<cv::Vec3b>(i,j)[1] > avg.val[1]) 
				Union.at<cv::Vec3b>(i,j)[1] = src.at<cv::Vec3b>(i,j)[1];
			else if(src.at<cv::Vec3b>(i,j)[1] <= avg.val[1]) 
				Union.at<cv::Vec3b>(i,j)[1] = avg.val[1];
			if(src.at<cv::Vec3b>(i,j)[2] > avg.val[1]) 
				Union.at<cv::Vec3b>(i,j)[2] = src.at<cv::Vec3b>(i,j)[2];
			else if(src.at<cv::Vec3b>(i,j)[2] <= avg.val[2]) 
				Union.at<cv::Vec3b>(i,j)[2] = avg.val[2];
		}	
	}

	imshow("opposite",opposite);
	imshow("union",Union);
	imwrite("opposite.jpg",opposite);
	imwrite("union.jpg",Union);
	waitKey(0);    
	return 0;    
}  

