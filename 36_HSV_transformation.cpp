#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// RGB renk uzayý renkleri farklý tonlardaki üç ana rengin(kýrmýzý, yeþil, mavi) karýþýmý ile tanýmlar.
// HSV renk uzayý ise Hue, Saturation ve Value terimleri ile rengi tanýmlar.
// RGB de renklerin karýþýmý kullanýlmasýna karþýn HSV de renk, doygunluk ve parlaklýk deðerleri kullanýlýr.
// HSV uzayýnda siyah renk için renk ve doygunluk deðerleri 0 ile 255 arasýnda herhangi bir alabilir iken parlaklýk deðeri sýfýrdýr.
// RGB nin aksine sadece hue deðerini kullanarak eþik deðer uygulama suretiyle renkleri daha net ayýrt edebiliriz.

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