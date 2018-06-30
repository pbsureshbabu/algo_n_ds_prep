#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

int main(int argc, const char **argv)
{
	Mat myImage;
	Mat myImage_converted;

	namedWindow("actual_image", CV_WINDOW_AUTOSIZE);
	namedWindow("converted_image", CV_WINDOW_AUTOSIZE);

	myImage = imread("C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_UNCHANGED);
	cvtColor(myImage, myImage_converted, CV_RGB2GRAY);

	imshow("actual_image", myImage);
	imshow("converted_image", myImage_converted);

	waitKey(0);
	destroyAllWindows();
	return 0;
}