#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void line(Mat input, Point pnt1, Point pnt2, Scalar scalar, int thickness)
{
	for (int i= pnt1.x; i < pnt2.x; i++)
	{
		for (int j = pnt1.y; j < pnt2.y + thickness; j++)
		{
			// input.at<Vec3b>(j, i)[0] = scalar[0];		// soft bir cizgi icin rengi ilgilendirmeyen scala satirlari commet yapilabilir
			// input.at<Vec3b>(j, i)[1] = scalar[1];
			input.at<Vec3b>(j, i)[2] = scalar[2];			// saydam kirmizi
		}
	}
}

int main()
{
	Mat orgimg = imread("image.jpg");
	Point Point1 = Point(300, 50);		// baslangic noktasi belirle
	Point Point2 = Point(400, 50);

	line(orgimg, Point1, Point2, Scalar(0, 0, 240), 10);

	imshow("image", orgimg);
	waitKey(0);
	return 0;
}