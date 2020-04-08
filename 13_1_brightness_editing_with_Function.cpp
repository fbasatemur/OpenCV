#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void convertTo(Mat input, Mat &output, int layer, float alfa, float beta)		// layer -> -1 ise 3 katmanli ; 1 ise tek katmanli image
{
	if (layer == -1)					// BGR image
	{
		for (int i = 0; i < input.rows; i++)
		{
			for (int j = 0; j < input.cols; j++)
			{
				for (int z = 0; z < 3; z++)
				{
					if ((input.at<Vec3b>(i, j)[z] * alfa) + beta > 255 )
						input.at<Vec3b>(i, j)[z] = 255;

					else if ((input.at<Vec3b>(i, j)[z] * alfa) + beta < 0 )		// alfa nin negative olmasi, 0 dan kucuk deger verebilir
						input.at<Vec3b>(i, j)[z] = 0;
					else
						input.at<Vec3b>(i, j)[z] = (input.at<Vec3b>(i, j)[z] * alfa) + beta;
				}
			}
		}

	}
	else if (layer == 1)						// Gray image
	{
		cvtColor(input, input, COLOR_BGR2GRAY);			// BGR image convert to Gray image
		for (int i = 0; i < input.rows; i++)
		{
			for (int j = 0; j < input.cols; j++)
			{
				if ((input.at<uchar>(i, j) * alfa) + beta > 255)
					input.at<uchar>(i, j) = 255;

				else if ((input.at<uchar>(i, j) * alfa) + beta < 0)
					input.at<uchar>(i, j) = 0;
				else
					input.at<uchar>(i, j) = (input.at<uchar>(i, j) * alfa) + beta;

			}
		}
	}

	output = input;
}
int main()
{
	Mat orgimg, cnvtimg;
	orgimg = imread("image.jpg");

	imshow("original image ", orgimg);

	convertTo(orgimg, cnvtimg, -1, 1, 100);
	imshow("BGR image", cnvtimg);

	convertTo(orgimg, cnvtimg, 1, 1, -100);
	imshow("Gray image", cnvtimg);

	waitKey(0);
	return 0;
}