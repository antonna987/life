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
#include <string>
#include "row.h"

Row::Row(int width)
{
    assert(width > 0);
    _width = width;
    _cells.reserve(width);
}

Row::Row(const Row *orig) : Row(orig->_width)
{
    for (int i = 0; i < _width; i++)
        _cells[i] = orig->_cells[i];
}

Row::~Row()
{
}

int Row::width()
{
    return _width;
}

bool Row::get(int col)
{
    assert(col >= 0);
    assert(col < _width);
    
    return _cells[col];
}

void Row::set(int col, bool alive)
{
    _cells[col] = alive;
}

std::ostream& operator<< (std::ostream& os, Row& that)
{
    /* Search for the last alive cell in a row */
    int last;
    for (last = that._width - 1; last >= 0; last--)
        if (that._cells[last])
            break;
    /* Print */
    for (int col = 0; col <= last; col++)
        os << that._btoc(that._cells[col]);

    //output << '.'; // for debug, to see end of line

    os << std::endl;
    
    return os;
}

std::istream& operator>> (std::istream& is, Row& that)
{
    std::string str;
    getline(is, str);
    
    int length = str.length();
    if (length > that._width)
            length = that._width;

    for (int i = 0; i < length; i++)
        that._cells[i] = that._ctob(str.at(i));
    
//    using namespace std;
//    cout << "String: " << str << endl;
//    cout << "Length: " << length << endl;
//    cout << "Result: " << that;
//    cout << "Width: " << that._width << endl;
//    cout << "Press Enter to continue..." << endl;
//    cin.ignore();
    
    return is;
}

bool Row::_ctob(char c)
{
    return (c == _calive);
}

char Row::_btoc(bool b)
{
    return (b ? _calive : _cdead);
}

