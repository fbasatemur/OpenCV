#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>


using namespace std;
using namespace cv;

Mat img;
int counter = 0;		// 1. ve 2. tiklamayi saymasi icin
Point point1, point2;		// 1. ve 2. tiklama noktalari

// eylem (event), kordinat(x ve y), setMouseCallback icin gerekli flags ve userdata parametreleri
void func(int event, int x, int y, int flags, void * userdata)		
{
	
	if (event == EVENT_LBUTTONDOWN)		// Sol button basildiysa
	{
		counter++;
		if (counter == 1)
		{
			point1.x = x;
			point1.y = y;
		}
		else if (counter == 2)
		{
			point2.x = x;
			point2.y = y;

			line(img, point1, point2, Scalar(255, 0, 0), 3, 8, 0);		// image, first click, second click, color, thickness, default value, shift 

			imshow("Window", img);

			counter = 0;
		}
	}

}


int main()
{
	img = imread("image.jpg");

	namedWindow("Window", WINDOW_AUTOSIZE);

	setMouseCallback("Window", func , NULL);		// pencere, guncelllencek fonksiyon, kullanilmayacak fonksiyon


	imshow("Window", img);
	waitKey(0);

	destroyWindow("Window");

	return 0;
}
