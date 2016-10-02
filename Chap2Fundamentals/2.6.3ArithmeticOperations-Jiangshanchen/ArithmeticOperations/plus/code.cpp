#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace cv;
using namespace std;
int main(){
    Mat orimg_1=imread("noise_1.jpg");
    Mat orimg_2=imread("noise_2.jpg");
    Mat orimg_3=imread("noise_3.jpg");
    Mat orimg_4=imread("noise_4.jpg");
    Mat orimg_5=imread("noise_5.jpg");
    int m =orimg_1.rows;
    int n = orimg_1.cols;
    Mat newimage;
    newimage.create(m,n,orimg_1.type());
    for (int i=1; i<m; i++)
    {
        for (int j=1; j<n; j++)
        {
            newimage.at<Vec3b>(i,j)[0]=(orimg_1.at<Vec3b>(i,j)[0]+orimg_2.at<Vec3b>(i,j)[0]+orimg_3.at<Vec3b>(i,j)[0]+orimg_4.at<Vec3b>(i,j)[0]+orimg_5.at<Vec3b>(i,j)[0])/5;
            newimage.at<Vec3b>(i,j)[1]=(orimg_1.at<Vec3b>(i,j)[1]+orimg_2.at<Vec3b>(i,j)[1]+orimg_3.at<Vec3b>(i,j)[1]+orimg_4.at<Vec3b>(i,j)[1]+orimg_5.at<Vec3b>(i,j)[1])/5;
            newimage.at<Vec3b>(i,j)[2]=(orimg_1.at<Vec3b>(i,j)[2]+orimg_2.at<Vec3b>(i,j)[2]+orimg_3.at<Vec3b>(i,j)[2]+orimg_4.at<Vec3b>(i,j)[2]+orimg_5.at<Vec3b>(i,j)[2])/5;
        }
    }
    namedWindow("newimage");
    imshow("newimage.jpg",newimage);
    waitKey(0);
    return 0;
}

