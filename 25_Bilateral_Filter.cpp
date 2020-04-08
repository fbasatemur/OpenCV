#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// Bileteral Filter -> Kenar korumasi yaparak duzlestirir bu da gauss filter gore daha iyi duzlestirme yaptigini gosterir.

int main()
{
	Mat blt;	// bilateral matrix
	Mat gss;	// gauss matrix
	Mat orgimg = imread("image.jpg");

	bilateralFilter(orgimg, blt, 15, 100,100);		
	GaussianBlur(orgimg, gss, Size(35, 35), 1);		// Gauss filtresi de kullanilarak aradaki farka bakalim

	imshow("original image", orgimg);
	imshow("bilateral filter image", blt);
	imshow("gaussian blue image", gss);

	waitKey(0);
	return 0;
}
