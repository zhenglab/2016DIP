#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(int argc,char* argv[])
{
    double dstRow;
    double dstCol;

    Mat src = imread("1.jpg");
    imshow("src",src);
    waitKey(0);


    cout<<"the srcImage size is:"<<endl<<src.rows<<endl<<src.cols<<endl;
    cout<<"please input the dstImage size"<<endl;
    cin>>dstRow>>dstCol;

    int row = src.rows;
    int col = src.cols;

    //最近邻内插法

    Mat dst=Mat::zeros(dstRow,dstCol,CV_8UC3);
    for(int i=0;i<dstRow;i++){
        for(int j=0;j<dstCol;j++){
                int x=cvRound(i*(row/dstRow));
                int y=cvRound(j*(col/dstCol));
                if(x >= 0 &&x <= row && y >=0 &&y <= col){
                    dst.at<cv::Vec3b>(i,j)[0]= src.at<cv::Vec3b>(x,y)[0];
                    dst.at<cv::Vec3b>(i,j)[1]= src.at<cv::Vec3b>(x,y)[1];
                    dst.at<cv::Vec3b>(i,j)[2]= src.at<cv::Vec3b>(x,y)[2];

                }
        }
    }

   imshow("nearest",dst) ;
   imwrite("nearest.jpg",dst);
   waitKey(0);
   cout<<"the dstImage size is:"<<endl<<dst.rows<<endl<<dst.cols<<endl;
   waitKey(0);
//双线性内插法
    float m=0;
    float n=0;
    CvScalar a,b,c,d;
    for(int i=0;i<dstRow-1;i++){
        for(int j=0;j<dstCol-1;j++){
                m=i*(double)(row/dstRow);
                n=j*(double)(col/dstCol);
                double ux=m-(int)m;
                double uy=n-(int)n;

                if(m >= 0 &&m <= row-1 && n >=0 &&n <= col-1){
                    a = src.at<cv::Vec3b>((int)m,(int)n);
                    b = src.at<cv::Vec3b>((int)m,(int)n+1)-src.at<cv::Vec3b>((int)m,(int)n);
                    c = src.at<cv::Vec3b>((int)m+1,(int)n)-src.at<cv::Vec3b>((int)m,(int)n);
                    d = src.at<cv::Vec3b>((int)m+1,(int)n+1)-src.at<cv::Vec3b>((int)m+1,(int)n)-src.at<cv::Vec3b>((int)m,(int)n+1)+src.at<cv::Vec3b>((int)m,(int)n);

                    b.val[0]=b.val[0]*uy;
                    b.val[1]=b.val[1]*uy;
                    b.val[2]=b.val[2]*uy;
                    c.val[0]=c.val[0]*ux;
                    c.val[1]=c.val[1]*ux;
                    c.val[2]=c.val[2]*ux;
                    d.val[0]=d.val[0]*ux*uy;
                    d.val[1]=d.val[1]*ux*uy;
                    d.val[2]=d.val[2]*ux*uy;
			}

				dst.at<cv::Vec3b>(i,j)[0]=(int)(a.val[0]+b.val[0]+c.val[0]+d.val[0]);
				dst.at<cv::Vec3b>(i,j)[1]=(int)(a.val[1]+b.val[1]+c.val[1]+d.val[1]);
				dst.at<cv::Vec3b>(i,j)[2]=(int)(a.val[2]+b.val[2]+c.val[2]+d.val[2]);

				//此段可防止图像失真，若失真，则如图bilinear1.jpg;
				if(a.val[0]+b.val[0]+c.val[0]+d.val[0] > 255){
                        dst.at<cv::Vec3b>(i,j)[0] = 255;
                }

                if(a.val[1]+b.val[1]+c.val[0]+d.val[1] > 255){
                   dst.at<cv::Vec3b>(i,j)[1] = 255;
                   }

                if(a.val[2]+b.val[2]+c.val[0]+d.val[2] > 255){
                        dst.at<cv::Vec3b>(i,j)[2] = 255;
                }

        }
    }
    imshow("bilinear",dst) ;
    imwrite("bilinear2.jpg",dst);
    waitKey(0);


}
