#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat orgimg, gryimg;
int a = 0;
int b = 0;
int trackValue = 0;

void track(int, void*)
{
	Mat cannyimg1(orgimg.rows, orgimg.cols, CV_8UC1, Scalar(0));	// kenarin kolon kiyaslamasi icin
	Mat cannyimg2(orgimg.rows, orgimg.cols, CV_8UC1, Scalar(0));	// kenarin satir kiyaslamasi icin

	// yukaridan asagi ya da asagidan yukarisi icin pixel farklarini threshold ile kiyasla
	for (int i=0;i < orgimg.cols - 1 ; i++)
	{
		for (int j=0; j< orgimg.rows - 1 ; j++)
		{
			a = gryimg.at<uchar>(j + 1, i) - gryimg.at<uchar>(j, i);	// 1,0 noktasindan 0,0 noktasini
			b = gryimg.at<uchar>(j, i) - gryimg.at<uchar>(j + 1, i);	// 0,0 noktasindan 1,0 noktasini

			if (a > trackValue || b > trackValue)		// pixel noktalari arasindaki fark esik degerinden buyukse
				cannyimg1.at<uchar>(j, i) = 255;		// white
			
			else
				cannyimg1.at<uchar>(j, i) = 0;			// black
			
		}
	}

	// sagdan sola ya da soldan saga pixel farklarini threshold ile kiyasla
	for (int i =0 ; i< orgimg.cols -1; i++)
	{
		for (int j=0; j< orgimg.rows -1; j++)
		{
			a = gryimg.at<uchar>(j, i + 1) - gryimg.at<uchar>(j, i);	// 0,1 noktasindan 0,0 noktasini
			b = gryimg.at<uchar>(j, i) - gryimg.at<uchar>(j, i + 1);	// 0,0 noktasindan 0,1 noktasini 

			if (a > trackValue || b > trackValue)
				cannyimg2.at<uchar>(j, i) = 255;
			
			else cannyimg2.at<uchar>(j, i) = 0;
		}
	}

	imshow("original image", orgimg);
	imshow("Canny Filter image", cannyimg1 + cannyimg2);	// kolon ve satir kenar matrislerini birlestir
}

int main()
{

	orgimg = imread("image.jpg");

	cvtColor(orgimg, gryimg, COLOR_BGR2GRAY);

	namedWindow("Trackbar", WINDOW_AUTOSIZE);
	createTrackbar("Threshold", "Trackbar", &trackValue, 100, track);

	waitKey(0);
	return 0;
}
