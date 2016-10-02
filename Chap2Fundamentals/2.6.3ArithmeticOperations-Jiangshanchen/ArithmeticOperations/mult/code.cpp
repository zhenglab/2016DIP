#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat inimage = imread("inimage.tif");
    Mat shadow = imread("shadow.tif");
    imshow("inimage" , inimage);
    imshow("shadow" , shadow);
    int rows =inimage.rows;
    int cols =inimage.cols;
    CvScalar Average,R;
    Mat dst;
    dst.create(rows, cols, inimage.type());
    for(int i = 0; i < rows; i ++)
    {
        for(int j = 0; j < cols; j ++)
        {
            Average.val[0] = shadow.at<Vec3b>(i,j)[0]/255;
            Average.val[1] = shadow.at<Vec3b>(i,j)[1]/255;
            Average.val[2] = shadow.at<Vec3b>(i,j)[2]/255;
            R.val[0] = inimage.at<Vec3b>(i,j)[0]*Average.val[0];
            R.val[1] = inimage.at<Vec3b>(i,j)[1]*Average.val[1];
            R.val[2] = inimage.at<Vec3b>(i,j)[2]*Average.val[2];
            dst.at<Vec3b>(i,j)[0] = (int)R.val[0];
            dst.at<Vec3b>(i,j)[1] = (int)R.val[1];
            dst.at<Vec3b>(i,j)[2] = (int)R.val[2];
        }
    }
    imshow("result",dst);
    imwrite("result.jpg",dst);
    waitKey(0);
    return 0;
}