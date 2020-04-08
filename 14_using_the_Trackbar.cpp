#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	int trkval =0;			// trackbar in anlik degiskeni

	// trackbar kullanarak istenilen fonksiyona anlik olarak parametere degeri atanabilir

	namedWindow("Trackbar");	// trackbar penceresi
	createTrackbar("Trbar", "Trackbar", &trkval, 100);	
	// Trackbar ismi, Trackbarin gosterilecegi pencere, variable adress, max trackbar degeri, trkval degistiginde parametresi gunccellenecek fonksiyon (su anlik ihtiyacimiz yok!)

	while (true)
	{
		cout << trkval << endl;
		if (waitKey(30) == 27)		// esc basinca cik (30 ms de bir kontroller ile)
			break;
	}

	waitKey(0);
	return 0;
}