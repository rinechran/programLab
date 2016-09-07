#include <opencv2/core.hpp>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <random>
#include <tuple>
#include <chrono>
using namespace cv;
using namespace std;

tuple<int, int> randPosition(cv::Mat &image) {
	std::mt19937 ex(chrono::system_clock::now().time_since_epoch().count());
	int cols = ex() % image.cols;
	int rows = ex() % image.rows;
	std::cout << ex();
	return std::tie(rows, cols);

}
void saltImage(cv::Mat &image, int n) {
	for (int i = 0;i < n;i++) {

		auto rowcols = randPosition(image);
		switch (image.channels())
		{
		case 1:
			image.at<uchar>(std::get<0>(rowcols), std::get<1>(rowcols)) = 255;
			break;
		case 3:
			image.at<cv::Vec3b>(std::get<0>(rowcols), std::get<1>(rowcols))[0] = 100;
			image.at<cv::Vec3b>(std::get<0>(rowcols), std::get<1>(rowcols))[1] = 100;
			image.at<cv::Vec3b>(std::get<0>(rowcols), std::get<1>(rowcols))[2] = 100;
			break;
		default:
			break;
		}
	}

}

int main() {


	Mat image1 = imread("test.jpg", IMREAD_COLOR);


	if (image1.empty())
		return 0;
	saltImage(image1, 1000);
	namedWindow("windows", WINDOW_AUTOSIZE);
	imshow("windows", image1);
	waitKey(0);
	return 0;

}