#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// RGB renk uzay� renkleri farkl� tonlardaki �� ana rengin(k�rm�z�, ye�il, mavi) kar���m� ile tan�mlar.
// HSV renk uzay� ise Hue, Saturation ve Value terimleri ile rengi tan�mlar.
// RGB de renklerin kar���m� kullan�lmas�na kar��n HSV de renk, doygunluk ve parlakl�k de�erleri kullan�l�r.
// HSV uzay�nda siyah renk i�in renk ve doygunluk de�erleri 0 ile 255 aras�nda herhangi bir alabilir iken parlakl�k de�eri s�f�rd�r.
// RGB nin aksine sadece hue de�erini kullanarak e�ik de�er uygulama suretiyle renkleri daha net ay�rt edebiliriz.

int main()
{
	Mat orgimg, hsvimg;
	orgimg = imread("image.jpg");
	resize(orgimg, orgimg, Size(600, 400));

	imshow("original image", orgimg);

	cvtColor(orgimg, hsvimg, COLOR_BGR2HSV);

	imshow("HSV image", hsvimg);
	
	waitKey(0);
	return 0;
}