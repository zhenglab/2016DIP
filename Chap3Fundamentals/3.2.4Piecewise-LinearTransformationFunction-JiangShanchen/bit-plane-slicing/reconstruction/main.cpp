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
    Mat inimage_8 = imread("/Users/jiangshanchen/chapter3/bit-plane-slicing/bit_8.jpg");
    Mat inimage_7 = imread("/Users/jiangshanchen/chapter3/bit-plane-slicing/bit_7.jpg");
    Mat inimage_6 = imread("/Users/jiangshanchen/chapter3/bit-plane-slicing/bit_6.jpg");
    Mat inimage_5 = imread("/Users/jiangshanchen/chapter3/bit-plane-slicing/bit_5.jpg");
    int rows =inimage.rows;
    int cols =inimage.cols;
    Mat newimage;
    newimage.create(rows, cols, inimage.type());
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            newimage.at<Vec3b>(i, j)[0]=(int)((float)inimage_8.at<Vec3b>(i,j)[0]/255*(float)pow(2, 7)+(float)inimage_7.at<Vec3b>(i,j)[0]/255*(float)pow(2, 6)+(float)inimage_6.at<Vec3b>(i,j)[0]/255*(float)pow(2, 5)+(float)inimage_5.at<Vec3b>(i,j)[0]/255*(float)pow(2, 4));
            newimage.at<Vec3b>(i, j)[1]=(int)((float)inimage_8.at<Vec3b>(i,j)[1]/255*(float)pow(2, 7)+(float)inimage_7.at<Vec3b>(i,j)[1]/255*(float)pow(2, 6)+(float)inimage_6.at<Vec3b>(i,j)[1]/255*(float)pow(2, 5)+(float)inimage_5.at<Vec3b>(i,j)[1]/255*(float)pow(2, 4));
            newimage.at<Vec3b>(i, j)[2]=(int)((float)inimage_8.at<Vec3b>(i,j)[2]/255*(float)pow(2, 7)+(float)inimage_7.at<Vec3b>(i,j)[2]/255*(float)pow(2, 6)+(float)inimage_6.at<Vec3b>(i,j)[2]/255*(float)pow(2, 5)+(float)inimage_5.at<Vec3b>(i,j)[2]/255*(float)pow(2, 4));
        }
    }
    imshow("result",newimage);
    imwrite("recon8765.jpg", newimage);
    waitKey(0);
    return 0;
}
