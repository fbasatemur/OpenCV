#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

// Tophat -> yuvarlak kenar islemlerinde
// Gradient -> nesnenin ana hatlarinii belirtir ( Canny kenar tespiti ile karistirilmamali )
int main()
{
	Mat gradimg, topimg, tophat, gradient;

	gradimg = imread("gradient.jpg");
	imshow("gradient original", gradimg);

	topimg = imread("tophat.jpg");
	imshow("tophat original", topimg);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));			// Size filtre boyutu arttirlarak daha olcekli arama yapilabilir

	// Tophat Morphology
	morphologyEx(topimg, tophat, MORPH_TOPHAT, element, Point(-1, -1), 5);		// topimg de tophat morfolojisini 5 kez islemle( MORPH_TOPHAT ile)
	// son arguman olan islemleme miktari arttirilarak daha saglikli tarama yapilabilir.

	imshow("tophat", tophat);

	// Gradient Morphology
	morphologyEx(gradimg, gradient, MORPH_GRADIENT, element, Point(-1, -1), 3);

	imshow("gradient", gradient);
	waitKey(0);
	return 0;
}