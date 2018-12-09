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

#include <cassert>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "field.h"

Field::Field(int width, int height) : _cells(height, std::vector<bool>(width))
{
    assert(width > 0);
    assert(height > 0);
    
    _width = width;
    _height = height;
        
    for (int row = 0; row < _height; row++)
        for (int col = 0; col < _width; col++)
            _cells[row][col] = false;
}

Field::Field(Field& orig) : Field(orig._width, orig._height)
{
    for (int row = 0; row < _height; row++)
        for (int col = 0; col < _width; col++)
            _cells[row][col] = orig._cells[row][col];
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
    return _cells[row][col];
}

void Field::set(int col, int row, bool alive)
{
    col = _normalize(col, _width);
    row = _normalize(row, _height);
    _cells[row][col] = alive;
}

int Field::getncount(int col, int row)
{
    int n = 0;
    for (int dcol = -1; dcol < 2; dcol++)
        for (int drow = -1; drow < 2; drow++)
            if (dcol != 0 || drow != 0)
                if (get(col + dcol, row + drow))
                    n++;
    
    return n;
}

std::ostream& operator<< (std::ostream& os, Field& that)
{
    int result = std::system("clear");
    if (result != 0) {
        std::cout << "Error on syscall 'clear'" << std::endl;
        abort();
    }
    
    for (int row = 0; row < that._height; row++) {
        /* Search for the last alive cell in a row */
        int lastcol = that._width - 1;
        while (lastcol) {
            if (that._cells[row][lastcol])
                break;
            lastcol--;
        }

        /* Print */
        for (int col = 0; col <= lastcol; col++)
            os << that._btoc(that._cells[row][col]);
        
        os << std::endl;
    }
    
    return os;
}

std::istream& operator>> (std::istream& is, Field& that)
{
    int row = 0;
    while (!is.eof() && row < that.height()) {
        std::string str;
        getline(is, str);

        int length = str.length();
        if (length > that._width)
                length = that._width;

        for (int i = 0; i < length; i++)
            that._cells[row][i] = that._ctob(str[i]);
        
        row++;
    }

    return is;
}

int Field::_normalize(int index, int count)
{
    while (index < 0)
        index += count;
    while (index >= count)
        index -= count;
    return index;
}
    
bool Field::_ctob(char c)
{
    return (c == _calive);
}

char Field::_btoc(bool b)
{
    return (b ? _calive : _cdead);
}

