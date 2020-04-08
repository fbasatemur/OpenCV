#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg, dst, cdst;
	orgimg = imread("image.jpg");
	
	// HoughLines ile cizgi tespitini yapmadan once orgimg Canny ile kenar tespiti yapilmali
	Canny(orgimg, dst, 50, 100, 3);

	cvtColor(dst, cdst, COLOR_GRAY2BGR);			// gray to color image 

	vector<Vec2f> lines;					// 2 Boyutlu float vector kordinatlar icin

	HoughLines(dst, lines, 1, CV_PI / 180, 300);		// input color image, kordinatlar icin, pixel uzakliklari, 360 der tarama( CV_PI/180 ), esik degeri

	for (size_t i = 0; i< lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;

		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));

		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3);	// pt1 den pt2 ye 3 kalinlikli 0,0,255 -> kirmizi cizgiyi csdt matrisine uygula
	}

	imshow("orginal image", orgimg);
	imshow("color image", cdst);

	waitKey(0);
	return 0;
}