#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture vid("video.mp4");	// "video.mp4" u acmasi icin vid objesi olusturuldu
	// video.mp4 yerine videonun adresi de yazilabilir

	if (!vid.isOpened())	// kontrol
	{
		cout << " video is not found !";
		return -1;
	}

	double fps = vid.get(CAP_PROP_FPS);		// videonun fps miktari
	cout << fps << endl;

	namedWindow("Video", WINDOW_AUTOSIZE);		// Video pencersi olustur
	Mat video;					// video matris
	bool frame;					// her seferinde bir frame okur
	while (true)
	{
		frame = vid.read(video);
		if (waitKey(0) == 27 || frame == 0)	// esc tuslayana veya video bitene kadar
		{
			destroyWindow("Video");
			break;
		}
		imshow("Video", video);
	}
	return 0;
}