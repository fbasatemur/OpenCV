#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg, negimg;
	orgimg = imread("image.jpg");

	// orgimg matrisinin tum degerleri bitwise logic not islevi ile negative matris elde edilir
	bitwise_not(orgimg, negimg);

	imshow("original image", orgimg);
	imshow("negative image", negimg);
	waitKey(0);
	return 0;
}