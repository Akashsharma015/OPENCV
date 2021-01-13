#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat image;
	image = imread("Image Path");
	Mat rotate;
	double angle;
	cin >> angle;

		if (image.empty())
		{
			cout << "Error!!"<<endl;
			cin.get();
			return -1;
		}

		Point2f pt(image.cols / 2., image.rows / 2.);
		
		Mat r = getRotationMatrix2D(pt, angle, 1.0);
		warpAffine(image, rotate, r, Size(image.cols, image.rows));

		namedWindow("My Rotated Image", WINDOW_NORMAL);
		imshow("My Rotated Image",rotate);
		waitKey(0);

	return 0;
}
