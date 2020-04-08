#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int LowH = 0, HighH = 179, LowS = 0, HighS = 255, LowV = 5, HighV = 255;		// kirmizi renk icin uygun degerler
Mat  orgimg, hsvimg, isimg;


int main()
{
	orgimg = imread("image.jpg");

	resize(orgimg, orgimg, Size(600, 600));
	imshow("original image", orgimg);							

	cvtColor(orgimg, hsvimg, COLOR_BGR2HSV);				// hsv format donustur

	inRange(hsvimg, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), isimg);		// Low - High arasindaki degerleri 1 yap -> isimg 

	// erode ve dilate islemleri ile gurultulerden kurtul

	erode(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));
	dilate(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));

	dilate(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));
	erode(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));

	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;

	findContours(isimg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));		// counturlari bul

	vector<Moments>mu(contours.size());			// countur momentleri icin

	for (int i = 0; i < contours.size(); i++)
		mu[i] = moments(contours[i]);

	vector<Point2f>mc(contours.size());

	// resim uzerinde tespit edilen nesnelerin merkezleri
	for (int i = 0; i < contours.size(); i++)
	{
		float mcenterx = mu[i].m10 / mu[i].m00;		// satir agirliklerini alana bol ve x merkezini bul
		float mcentery = mu[i].m01 / mu[i].m00;		// sutun agirliklarini alana bol ve y merkezini bul
		mc[i] = Point2f((mcenterx), (mcentery));

		circle(orgimg, Point(mcenterx, mcentery), 3, Scalar(0, 255, 255), 3, LINE_AA, 0);	// nokta isaretle
	}

	float orta = ( mu[0].m10 / mu[0].m00 + mu[1].m10 / mu[1].m00) / 2;
	circle(orgimg, Point( orta, 200), 3, Scalar(100, 255, 0), 3, LINE_AA, 0);

	circle(orgimg, Point(300, 300), 3, Scalar(255, 255, 0), 3, LINE_AA, 0);

	imshow("orgimg", orgimg);
	

	waitKey(0);
	return 0;
}