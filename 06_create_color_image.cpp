#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	// 3 kanalli yani BGR goruntu olustur
	Mat createimg(300, 300, CV_8UC3, Scalar(50, 20, 50));		// height, width, 3 kanalli 8 bits color, Scalar(Blue, Green, Red)

	namedWindow("create image");
	imshow("create image",createimg);

	waitKey(0);

	return 0;
}