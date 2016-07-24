#include <opencv/cv.hpp>
#include <opencv/cxcore.hpp>
#include <opencv/highgui.h>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;


int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;
Mat src; Mat dst;
char window_name[] = "Filter Demo 1";
int display_dst(int delay)
{
	imshow(window_name, dst);
	int c = waitKey(delay);
	if (c >= 0) { return -1; }
	return 0;
}
int display_caption(char *caption) {
	dst = Mat::zeros(src.size(), src.type());
	putText(dst,caption,Point(src.cols/4,src.rows/2),
		FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
	imshow(window_name, dst);
	int c = waitKey(1500);
	if (c >= 0) { return -1; }
	return 0;
}
int main() {
	namedWindow(window_name, WINDOW_AUTOSIZE);
	cvNamedWindow(window_name, WINDOW_AUTOSIZE);
	src = imread("test.jpg", IMREAD_COLOR);
	if (display_caption("Orignal image")!= 0) return 0;

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		blur(src, dst, Size(i, i), Point(-1,-1));
		display_dst(DELAY_BLUR);
	}
	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		if (display_dst(DELAY_BLUR) != 0) { return 0; }
	}

	for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
	{
		medianBlur(src, dst, i);
		if (display_dst(DELAY_BLUR) != 0) { return 0; }
	}


}

//blur GaussianBlur  medianBlur bilateralFilter

/*
가우시안 필터:
- 잡음(Gaussian noise)를 제거하기 위한 저주파 필터 (Low-pass filter)
- 임펄스 잡음(0, 255)을 제거하는데 부적합

미디언 필터:
- 강한 엣지를 보존하고 기존의 엣지들을 좀더 상세하게 보존
- 매우 뚜렷한 밝기를 가진 점들이 이웃한 화소들과 유사하도록 만들어 돌출되는 화소값을 제거
출처  :http://forum.falinux.com/zbxe/index.php?document_srl=549330&mid=lecture_tip
*/