#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>				// for face detection lib
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("face_image.jpg");
	resize(img, img, Size(800, 500));

	CascadeClassifier data;		
	data.load("haarcascade_frontalface_default.xml");		// .xml file is loaded

	Mat grayimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);

	vector<Rect> dataVec;		// rectangle vector is defined

	data.detectMultiScale(grayimg, dataVec, 1.1, 3, 0, Size(30, 30));		// gryimg uzerindeki nesneleri tespit eder ve dataVec e atar
	// 1.1 ve 3 parametreleri guncellenerek ( bi yere kadar ) daha iyi tespit islemi gerceklestirilebilir

	// tespit edilen nesnelerin etrafina dikdortgen cizelim
	for (int i = 0; i< dataVec.size(); i++)
	{
		Point pt1(dataVec[i].x, dataVec[i].y);						// start point
		Point pt2(dataVec[i].x + dataVec[i].width, dataVec[i].y + dataVec[i].height);   // finish point
		rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);							// rectangle draw
	}

	imshow("output image", img);

	waitKey(0);
	return 0;
}