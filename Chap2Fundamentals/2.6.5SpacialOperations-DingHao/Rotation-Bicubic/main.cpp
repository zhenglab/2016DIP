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
	CvScalar p00,p01,p02,p03,p10,p11,p12,p13,p20,p21,p22,p23,p30,p31,p32,p33;//16个点
	CvScalar a00,a01,a02,a03,a10,a11,a12,a13,a20,a21,a22,a23,a30,a31,a32,a33;
	CvScalar F;
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
		//取十六个点
			p00 = src.at<cv::Vec3b>((int)x-1,(int)y-1);
			p10 = src.at<cv::Vec3b>((int)x,(int)y-1);
			p20 = src.at<cv::Vec3b>((int)x+1,(int)y-1);
			p30 = src.at<cv::Vec3b>((int)x+2,(int)y-1);
			p01 = src.at<cv::Vec3b>((int)x-1,(int)y);
			p11 = src.at<cv::Vec3b>((int)x,(int)y);
			p21 = src.at<cv::Vec3b>((int)x+1,(int)y);
			p31 = src.at<cv::Vec3b>((int)x+2,(int)y);
			p02 = src.at<cv::Vec3b>((int)x-1,(int)y+1);
			p12 = src.at<cv::Vec3b>((int)x,(int)y+1);
			p22 = src.at<cv::Vec3b>((int)x+1,(int)y+1);
			p32 = src.at<cv::Vec3b>((int)x+2,(int)y+1);
			p03 = src.at<cv::Vec3b>((int)x-1,(int)y+2);
			p13 = src.at<cv::Vec3b>((int)x,(int)y+2);
			p23 = src.at<cv::Vec3b>((int)x+1,(int)y+2);
			p33 = src.at<cv::Vec3b>((int)x+2,(int)y+2);
			for(int k = 0;k < 3;k ++)
			{
				a00.val[k]=p11.val[k];

				a01.val[k]=-0.5 * p10.val[k] + 0.5 * p12.val[k];

				a02.val[k]=p10.val[k] - 2.5 * p11.val[k] + 2 * p12.val[k] - 0.5 * p13.val[k];

				a03.val[k]=-0.5 * p10.val[k] + 1.5 * p11.val[k] - 1.5 * p12.val[k] + 0.5 * p13.val[k];

				a10.val[k]=-0.5 * p01.val[k] + 0.5 * p21.val[k];

				a11.val[k]=0.25*p00.val[k]-0.25*p02.val[k]-0.25*p20.val[k]+0.25*p22.val[k];

				a12.val[k]=-0.5*p00.val[k]+1.25*p01.val[k]-p02.val[k]+0.25*p03.val[k]+0.5*p20.val[k]-1.25*p21.val[k]+p22.val[k]-0.25*p23.val[k];

				a13.val[k]=0.25*p00.val[k]-0.75*p01.val[k]+0.75*p02.val[k]-0.25*p03.val[k]-0.25*p20.val[k]+0.75*p21.val[k]-0.75*p22.val[k]+0.25*p23.val[k];

				a20.val[k]=p01.val[k]-2.5*p11.val[k]+2*p21.val[k]-0.5*p31.val[k];

				a21.val[k]=-0.5*p00.val[k]+0.5*p02.val[k]+1.25*p10.val[k]-1.25*p12.val[k]-p20.val[k]+p22.val[k]+0.25*p30.val[k]-0.25*p32.val[k];

				a22.val[k]=p00.val[k]-2.5*p01.val[k]+2*p02.val[k]-0.5*p03.val[k]-2.5*p10.val[k]+6.25*p11.val[k]-5*p12.val[k]+1.25*p13.val[k]+2*p20.val[k]-5*p21.val[k]+4*p22.val[k]-p23.val[k]-0.5*p30.val[k]+1.25*p31.val[k]-p32.val[k]+0.25*p33.val[k];

				a23.val[k]=-0.5*p00.val[k]+1.5*p01.val[k]-1.5*p02.val[k]+0.5*p03.val[k]+1.25*p10.val[k]-3.75*p11.val[k]+3.75*p12.val[k]-1.25*p13.val[k]-p20.val[k]+3*p21.val[k]-3*p22.val[k]+p23.val[k]+0.25*p30.val[k]-0.75*p31.val[k]+0.75*p32.val[k]-0.25*p33.val[k];

				a30.val[k]=-0.5*p01.val[k]+1.5*p11.val[k]-1.5*p21.val[k]+0.5*p31.val[k];
				a31.val[k]=0.25*p00.val[k]-0.25*p02.val[k]-0.75*p10.val[k]+0.75*p12.val[k]+0.75*p20.val[k]-0.75*p22.val[k]-0.25*p30.val[k]+0.25*p32.val[k];

				a32.val[k]=-0.5*p00.val[k]+1.25*p01.val[k]-p02.val[k]+0.25*p03.val[k]+1.5*p10.val[k]-3.75*p11.val[k]+3*p12.val[k]-0.75*p13.val[k]-1.5*p20.val[k]+3.75*p21.val[k]-3*p22.val[k]+0.75*p23.val[k]+0.5*p30.val[k]-1.25*p31.val[k]+p32.val[k]-0.25*p33.val[k];

				a33.val[k]=0.25*p00.val[k]-0.75*p01.val[k]+0.75*p02.val[k]-0.25*p03.val[k]-0.75*p10.val[k]+2.25*p11.val[k]-2.25*p12.val[k]+0.75*p13.val[k]+0.75*p20.val[k]-2.25*p21.val[k]+2.25*p22.val[k]-0.75*p23.val[k]-0.25*p30.val[k]+0.75*p31.val[k]-0.75*p32.val[k]+0.25*p33.val[k];


				F.val[k]=a00.val[k]+a01.val[k]*uy+a02.val[k]*uy*uy+a03.val[k]*uy*uy*uy+a10.val[k]*ux+a11.val[k]*ux*uy+a12.val[k]*ux*uy*uy+a13.val[k]*ux*uy*uy*uy+a20.val[k]*ux*ux+a21.val[k]*ux*ux*uy+a22.val[k]*ux*ux*uy*uy+a23.val[k]*ux*ux*uy*uy*uy+a30.val[k]*ux*ux*ux+a31.val[k]*ux*ux*ux*uy+a32.val[k]*ux*ux*ux*uy*uy+a33.val[k]*ux*ux*ux*uy*uy*uy;
			}
			if(F.val[0]> 255)F.val[0] = 255;
			if(F.val[1] > 255)F.val[1] = 255;
			if(F.val[2] > 255)F.val[2] = 255;
			if(F.val[0]<0)F.val[0] = 0;
			if(F.val[1]<0)F.val[1] = 0;
			if(F.val[2]<0)F.val[2] = 0;
			//系数相加为处理后的点值
			dst.at<cv::Vec3b>(i,j)[0]=F.val[0];
			dst.at<cv::Vec3b>(i,j)[1]=F.val[1];
			dst.at<cv::Vec3b>(i,j)[2]=F.val[2];	
		}
	}	
	imshow("dst",dst);
	//imshow("union",Union);
	imwrite("Rotation.jpg",dst);
	//imwrite("union.jpg",Union);
	waitKey(0);    
	return 0;    
}  

