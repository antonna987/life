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
 * File:   cell.cpp
 * Author: Anton Nazin <anton.na987@gmail.com>
 * 
 * Created on November 25, 2018, 4:49 PM
 */

#include "cell.h"


/*
 * Public
 */

Cell::Cell()
{
    alive(false);
}

void Cell::alive(bool set)
{
    if (set)
        _data |= _CELL_MASK_ALIVE;
    else
        _data &= ~_CELL_MASK_ALIVE;
}

void Cell::alive(char set)
{
    alive(set != _cdead);
}

bool Cell::alive()
{
    return (_data & _CELL_MASK_ALIVE);
}

std::ostream& operator<< (std::ostream& output, Cell& that)
{
    output << ((that.alive()) ? that._calive : that._cdead);
    
    return output;
}


/*
 * Private
 */

