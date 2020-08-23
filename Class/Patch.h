//
// Created by lirisimagine on 18/08/2020.
//

#ifndef SEGMENTATION3D_PATCH_H
#define SEGMENTATION3D_PATCH_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class Patch {
public:
    Patch(Mat &image, int x, int y, bool traverse);
    Patch();
    void setPatch(Mat &image);
    Mat getPatch();
    int getPositionX();
    void setPositionX(int x);
    int getPositionY();
    void setPositionY(int y);
    void setTraverse(bool traverse);
    bool getTraverse();
    Rect rect_from_big_image;
    ~Patch();

private:
    int m_positionX;
    int m_positionY;
    Mat m_patch;
    bool m_traverse;
};


#endif //SEGMENTATION3D_PATCH_H
