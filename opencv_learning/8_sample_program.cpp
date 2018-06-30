#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	Mat image_load;
	image_load = imread("C:/Testing/lisa_384x384.jpg", CV_LOAD_IMAGE_UNCHANGED );
	int n_of_chs = image_load.channels();
	cout << n_of_chs << endl;

	system("pause");
	waitKey(0);
	return 0;
}