#include <iostream>
#include <cmath>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main()
{

Mat srcimage=imread("11.tif");
if(!srcimage.data)

{

cout << "image read is error!" << endl;

return 0;

}
cout << "image Info:Height:" << srcimage.size().height << " Width:" << srcimage.size().width << endl;
imshow("origin",srcimage);
imwrite("1250.jpg",srcimage);
int a[3]={4,8,16};
int nl = srcimage.rows;
int nc = srcimage.cols ;
for(int w=0;w<3;w++)
{
int r=nl/a[w];
int c=nc/a[w];
int sum1,sum2,sum3,avg1,avg2,avg3;
Mat dstimage;
dstimage.create(r,c,srcimage.type());
 CvScalar  sum,avg;
for(int x=0;x<r;x++)
{
 for(int y=0;y<c;y++)
   {
     sum=0;
     
     for(int i=a[w]*x;i<a[w]*(x+1);i++)
	{ 
         for(int j=a[w]*y;j<a[w]*(y+1);j++)
         	{
		
                sum.val[0]=sum.val[0]+srcimage.at<Vec3b>(i,j)[0];
               
                sum.val[1]=sum.val[1]+srcimage.at<Vec3b>(i,j)[1];
                
                sum.val[2]=sum.val[2]+srcimage.at<Vec3b>(i,j)[2];
                
               
		}
	 } 
                
		dstimage.at<Vec3b>(x,y)[0]=sum.val[0]/(a[w]*a[w]);
                dstimage.at<Vec3b>(x,y)[1]=sum.val[1]/(a[w]*a[w]);
                dstimage.at<Vec3b>(x,y)[2]=sum.val[2]/(a[w]*a[w]);

    }
}
String str[3]={"300dpi.jpg","150dpi.jpg","72dpi.jpg"};
imshow(str[w],dstimage);
imwrite(str[w], dstimage);
}

waitKey(0);
return 0;
}
