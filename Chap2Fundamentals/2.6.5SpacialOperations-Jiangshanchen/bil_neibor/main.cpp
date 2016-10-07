#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
int main(){
    Mat inimage=imread("/Users/jiangshanchen/2.6.5SpacialOperations-Jiangshanchen/bil_neibor/letter_T.tif");
    imshow("origin", inimage);
    Mat newimage;
    float cr =inimage.rows;
    float cl =inimage.cols;
    newimage.create(cr, cl, inimage.type());
    float f =1;
    float a =f*cr;
    float b =f*cl;
    CvScalar m1,m2,m3,m4,sum;
    for (float X=0; X<a; X++) {
        for (float Y=0; Y<b; Y++) {
            float x= X/f;
            float y= Y/f;
            int x1=(int)(x);
            int x2=(int)(x)+1;
            int y1=(int)(y);
            int y2=(int)(y)+1;
            m1=inimage.at<Vec3b>((int)(x1*cos(201)-y1*sin(201)),(int)(x1*sin(201)+y1*cos(201)));
            m2=inimage.at<Vec3b>((int)(x2*cos(201)-y1*sin(201)),(int)(x2*sin(201)+y1*cos(201)));
            m3=inimage.at<Vec3b>((int)(x1*cos(201)-y2*sin(201)),(int)(x1*sin(201)+y2*cos(201)));
            m4=inimage.at<Vec3b>((int)(x2*cos(201)-y2*sin(201)),(int)(x2*sin(201)+y2*cos(201)));
            sum.val[0]=(y2-y)*(m1.val[0]*(x2-x)+m2.val[0]*(x-x1))+(y-y1)*(m3.val[0]*(x2-x)+m4.val[0]*(x-x1));
            sum.val[1]=(y2-y)*(m1.val[1]*(x2-x)+m2.val[1]*(x-x1))+(y-y1)*(m3.val[1]*(x2-x)+m4.val[1]*(x-x1));
            sum.val[2]=(y2-y)*(m1.val[2]*(x2-x)+m2.val[2]*(x-x1))+(y-y1)*(m3.val[2]*(x2-x)+m4.val[2]*(x-x1));
            newimage.at<Vec3b>(X,Y)[0]=sum.val[0]/((x2-x1)*(y2-y1));
            newimage.at<Vec3b>(X,Y)[1]=sum.val[1]/((x2-x1)*(y2-y1));
            newimage.at<Vec3b>(X,Y)[2]=sum.val[2]/((x2-x1)*(y2-y1));
        }
    }
    imshow("newimage", newimage);
    imwrite("result.jpg", newimage);
    waitKey(0);
}