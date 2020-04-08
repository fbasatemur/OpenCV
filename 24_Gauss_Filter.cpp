#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
// Gauss Filtresi, Gauss dagilimini kullanarak resmi duzlestirir ve pixel degerlerini azaltir. 
// Goruntudeki gurulteleri gidermek icin kullanilir. 

int main()
{
	Mat orgimg, dst;
	orgimg = imread("image.jpg");
	int ksize = 0;
	while (true)
	{
		GaussianBlur(orgimg, dst, Size(ksize + 1, ksize + 1), 2);	// input, output matrix, Filtre size, Standart S.(Gauss Dagilimindaki Sigma)
		imshow("Original image", orgimg);
		imshow("Gaussian Blur image", dst);

		if (waitKey(400) == 27)		// esc kontrolu
			break;
		ksize = ksize + 2;
		cout << ksize << endl;
	}

	return 0;
}