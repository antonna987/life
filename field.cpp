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
 * File:   field.cpp
 * Author: Anton Nazin <anton.na987@gmail.com>
 * 
 * Created on November 14, 2018, 8:44 PM
 */

#include <cstdlib>
#include <string>
#include <unistd.h>
#include "field.h"


/*
 * Public
 */

Field::Field(int width, int height)
{
    _init(width, height);
    for (int i = 0; i < _height; i++)
        _rows[i] = new Row(_width);
}

Field::Field(const Field& orig)
{
    _init(orig._width, orig._height);
    for (int i = 0; i < _height; i++)
        _rows[i] = new Row(orig._rows[i]);
}

Field::~Field()
{
    for (int i = 0; i < _height; i++)
        delete _rows[i];
    delete [] _rows;
}

int Field::width() 
{ 
    return _width; 
}

int Field::height() 
{ 
    return _height; 
}

bool Field::get(int col, int row)
{
    col = _normalize(col, _width);
    row = _normalize(row, _height);
    return _rows[row]->get(col);
}

void Field::set(int col, int row, bool alive)
{
    col = _normalize(col, _width);
    row = _normalize(row, _height);
    _rows[row]->set(col, alive);
}

int Field::getncount(int col, int row)
{
    int n = 0;
    for (int dcol = -1; dcol < 2; dcol++) {
        for (int drow = -1; drow < 2; drow++) {
            if (dcol != 0 || drow != 0) {
                if (get(col + dcol, row + drow))
                    n++;
            }
        }
    }
    
    return n;
}

std::ostream& operator<< (std::ostream& os, Field& that)
{
    int result = std::system("clear");
    if (result != 0) {
        std::cout << "Error on syscall 'clear'" << std::endl;
        abort();
    }
    for (int row = 0; row < that._height; row++)
        os << *(that._rows[row]);
    
    return os;
}

std::istream& operator>> (std::istream& is, Field& that)
{
    int row = 0;
    while (!is.eof() && row < that._height) {
        is >> *(that._rows[row]);
        
//        using namespace std;
//        cout << "Result[" << row << "]: " << *(that._rows[row]);
//        cout << "Width: " << that._width << endl;
//        cout << "Press Enter to continue..." << endl;
//        cin.ignore();

        row++;
    }
    
    return is;
}

/*
 * Private
 */

void Field::_init(int width, int height)
{ 
    if (width < 1 || height < 1) {
        std::cout << "Error at 'Field::_init()'" << std::endl;
        abort();
    }
    _width = width;
    _height = height;
    _rows = new Row *[_height];
}

int Field::_normalize(int index, int count)
{
    while (index < 0)
        index += count;
    while (index >= count)
        index -= count;
    return index;
}
    

