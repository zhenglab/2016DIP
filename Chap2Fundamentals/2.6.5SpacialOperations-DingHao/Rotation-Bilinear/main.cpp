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
	Mat dst = Mat::zeros(src.rows , src.cols , CV_8UC3);
	//实现变换
	CvScalar a,b,c,d;
	int ang = 339;
	for(int i = 0;i < src.rows;i ++)
	{	
		for(int j = 0;j < src.cols;j ++)
		{	
			float x = i * cos(ang) - j * sin(ang);
			float y = i * sin(ang) + j * cos(ang);
			//x = x + 200;
			//y = y + 200;
			float ux=(int)x,uy=(int)y;
			ux=abs(ux-x);uy=abs(uy-y);
		
		//取四个点
			a = src.at<cv::Vec3b>((int)x,(int)y);
			b = src.at<cv::Vec3b>((int)x,(int)y+1);
			c = src.at<cv::Vec3b>((int)x+1,(int)y);
			d = src.at<cv::Vec3b>((int)x+1,(int)y+1);
		//系数相加为处理后的点值
			dst.at<cv::Vec3b>(i,j)[0]=(a.val[0]*(1-ux)+c.val[0]*ux)*(1-uy)+(b.val[0]*(1-ux)+d.val[0]*ux)*uy;
			dst.at<cv::Vec3b>(i,j)[1]=(a.val[1]*(1-ux)+c.val[1]*ux)*(1-uy)+(b.val[1]*(1-ux)+d.val[1]*ux)*uy;
			dst.at<cv::Vec3b>(i,j)[2]=(a.val[2]*(1-ux)+c.val[2]*ux)*(1-uy)+(b.val[2]*(1-ux)+d.val[2]*ux)*uy;
		}	
	}


	imshow("dst",dst);
	//imshow("union",Union);
	imwrite("Rotation.jpg",dst);
	//imwrite("union.jpg",Union);
	waitKey(0);    
	return 0;    
}  

