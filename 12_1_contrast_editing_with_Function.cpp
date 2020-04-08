#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// her bir pixel max 255 degerini alma kosuluyla katsayi ile carpilir
void convertTo(Mat input, Mat& output, int layer, float katsayi)		// layer -> -1 ise 3 kanalli(renkli); 1 ise tek kanalli (gray)
{
	if (layer == -1)
	{
		for (int i = 0; i < input.rows; i++)		// satir
		{
			for (int j = 0; j < input.cols; j++)		// sutun
			{
				for (int z = 0; z < 3; z++)				// her pixel ve 3 kanal icin 8 bit(255) asimini kontrol et
				{
					if (input.at<Vec3b>(i, j)[z] * katsayi > 255)
						input.at<Vec3b>(i, j)[z] = 255;
					else
						input.at<Vec3b>(i, j)[z] *= katsayi;
				}
				
			}
		}
	}
	else if (layer == 1)
	{
		cvtColor(input, input, COLOR_BGR2GRAY);		// ilk olarak gri resme cevir

		for (int i = 0; i < input.rows; i++)		// satir
		{
			for (int j = 0; j < input.cols; j++)		// sutun
			{
				// tek kanal icin 8 bit(255) asimini kontrol et
				if (input.at<uchar>(i, j) * katsayi > 255)
					input.at<uchar>(i, j) = 255;
				else
					input.at<uchar>(i, j) *= katsayi;
			}
		}
	}
	output = input;
}
int main()
{
	Mat orgimg, cvtimg;		// original and convert image

	orgimg = imread("image.jpg");
	imshow("original image", orgimg);

	convertTo(orgimg, cvtimg, -1, 1.5);			// high contrast BGR image
	imshow("BGR convert image", cvtimg);

	convertTo(orgimg, cvtimg, 1, 0.5);			// low contrast GRAY image
	imshow("Gray convert image", cvtimg);

	waitKey(0);
	return 0;
}