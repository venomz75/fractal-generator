#!/bin/bash

function checkfiles() {
    if [ ! -e ./sierpinski_triangle ]; then
        if [ -e ./sierpinski_triangle.cpp ]; then
            echo -e -n "\e[33mFile\e[0m sierpinski_triangle \e[33mnot found, compiling now...\e[0m "
            g++ sierpinski_triangle.cpp -o sierpinski_triangle
            echo -e "\e[92mDone!\e[0m"
        else
            echo -e "\e[31mFiles\e[0m sierpinski_triangle \e[31mand\e[0m sierpinski_triangle.cpp \e[31mnot found!\e[0m "
        fi
    fi

    if [ ! -e ./sierpinski_carpet ]; then
        if [ -e ./sierpinski_carpet.cpp ]; then
            echo -e -n "\e[33mFile\e[0m sierpinski_carpet \e[33mnot found, compiling now...\e[0m "
            g++ sierpinski_carpet.cpp -o sierpinski_carpet
            echo -e "\e[92mDone!\e[0m"
        else
            echo -e "\e[31mFiles\e[0m sierpinski_carpet \e[31mand\e[0m sierpinski_carpet.cpp \e[31mnot found!\e[0m "
        fi
    fi

    if [ ! -e ./vicsek_fractal ]; then
        if [ -e ./vicsek_fractal.cpp ]; then
            echo -e -n "\e[33mFile\e[0m vicsek_fractal \e[33mnot found, compiling now...\e[0m "
            g++ vicsek_fractal.cpp -o vicsek_fractal
            echo -e "\e[92mDone!\e[0m"
        else
            echo -e "\e[31mFiles\e[0m vicsek_fractal \e[31mand\e[0m vicsek_fractal.cpp \e[31mnot found!\e[0m "
        fi
    fi
}

function menu() {
    case $1 in
        [1]* ) read -p "Invalid input! Select a number from 1-5: " input;;
        [2]* ) read -p "Select a fractal or option: " input;;
        * ) printoptions; read -p "Select a fractal or option: " input;;
    esac

    case $input in
        [1]* ) ./sierpinski_triangle; continue;;
        [2]* ) ./sierpinski_carpet; continue;;
        [3]* ) ./vicsek_fractal; continue;;
        [4]* ) recompile;;
        [5]* ) quit;;
        * ) menu 1;;
    esac
}

function printoptions() {
    echo ""
    echo -e "\e[96mfractalASCII by \e[95mvenomz75\e[0m"
    echo ""
    echo -e "\e[4mFractals             \e[0m"
    echo -e "\e[7m1\e[0m Sierpinski Triangle"
    echo -e "\e[7m2\e[0m Sierpinski Carpet"
    echo -e "\e[7m3\e[0m Vicsek Fractal"
    echo -e "\e[4mOptions             \e[0m"
    echo -e "\e[7m4\e[0m Recompile fractals"
    echo -e "\e[7m5\e[0m Exit"
    echo ""
}

function recompile() {
    echo -e -n "\e[33mRecompiling all fractals...\e[0m "
    g++ sierpinski_triangle.cpp -o sierpinski_triangle
    g++ sierpinski_carpet.cpp -o sierpinski_carpet
    g++ vicsek_fractal.cpp -o vicsek_fractal
    echo -e "\e[92mDone!\e[0m"
    echo ""
    menu 2
}

function continue() {
    case $1 in
        [1]* ) read -p "Invalid input!\e[0m Select from [Y,y,1/N,n,0]: " cont;;
        * ) read -p "Do another fractal or option? [Y/n]: " cont ;;
    esac
    
    case $cont in
        [Yy1]* ) menu;;
        [Nn0]* ) quit;;
        * ) continue 1;;
    esac
}

function quit() {
    echo -e "\e[91mExiting..."
    exit
}

checkfiles
menu