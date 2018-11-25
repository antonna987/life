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
#include <unistd.h>
#include "field.h"

Field::Field(int cols, int rows)
{
    assert(cols > 0 && rows > 0);
    _cols = cols;
    _rows = rows;
    int asize = _cols * _rows;
    _cell = new Cell[asize];
}

Field::Field(const Field& orig)
{
    _cols = orig._cols;
    _rows = orig._rows;
    int asize = _cols * _rows;
    _cell = new Cell[asize];
    for (int i = 0; i < asize; i++)
        _cell[i] = orig._cell[i];
}

Field::~Field()
{
    delete [] _cell;
}

bool Field::alive(int col, int row) 
{ 
    return _cell[_addr(col, row)].alive(); 
}

void Field::alive(int col, int row, bool set) 
{ 
    _cell[_addr(col, row)].alive(set); 
}

int Field::getncount(int col, int row)
{
    int n = 0;
    for (int dcol = -1; dcol < 2; dcol++) {
        for (int drow = -1; drow < 2; drow++) {
            if (dcol != 0 || drow != 0) {
                if (alive(col + dcol, row + drow))
                    n++;
            }
        }
    }
    
    return n;
}

char Field::getchar (int col, int row)
{
    if (alive(col, row))
        return _calive;
    else
        return _cdead;
}

void Field::setrow(int row, char const *const str)
{
    row = _normalize(row, _rows);
    for (int col = 0; col < _cols; col++) {
        if (str[col] != 0) {
            bool check = (str[col] == _calive);
            alive(col, row, check);
        } else
            return;
    }
}

std::ostream& operator<< (std::ostream& output, Field& that)
{
    int result = std::system("clear");
    assert(result == 0);    /* What should I do with it? */
    for (int row = 0; row < that._rows; row++) {
        /* Search for the last alive cell in a row */
        int last = that._cols - 1;
        for (int col = last; col >= 0; col--) {
            last = col;
            if (that.alive(last, row))
                break;
        }
        /* Print */
        for (int col = 0; col <= last; col++)
            output << that.getchar(col, row);
        
        //output << '.'; /* for debug, to see end of line */
        
        output << std::endl;
    }
    
    return output;
}

int Field::_normalize(int index, int count)
{
    while (index < 0)
        index += count;
    while (index >= count)
        index -= count;
    return index;
}
    
int Field::_addr(int col, int row)
{
    col = _normalize(col, _cols);
    row = _normalize(row, _rows);
    return row * _cols + col;
}




