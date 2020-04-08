#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// Erosion -> Resimde daha net bir sekilde gurultu yoketmek icin kullanilir (Median Filter a gore daha saglikli sonuclar uretir)
// Tek kanlli yani S-B resimler uzerinde uygulanir.
int main()
{
	Mat orgimg, dst;

	orgimg = imread("image.jpg");
	

	erode(orgimg, dst, getStructuringElement(MORPH_RECT, Size(7,7)));		// Size degerleri arttirilarak erosion miktari arttirilabilir.

	imshow("original image", orgimg);
	imshow("erode", dst);
	waitKey(0);

	return 0;
}