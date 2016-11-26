#include <opencv2/opencv.hpp>
#include <iostream>


int main( int argc, char** argv )
{
      using namespace cv;
       
          Mat src1, src2, dst;

              
              src1 = imread("/Users/rinechran/Xcode/Project/opencv C++/1.jpg");

                  namedWindow("Linear Blend", 1);

                      imshow( "Linear Blend", src1 );
                          waitKey(0);
                              return 0;
}
