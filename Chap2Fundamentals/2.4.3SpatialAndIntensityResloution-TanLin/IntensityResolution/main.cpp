#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <iostream>  
using namespace std;  
using namespace cv;
int main()
{  

	
	Mat srcimage = imread("22.tif");  
	imshow("原始图像",srcimage);  
        imwrite("k=8.tif",srcimage);
	//按原始图的参数规格来创建创建效果图
	Mat dstimage;
	dstimage.create(srcimage.rows,srcimage.cols,srcimage.type());//效果图的大小、类型与原图片相同 
	int a[7]={2,4,8,16,32,64,128};
        for(int w=0;w<7;w++)
          {
	   int r = srcimage.rows;  //行数
	   int c = srcimage.cols;  //列数

	    for(int i = 0;i < r;i++)  
		{  
		   for(int j = 0;j < c;j++)  
			{  	
		
			  dstimage.at<Vec3b>(i,j)[0] = srcimage.at<Vec3b>(i,j)[0]/a[w]*a[w] + a[w]/2;  //蓝色通道
			  dstimage.at<Vec3b>(i,j)[1] = srcimage.at<Vec3b>(i,j)[1]/a[w]*a[w] + a[w]/2;  //绿色通道
			  dstimage.at<Vec3b>(i,j)[2] = srcimage.at<Vec3b>(i,j)[2]/a[w]*a[w] + a[w]/2;  //红是通道
			
			}       
		} 


           string str[7]={"k=7.tif","k=6.tif","k=5.tif","k=4.tif","k=3.tif","k=2.tif","k=1.tif"};
	   imshow(str[w],dstimage);
           imwrite(str[w],dstimage); 
          } 
	waitKey(0); 
        return 0;  
}  



