#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg = imread("image.jpg");
	Mat blrimg;

	blur(orgimg, blrimg, Size(3, 3));	// Size(9,9) -> blur filtresinin boyutu arttikca, orgimg daha fazla bulaniklasir

	imshow("original image", orgimg);
	imshow("blur image", blrimg);

	waitKey(0);
	return 0;
}