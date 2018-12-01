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
 * File:   row.cpp
 * Author: Anton Nazin <anton.na987@gmail.com>
 * 
 * Created on December 1, 2018, 12:34 PM
 */

#include <cassert>
#include <climits>
#include <cstring>
#include "row.h"


/*
 * Public
 */

Row::Row(int width)
{
    _width = width;
    _cells = new Cell[_width];
}

Row::Row(const Row *orig) : Row(orig->_width)
{
    for (int i = 0; i < _width; i++)
        _cells[i].alive(orig->_cells[i]);
}

Row::~Row()
{
    delete [] _cells;
}

void Row::set(const char *str)
{
    int length = strnlen(str, INT_MAX);
    if (length > 0) {
        if (length > _width)
            length = _width;
        for (int i = 0; i < length; i++)
            _cells[i].alive(str[i]);
    }
}

int Row::width()
{
    return _width;
}

Cell& Row::cell(int col)
{
    return _cells[col];
}

std::ostream& operator<< (std::ostream& output, Row *that)
{
    /* Search for the last alive cell in a row */
    int last;
    for (last = that->_width - 1; last >= 0; last--)
        if (that->cell(last).alive())
            break;
    /* Print */
    for (int col = 0; col <= last; col++)
        output << that->cell(col);

    //output << '.'; /* for debug, to see end of line */

    output << std::endl;
    
    return output;
}


/*
 * Private
 */

