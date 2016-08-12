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
int a[3]={4,8,16};
int nl = srcimage.rows;
int nc = srcimage.cols ;
for(int w=0;w<3;w++)
 {
int l= (int)(nl/a[w]+0.5);
int c= (int)(nc/a[w]+0.5);
Mat dstimage;
dstimage.create(l,c,srcimage.type());
for(int i=0;i<l;i++)
	{ 
         for(int j=0;j<c;j++)
         	{
               dstimage.at<Vec3b>(i,j)[0]=srcimage.at<Vec3b>(a[w]*i,a[w]*j)[0];
               dstimage.at<Vec3b>(i,j)[1]=srcimage.at<Vec3b>(a[w]*i,a[w]*j)[1];
               dstimage.at<Vec3b>(i,j)[2]=srcimage.at<Vec3b>(a[w]*i,a[w]*j)[2];

		}
	} 
String str[3]={"300dpi.tif","150dpi.tif","72dpi.tif"};
imshow(str[w],dstimage);
imwrite(str[w], dstimage);
}
waitKey(0);
return 0;
}
