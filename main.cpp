#include <iostream>
#include <png++/png.hpp>
#include <vector>

using namespace std;
using namespace png;

int main(){
    cout << "What image do you wanna change into ascii art: ";
    string imageName;
    cin >> imageName;

    image<png::rgb_pixel> image(imageName);

    int brightness;

    int width = image.get_width();
    int height = image.get_height();

    string outImage[height][width];


    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            brightness = (image[i][j].blue + image[i][j].red + image[i][j].green) / 3;
            if (brightness > 230){
                outImage[i][j] = ' ';
            } else if (brightness > 200){
                outImage[i][j] = '.';
            } else if (brightness > 160){
                outImage[i][j] = '!';
            } else if (brightness > 120){
                outImage[i][j] = '$';
            } else if (brightness > 80){
                outImage[i][j] = '"';
            } else if (brightness > 40){
                outImage[i][j] = 'H';
            } else if (brightness > 0){
                outImage[i][j] = 'M';
            }
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << outImage[i][j];
        }
        cout << '\n';
    }
    return 0;
}