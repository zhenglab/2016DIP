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
	//循环
	int m = 11;
	int n = 11;
	int hm = m / 2;
	int hn = n / 2;
	Mat dst = Mat::zeros(src.rows , src.cols , CV_8UC3);	
	for(int i = 0;i < src.rows;i ++)
	{
		for(int j = 0;j < src.cols;j ++)
		{	
			CvScalar sum = 0;
			for(int u = -hm;u < hm;u ++)
			{
				for(int v = -hm;v < hn;v ++)
				{
					sum.val[0] = sum.val[0] + src.at<cv::Vec3b>(i + u,j + v)[0];
					sum.val[1] = sum.val[1] + src.at<cv::Vec3b>(i + u,j + v)[1];
					sum.val[2] = sum.val[2] + src.at<cv::Vec3b>(i + u,j + v)[2];
				}
			}
			sum.val[0] = sum.val[0] / m / n;
			sum.val[1] = sum.val[1] / m / n;
			sum.val[2] = sum.val[2] / m / n;
			dst.at<cv::Vec3b>(i,j)[0] = sum.val[0];
			dst.at<cv::Vec3b>(i,j)[1] = sum.val[1];
			dst.at<cv::Vec3b>(i,j)[2] = sum.val[2];
		}
	}


	imshow("dst",dst);
	imwrite("Rotation.jpg",dst);
	waitKey(0);    
	return 0;    
}  

