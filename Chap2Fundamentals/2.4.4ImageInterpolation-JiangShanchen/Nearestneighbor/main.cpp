#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
using namespace cv;
using namespace std;
int main(){
    Mat reimage =imread("ddd.jpg");
    imshow("reimage", reimage);
    Mat newimage;
    float cr =reimage.rows;
    float cl =reimage.cols;
    float f =1.5;
    float a =f*cr;
    float b =f*cl;
    newimage.create(a, b, reimage.type());
    for (int i =0; i<a; i++) {
        for (int j=0; j<b; j++) {
            int m , n ;
            float l = i/f;
            float k = j/f;
            m=(int) (l+0.5)>(int) (l)?(int) (l+1):(int) l;
            n=(int) (k+0.5)>(int) (k)?(int) (k+1):(int) k;//四舍五入
            newimage.at<Vec3b>(i,j)[0]=reimage.at<Vec3b>(m,n)[0];
            newimage.at<Vec3b>(i,j)[1]=reimage.at<Vec3b>(m,n)[1];
            newimage.at<Vec3b>(i,j)[2]=reimage.at<Vec3b>(m,n)[2];//赋值
        }
    }
    imshow("newimage", newimage);
    waitKey(0);
    return 0;
}
