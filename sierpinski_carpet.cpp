#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//global variables
int l, cX, cY;              //master square vars: length, centerX, centerY
vector<vector<char>> grid;  //the ASCII grid is stored in a 2D vector

//creating the master square and initialising vars
void setup() {
    //initialise globals
    cout << "Desired iterations(over 5 creates very large shapes!): ";
    cin >> l;
    l = pow(3, l);
    cX = l/2;
    cY = cX;
    grid.resize(l, vector<char>(l));

    //create the master square filling the entire grid
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            grid[i][j] = '*';
        }
    }
}

//draw grid to console, kept in a function to keep tidy and assist debugging/step tracing
void draw() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

//creating gaps recursively to create the fractal
void recursion(int l_, int cX_, int cY_) {
    //escape condition
    if (l_ < 3) return;

    //length of hole
    int holeL = l_ / 3;

    //8 cardinal directions to go in recursively
    recursion(l_/3,cX_-holeL,cY_-holeL); //NW
    recursion(l_/3,cX_,cY_-holeL); //N
    recursion(l_/3,cX_+holeL,cY_-holeL); //NE
    recursion(l_/3,cX_+holeL,cY_); //E
    recursion(l_/3,cX_+holeL,cY_+holeL); //SE
    recursion(l_/3,cX_,cY_+holeL); //S
    recursion(l_/3,cX_-holeL,cY_+holeL); //SW
    recursion(l_/3,cX_-holeL,cY_); //W

    //create hole in square
    for (int i = cY_-holeL/2; i <= cY_+holeL/2; i++) {
        for (int j = cX_-holeL/2; j <= cX_+holeL/2; j++) {
            grid[i][j] = ' ';
        }
    }
}

//entry point
int main() {
    setup();
    recursion(l,cX,cY);
    draw(); 
    return 0;
}