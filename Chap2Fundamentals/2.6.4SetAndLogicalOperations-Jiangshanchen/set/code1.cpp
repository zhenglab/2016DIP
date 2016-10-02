#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat inimage = imread("/Users/jiangshanchen/DIP/2.6.4SetAndLogicalOperations-Jiangshanchen/inimage.jpg");
    imshow("inimage" , inimage);
    int rows =inimage.rows;
    int cols =inimage.cols;
    Mat dst,sumimage,fin;
    Scalar sum,mul;
    dst.create(rows, cols, inimage.type());
    sumimage.create(rows, cols, inimage.type());
    fin.create(rows, cols, inimage.type());
    for(int i = 0; i < rows; i ++)
    {
        for(int j = 0; j < cols; j ++)
        {
            dst.at<Vec3b>(i,j)[0] =256-1-inimage.at<Vec3b>(i,j)[0];
            dst.at<Vec3b>(i,j)[1] =256-1-inimage.at<Vec3b>(i,j)[1];
            dst.at<Vec3b>(i,j)[2] =256-1-inimage.at<Vec3b>(i,j)[2];
        }
    }
    imshow("result",dst);
    imwrite("result.jpg",dst);
    for (int k=0; k<rows; k++) {
        for (int l =0; l<cols; l++) {
            sum.val[0]+=inimage.at<Vec3b>(k,l)[0];
            sum.val[1]+=inimage.at<Vec3b>(k,l)[1];
            sum.val[2]+=inimage.at<Vec3b>(k,l)[2];
            sumimage.at<Vec3b>(k,l)[0]=3*sum.val[0]/(rows*cols);
            sumimage.at<Vec3b>(k,l)[1]=3*sum.val[1]/(rows*cols);
            sumimage.at<Vec3b>(k,l)[2]=3*sum.val[2]/(rows*cols);
            if (dst.at<Vec3b>(k,l)[0]>sumimage.at<Vec3b>(k,l)[0])
                fin.at<Vec3b>(k,l)[0]=inimage.at<Vec3b>(k,l)[0];
            else fin.at<Vec3b>(k,l)[0]=sum.val[0];
            if (dst.at<Vec3b>(k,l)[1]>sumimage.at<Vec3b>(k,l)[1])
                fin.at<Vec3b>(k,l)[1]=inimage.at<Vec3b>(k,l)[1];
            else fin.at<Vec3b>(k,l)[1]=sum.val[1];
            if (dst.at<Vec3b>(k,l)[2]>sumimage.at<Vec3b>(k,l)[2])
                fin.at<Vec3b>(k,l)[2]=inimage.at<Vec3b>(k,l)[2];
            else fin.at<Vec3b>(k,l)[2]=sum.val[2];
        }
    }
    imshow("result2",sumimage);
    imwrite("result2.jpg",sumimage);
    imshow("result3", fin);
    imwrite("result3.jpg", fin);
    waitKey(0);
    return 0;
}