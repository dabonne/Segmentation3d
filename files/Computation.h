//
// Created by lirisimagine on 13/08/2020.
//

#ifndef SEGMENTATION3D_COMPUTATION_H
#define SEGMENTATION3D_COMPUTATION_H

#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "gdal/gdal_priv.h"
#include "ogrsf_frmts.h"
#include "ogr_api.h"
#include "shapefil.h"
#include <shapefil.h>
#include <gdal_utils.h>
#include <fstream>
#include "../Class/Patch.h"

using namespace std;
using namespace cv;

int randownInt(void);
char *randomTifName(void);
void flouGaussian(Mat &image1, Mat &image2);
vector<Patch> shapePatch(Mat &image);
cv::Mat Morphology_Operations(cv::Mat &src);

string rasterize(char *inputName);
string translateTif(char *inputName);


#endif //SEGMENTATION3D_COMPUTATION_H
