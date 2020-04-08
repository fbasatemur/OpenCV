#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat image(600,900,CV_8UC3,Scalar(255, 0, 0));		// height, width, 8 bits of 3 layers, Scalar(BLUE, GREEN, RED)

	// matrix, Text , baslangic noktasi, yazi fontu, boyutu, renk, kalinlik
	putText(image, "Text", Point(100, 100), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 255, 0), 5);

	imshow("image", image);
	
	waitKey(0);
	return 0;
}