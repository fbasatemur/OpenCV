#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// Genellikle goruntu uzeirndeki gurultuleri gidermek icin kullanilir, islem mantigi :
// Matrisin degerleri kucukten buyuge siralanir ve matrisin medyani, matrisin ortasina yerlestirilir.
// matris -> 3*3, 5*5 ... seklinde olabilir

Mat orgimg, dst;
int trackval = 1;

void track(int, void* )
{
	if (trackval % 2 == 1)		// matris 3*3, 5*5 gibi ortasi bulunan olmasi gerekir, bu yuzden trackval tek ise
	{
		medianBlur(orgimg, dst, trackval);

		imshow("Median Blur", dst);			// median blur penceresi
	}
}


int main()
{
	orgimg = imread("image.jpg");

	namedWindow("Window", WINDOW_AUTOSIZE);

	// trackbar kullanarak anlik olceklendirelim
	createTrackbar("Blur", "Window", &trackval, 100, track);	
	imshow("Window", orgimg);
	waitKey(0);
	return 0;
}