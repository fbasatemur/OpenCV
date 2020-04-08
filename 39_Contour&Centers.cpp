#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int LowH = 0, HighH = 50, LowS = 150, HighS = 255, LowV =101, HighV = 255;		// sari renk icin tahmini uygun degerler
Mat  video, hsvimg, isimg;


int main()
{
	VideoCapture vid("video.mp4");
	bool frame;

	while(true)
	{
		frame = vid.read(video);
		
		if (waitKey(30) == 27 || frame == 0)
		{
			destroyAllWindows();
			break;
		}

		imshow("video", video);							// matrise okunani ekrana yansit

		cvtColor(video, hsvimg, COLOR_BGR2HSV);					// hsv format donustur

		inRange(hsvimg, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), isimg);	// Low - High arasindaki degerleri 1 yap -> isimg 

		// erode ve dilate islemleri ile gurultulerden kurtul

		erode(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));
		dilate(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));

		dilate(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));
		erode(isimg, isimg, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));

		vector<vector<Point>>contours;
		vector<Vec4i>hierarchy;

		findContours(isimg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

		vector<Moments>mu(contours.size());

		for (int i = 0; i < contours.size(); i++)
			mu[i] = moments(contours[i]);


		vector<Point2f>mc(contours.size());

		// resim uzerinde tespit edilen nesnelerin merkezleri ve conturlari bul
		for (int i = 0; i < contours.size(); i++)
		{
			float mcenterx = mu[i].m10 / mu[i].m00;		// satir agirliklerini alana bol ve x merkezini bul
			float mcentery = mu[i].m01 / mu[i].m00;		// sutun agirliklarini alana bol ve y merkezini bul
			mc[i] = Point2f((mcenterx), (mcentery));

			drawContours(video, contours, i, Scalar(0, 255, 0), 2, 8);			// contour lari ciz
			circle(video, Point(mcenterx, mcentery), 3, Scalar(0, 0, 255), 3, LINE_AA, 0);	// merkezlerini isaretle
		}

		imshow("frame", video);
	}
	
	waitKey(0);
	return 0;
}