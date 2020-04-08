#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat orgimg = imread("image.jpg");
	Mat highimg, lowimg;				// yuksek ve alcak parlakik matrisleri 

	orgimg.convertTo(highimg, -1, 1, 100);		// output_matris, resim ayni kalsin(-1), alfa katsayisi, beta arttirimi -> Yuksek parlaklik

	orgimg.convertTo(lowimg, -1, 1, -100);		// dusuk parlaklik icin beta arttirimi negative deger girilir

	imshow("original image", orgimg);
	imshow("high brightness", highimg);
	imshow("low brightness", lowimg);

	waitKey(0);
	return 0;
}