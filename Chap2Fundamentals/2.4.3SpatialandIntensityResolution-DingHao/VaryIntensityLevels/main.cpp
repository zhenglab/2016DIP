#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])  
{  
//缩减倍数  
double x = 128;

//导入图像
if ( argc != 2 )
{
	cout<<"Wrong arguments."<<endl;
	cout<<"Usage:"<<endl;
	cout<<"\t "<<argv[0]<<"Image"<<endl;
	exit(7);
}
string image = argv[1];
Mat src = imread(image);  
cvtColor(src,src,CV_BGR2GRAY);
imshow("src",src); 
//读图格式报错
if(! src.data)
{
	cout << "Can't process this kind of image" << endl;
	exit(8);
}

//读取长宽  
int row = src.rows;
int col = src.cols;

//创建矩阵
Mat dst = Mat::zeros(row,col,CV_8UC1);  
int X = 0,Y = 0;//原图坐标

for ( int i = 0; i < row; i++)
{
	for(int j = 0; j < col; j++)
	{
		dst.at<uchar>(i,j) = cvRound(src.at<uchar>(i,j) / x);
		dst.at<uchar>(i,j) = dst.at<uchar>(i,j) * x;
	} 
}
   
imshow("src",src); 
imshow("dst",dst);  
imwrite("Level.jpg",dst); 
waitKey(0);  
return 0;  
}  

