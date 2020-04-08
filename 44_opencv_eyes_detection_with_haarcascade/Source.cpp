#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat frame, gry;
	VideoCapture cam(0);		
	namedWindow("Camera", WINDOW_AUTOSIZE); 
	
	CascadeClassifier data;				// haarcascade in yuklenecegi classifier
	data.load("haarcascade_eye.xml");		// haarcascade loaded 

	vector<Rect> dataVec;				// cascade yardimyla tespit edilen nesnelerin koordinat, en vs. bilgisini barindiracak
	
	while (true)
	{
		if (waitKey(30) == 27)
			break;

		cam >> frame;				// goruntuyu webcam den oku
		cvtColor(frame, gry, COLOR_BGR2GRAY);

		data.detectMultiScale(gry, dataVec, 1.1, 3, 0, Size(30, 30), Size(60, 60));		// object detection

		for (int i = 0; i< dataVec.size(); i++)
		{
			Point pt1(dataVec[i].x, dataVec[i].y);						// cizilecek dikdortgenn baslangic noktasi
			Point pt2(dataVec[i].x + dataVec[i].width, dataVec[i].y + dataVec[i].height);	// bitis noktasi
			rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);				// draw to rectangle
		}
		
		imshow("Camera", frame);

	}	

	waitKey(0);
	return 0;
}