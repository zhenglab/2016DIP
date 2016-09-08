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
	if(argc != 3)
	{
		cout << "Wrong arguments input" << endl;
		cout << "usage:" << endl;
		cout << "\t" << argv[0] << "Image name" << endl;
		exit(1);
	}
	//读入图像
	string image1 = argv[1];
	string image2 = argv[2];
	Mat Xray = imread(image1);
	Mat mask = imread(image2);
	//读入图像报错
  	if(!Xray.data )
	{
		cout << "Can't read image properly" << endl;
		exit(2);
	}
	//显示输入图像
	imshow("Xray" , Xray);
	imshow("mask" , mask);
	//建立输出图像
	CvScalar F;
	Mat dst = Mat::zeros(Xray.rows , Xray.cols , CV_8UC3);
	for(int i = 0;i < Xray.rows;i ++)
	{	
		for(int j = 0;j < Xray.cols;j ++)
		{
			if(mask.at<cv::Vec3b>(i,j)[0] > 0) mask.at<cv::Vec3b>(i,j)[0] = 1;
			if(mask.at<cv::Vec3b>(i,j)[1] > 0) mask.at<cv::Vec3b>(i,j)[1] = 1;
			if(mask.at<cv::Vec3b>(i,j)[2] > 0) mask.at<cv::Vec3b>(i,j)[2] = 1;
			F.val[0] = Xray.at<cv::Vec3b>(i,j)[0] * mask.at<cv::Vec3b>(i,j)[0];
			F.val[1] = Xray.at<cv::Vec3b>(i,j)[1] * mask.at<cv::Vec3b>(i,j)[1];
			F.val[2] = Xray.at<cv::Vec3b>(i,j)[2] * mask.at<cv::Vec3b>(i,j)[2];
			dst.at<cv::Vec3b>(i,j)[0] = F.val[0];
			dst.at<cv::Vec3b>(i,j)[1] = F.val[1];
			dst.at<cv::Vec3b>(i,j)[2] = F.val[2];
		}	
	}

	imshow("result",dst);
	imwrite("result.jpg",dst);
	waitKey(0);    
	return 0;    
}  

