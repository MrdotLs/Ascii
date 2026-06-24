#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    cout << "before opencv" << endl;
    Mat img = Mat::zeros(100, 100, CV_8UC3);
    cout << "after opencv" << endl;
    return 0;
}