/* MIT License
 * 
 * Copyright (c) 2018 Anton Nazin
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the 
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
 * sell copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. */

/* 
 * File:   main.cpp
 * Author: Anton Nazin <anton.na987@gmail.com>
 *
 * Created on November 13, 2018, 9:02 PM
 */

#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include "life.h"

using namespace std;

/*
 * 
 */
int main(int argc, char **argv)
{
    Life life(80, 40);
    char str[5][32];

    ifstream file;
    if (argc < 2) {
        cout << "Usage: life FILE" << endl;
        return 0;
    }
    file.open(argv[1], ios::in);
    if (!file.is_open()) {
        cout << "File open error" << endl;
        return 0;
    }
    for (int i = 0; i < 5; i++)
        file >> str[i];
    //file >> life;
    file.close();

    life.setrow(0, "    X              ");
    life.setrow(1, " XX XX  X    XX    ");
    life.setrow(2, "  XX XXX     XX    ");
    life.setrow(3, "X  XXX             ");
    life.setrow(4, " XX X X            ");

    int i = 0;
    while (1) {
        cout << life;
        cout << i << endl;
        i++;

        life.tick();
        usleep(1000000 / 20);
    }

    return 0;
}




