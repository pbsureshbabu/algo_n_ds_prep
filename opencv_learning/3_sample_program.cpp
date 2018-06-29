#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat myImage[3]; // declaring array of 3 matrices
	string window1 = "photoFrame1";
	string window2 = "photoFrame2";
	string window3 = "photoFrame3";

	namedWindow( window1, CV_WINDOW_KEEPRATIO ); // creating a frame/window #1
	namedWindow( window2, CV_WINDOW_KEEPRATIO ); // creating a frame/window #2
	namedWindow( window3, CV_WINDOW_KEEPRATIO ); // creating a frame/window #3

	myImage[0] = imread( "C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_UNCHANGED ); // reading the image into matrix #1
	myImage[1] = imread( "C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_UNCHANGED ); // reading the image into matrix #2
	myImage[2] = imread( "C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_UNCHANGED ); // reading the image into matrix #3

	if (myImage[0].empty() || myImage[1].empty() || myImage[2].empty() ) // if any of the three matrices are empty; return w/ an error
	{
		cout << "Couldn't load the image" << endl;
		system("pause");
		return -1;
	}
	
	// show the contents of the matrices in the particular frame or window
	imshow( window1, myImage[0] );
	imshow( window2, myImage[1] );
	imshow( window3, myImage[2] );

	waitKey(0);
	
	// destroy all the three frames or windows
	destroyWindow( window1 );
	destroyWindow( window2 );
	destroyWindow( window3 );
	
	return 0;
}