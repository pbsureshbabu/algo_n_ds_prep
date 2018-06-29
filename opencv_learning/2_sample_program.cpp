#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat myImage;
	namedWindow( "PhotoFrame", CV_WINDOW_AUTOSIZE );
	myImage = imread("C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_UNCHANGED );
	if (myImage.empty())
	{
		cout << "Couldn't load the image" << endl;
		system("pause");
		return -1;
	}

	imshow( "PhotoFrame", myImage );
	waitKey(0);
	destroyWindow("PhotoFrame");

	return 0;
}