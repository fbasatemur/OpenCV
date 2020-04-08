#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat orgimg = imread("image.jpg");

	imshow("image", orgimg);
	
	// split edilmeden once kanallari tutmasi icin kanal sayisi kadar matris uretilir.
	Mat rgbkanal[3];			// 3 kanalli matris
	split(orgimg, rgbkanal);		// orgimg i 3 kanala parcala

	imshow("kanal 0", rgbkanal[0]);
	imshow("kanal 1", rgbkanal[1]); 
	imshow("kanal 2", rgbkanal[2]);

	// kanallari birlestirirken kanallar ilk olarak matris turu vector e itilir, daha sonra merge() func kullanarak bir matrise yazilir
	vector<Mat> kanallar;
	
	kanallar.push_back(rgbkanal[0]);
	kanallar.push_back(rgbkanal[1]);
	kanallar.push_back(rgbkanal[2]);

	merge(kanallar, orgimg);

	imshow("Merge", orgimg);

	waitKey(0);
	return 0;
}