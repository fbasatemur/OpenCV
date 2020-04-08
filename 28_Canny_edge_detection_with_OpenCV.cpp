#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// Canny Kenar Tespiti Filtresi -> Laplace Filtresinden farkli olarak Threshold degerlerine bagli sekilde kenarlara filtre uygular.

int main()
{
	Mat orgimg;
	orgimg = imread("image.jpg");

	imshow("original image", orgimg);

	cvtColor(orgimg, orgimg, COLOR_BGR2GRAY);

	Canny(orgimg, orgimg, 100, 300);	// input, output image, first threshold value , second threshold value

	imshow("canny filter image", orgimg);


	waitKey(0);
	return 0;
}
