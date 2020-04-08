#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// Dilation -> Resimde genisletme yapar 
// Tek kanlli yani S-B resimler uzerinde uygulanir.

int main()
{
	Mat orgimg, dst;

	orgimg = imread("image.jpg");
	resize(orgimg, orgimg, Size(200,300));

	dilate(orgimg, dst, getStructuringElement(MORPH_RECT, Size(10, 10)));		// Size degerleri dilation etkisini arttirir

	imshow("original image", orgimg);
	imshow("erode", dst);
	waitKey(0);

	return 0;
}