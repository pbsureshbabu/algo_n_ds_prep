#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main() 
{
	Mat image = Mat(200, 400, CV_8UC3, Scalar(255, 255, 255));
	Point text_position(5, 100);
	int font_size = 1;
	Scalar font_color(0, 0, 0);
	int font_weight = 2;
	putText(image, "Suresh Here", text_position, FONT_HERSHEY_SIMPLEX, font_size, font_color, font_weight);
	imshow("Image", image);
	waitKey(0);

	return 0;
}