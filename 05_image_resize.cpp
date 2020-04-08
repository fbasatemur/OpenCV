#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat newsize;			// resize sonucu olusan resim icin
	Mat image1, image2;		// resim 1 ve 2

	image1 = imread("image1.jpg");
	image2 = imread("image2.jpg");

	// image2 yi, image1 boyutuna olcekleyelim
	resize(image2, newsize, Size(image1.cols, image1.rows));	

	namedWindow("image1", WINDOW_AUTOSIZE);
	namedWindow("image2", WINDOW_AUTOSIZE);
	namedWindow("newsize",WINDOW_AUTOSIZE);

	// ekrana yansit
	imshow("image1",image1);
	imshow("image2",image2);
	imshow("newsize",newsize);

	waitKey(0);		// ekrani beklet

	destroyAllWindows();		
	
	return 0;
}