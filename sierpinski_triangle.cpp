//Sierpinski Triangle by venomz75 (MMXX)

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//global variables
int height, width, centerX, centerY;    //starting variables
vector<vector<char>> grid;              //ASCII grid

//initialising vars and populating grid
void setup() {
    cout << "Select no. of iterations(0-5 recommended): ";
    cin >> height;
    height = pow(2, height+1);
    width = 2*height-1;
    centerX = height-1;
    if (centerX % 2 == 0) centerY = centerX / 2; 
    else {centerY = (centerX + 1) / 2;}
    grid.resize(height, vector<char>(width, ' '));

    //draw triangle
    for (int i = 0; i < height; i++) {
        for (int j = centerX-i; j <= centerX+i; j++){
            grid[i][j] = '*';
        }   
    }
}

//draw grid to console
void draw() {
    cout << "\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

//creating triangular gaps recursively
void recursion(int h, int w, int cX, int cY) {
    //escape condition
    if (h < 4) return;
    
    //local vars for triangle removal and use as input parameters in recursive steps
    int diff = w / 4;
    int left = cX - diff;
    int right = cX + diff;

    recursion(h/2,w/2,cX,cY-(h/4));         //UPPER
    recursion(h/2,w/2,left-1,(cY+(h/4)));   //LEFT
    recursion(h/2,w/2,right+1,(cY+(h/4)));  //RIGHT
    
    //create gaps in triangles
    for (int i = cY; i <= cY+diff; i++) {
        for (int j = left; j <= right; j++) {
            grid[i][j] = ' ';
        }
        left++;
        right--;
    }   
}

//entry point
int main() {
    setup();
    recursion(height,width,centerX,centerY);
    draw(); 
    return 0;
}