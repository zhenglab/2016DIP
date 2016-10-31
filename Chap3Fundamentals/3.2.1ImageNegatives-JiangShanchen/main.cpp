#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat inimage = imread("/Users/jiangshanchen/Fig0304(a)(breast_digital_Xray).tif");
    imshow("inimage" , inimage);
    int rows =inimage.rows;
    int cols =inimage.cols;
    Mat newimage;
    newimage.create(rows, cols, inimage.type());
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            newimage.at<Vec3b>(i,j)[0]=255-inimage.at<Vec3b>(i,j)[0];
            newimage.at<Vec3b>(i,j)[1]=255-inimage.at<Vec3b>(i,j)[1];
            newimage.at<Vec3b>(i,j)[2]=255-inimage.at<Vec3b>(i,j)[2];
        }
    }
    imshow("result",newimage);
    imwrite("reult.jpg", newimage);
    waitKey(0);
    return 0;
}
