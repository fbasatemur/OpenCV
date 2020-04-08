#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg(700, 700, CV_8UC3, Scalar(50, 50, 50));	// test icin goruntu olustur

	// input_matrix, baslangic nok, yaricap, renk, kalinlik, cizgi kalitesi, kayma
	circle(orgimg, Point(100, 100), 30, Scalar(0, 255, 0), 5, LINE_AA, 0);

	imshow("image", orgimg);
	waitKey(0);
	return 0;
}