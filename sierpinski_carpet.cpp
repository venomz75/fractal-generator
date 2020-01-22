//Sierpinski Carpet by venomz75 (MMXX)

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//global variables
int length, centerX, centerY;   //starting variables
vector<vector<char>> grid;      //ASCII grid

//initialising vars and populating grid
void setup() {
    cout << "Select no. of iterations(0-4 recommended): ";
    cin >> length;
    length = pow(3, length);
    centerX = length/2;
    centerY = centerX;
    grid.resize(length, vector<char>(length, '#'));
}

//draw grid to console
void draw() {
    cout << "\n";
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

//creating rings of holes recursively
void recursion(int l, int cX, int cY) {
    //escape condition
    if (l < 3) return;

    //only l/3 is needed after this, shrunk now for readability
    l = l / 3;

    //create hole in square
    for (int i = cY-l/2; i <= cY+l/2; i++) {
        for (int j = cX-l/2; j <= cX+l/2; j++) {
            grid[i][j] = ' ';
        }
    }

    recursion(l,cX-l,cY-l);     //NW
    recursion(l,cX,cY-l);       //N
    recursion(l,cX+l,cY-l);     //NE
    recursion(l,cX+l,cY);       //E
    recursion(l,cX+l,cY+l);     //SE
    recursion(l,cX,cY+l);       //S
    recursion(l,cX-l,cY+l);     //SW
    recursion(l,cX-l,cY);       //W
}

//entry point
int main() {
    setup();
    recursion(length,centerX,centerY);
    draw(); 
    return 0;
}