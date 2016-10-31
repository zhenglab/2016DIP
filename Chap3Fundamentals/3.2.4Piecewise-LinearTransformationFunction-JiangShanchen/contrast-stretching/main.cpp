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
    Mat inimage = imread("/Users/jiangshanchen/chapter3/contrast-stretching/Fig0310(b)(washed_out_pollen_image).tif");
    namedWindow("initial image");
    imshow("initial image" , inimage);
    int rows =inimage.rows;
    int cols = inimage.cols * inimage.channels();
    uchar *date;
    int date_max=0,date_min=255;
    for(int i = 0; i < rows; i++)
    {
        date=inimage.ptr<uchar>(i);
        for(int j = 0; j < cols; j++)
        {
            if (date[j]>date_max) date_max=date[j];
            if (date[j]<date_min) date_min=date[j];
        }
    }
    cout<<date_min<<endl<<date_max;
    for (int i=0; i<rows; i++) {
        date=inimage.ptr<uchar>(i);
        for (int j=0; j<cols; j++) {
            date[j]=(date[j]-date_min)*255/(date_max-date_min);
        }
    }
    namedWindow("handle image");
    imshow("handle image",inimage);
    imwrite("result_intensity_level.jpg", inimage);
    waitKey(0);
    return 0;
}
