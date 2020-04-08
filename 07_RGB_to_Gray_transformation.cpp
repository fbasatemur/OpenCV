#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat orgimg = imread("image.jpg");
	Mat grayimg;					// for gray image

	cvtColor(orgimg, grayimg, COLOR_BGR2GRAY);	// color transformation

	imshow("BGR to Gray ", grayimg);
	waitKey(0);
	
	
	return 0;
}