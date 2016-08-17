#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include<opencv2/legacy/legacy.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(  )
{
    //【0】改变console字体颜色
    system("color 2F");


    //【1】载入素材图
    Mat srcImage1 = imread("1.jpg",1);
    Mat srcImage2 = imread("2.jpg",1);

    imshow("原始图1",srcImage1);
    imshow("原始图2",srcImage2);

    //【2】使用SURF算子检测关键点
    int minHessian = 400;//SURF算法中的hessian阈值
    SurfFeatureDetector detector(minHessian);//定义一个SurfFeatureDetector（SURF） 特征检测类对象

    std::vector<KeyPoint> keypoints1, keypoints2;//vector模板类，存放任意类型的动态数组

    //【3】调用detect函数检测出SURF特征关键点，保存在vector容器中
    detector.detect( srcImage1, keypoints1 );
    detector.detect( srcImage2, keypoints2 );


    Mat imgkeypoints1; Mat imgkeypoints2;
    drawKeypoints( srcImage1, keypoints1, imgkeypoints1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    drawKeypoints( srcImage2, keypoints2, imgkeypoints2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );


    imshow("特征点检测效果图1", imgkeypoints1 );
    imshow("特征点检测效果图2", imgkeypoints2 );

    waitKey(0);
    return 0;
}

