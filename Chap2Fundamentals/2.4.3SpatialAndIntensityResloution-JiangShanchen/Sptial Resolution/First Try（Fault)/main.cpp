#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
using namespace cv;
using namespace std;
int main(){
    Mat primage =imread("ddd.jpg");
    imshow("origin", primage);
    int a[3]={4,8,16};
    int nr = primage.rows;
    int nc = primage.cols;
    for (int i=0; i<3; i++) {
        int m =nr/a[i];
        int n =nc/a[i];
        Mat newimage;
        newimage.create(m,n,primage.type());
        for (int z=0; z<m; z++) {
            for (int c=0; c<n; c++) {
                for (int r=z*a[i]; r<(z+1)*a[i]; r++) {
                    for (int p=c*a[i]; p<(c+1)*a[i]; p++){
                        newimage.at<Vec3b>(z,c)[0]=primage.at<Vec3b>(r,p)[0];
                        newimage.at<Vec3b>(z,c)[1]=primage.at<Vec3b>(r,p)[1];
                        newimage.at<Vec3b>(z,c)[2]=primage.at<Vec3b>(r,p)[2];
                    }
                }
            }
        }
        String str[3] = {"300dpi.jpg","150dpi.jpg","72dpi.jpg"};
        imshow(str[i],newimage);
        imwrite(str[i],newimage);
    }
    waitKey(0);
    return 0;
}