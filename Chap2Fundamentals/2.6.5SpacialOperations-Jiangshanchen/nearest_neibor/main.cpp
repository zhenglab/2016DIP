#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat inimage = imread("letter_T.tif");
    imshow("inimage" , inimage);
    int rows =inimage.rows;
    int cols =inimage.cols;
    Mat dst;
    float n=1.0;
    dst.create(rows*n, cols*n, inimage.type());
    float x,y,i,j;
    for (i=0; i<rows*n; i++) {
        for (j=0; j<cols*n; j++) {//遍历新图上的点
            float l=i/n;
            float k=j/n;//旧图上的点
            x=(int) (l+0.5)>(int) (l)?(int) (l+1):(int) l;
            y=(int) (k+0.5)>(int) (k)?(int) (k+1):(int) k;//查找旧图上的点
            dst.at<Vec3b>(i,j)[0]=inimage.at<Vec3b>(x*cos(201)-y*sin(201),x*sin(201)+y*cos(201))[0];
            dst.at<Vec3b>(i,j)[1]=inimage.at<Vec3b>(x*cos(201)-y*sin(201),x*sin(201)+y*cos(201))[1];
            dst.at<Vec3b>(i,j)[2]=inimage.at<Vec3b>(x*cos(201)-y*sin(201),x*sin(201)+y*cos(201))[2];
        }
    }
    imshow("result",dst);
    imwrite("result-2.jpg",dst);
    waitKey(0);
    return 0;
}