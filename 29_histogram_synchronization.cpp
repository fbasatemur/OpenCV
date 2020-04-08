#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// Histogram Esitleme -> Resimdeki pixel degerlerinin bir aralikta cok ya da baska bir aralikta az olmasindan kaynaklanan durumlarda kullanilir.  
// ilk olarak resme gray filter uygulanir, daha sonra histogram ve histogram pixel degerleri sayilir, 
// son olarak histogram uygulanmis pixel degeri buyuklukleri grafik olarak ekrana yansitilir.

int main()
{
	Mat orgimg, gryimg, histimg;
	int * counter = (int *)calloc(255, sizeof(int));			// pixel degerlerinden kac adt oldugunu saymak icin
	Mat graphic(600, 800, CV_8UC3, Scalar(0, 0, 0));			// 600* 800 grafik matrisi

	orgimg = imread("image.jpg");

	cvtColor(orgimg, gryimg, COLOR_BGR2GRAY);
	
	equalizeHist(gryimg, histimg);								// Histogram

	// pixel degerlerini histogram uygulanmis matrise gore say

	for (int i =0; i < orgimg.rows; i++)
	{
		for (int j =0; j < orgimg.cols; j++)
		{
			for (int z = 0; z < 255; z++)						// pixel degerleri 0-255 arasi degisir
			{
				if (histimg.at<uchar>(i, j) == z)
					counter[z] = counter[z] + 1;
			}
		}
	}

	for (int z = 0; z< 255; z++)
		cout << z << " degeri "<< counter[z]<<" tane" << endl;


	// graphic matrisine ciz

	for (int i = 0; i < 255; i++)
	{
		// 0,600 den basla ->  0, ( 600 - pixel degeri miktari / k (ekrana sigmasi icin)) 
		line(graphic, Point(i*800/255, 600), Point(i*800 /255, 600 - counter[i] / 30), Scalar(0, i, counter[i]), 2, 8, 0);		
	}

	imshow("Histogram ", graphic);
	
	waitKey(0);

	free(counter);			

	return 0;
}