#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "files/Computation.h"
#include "Class/Patch.h"
#include <math.h>


using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
    cv::Mat vesselImage = cv::imread("/home/lirisimagine/CLionProjects/Segmentation3d/Results/TraverseBack/img896x2240.png",0); //the original image
    cv::threshold(vesselImage, vesselImage, 125, 255, THRESH_BINARY);
    cv::Mat blurredImage; //output of the algorithm

    cout << vesselImage.rows << endl;
    for (int i = 0; i < vesselImage.rows; ++i) {
        for (int j = 0; j < vesselImage.cols; ++j) {
            if (vesselImage.at<uchar>(i, j) == 255) {
                vesselImage.at<uchar>(i, j) = 0;
            } else vesselImage.at<uchar>(i, j) = 255;
        }
    }
    imshow("original", vesselImage);
    Mat element = getStructuringElement( MORPH_ELLIPSE,
                                         Size( 3, 3 ),
                                         Point( -1, -1 ) );
    Mat mo;
    dilate( vesselImage, mo, element );
    //cv::pyrUp(vesselImage, blurredImage);

   // mo = Morphology_Operations(vesselImage);


    //for (int i = 0; i < 15; i++)
        cv::GaussianBlur(mo, blurredImage, Size(3,3),1.0);

    //cv::pyrDown(blurredImage, blurredImage);
    //cv::threshold(blurredImage, blurredImage, 200, 255, THRESH_BINARY);

    namedWindow("teste",WINDOW_FULLSCREEN);
    namedWindow("original",WINDOW_FULLSCREEN);
    namedWindow("Morph",WINDOW_FULLSCREEN);

    imshow("teste", blurredImage);

    //imshow("Morph", mo);
    waitKey(0);

/*    Mat image;
    image = imread("/home/lirisimagine/CLionProjects/creatPatch/cmake-build-debug/rasters/annotaion.png",0);
    //threshold(image, image, 125, 255, THRESH_BINARY);
    vector<Patch> patchs = shapePatch(image);
    for(Patch patch_element: patchs){
        for (int i = 0; i < patch_element.getPatch().rows; ++i) {
            for (int j = 0; j < patch_element.getPatch().cols; ++j) {
                if(patch_element.getPatch().at<uchar>(i,j) == 0)
                {
                    patch_element.getPatch().at<uchar>(i,j) = 255;
                }
                else patch_element.getPatch().at<uchar>(i,j) = 0;
            }
        }
      if(patch_element.getTraverse()){
            imwrite("../Results/TraverseBack/img"+to_string(patch_element.getPositionX())+"x"+to_string(patch_element.getPositionY())+".png",patch_element.getPatch());
        }else{
            imwrite("../Results/pasTraverseBack/img"+to_string(patch_element.getPositionX())+"x"+to_string(patch_element.getPositionY())+".png",patch_element.getPatch());
        }
    }*/

    return 0;
}



