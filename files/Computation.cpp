//
// Created by lirisimagine on 13/08/2020.
//

#include "Computation.h"


vector<Patch> shapePatch(Mat &image){
    Mat imageResize, img;
    vector<Patch> patchs;
    bool traverse = false;
    resize(image, imageResize, Size(32935,30880));
    const unsigned int height(224), width(224);
    double diagonale(sqrt(pow(height,2)+pow(width,2)));
    for(int x(0); x+height<= imageResize.rows; x+=height){
        for(int y(0); y+width<= imageResize.cols; y+=width){
            Rect imgRect = Rect(x, y, width, height);
            if(0 <= imgRect.x && 0 <= imgRect.width && imgRect.x + imgRect.width < imageResize.cols &&
               0 <= imgRect.y && 0 <= imgRect.height && imgRect.y + imgRect.height < imageResize.rows)
            {
                img = imageResize(imgRect);
                traverse = countNonZero(img) > diagonale;
                Patch patch(img, x, y,traverse);
                patchs.push_back(patch);
            }
        }
    }
    return patchs;
}





string rasterize(char *inputName){
    if(*inputName){
        cout << endl;
        cout << endl;
        cout << "========================= En cour de rasterisation ====================" << endl;
        cout << endl;
        cout << endl;
        GDALAllRegister();
        const int nbOptions = 11;
        char **options = (char **)malloc(nbOptions * sizeof(char *));
        options[0] = "-burn";
        options[1] = "255";
        options[2] = "-burn";
        options[3] = "255";
        options[4] = "-burn";
        options[5] = "255";
        options[6] = "-ot";
        options[7] = "Byte";
        options[8] = "-ts";
        options[9] = "32935";
        options[10] = "30880";
        int argc = GDALGeneralCmdLineProcessor(nbOptions, &options, 0);
        GDALRasterizeOptions *psOptions = GDALRasterizeOptionsNew(options,0);

        char resultTif[40] = "./shapes/new_";
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = '.';
        resultTif[strlen(resultTif)] = 't';
        resultTif[strlen(resultTif)] = 'i';
        resultTif[strlen(resultTif)] = 'f';

        char *filename2 = inputName;
        GDALDatasetH lineDS,lineDS_shp;

        lineDS_shp = GDALOpenEx(filename2, GDAL_OF_VECTOR, NULL, NULL, NULL );
        lineDS = GDALRasterize(resultTif,NULL,lineDS_shp,psOptions,NULL);
        GDALClose(lineDS_shp);

        GDALClose(lineDS);
        string modif = translateTif(resultTif);
        return modif;
    }
    else {
        cout << "*********************************************************************************" << endl;
        cout << "========================= Vous devez fournir un .tif valide ====================" << endl;
        cout << "*********************************************************************************" << endl;
        exit(0);
    }

}
string translateTif(char *inputName){
    GDALDatasetH  hDataset, rDataset;
    GDALAllRegister();
    hDataset = GDALOpen( inputName,
                         GA_ReadOnly );
    if (hDataset){
        cout << endl;
        cout << endl;
        cout << "========================= Pretraitement du raster ====================" << endl;
        cout << endl;
        cout << endl;
        char resultTif[40] = "./rasters/new_";
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = randownInt()+'0';
        resultTif[strlen(resultTif)] = '.';
        resultTif[strlen(resultTif)] = 'p';
        resultTif[strlen(resultTif)] = 'n';
        resultTif[strlen(resultTif)] = 'g';
        GDALTranslate(resultTif, hDataset, NULL, NULL);
        return  (resultTif);
    }
    else {
        cout << "*********************************************************************************" << endl;
        cout << "=========================Vous devez fournir un shapefile valide====================" << endl;
        cout << "*********************************************************************************" << endl;
        exit(0);
    }

}

char *randomTifName(void){
    char resultTif[] = "./new_";
    resultTif[strlen(resultTif)] = randownInt()+'0';
    resultTif[strlen(resultTif)] = randownInt()+'0';
    resultTif[strlen(resultTif)] = randownInt()+'0';
    resultTif[strlen(resultTif)] = randownInt()+'0';
    resultTif[strlen(resultTif)] = randownInt()+'0';
    resultTif[strlen(resultTif)] = '.';
    resultTif[strlen(resultTif)] = 't';
    resultTif[strlen(resultTif)] = 'i';
    resultTif[strlen(resultTif)] = 'f';
    return resultTif;
}

int randownInt(void){
    static int first = 0;

    if (first == 0)
    {
        srand (time (NULL));
        first = 1;
    }
    return (rand ()%10);
}

cv::Mat Morphology_Operations(cv::Mat &src)
{
    cv::Mat dst;
    cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(5,5));
    morphologyEx( src, dst, cv::MORPH_CLOSE, element );
    //morphologyEx( src, dst, cv::MORPH_OPEN, element );
    return  dst;
}