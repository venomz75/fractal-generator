#!bin/bash

if [ ! -e ./sierpinski_triangle ]; then
    echo "File sierpinski_triangle not found, compiling now..."
    g++ sierpinski_triangle.cpp -o sierpinski_triangle;
    echo "Done!"
fi

if [ ! -e ./sierpinski_carpet ]; then
    echo "File sierpinski_carpet not found, compiling now..."
    g++ sierpinski_carpet.cpp -o sierpinski_carpet;
    echo "Done!"
fi

if [ ! -e ./vicsek_fractal ]; then
    echo "File vicsek_fractal not found, compiling now..."
    g++ vicsek_fractal.cpp -o vicsek_fractal;
    echo "Done!"
fi

echo ""
echo -e "\e[96mfractalASCII by \e[95mvenomz75\e[0m"
echo ""
echo -e "\e[4mFractals             \e[0m"
echo -e "\e[7m1\e[0m Sierpinski Triangle"
echo -e "\e[7m2\e[0m Sierpinski Carpet"
echo -e "\e[7m3\e[0m Vicsek Fractal"
echo -e "\e[4mOptions             \e[0m"
echo -e "\e[7m4\e[0m Recompile fractals"
echo ""
read -p "Select a fractal/option: " input 

if [ $input = 1 ]; then
    ./sierpinski_triangle;
fi

if [ $input = 2 ]; then
    ./sierpinski_carpet;
fi

if [ $input = 3 ]; then
    ./vicsek_fractal;
fi
if [ $input = 4 ]; then
    echo "Recompiling all fractals..."
    g++ sierpinski_triangle.cpp -o sierpinski_triangle;
    g++ sierpinski_carpet.cpp -o sierpinski_carpet;
    g++ vicsek_fractal.cpp -o vicsek_fractal;
    echo "Done! Run the script again to execute."
fi