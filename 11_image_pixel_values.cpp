#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{	
	
	Mat orgimg = imread("image.jpg");

	// renkli resmin pixel degerleri 
	// 3 ana rengin 100,120 (satir, sutun) lik kordinatlarda ki yogunluklari 

	int blue = orgimg.at<Vec3b>(100, 120)[0];		
	int green = orgimg.at<Vec3b>(100, 120)[1];
	int red = orgimg.at<Vec3b>(100, 120)[2];

	cout <<"Blue:"<< blue <<" Green:"<< green <<" Red:"<< red << endl;
	imshow("orgimg", orgimg);		// BGR image

	// gri rsmin pixel degerleri
	Mat gryimg;

	cvtColor(orgimg, gryimg, COLOR_BGR2GRAY);	// BGR to Gray transformation

	resize(gryimg, gryimg, Size(240,360));		// yeniden boyutlandir

	int black = gryimg.at<uchar>(100, 140);		// gri resim tek kanalli oldugundan (unsigned char) 100,140 kord renk bilgisi
	cout << "Gray image: " << black << endl;
	
	imshow("gray image", gryimg);			// Gray image 
	waitKey(0);

	return 0;
}