#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <math.h>
using namespace cv;
using namespace std;
int main()
{
    Mat inimage = imread("/Users/jiangshanchen/chapter3/bit-plane-slicing/Fig0314(a)(100-dollars).tif");
    imshow("inimage" , inimage);
    int rows =inimage.rows;
    int cols =inimage.cols;
    Mat newimage;
    newimage.create(rows, cols, inimage.type());
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            int n=7;
            if ((inimage.at<Vec3b>(i,j)[0]>>n)%2==0) {
                newimage.at<Vec3b>(i,j)[0]=0;
            }else newimage.at<Vec3b>(i,j)[0]=255;
            if ((inimage.at<Vec3b>(i,j)[1]>>n)%2==0) {
                newimage.at<Vec3b>(i,j)[1]=0;
            }else newimage.at<Vec3b>(i,j)[1]=255;
            if ((inimage.at<Vec3b>(i,j)[2]>>n)%2==0) {
                newimage.at<Vec3b>(i,j)[2]=0;
            }else newimage.at<Vec3b>(i,j)[2]=255;
        }
    }
    imshow("result",newimage);
    imwrite("bit_8.jpg", newimage);
    waitKey(0);
    return 0;
}
