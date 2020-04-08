#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>


using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);		// 0 -> camera indexi(bir kamera var) 

	if (!cap.open(0))		// 0 indexli camera acildi mi
	{
		return 0;
	}
	Mat frame;				// cap den goruntu okumak icin matris tanimla
	while (true)
	{
		cap >> frame;		
		if (waitKey(30) == 27 || frame.empty())		// esc basilana kadar ya da matris bos ise
			break;
		imshow("webcam", frame);			// matrise okunani ekrana yansit
	}
	return 0;
}
