#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//global variables
int h, w, cX, cY;           //master triangle vars: height, width, centerX, centerY
vector<vector<char>> grid;  //the ASCII grid is stored in a 2D vector

//creating the master triangle and initialising vars
void setup() {
    //initialise globals
    cout << "Desired iterations(over 5 creates very large shapes!): ";
    cin >> h;
    h = pow(2, h+1);
    w = 2*h-1;
    cX = h-1;
    if (cX % 2 == 0) {cY = cX / 2;} else {cY = (cX + 1) / 2;}
    grid.resize(h, vector<char>(w));

    //create triangle from spaces and asterisks
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            grid[i][j] = ' ';
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = cX-i; j <= cX+i; j++){
            grid[i][j] = '*';
        }   
    }
}

//draw grid to console, kept in a function to keep tidy and assist debugging/step tracing
void draw() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

//creating gaps recursively to create the fractal
void recursion(int h_, int w_, int cX_, int cY_) {
    //escape condition
    if (h_ < 4) return;
    
    //local vars for triangle removal and use as input parameters in recursive steps
    int diff = w_ / 4;
    int left = cX_ - diff;
    int right = cX_ + diff;

    //recursion done before drawing on grid as left/right will change, and we have all the vars needed
    recursion(h_/2,w_/2,cX_,cY_-(h_/4));        //upper
    recursion(h_/2,w_/2,left-1,(cY_+(h_/4)));   //left
    recursion(h_/2,w_/2,right+1,(cY_+(h_/4)));  //right
    
    //create gaps in triangles
    for (int i = cY_; i <= cY_+diff; i++) {
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
    recursion(h,w,cX,cY);
    draw(); 
    return 0;
}