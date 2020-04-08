#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat orgimg = imread("image.jpg");
	Mat highimg, lowimg;				// yuksek ve dusuk kontrast matrisleri

	// convertTo -> matris donusturme fonksiyonudur.
	orgimg.convertTo(highimg, -1, 2, 0);		// output_matrix, resim cozunurlugunu koru(-1), pixel carpani, pixel ekleneni
	orgimg.convertTo(lowimg, -1, 0.2, 0);

	imshow("Original image", orgimg);
	imshow("High Contrast image", highimg);
	imshow("Low Contrast image", lowimg);

	waitKey(0);
	return 0;
}