#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat image;		// goruntunun depolanacagi matris
int main()
{
	image = imread("image.jpg");	// goruntuyu bulunan dizinden oku

	namedWindow("image window", WINDOW_AUTOSIZE);	// display icin goruntu boyutunda pencere tanimla 
	// WINDOW_AUTOSIZE -> goruntu boyutunda pencere olustur

	if (image.empty())				// matris kontrolu
	{
		cout << "image not found !";
		return -1;
	}
	imshow("image window", image);		// display
	waitKey(0);							// herhangi bir tusa basana kadar bekle
	destroyWindow("image window");		// acilan pencereyi yoket

	return 0;
}


