#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])  
{  
//缩小倍数  
double x = 2;

//导入图像
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
if(! src.data)
{
	cout << "Can't process this kind of image" << endl;
	exit(8);
}

//处理长宽  
int row = src.rows;//原图长宽
int col = src.cols;
float nrow = (float)row / x;//新图长宽
float ncol = (float)col / x;
	
//创建矩阵
Mat dst = Mat::zeros(nrow,ncol,CV_8UC3);  
int X = 0,Y = 0;//原图坐标

for ( int i = 0; i < row; i++)
{
	for(int j = 0; j < col; j++)
	{
		X = cvRound ( i * x );
		Y = cvRound ( j * x );
		if( X < row && X >= 0 && Y >= 0 && Y <= col )
		{	
			dst.at<cv::Vec3b>(i,j)[0]=src.at<cv::Vec3b>(X,Y)[0];
			dst.at<cv::Vec3b>(i,j)[1]=src.at<cv::Vec3b>(X,Y)[1];
			dst.at<cv::Vec3b>(i,j)[2]=src.at<cv::Vec3b>(X,Y)[2];
		}
	}
}
   
imshow("src",src); 
imshow("dst",dst);  
imwrite("Reduce.jpg",dst); 
waitKey(0);  
return 0;  
}  

