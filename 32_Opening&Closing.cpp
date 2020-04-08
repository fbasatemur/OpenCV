#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat orgimg, openi, closen;

int main()
{
	
	orgimg = imread("image.jpg");

	imshow(" image", orgimg);
	
	// getStructuringElement() -> Filtre boyutunu belirtir
	Mat element = getStructuringElement(MORPH_RECT, Size(5,5));		// Filtre boyutunu disaridan belirtelim
	
	// Opening
	morphologyEx(orgimg, openi, MORPH_OPEN, element,Point(-1, -1), 6);	// in , out ,open islemi, element matrix, nokta belirtmedik (-1,1), 4 kez erode - dilate yapicak

	imshow("open", openi);
	// Closing
	morphologyEx(orgimg, closen, MORPH_CLOSE, element, Point(-1, -1), 6);

	imshow("close", closen);

	waitKey(0);
	return 0;
}