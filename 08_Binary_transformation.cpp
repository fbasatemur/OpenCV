#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg, gryimg, bnryimg;
	orgimg= imread("image.jpg");
	
	// binary donusumu yapmadan once RGB resmi gray formata cevirmeliyiz
	cvtColor(orgimg, gryimg, COLOR_BGR2GRAY);

	// input_image, outpt_image, esik degeri(altini 0; ustunu 255), 0 ile 255 arasi (8 bit image icin) deger alabilir, THRESH_BINARY 
	threshold(gryimg, bnryimg, 100, 255, THRESH_BINARY);	

	imshow("gray image", gryimg);
	imshow("binary image",bnryimg);

	waitKey(0);
	return 0;
}