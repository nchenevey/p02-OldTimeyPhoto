// Author: Nicholas Chenevey
#include <iostream>
#include <cstdlib>
#include <string>
#include "bitmap.h"
#include <fstream>
#include <vector>
 using namespace std;

int main()
{
// So far this is an empty file im going to use for the project. 
// I will create a great program that does exactly what it is supposed to
Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;

image.open("machupicchu.bmp");
bmp = image.toPixelMatrix();



if( bmp[0].size() > 0 && bmp.size() > 0 )
{
        cout<< "It is "<< bmp[0].size() << " pixels wide and " << bmp.size() << " pixels high."<<endl;
}
else
{
    cout<< "It would appear this has either no height or no width. Please try again." << endl;
}






 return 0;

 }
