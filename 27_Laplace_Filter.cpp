#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// Laplace Filter -> Kenar tespiti icin kullanilir
// Laplace filtresi uygulanmadan once resim gray formata cevirilmeli, 
// uygulandiktan sonra ise dst matrisin mutlak degeri alinmali, sebebi ise Laplace filtresinde negative degerlerin bulunmasidir

int main()
{
	Mat orgimg, dst, gryimg;
	orgimg = imread("image.jpg");


	GaussianBlur(orgimg, orgimg, Size(3, 3), 1);		// Gaussian Filter

	cvtColor(orgimg, gryimg, COLOR_RGB2GRAY);		// RGB to Gray
	
	// Filter Size -> Ayarlanarak, tespit edilen kenar kalinligi degistirilebilir
	Laplacian(gryimg, dst, CV_16S, 5);			// input, output matrix, 16 bites image, Filter Size

	convertScaleAbs(dst, dst);				// ABS

	imshow("original image", orgimg);

	imshow("Laplacian Filter image", dst);
	waitKey(0);

	return 0;
}