#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <time.h>

using namespace cv;
using namespace std;

#define TWO_PI 6.2831853071795864769252866


double generateGaussianNoise()  
{  
	static bool hasSpare = false;  
	static double rand1, rand2;         
	if(hasSpare)  
	{  
		hasSpare = false;  
		return sqrt(rand1) * sin(rand2);  
	}         
	hasSpare = true;       
	  
	rand1 = rand() / ((double) RAND_MAX);  
	if(rand1 < 1e-100) rand1 = 1e-100;  
	rand1 = -2 * log(rand1);  
	rand2 = (rand() / ((double) RAND_MAX)) * TWO_PI;         
	return sqrt(rand1) * cos(rand2);  
}  
      

void AddGaussianNoise(Mat& I)  
{       
	CV_Assert(I.depth() != sizeof(uchar));  
      
	int channels = I.channels();  
      
	int nRows = I.rows;  
	int nCols = I.cols * channels;  
      
	if(I.isContinuous())
	{  
		nCols *= nRows;  
		nRows = 1;  
	}  
      
int i,j;  
uchar* p;  
for(i = 0; i < nRows; ++i)
{  
	p = I.ptr<uchar>(i);  
	for(j = 0; j < nCols; ++j)
	{  
		double val = p[j] + generateGaussianNoise() * 8;  
                if(val < 0)  
                    val = 0;  
                if(val > 255)  
                    val = 255;  
      
                p[j] = (uchar)val;  
      
        }  
}  
}  
      
 
int main(int argc, char* argv[])  
{  
int time1 = 30;

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
int row = src.rows;//原图长宽
int col = src.cols;

//读图格式报错
if( !src.data )
{
	cout<<"Can't process this kind of image"<<endl;
	exit(8);
}
imshow( "OriginalImage", src); 
Mat noise[time1];

int i,j,k;
Mat dst = Mat::zeros(row,col,CV_8UC3);
CvScalar sum;


for(k = 0;k < time1;k ++)
{
	for ( int l = 0; l < row; l++)
	{
		for(int d = 0; d < col; d++)
		{	noise[k].create(src.rows,src.cols,src.type());
			noise[k].at<cv::Vec3b>(l,d)[0]=src.at<cv::Vec3b>(l,d)[0];
			noise[k].at<cv::Vec3b>(l,d)[1]=src.at<cv::Vec3b>(l,d)[1];
			noise[k].at<cv::Vec3b>(l,d)[2]=src.at<cv::Vec3b>(l,d)[2];			
		}
	}
	srand(k);
	AddGaussianNoise(noise[k]); 
}

for ( int i = 0; i < row; i++)
{
	for(int j = 0; j < col; j++)
	{
		sum.val[0] = 0;
		sum.val[1] = 0;
		sum.val[2] = 0;
		for(k = 0;k < time1;k ++)
		{
			sum.val[0] = sum.val[0] + noise[k].at<cv::Vec3b>(i,j)[0];
			sum.val[1] = sum.val[1] + noise[k].at<cv::Vec3b>(i,j)[1];
			sum.val[2] = sum.val[2] + noise[k].at<cv::Vec3b>(i,j)[2];
	
		}
		dst.at<cv::Vec3b>(i,j)[0] = sum.val[0] / time1;
		dst.at<cv::Vec3b>(i,j)[1] = sum.val[1] / time1;
		dst.at<cv::Vec3b>(i,j)[2] = sum.val[2] / time1;
	}
}
  
imshow("noise.jpg", noise[0]);
imshow("Processed.jpg" , dst);
imwrite("Noise.jpg" , noise[0]); 
imwrite("Processed.jpg",dst);
waitKey(0);    
return 0;    
	

}  

