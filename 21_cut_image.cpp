#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


Mat img, newimg, cut_img;
Point pt1, pt2;

void func(int event, int x, int y, int flags, void * userdata)
{
	if (event == EVENT_LBUTTONDOWN)								// sol button basildiysa, baslangic noktasini tut
	{
		pt1.x = x;
		pt1.y = y;
	}
	if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON)				// mouse hareketli ve sol button basili iken
	{
		pt2.x = x;									// bitis noktasi kordinatlari surekli guncellenir
		pt2.y = y;

		Mat rect = Mat::zeros(img.size(), CV_8UC3);				// dikdortgen matrisi( image boyutunda ve 3 katmanli)
		rectangle(rect, pt1, pt2, Scalar(0,255,0), 1,8,0);		// rect matrisi uzerine pt1 ve pt2 noktalari arasinda , renk , kalinlik, default deger (8), kayma olmadan dikdortgen ciz
		newimg = rect + img;								// kirpma hatlarini orginal image uzerine yansitmak icin newimg kullan
		imshow("Window", newimg);
	}

	if (event == EVENT_LBUTTONUP)						// sol button kalktiginda resmi kes
	{
		pt2.x > img.cols ? pt2.x = img.cols : (pt2.x < 0 ? pt2.x = 0 : true);				// bitis noktasi kordinatlari kontrollu sekilde guncellenir
		pt2.y > img.rows ? pt2.y = img.rows : (pt2.y < 0 ? pt2.y = 0 : true);				// bu kontroller ekran disi isaretlemeye karsi
		Rect crop;

		// crop dikdortgeninin baslangic noktalari
		crop.x = pt1.x;	
		crop.y = pt1.y;

		// iki nokta arasindaki uzaklik degeri crop dikdortgeninin boyutu olacak
		// Buna bagli olarak 4 yone rahatca kesme yapilirsa  crop. with ve height negatif cikar
		crop.width = pt2.x - pt1.x;	
		crop.height = pt2.y - pt1.y;

		// crop boyutunu kontrol ederek crop baslangic noktalarini guncelleyebiliriz

		if (crop.width < 0 && crop.height > 0)				// sagdan sola asagi dogru
		{
			crop.x = pt2.x;
			crop.y = pt1.y;
			crop.width = pt1.x - pt2.x;
			
		}
		else if (crop.width > 0 && crop.height < 0)			// soldan saga yukari dogru
		{
			crop.x = pt1.x;
			crop.y = pt2.y;
			crop.height = pt1.y - pt2.y;
		}				
		else if (crop.width < 0 && crop.height < 0)			// sagdan sola yukari dogru
		{
			crop.x = pt2.x;
			crop.y = pt2.y;
			crop.width = pt1.x - pt2.x;
			crop.height = pt1.y - pt2.y;
		}
		else if(crop.width == 0 || crop.height == 0)			// width veya height == 0 ise en kucuk 1*1 lik crop yap
		{
			crop.width = 1;
			crop.height = 1;
		}

		// soldan saga ve yukaridan asagi dogru ise direk ciz
		cut_img = img(crop);
		imshow("cut", cut_img);
		
	}
}

int main()
{
	img = imread("image.jpg");
	namedWindow("Window", WINDOW_AUTOSIZE);

	setMouseCallback("Window", func, NULL);


	imshow("Window", img);
	
	waitKey(0);
	return 0;
}
