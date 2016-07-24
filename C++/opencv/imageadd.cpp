int main() {

	Mat image1 = imread("test.jpg", IMREAD_COLOR);
	Mat image2 = imread("test1.jpg", IMREAD_COLOR);
	Mat result;
	double alpha = 0.3;
	double beta = 1 - alpha;
	//g(x)=(1−α)f0(x)+αf1(x)
	addWeighted(image1, alpha, image2, beta, 0.0, result);


	namedWindow("result", WINDOW_AUTOSIZE);
	imshow("result", result);
	waitKey(0);

}
