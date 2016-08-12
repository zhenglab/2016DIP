#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;

    int main(int argc, char* argv[])  
    {
	//放大倍数  
	double x=2;

        //读图语句报错
	if ( argc != 2 )
	{
		cout<<"Wrong arguments."<<endl;
		cout<<"Usage:"<<endl;
		cout<<"\t "<<argv[0]<<" Image"<<endl;
		exit(7);
	}

	string image = argv[1];
        Mat src = imread(image);  
       
	//读图格式报错
	if( !src.data )
	{
		cout<<"Can't process this kind of image"<<endl;
		exit(8);
	}

        //显示  
        imshow("src",src);  
      
        //处理长宽  
	int row=src.rows;
	int col=src.cols;
	float nrow=x*(float)row;
	float ncol=x*(float)col;
	
	//创建矩阵
        Mat dst = Mat::zeros(nrow,ncol,CV_8UC3);  
      	
	float X=0,Y=0;
	CvScalar a,b,c,d;

	//双线性内插
	for ( int i = 0; i < nrow-1; i++)
	{
		for(int j = 0; j < ncol-1; j++)
		{
			X= i / (double)x ;
			Y= j / (double)x ;
			float ux=(int)X,uy=(int)Y;
			ux=abs(ux-X);uy=abs(uy-Y);
			
			if( X < row-1 && X >= 0 && Y >= 0 && Y < col-1 )
			{
		//取四个系数
			a = src.at<cv::Vec3b>((int)X,(int)Y);
			b = src.at<cv::Vec3b>((int)X,(int)Y+1)-src.at<cv::Vec3b>((int)X,(int)Y);
			c = src.at<cv::Vec3b>((int)X+1,(int)Y)-src.at<cv::Vec3b>((int)X,(int)Y);
			d = src.at<cv::Vec3b>((int)X+1,(int)Y+1)-src.at<cv::Vec3b>((int)X+1,(int)Y)-src.at<cv::Vec3b>((int)X,(int)Y+1)+src.at<cv::Vec3b>((int)X,(int)Y);
		//计算系数
			b.val[0]=b.val[0]*uy;
			b.val[1]=b.val[1]*uy;
			b.val[2]=b.val[2]*uy;
			c.val[0]=c.val[0]*ux;
			c.val[1]=c.val[1]*ux;
			c.val[2]=c.val[2]*ux;
			d.val[0]=d.val[0]*ux*uy;
			d.val[1]=d.val[1]*ux*uy;
			d.val[2]=d.val[2]*ux*uy;
			}
		//系数相加为处理后的点值
				dst.at<cv::Vec3b>(i,j)[0]=(int)(a.val[0]+b.val[0]+c.val[0]+d.val[0]);
				dst.at<cv::Vec3b>(i,j)[1]=(int)(a.val[1]+b.val[1]+c.val[1]+d.val[1]);
				dst.at<cv::Vec3b>(i,j)[2]=(int)(a.val[2]+b.val[2]+c.val[2]+d.val[2]);

			if(a.val[0]+b.val[0]+c.val[0]+d.val[0] > 255)
			{dst.at<cv::Vec3b>(i,j)[0] = 255;}

			if(a.val[1]+b.val[1]+c.val[0]+d.val[1] > 255)
			{dst.at<cv::Vec3b>(i,j)[1] = 255;}

			if(a.val[2]+b.val[2]+c.val[0]+d.val[2] > 255)
			{dst.at<cv::Vec3b>(i,j)[2] = 255;}
		}
	}        


      
        imshow("dst",dst);  
      	imwrite("double.bmp",dst);

        waitKey(0);  
        return 0;  
    }  



