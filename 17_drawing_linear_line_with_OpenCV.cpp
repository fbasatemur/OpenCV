#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg = imread("image.jpg");

	// imput_matrix, baslangic noktasi, bitis noktasi, cizgi rengi, kalinlik, cizgi kalitesi, kayma miktari
	line(orgimg, Point(200, 200), Point(300,300), Scalar(255,0,0), 5, CV_AVX, 0 );

	imshow("image", orgimg);
	waitKey(0);
	return 0;
}