#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg, gryimg;
	orgimg = imread("image.jpg");

	cvtColor(orgimg, gryimg, COLOR_BGR2GRAY);		// BGR to gray

	// Gauss Filter uygula
	GaussianBlur(gryimg, gryimg, Size(3, 3), 2, 2);
    
	vector<Vec3f> circles;						// 3 boyutlu float daire kordinat vektoru

	HoughCircles(gryimg, circles, HOUGH_GRADIENT, 1, gryimg.rows / 8, 90, 90);	// son 2 parametrenin degistilmesi daire tespitini ayarlar

	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(orgimg, center, 1, Scalar(0, 255, 0), -1, 8, 0);			// original image uzerine cember ciz
		circle(orgimg, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}

	imshow("Hough Circle", orgimg);

	waitKey(0);
	return 0;
}

