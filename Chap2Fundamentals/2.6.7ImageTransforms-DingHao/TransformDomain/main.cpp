#include <iostream> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <time.h>

using namespace cv;
using namespace std;

void fft2(IplImage *src,IplImage *dst)
{
	IplImage *image_Re = 0,*image_Im = 0,*Fourier = 0;
	image_Re = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,1);//实部
	image_Im = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,1);//虚部
	Fourier = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,2);
	cvConvertScale(src,image_Re,1,0);
	cvZero(image_Im);
	cvMerge(image_Re,image_Im,0,0,Fourier);
	cvDFT(Fourier,dst,CV_DXT_FORWARD);
	cvReleaseImage(&image_Re);
	cvReleaseImage(&image_Im);
	cvReleaseImage(&Fourier);
}

void fft2shift(IplImage *src,IplImage *dst)
{
	IplImage *image_Re = 0,*image_Im = 0;
	int nRow,nCol,i,j,cy,cx;
	double scale,shift,tmp13,tmp24;
	image_Re = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,1);
	image_Im = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,1);
	cvSplit(src,image_Re,image_Im,0,0);
	cvPow(image_Re,image_Re,2.0);
	cvPow(image_Im,image_Im,2.0);
	cvAdd(image_Re,image_Im,image_Re);
	cvPow(image_Re,image_Re,0.5);
	cvAddS(image_Re,cvScalar(1.0),image_Re);
	cvLog(image_Re,image_Re);
	nRow = src -> height;
	nCol = src -> width;
	cx = nCol / 2;cy = nRow / 2;
 	for(j = 0;j < cy;j ++)
	{
		for(i = 0;i < cx;i ++)
		{
			tmp13 = CV_IMAGE_ELEM(image_Re,double,j,i);
			CV_IMAGE_ELEM(image_Re,double,j,i) = CV_IMAGE_ELEM(image_Re,double,j + cy,i + cx);
			CV_IMAGE_ELEM(image_Re,double,j + cy,i + cx) = tmp13;
			tmp24 = CV_IMAGE_ELEM(image_Re,double,j,i + cx);
			CV_IMAGE_ELEM(image_Re,double,j,i + cx) = CV_IMAGE_ELEM(image_Re,double,j + cy,i);
			CV_IMAGE_ELEM(image_Re,double,j + cy,i) = tmp24;
		}
	}
	double minVal = 0,maxVal = 0;
	cvMinMaxLoc(image_Re,&minVal,&maxVal);
	scale = 255 / (maxVal - minVal);
	shift = -minVal * scale;
	cvConvertScale(image_Re,dst,scale,shift);
	cvReleaseImage(&image_Re);
	cvReleaseImage(&image_Im);	
}

int main(int argc , char *argv[])
{
	//输入语句报错
	if(argc != 2)
	{
		cout << "Wrong arguments input" << endl;
		cout << "usage:" << endl;
		cout << "\t" << argv[0] << "Image name" << endl;
		exit(1);
	}
	//读入图像
	IplImage *src = cvLoadImage(argv[1],0);
	//创建图像
	IplImage *Fourier = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,2);
	IplImage *dst = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,2);
	IplImage *ImageRe = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,1);
	IplImage *ImageIm = cvCreateImage(cvGetSize(src),IPL_DEPTH_64F,1);
	IplImage *Image = cvCreateImage(cvGetSize(src),src -> depth,src -> nChannels);
	IplImage *ImageDst = cvCreateImage(cvGetSize(src),src -> depth,src -> nChannels);
	double m,M;
	double scale;
	double shift;
	//傅里叶
	fft2(src,Fourier);

	//相乘
	cvResize(Fourier,Fourier,CV_INTER_LINEAR);
	
	//反傅里叶
	fft2shift(Fourier,Image);
	cvNamedWindow("fourier",0);
	cvShowImage("fourier",Image);
	//画圆
	int nRow = src -> height;
	int nCol = src -> width;
	int cx = nCol / 2;
	int cy = nRow / 2;
	IplImage *img;
	CvPoint CircleCenter = cvPoint(cx,cy);
	int Radius = 80;
	CvScalar Color = CV_RGB(255,0,0);
	int Thickness = 3;
	int Shift = 0;
	img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
	cvThreshold(img,img,0,255,0);
	cvCircle(img,CircleCenter,Radius,0,Thickness,CV_AA,Shift);
	cvNamedWindow("circle",0);
	cvShowImage("circle",img);
	cvMul(Fourier,img,Fourier);

	cvDFT(Fourier,dst,CV_DXT_INV_SCALE);
	cvSplit(dst,ImageRe,ImageIm,0,0);
	cvNamedWindow("original",0);
	cvShowImage("original",src);
	cvPow(ImageRe,ImageRe,2);
	cvPow(ImageIm,ImageIm,2);
	cvAdd(ImageRe,ImageIm,ImageRe,NULL);
	cvPow(ImageRe,ImageRe,0.5);
	cvMinMaxLoc(ImageRe,&m,&M,NULL,NULL);
	scale = 255 / (M - m);
	shift = -m * scale;
	cvConvertScale(ImageRe,ImageDst,scale,shift);

	//显示
	cvNamedWindow("back",0);
	cvShowImage("back",ImageDst);

	waitKey(0);    
	return 0;    
}  

