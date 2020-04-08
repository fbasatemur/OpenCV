#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// Trackbar kullanarak Sharpen uygulayalim ;  
// ilk olarak GaussianBlur filtresi ile duzlestirme yaparak resimdeki gurultulerden kurtulucaz, 
// sonrasinda ise duzlestirilmis resimde addWeighted ile keskinlestirme yapicaz.

Mat orgimg, dst;
int trackValue = 1; 

void track(int, void* )
{
	addWeighted(orgimg, trackValue / 7.0, dst, -0.5, 0, dst);	// Sharpen 
	imshow("addWighted", dst);
}
int main()
{
	orgimg = imread("image.jpg");
	resize(orgimg, orgimg, Size(400, 600));			// hiz kazanmak icin yeniden boyutlandiralim

	GaussianBlur(orgimg, dst, Size(3, 3), 10);		// Gaussian Filter

	namedWindow("Trackbar", WINDOW_AUTOSIZE);

	createTrackbar("Sharpen", "Trackbar", &trackValue, 100, track);		// trackbar
	
	imshow("original image", orgimg);

	waitKey(0);

	return 0;
}