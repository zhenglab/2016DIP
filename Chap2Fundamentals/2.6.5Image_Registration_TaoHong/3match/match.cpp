#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include<opencv2/legacy/legacy.hpp>
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{


//读取原始图片并显示
    Mat srcImage1 = imread("1.jpg",1);
    Mat srcImage2 = imread("2.jpg",1);
    imshow("原始图1",srcImage1);
    imshow("原始图2",srcImage2);
//SURF 相关点检测
    int minHessian = 300;//hessian阈值
    SURF detector(minHessian);//定义一个SurfFeatureDetector（SURF） 特征检测类对象
    std::vector<KeyPoint> keypoints1, keypoints2;//vector模板类，存放任意类型的动态数组
    //【3】调用detect函数检测出SURF特征关键点，保存在vector容器中
    detector.detect( srcImage1, keypoints1 );
    detector.detect( srcImage2, keypoints2 );
//计算特征向量

    SURF extractor;
    Mat descriptors1; Mat descriptors2;
    extractor.compute(srcImage1, keypoints1, descriptors1);
    extractor.compute(srcImage2, keypoints2, descriptors2);
//采用FLANN算法匹配描述向量

    FlannBasedMatcher matcher;
    std::vector< DMatch > matches;
    matcher.match(descriptors1,descriptors2,matches);
    double max_dist = 0;double min_dist = 100;
//关键点之间的最大最小值
    for(int i=0;i < descriptors1.rows;i++)
    {
    double dist=matches[i].distance;
    if(dist<min_dist) min_dist=dist;
    if(dist>max_dist) max_dist=dist;
    }
//输出距离信息
    printf(">最大距离（Max dist）: %f \n",max_dist);
    printf(">最小距离（Min dist）: %f \n",min_dist);
//存下符合条件的匹配结果
    std::vector<DMatch>good_matches;
    for(int i=0;i<descriptors1.rows;i++)
    {
    if(matches[i].distance<2*min_dist)
    {good_matches.push_back(matches[i]);}
    }
//绘制符合条件的匹配点
    Mat img_matches;
    drawMatches(srcImage1,keypoints1,srcImage2,keypoints2,good_matches,img_matches,Scalar::all(-1),Scalar::all(-1),vector<char>(),DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
//输出相关匹配点
    for(int i=0;i<good_matches.size();i++)
    {
    printf(">符合条件的匹配点[%d] 特征点1：--%d 特征点2：%d \n",i,good_matches[i].queryIdx,good_matches[i].trainIdx);
    }
    imshow("匹配效果图", img_matches);

    waitKey(0);
    return 0;
}

