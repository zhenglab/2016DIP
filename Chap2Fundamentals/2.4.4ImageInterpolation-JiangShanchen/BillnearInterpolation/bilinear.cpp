#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace cv;
using namespace std;
int main(){
    Mat reimage =imread("ddd.jpg");
    imshow("reimage", reimage);
    Mat newimage;
    float cr =reimage.rows;
    float cl =reimage.cols;
    float f =1.5;
    float a =f*cr;
    float b =f*cl;
    CvScalar m1,m2,m3,m4,sum;
    newimage.create(a, b,reimage.type());
    for (float X=0; X<a; X++) {
        for (float Y=0; Y<b; Y++) {
            float x= X/f;
            float y= Y/f;
            int x1=(int)(x);
            int x2=(int)(x)+1;
            int y1=(int)(y);
            int y2=(int)(y)+1;
            m1=reimage.at<Vec3b>(x1,y1);
            m2=reimage.at<Vec3b>(x2,y1);
            m3=reimage.at<Vec3b>(x1,y2);
            m4=reimage.at<Vec3b>(x2,y2);
            sum.val[0]=(y2-y)*(m1.val[0]*(x2-x)+m2.val[0]*(x-x1))+(y-y1)*(m3.val[0]*(x2-x)+m4.val[0]*(x-x1));
            sum.val[1]=(y2-y)*(m1.val[1]*(x2-x)+m2.val[1]*(x-x1))+(y-y1)*(m3.val[1]*(x2-x)+m4.val[1]*(x-x1));
            sum.val[2]=(y2-y)*(m1.val[2]*(x2-x)+m2.val[2]*(x-x1))+(y-y1)*(m3.val[2]*(x2-x)+m4.val[2]*(x-x1));
            newimage.at<Vec3b>(X,Y)[0]=sum.val[0]/((x2-x1)*(y2-y1));
            newimage.at<Vec3b>(X,Y)[1]=sum.val[1]/((x2-x1)*(y2-y1));
            newimage.at<Vec3b>(X,Y)[2]=sum.val[2]/((x2-x1)*(y2-y1));
        }
    }
    imshow("newimage", newimage);
    waitKey(0);
}
