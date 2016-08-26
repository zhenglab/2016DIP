#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{

    Mat srcimage1 = imread("11.tif");
    
    imshow("Original", srcimage1);

    imwrite("original.jpg", srcimage1);
    
    Mat srcimage2 = imread("22.tif");
    
    imshow("yinying", srcimage2);

    imwrite("yinying.jpg", srcimage2);
     Mat dstimage;

    dstimage.create(srcimage1.rows,srcimage2.cols,srcimage1.type());

       int r1 = srcimage1.rows;

       int c1 = srcimage1.cols;
       int r2= srcimage2.rows;

       int c2 = srcimage2.cols;
    if(srcimage1.cols==srcimage1.rows)
     {

      

       for(int k = 0;k < r1;k ++)
       {
       
        for(int w =0;w < c1;w ++)
         {
           for(int i = 0;i < r2;i ++)
           {
       
             for(int j =0;j < c2;j ++)
             {
             
            dstimage.at<Vec3b>(k,j)[0] = srcimage1.at<Vec3b>(k,w)[0]*srcimage2.at<Vec3b>(i,j)[0];
         
            dstimage.at<Vec3b>(k,j)[1] = srcimage1.at<Vec3b>(k,w)[1]*srcimage2.at<Vec3b>(i,j)[1];

            dstimage.at<Vec3b>(k,j)[2] = srcimage1.at<Vec3b>(k,w)[2]*srcimage2.at<Vec3b>(i,j)[2];


             }
            }       
          }
        }
      }
     else if(srcimage1.cols>=srcimage1.rows)
     {

        for(int k = 0;k < r1;k ++)
       {
       
        for(int w =c1-r2;w < c1;w ++)
         {
           for(int i = 0;i < r2;i ++)
           {
       
             for(int j =0;j < c2;j ++)
             {
             
            dstimage.at<Vec3b>(k,j)[0] = srcimage1.at<Vec3b>(k,w)[0]*srcimage2.at<Vec3b>(i,j)[0];
         
            dstimage.at<Vec3b>(k,j)[1] = srcimage1.at<Vec3b>(k,w)[1]*srcimage2.at<Vec3b>(i,j)[1];

            dstimage.at<Vec3b>(k,j)[2] = srcimage1.at<Vec3b>(k,w)[2]*srcimage2.at<Vec3b>(i,j)[2];


             }
            }       
          }
        }

      }
     else 
     {

        for(int k = 0;k < r1;k ++)
       {
       
        for(int w =0;w < c1;w ++)
         {
           for(int i = r2-c1;i < r2;i ++)
           {
       
             for(int j =0;j < c2;j ++)
             {
             
            dstimage.at<Vec3b>(k,j)[0] = srcimage1.at<Vec3b>(k,w)[0]*srcimage2.at<Vec3b>(i,j)[0];
         
            dstimage.at<Vec3b>(k,j)[1] = srcimage1.at<Vec3b>(k,w)[1]*srcimage2.at<Vec3b>(i,j)[1];

            dstimage.at<Vec3b>(k,j)[2] = srcimage1.at<Vec3b>(k,w)[2]*srcimage2.at<Vec3b>(i,j)[2];


             }
            }       
          }
        }

      }
       
      imshow("xiaoguotu", dstimage);

      imwrite("xiaoguotu.jpg", dstimage);

      waitKey(0);

      return 0;
}
