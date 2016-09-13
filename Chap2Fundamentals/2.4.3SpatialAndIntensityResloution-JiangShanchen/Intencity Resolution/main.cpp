//
//  main.cpp
//  
//
//  Created by 姜善宸 on 16/9/13.
//
//

#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace cv;
using namespace std;
int main(){
    Mat primage =imread("kk.jpg");
    imshow("origin", primage);
    int a[7]={2,4,8,16,32,64,128};
    Mat newimage;
    newimage.create(primage.rows, primage.cols, primage.type());
    for (int b=0; b<7; b++) {
        int q =primage.rows;
        int w =primage.cols;
        for (int i =0; i<q; i++) {
            for (int j=0; j<w; j++) {
                newimage.at<Vec3b>(i,j)[0]=primage.at<Vec3b>(i,j)[0]/a[b];
                newimage.at<Vec3b>(i,j)[1]=primage.at<Vec3b>(i,j)[1]/a[b];
                newimage.at<Vec3b>(i,j)[2]=primage.at<Vec3b>(i,j)[2]/a[b];
            }
        }
        string str[7]={"k=7.jpg","k=6.jpg","k=5.jpg","k=4.jpg","k=3.jpg","k=2.jpg","k=1.jpg"};
        imshow(str[b],newimage);
        imwrite(str[b],newimage);
    }
    waitKey(0);
    return 0;
}
