#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int LowH = 0, HighH = 50, LowS = 150, HighS = 255, LowV = 101, HighV = 255;
Mat video, hsvimg, dstimg;

int main()
{

	VideoCapture vid("video.mp4");

	namedWindow("Control", WINDOW_AUTOSIZE);

	createTrackbar("LowH", "Control", &LowH, 179);		// Hue (0-179)
	createTrackbar("HighH", "Control", &HighH, 179);
	createTrackbar("LowS", "Control", &LowS, 255);		// Saturation (0-255)
	createTrackbar("HighS", "Control", &HighS, 255);
	createTrackbar("LowV", "Control", &LowV, 255);		// Value (0-255)
	createTrackbar("HighV", "Control", &HighV, 255);

	bool flag;

	while (true)
	{
		flag = vid.read(video);

		if (waitKey(30) == 27 || flag == 0)
			break;

		// Goruntuyu HSV formatina donustur
		cvtColor(video, hsvimg, COLOR_BGR2HSV);

		// inRange() ile hsvimg deki her pixel icin;
		// Hui degeri LowH <-> HighH arasinda ise 1 ,
		// Saturation degeri LowS <-> HighS arasinda 1 ,
		// Value degeri LowV <-> HighV arasinda ise 1; degilse 0 yaparak dstimg matrisine aktar.

		inRange(hsvimg, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), dstimg);

		// Goruntudeki gurultuleri gidermek icin once erode sonra dilate daha sonra ise tersi uygulanir.

		erode(dstimg, dstimg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(dstimg, dstimg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		dilate(dstimg, dstimg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(dstimg, dstimg, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		imshow("dst image", dstimg);

		imshow("video", video);
	}
	   	
	return 0;
}