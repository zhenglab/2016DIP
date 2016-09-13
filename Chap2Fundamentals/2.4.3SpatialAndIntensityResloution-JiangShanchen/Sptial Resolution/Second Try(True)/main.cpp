#include <iostream>
#include <math.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
using namespace cv;
using namespace std;
int main(){
    Mat primage =imread("ddd.jpg");
    imshow("origin", primage);
    Mat newimage;
    int a[3]={4,8,16};
    int nr = primage.rows;
    int nc = primage.cols;
    for (int i=0; i<3; i++) {
        int m =nr/a[i];
        int n  =nc/a[i];
        newimage.create(m,n,primage.type());
        CvScalar sum,avg;
        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                sum =0;
                for (int l=a[i]*x; l<a[i]*(x+1);l++) {
                    for (int k=a[i]*y; k<a[i]*(y+1);k++) {
                        sum.val[0]=sum.val[0]+primage.at<Vec3b>(l,k)[0];
                        sum.val[1]=sum.val[1]+primage.at<Vec3b>(l,k)[1];
                        sum.val[2]=sum.val[2]+primage.at<Vec3b>(l,k)[2];
                    }
                }
                newimage.at<Vec3b>(x,y)[0]=sum.val[0]/(a[i]*a[i]);
                newimage.at<Vec3b>(x,y)[1]=sum.val[1]/(a[i]*a[i]);
                newimage.at<Vec3b>(x,y)[2]=sum.val[2]/(a[i]*a[i]);
            }
        }
        String str[3] = {"300dpi.jpg","150dpi.jpg","72dpi.jpg"};
        imshow(str[i],newimage);
        imwrite(str[i],newimage);
    }
    
    waitKey(0);
    return 0;
}