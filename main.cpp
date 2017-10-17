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
Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;

int gray;
string inPic;

cout<<"Please provide the file to be modified."<<endl;
cin>>inPic;

image.open(inPic);
bool validBmp = image.isImage();
 
while(validBmp == false)
{
    cout<<"The file must be a 24 bit depth Windows BMP file. Please try again."<<endl;
    cin>>inPic;
    image.open(inPic);
    validBmp = image.isImage();
}

bmp = image.toPixelMatrix();
char choice;
 
do
{
    cout<<"Please select an option."<<endl;
    cout<<"Pixel Count(P)"<<endl<<"Change color to black and white(C)"<<endl<<"Exit(E)"<<endl;
    cin>> choice;

    if( bmp[0].size() > 0 && bmp.size() > 0 )
    {
        if(choice == 'p' || choice == 'P')
        {
            cout<< "It is "<< bmp[0].size() << " pixels wide and " << bmp.size() << " pixels high."<<endl;
        }
        else if(choice == 'c' || choice == 'C')
        {
            for(int row = 0; row < bmp.size(); row++)
            {
                for(int col = 0; col < bmp[0].size(); col++)
                {
                    rgb = bmp[row][col];
                    int r = rgb.red;
                    int g = rgb.green;
                    int b = rgb.blue;
                    gray = (r + g + b)/3;
                    rgb.red = gray;
                    rgb.green = gray;
                    rgb.blue = gray;
                    bmp[row][col] = rgb;
                }
            }
        image.fromPixelMatrix(bmp);
        image.save("oldtimey.bmp");
        }
    }
    else
    {
        cout<< "It would appear this has either no height or no width. Please try again." << endl;
    }

}while(choice != 'E' && choice != 'e' );

return 0;
}
