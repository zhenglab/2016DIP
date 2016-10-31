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
    Mat inimage = imread("/Users/jiangshanchen/images/DIP3E_Original_Images_CH03/Fig0312(a)(kidney).tif");
    imshow("inimage" , inimage);
    int rows =inimage.rows;
    int cols =inimage.cols;
    CvScalar sg;
    Mat newimage;
    newimage.create(rows, cols, inimage.type());
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (inimage.at<Vec3b>(i,j)[0]<=150) {
                inimage.at<Vec3b>(i,j)[0]=0;
            }
            if (inimage.at<Vec3b>(i,j)[1]<=150) {
                inimage.at<Vec3b>(i,j)[1]=0;
            }
            if (inimage.at<Vec3b>(i,j)[2]<=150) {
                inimage.at<Vec3b>(i,j)[2]=0;
            }
            if (inimage.at<Vec3b>(i,j)[0]>=170) {
                inimage.at<Vec3b>(i,j)[0]=255;
            }
            if (inimage.at<Vec3b>(i,j)[1]>=170) {
                inimage.at<Vec3b>(i,j)[1]=255;
            }
            if (inimage.at<Vec3b>(i,j)[2]>=170) {
                inimage.at<Vec3b>(i,j)[2]=255;
            }
        }
    }
    imshow("result",inimage);
    imwrite("reult_170+.jpg", newimage);
    waitKey(0);
    return 0;
}
