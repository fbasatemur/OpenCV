#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

// PID(Proportional, Integral, Derivative) ;
// PID aslýnda bir kontrol geri bildirim mekanizmasýdýr.
// Bir PID denetleyici ölçülü bir süreç içinde deðiþen ve istenilen ayar noktasý ile arasýndaki farký olarak bir “hata” deðerini hesaplar.
// Kontrol giriþ ayarý yapýlarak bu hata en aza indirilmesi saðlanýr.

int track = 500;						// track value default 500
int integrl = 0, lasterror = 0;		
float pidvalue = 0.0;			
float kp = 0.5, ki = 0, kd = 0.3;			// kp -> Prooprtional katsayi, ki -> inegral katsayi ..
void trackfunc(int, void*)
{
	int error = 500 - track;			// 500 referans deger olarak alinir ve 500 ustunde veya altinda olmasi hata degeri olusturur
	integrl += error;				// integral degeri, referans noktasindan olan toplam uzakliktir.

	lasterror = error;
	pidvalue = kp * error + ki * integrl + kd * (error - lasterror);

	cout << pidvalue <<endl;
}

int main()
{
	namedWindow("Trackbar", WINDOW_AUTOSIZE);
	createTrackbar("Vlue", "Trackbar", &track, 1000, trackfunc);

	waitKey(0);
	return 0;
}