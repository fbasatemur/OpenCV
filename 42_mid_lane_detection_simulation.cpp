#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int LowH = 0, LowS = 0, LowV = 5, HighH = 179, HighS = 255, HighV = 255;
float mcenterx = 0.0, mcentery = 0.0;
int trackvalue = 0;
float intgral = 0.0, lasterror = 0.0;
Mat orgimg, hsvimg, dst;

void track(int , void *)
{
	orgimg = imread("image.jpg");
	resize(orgimg, orgimg, Size(600, 600));

	int x = 0, y = trackvalue * 5;

	Rect crop;	// Kirpma icin dikdorgen

	crop.x = x;
	crop.y = y;
	
	crop.width = 600;
	crop.height = 100;
	Mat cropimg = orgimg(crop);
	imshow("image", cropimg);
	
	cvtColor(cropimg, hsvimg, COLOR_BGR2HSV);
	inRange(hsvimg, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), dst);

	erode(dst, dst, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	dilate(dst, dst, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	dilate(dst, dst, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	erode(dst, dst, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(dst,contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<Moments> mu(contours.size());
	
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i]);
	}

	vector<Point2f> mc(contours.size());
	cout << contours.size() << endl;
	for (int i = 0; i < contours.size(); i++)
	{
		mcenterx = mu[i].m10 / mu[i].m00;
		mcentery = mu[i].m01 / mu[i].m00;
		mc[i] = Point2f((mcenterx), (mcentery));
		
		circle(cropimg, Point(mcenterx, mcentery), 3, Scalar(0, 255, 0), 3, LINE_AA, 0);
	}
	
	float middle = (mu[1].m10 / mu[1].m00 + mu[0].m10 / mu[0].m00) / 2;
	
	circle(cropimg, Point(middle, 50), 3, Scalar(100, 255, 0), 3, LINE_AA, 0 );
	
	circle(orgimg, Point(300, 50 + trackvalue), 3, Scalar(255, 255, 0), 3, LINE_AA, 0);

	// pld algorithm
	float error = 300 - middle;
	intgral += error;
	float pidvalue = 0.3 * error + 0.5 * intgral + 0.3 * (error - lasterror);
	lasterror = error;

	cout << "pid value:" << pidvalue << endl;
	imshow("image2", cropimg);
}
int main()
{
	orgimg = imread("image.jpg");
	resize(orgimg, orgimg, Size(600, 600));

	imshow("orginal image", orgimg);

	namedWindow("Trackbar", WINDOW_AUTOSIZE);
	createTrackbar("vol", "Trackbar", &trackvalue, 100, track);


	waitKey(0);
	return 0;
}