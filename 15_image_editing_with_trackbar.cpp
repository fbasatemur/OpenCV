#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg, newimg;
	orgimg = imread("image.jpg");
	newimg = imread("image.jpg");
	int brtness = 0, contrast = 1.0, image_cols = orgimg.cols, image_rows= orgimg.rows, negative = 0;			// tranckbar degiskenleri
	
	
	// trackbar kullanarak istenilen fonksiyona anlik olarak parametre degeri atanabilir

	namedWindow("Settings", WINDOW_AUTOSIZE);
	// Trackbar ismi, Trackbarin gosterilecegi pencere, variable adress, max value, trackbar degiskeni degistiginde parametresi gunccellenecek fonksiyon
	createTrackbar("Brightness", "Settings", &brtness, 100);
	createTrackbar("Contrast", "Settings", &contrast, 5);
	createTrackbar("Height", "Settings", &image_rows, orgimg.rows);
	createTrackbar("Width", "Settings", &image_cols, orgimg.cols);
	createTrackbar("Negative", "Settings", &negative, 1);
	

	while (true)
	{
		image_cols < 10 ? image_cols = 10 : true;				// minimum resim boyutunu belirle -> 10*10 
		image_rows < 10 ? image_rows = 10 : true;
		resize(orgimg, newimg, Size(image_cols, image_rows));			// anlik boyut degisimi
		newimg.convertTo(newimg, -1, contrast, brtness);			// anlik contrast ve brightness degisimi
		if( negative == 1)	bitwise_not(newimg, newimg);			// negative 
		imshow("image ", newimg);						// anlik olarak ekrana yansit
		
		if (waitKey(30) == 27)
			break;
	}
	
	waitKey(0);
	return 0;
}