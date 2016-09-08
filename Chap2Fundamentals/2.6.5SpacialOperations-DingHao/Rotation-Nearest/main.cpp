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
	//创建画布
	Mat dst = Mat::zeros(src.rows * 2, src.cols * 2, CV_8UC3);
	//实现变换
	int ang = 339;
	for(int i = 0;i < src.rows;i ++)
	{	
		for(int j = 0;j < src.cols;j ++)
		{	
			int x = i * cos(ang) - j * sin(ang);
			int y = i * sin(ang) + j * cos(ang);
			x = x + 200;
			y = y + 200;
			dst.at<cv::Vec3b>(x,y)[0] = src.at<cv::Vec3b>(i,j)[0];
			dst.at<cv::Vec3b>(x,y)[1] = src.at<cv::Vec3b>(i,j)[1];
			dst.at<cv::Vec3b>(x,y)[2] = src.at<cv::Vec3b>(i,j)[2];
		}	
	}


	imshow("dst",dst);
	//imshow("union",Union);
	imwrite("Rotation.jpg",dst);
	//imwrite("union.jpg",Union);
	waitKey(0);    
	return 0;    
}  

