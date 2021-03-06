#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat orgimg, hsvimg, isimg;
	orgimg = imread("image.jpg");

	cvtColor(orgimg, hsvimg, COLOR_BGR2HSV);

	inRange(hsvimg, Scalar(0, 0, 0), Scalar(0, 0, 0), isimg);

	erode(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));
	dilate(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));

	dilate(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));
	erode(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));
	
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;

	findContours(isimg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<Moments>mu(contours.size());

	for (int i=0; i< contours.size(); i++)
		mu[i] = moments(contours[i]);
	

	vector<Point2f>mc(contours.size());

	// resim uzerinde tespit edilen nesnelerin merkezleri
	for (int i=0; i< contours.size(); i++)
	{
		float mcenterx = mu[i].m10 / mu[i].m00;		// x noktasini alana bol ve x merkezini bul
		float mcentery = mu[i].m01 / mu[i].m00;		// y noktasini alana bol ve y merkezini bul
		mc[i] = Point2f((mcenterx), (mcentery));

		cout << "Area: " << mu[i].m00<< endl<< "center x coord: "<< mcenterx << endl << "center y coord:"<< mcentery <<endl;
	}

	imshow("image", isimg);
	waitKey(0);
	return 0;
}