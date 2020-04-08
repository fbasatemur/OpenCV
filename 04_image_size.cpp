#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>


using namespace std;
using namespace cv;

int main()
{
	Mat image_matrise = imread("image.jpg");
	
	int image_column = image_matrise.cols;			// resim matrisinin sutun sayisi
	int image_row = image_matrise.rows;			// resim matrisinin satir sayisi
	cout << "Satir:" << image_row <<endl<< "Sutun:" << image_column <<endl;

	// pencere olusturarak okunan resme bakalim
	namedWindow("image");
	imshow("image", image_matrise);
	waitKey(0);
	destroyWindow("image");
	return 0;
}