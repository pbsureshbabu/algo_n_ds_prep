#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char **argv)
{
	Mat gray_image_0( 384, 384, CV_8UC1, Scalar(0) );
	Mat gray_image_100( 384, 384, CV_8UC1, Scalar(100) );
	Mat gray_image_255( 384, 384, CV_8UC1, Scalar(255) );

	namedWindow( "photo_gray_image_0", CV_WINDOW_KEEPRATIO );
	namedWindow( "photo_gray_image_100", CV_WINDOW_KEEPRATIO );
	namedWindow( "photo_gray_image_255", CV_WINDOW_KEEPRATIO );

	imshow( "photo_gray_image_0", gray_image_0 );
	imshow( "photo_gray_image_100", gray_image_100 );
	imshow( "photo_gray_image_255", gray_image_255 );

	waitKey(0);
	return 0;
}