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
    Mat inimage = imread("/Users/jiangshanchen/chapter3/power-law_transform[]/Fig0308(a)(fractured_spine).tif");
    imshow("inimage" , inimage);
    int rows =inimage.rows;
    int cols =inimage.cols;
    Mat newimage;
    newimage.create(rows, cols, inimage.type());
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            newimage.at<Vec3b>(i,j)[0]=(int)(pow((float)inimage.at<Vec3b>(i,j)[0]/255,(float)0.3)*255);
            newimage.at<Vec3b>(i,j)[1]=(int)(pow((float)inimage.at<Vec3b>(i,j)[1]/255,(float)0.3)*255);
            newimage.at<Vec3b>(i,j)[2]=(int)(pow((float)inimage.at<Vec3b>(i,j)[2]/255,(float)0.3)*255);
        }
    }
    imshow("result",newimage);
    imwrite("reult_0.3.jpg", newimage);
    waitKey(0);
    return 0;
}
