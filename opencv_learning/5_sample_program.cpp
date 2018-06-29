#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
 {
	Mat myImage;
	Mat myImage_gray;

	namedWindow( "PhotoFrame", CV_WINDOW_AUTOSIZE ); // declaring the frame/window to show the image
	namedWindow( "grayPhotoFrame", CV_WINDOW_AUTOSIZE ); // declaring another frame/window to show the gray image
	myImage = imread( "C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_UNCHANGED ); // loading the image into the matrix
	if (myImage.empty())
	 {
		cout << "Couldn't load the color image" << endl;
		system( "pause" );
		return -1;
	}
	myImage_gray = imread( "C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_GRAYSCALE ); // loading th gray scale image into the matrix
	if (myImage.empty())
	{
		cout << "Couldn't load the gray scale image" << endl;
		system( "pause" );
		return -1;
	}

	imshow( "PhotoFrame", myImage );
	imshow( "grayPhotoFrame", myImage_gray );

	waitKey(0);

	destroyWindow( "PhotoFrame" );
	destroyWindow( "grayPhotoFrame" );

	return 0;
}