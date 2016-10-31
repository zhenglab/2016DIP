#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat srcimage_1 = imread("/Users/jiangshanchen/2016DIP/Chap2Fundamentals/2.6.3ArithmeticOperations-Jiangshanchen/ArithmeticOperations/subtract/ang2.tif");
    Mat srcimage_2 = imread("/Users/jiangshanchen/2016DIP/Chap2Fundamentals/2.6.3ArithmeticOperations-Jiangshanchen/ArithmeticOperations/subtract/ang1.tif");
    imshow("Original_1", srcimage_1);
    imshow("Original_2", srcimage_2);
    Mat dstimage;
    dstimage.create(srcimage_1.rows,srcimage_1.cols,srcimage_1.type());
    int r = srcimage_1.rows;
    int c = srcimage_1.cols;
    for(int i = 0; i < r; i ++)
    {
        for(int j = 0; j < c; j ++)
        {
            dstimage.at<Vec3b>(i,j)[0]=srcimage_1.at<Vec3b>(i,j)[0]-srcimage_2.at<Vec3b>(i,j)[0];
            dstimage.at<Vec3b>(i,j)[1]=srcimage_1.at<Vec3b>(i,j)[1]-srcimage_2.at<Vec3b>(i,j)[1];
            dstimage.at<Vec3b>(i,j)[2]=srcimage_1.at<Vec3b>(i,j)[2]-srcimage_2.at<Vec3b>(i,j)[2];
            if(dstimage.at<Vec3b>(i,j)[0]<40)
                dstimage.at<Vec3b>(i,j)[0]=255;
            if(dstimage.at<Vec3b>(i,j)[1]<40)
                dstimage.at<Vec3b>(i,j)[1]=255;
            if(dstimage.at<Vec3b>(i,j)[2]<40)
                dstimage.at<Vec3b>(i,j)[2]=255;
        }
    }
    imshow("dstimage", dstimage);
    imwrite("sub.jpg", dstimage);
    waitKey(0);
    return 0;
}
