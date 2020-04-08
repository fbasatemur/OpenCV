#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
// Arkaplani yesil olan goruntuye, baska bir goruntu ekleme

Mat img1, img2, hsvimg, dst;
int LowH = 40, HighH = 60, LowS = 50, HighS = 255, LowV = 60, HighV = 255;	// image1 i arkaplandan ayirmak icin uygun deger araliklari
	

int main()
{
	// image1 in arkaplanina image 2 yi yerlestiricez
	img1 = imread("image1.jpg");			
	img2 = imread("image2.jpg");
	
	resize(img1, img1, Size(800, 600));					// image1 ve image2 yi ayni boyutlara donustur
	resize(img2, img2, Size(800, 600));		

	imshow("image 1", img1);
	imshow("image 2", img2);

	cvtColor(img1, hsvimg, COLOR_BGR2HSV);					// renk kontrolu icin hsv donusumu yap

	inRange(hsvimg, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), dst);	// deger araliklarinda ise 1
	
	// resmi gurultulerden arindir
	erode(dst, dst, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
	dilate(dst, dst, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
	dilate(dst, dst, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
	erode(dst, dst, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));

	imshow("dst", dst);							// arkaplani beyaz, kendisi siyah olan foto
	
	// arkaplani beyaz olan resmin (image 1) beyaz pixellerini image 2 nin pixel degerleri ile degistir
	for (int i =0; i< img1.rows; i++)
	{
		for(int j= 0; j< img1.cols; j++)
		{
			if (dst.at<uchar>(i, j) == 255)				// pixel degeri beyaz ise
				img1.at<Vec3b>(i, j) = img2.at<Vec3b>(i, j);	// img2 nin pixel degerlerini img1 e at
		}
	}


	imshow("img1", img1);

	waitKey(0);
	return 0;
}