
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;


void cartoonToImageGray(cv::Mat & src, cv::Mat & dst){
    cv::Mat gray;
    cvtColor(src, gray,  CV_RGB2GRAY);
    
    medianBlur(gray, gray, 7);
    Mat eages;
    
    Laplacian(gray, eages, CV_8U, 5);

    threshold(eages, dst, 80, 255, THRESH_BINARY_INV);
    
}

void cartoonToImageColor(cv::Mat & src, cv::Mat & dst){
    Size size = src.size();
    size.width = size.width/2;
    size.height = size.height/2;
    
    Mat samllImag = Mat(size,CV_8UC3);
    cv::resize(src, samllImag, size);
    
    cv::Mat tmp(samllImag.size(),CV_8UC3);
    for(int i = 0 ;i < 7 ;i++){
        int ksize = 9;
        bilateralFilter(samllImag, tmp, ksize, 9, 7);
        bilateralFilter(tmp, samllImag, ksize, 9, 7);

    }

    resize(samllImag,dst, src.size());
    
}
void face(cv::Mat & src, cv::Mat & dst){

}
int main( void )
{
    cv::VideoCapture camera;
    camera.open(0);
    
    if(!camera.isOpened()){
        std::cout<<"camera error"<<std::endl;
        return 0;
    }

    while(true){
        cv::Mat frame;
        camera >> frame;
        
        cv::Mat cartoom(frame.size(),CV_8UC3);
        
        cartoonToImageGray(frame,cartoom);
        //cartoonToImageColor(frame,cartoom);
        imshow("asdas", cartoom);
        waitKey(20);
    }
    
    return 0;
}
