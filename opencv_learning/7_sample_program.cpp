#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char **argv)
{
	Mat image_blue(200, 200, CV_8UC3, Scalar(255, 0, 0)); // creating an image matrix w/ 3 channels and initing w/ default values.
	Mat image_green(200, 200, CV_8UC3, Scalar(0,255,0)); // same as above
	Mat image_red(200,200,CV_8UC3, Scalar(0,0,255)); // same as above
	Mat image_combination(200,200,CV_8UC3, Scalar(140,90,100)); // having a certain combination

	// creating the frames to display the images
	namedWindow("blue", CV_WINDOW_AUTOSIZE);
	namedWindow("green", CV_WINDOW_AUTOSIZE);
	namedWindow("red", CV_WINDOW_AUTOSIZE);
	namedWindow("combination", CV_WINDOW_AUTOSIZE);

	// showing those frames
	imshow("blue", image_blue);
	imshow("green", image_green);
	imshow("red", image_red);
	imshow("combination", image_combination);
	
	waitKey(0);
	return 0;
}