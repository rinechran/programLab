//example imageVlaue(image, Matcopy, [](const uchar &input) {return input*1.7;});
template <typename T>
void imageVlaue(const Mat &input, Mat  &ouput, T fn) {
	int channels = input.channels();
	ouput.create(input.rows, input.cols, input.type());

	int Rows = input.rows;
	int Cols = input.cols;
	for (int i = 0;i < Rows;i++) {
		for (int j = 0;j < Cols;j++) {
			ouput.at<uchar>(i,j) = saturate_cast<uchar>(fn(input.at<uchar>(i, j)));
		}
	}
}


// warning image1,image2 row.col equal
Mat imageCompose(const Mat &obj, Mat&obj2) {
	Mat result;
	result.create(obj.rows, obj.cols,obj.type());


	for (int i = 0;i < result.rows;i++) {
		for (int j = 0;j < result.rows;j++) {
			uchar val = saturate_cast<uchar>(obj.at<uchar>(i, j) + obj2.at<uchar>(i, j));
			result.at<uchar>(i, j) = val;
		}
	}
	return result;

}
Mat imageDiff(const Mat &obj, Mat&obj2) {
	Mat result;
	result.create(obj.rows, obj.cols, obj.type());


	for (int i = 0;i < result.rows;i++) {
		for (int j = 0;j < result.rows;j++) {
			uchar val = saturate_cast<uchar>(obj.at<uchar>(i, j) - obj2.at<uchar>(i, j));
			result.at<uchar>(i, j) = abs(val);
		}
	}
	return result;

}