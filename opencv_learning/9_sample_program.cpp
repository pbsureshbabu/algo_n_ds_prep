#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char **argv)
{
	Mat my_image;
	Mat different_channels[3];
	my_image = imread("C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_UNCHANGED);
	split(my_image, different_channels);

	//Mat b = different_channels[0];
	//Mat g = different_channels[1];
	//Mat r = different_channels[2];
	
	imshow("blue", different_channels[0]); // in the frame called blue, displaying the matrix object b
	imshow("green", different_channels[1]);
	imshow("red", different_channels[2]);
	imshow("actual_image", my_image);

	waitKey(0);
	destroyAllWindows(); // this closes all the opened frames
	return 0;
}