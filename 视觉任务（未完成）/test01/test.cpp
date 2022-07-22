#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	VideoCapture capture;
	Mat frame;
	//frame = capture.open(0);
	frame = capture.open("D:\\1.mp4");
	if (!capture.isOpened())
	{
		printf("Error   \n");
		return -1;
	}
	Mat dst;
	Mat kernel;

	kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hireachy;
	Rect rect;
	Point2f center;
	float radius = 20;

	while (capture.read(frame))
	{
		Mat hsv;
		cvtColor(frame, hsv, COLOR_BGR2HSV);
		inRange(hsv, Scalar(0, 0, 0), Scalar(100, 60, 255), dst);
		morphologyEx(dst, dst, MORPH_OPEN, kernel);
		morphologyEx(dst, dst, MORPH_OPEN, kernel);
		morphologyEx(dst, dst, MORPH_OPEN, kernel);
		morphologyEx(dst, dst, MORPH_OPEN, kernel);
		findContours(dst, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
		if (contours.size() > 0)
		{
			double maxArea = 0;
			for (int i = 0; i < contours.size(); i++)
			{
				double area = contourArea(contours[static_cast<int>(i)]);
				if (area > maxArea)
				{
					maxArea = area;
					rect = boundingRect(contours[static_cast<int>(i)]);
					minEnclosingCircle(contours[static_cast<int>(i)], center, radius);
				}
			}
		}
		rectangle(frame, rect, Scalar(0, 255, 255), 2);
		putText(frame, "test", Point(rect.x, rect.y - 5), FONT_HERSHEY_PLAIN, 1, Scalar(0,0,0), 1, 8, 0);
		imshow("input", frame);
		imshow("output", dst);

		waitKey(100);
	}

	capture.release();
	return 0;
}
