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
 * Author: Anton Nazin
 * 
 * Created on November 14, 2018, 8:44 PM
 */

#include <cassert>
#include <cstdlib>
#include "field.h"

Field::Field(int cols, int rows)
{
    assert(cols > 0 && rows > 0);
    _cols = cols;
    _rows = rows;
    int asize = _cols * _rows;
    _cell = new bool[asize];
    for (int i = 0; i < asize; i++)
        _cell[i] = false;
}

Field::Field(const Field& orig)
{
    //Field field(orig._cols, orig._rows);  
    //this = field;
    _cols = orig._cols;
    _rows = orig._rows;
    int asize = _cols * _rows;
    _cell = new bool[asize];
    for (int i = 0; i < asize; i++)
        _cell[i] = orig._cell[i];
}

Field::~Field()
{
    delete [] _cell;
}

int Field::getneigh(int col, int row)
{
    int n = 0;
    for (int dcol = -1; dcol < 2; dcol++) {
        for (int drow = -1; drow < 2; drow++) {
            if (dcol != 0 || drow != 0) {
                if (getalive(col + dcol, row + drow))
                    n++;
            }
        }
    }
    
    return n;
}

char Field::getchar (int col, int row)
{
    if (getalive(col, row))
        return _calive;
    else
        return _cdead;
}

void Field::setrow(int row, char const *const str)
{
    row = _swap(row, _rows);
    for (int col = 0; col < _cols; col++) {
        if (str[col] != 0) {
            bool alive = (str[col] == _calive);
            setalive(col, row, alive);
        } else
            return;
    }
}

std::ostream& operator<< (std::ostream& output, Field& that)
{
    int res = std::system("clear"); /* To prevent error: ignoring return val */
    res = 0;    /* What should I do with it? */
    for (int row = 0; row < that._rows; row++) {
        for (int col = 0; col < that._cols; col++)
            output << that.getchar(col, row);
        output << std::endl;
    }
    
    return output;
}

int Field::_swap(int colrow, int colrows)
{
    while (colrow < 0)
        colrow += colrows;
    while (colrow >= colrows)
        colrow -= colrows;
    return colrow;
}
    
int Field::_addr(int col, int row)
{
    col = _swap(col, _cols);
    row = _swap(row, _rows);
    return row * _cols + col;
}




