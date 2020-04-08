#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat img;

// func() parametreleri her seferinde mouse bilgilerini okumak icin sart parametrelerdir
void func(int event, int x, int y, int flags, void* userdata )	 // islem etiketi, x, y kordinat bilgisi
{
	// events -> EVENT_MOUSEMOVE (imlec), EVENT_RBUTTONDOWN (sag tus tik), EVENT_LBUTTONDOWN (sol tus tik), EVENT_MBUTTONDOWN (roll ) 
	
	if (event == EVENT_MOUSEMOVE)
	{
		int blue = img.at<Vec3b>(y, x)[0];
		int green = img.at<Vec3b>(y, x)[1];
		int red = img.at<Vec3b>(y, x)[2];

		cout << "Blue: " << blue << " Green: " << green << " Red: " << red << " Cols: " << x << " Rows: " << y << endl;

	}
	
}
int main()
{
	img = imread("image.jpg");

	namedWindow("Window", 1);

	setMouseCallback("Window", func, NULL);		// Window pencerindeki mouse bilgilerini func fonksiyonuna aktar 

	imshow("Window", img);
	
	waitKey(0);
	destroyWindow("Window");
	return 0;
}