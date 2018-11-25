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
 * File:   field.h
 * Author: Anton Nazin <anton.na987@gmail.com>
 *
 * Created on November 14, 2018, 8:44 PM
 */

#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include "cell.h"

class Field {
public:
    Field(int cols, int rows);  // (x, y)
    Field(const Field& orig);
    ~Field();
    
    int cols() { return _cols; };
    int rows() { return _rows; };
    bool alive(int col, int row);
    void alive(int col, int row, bool set);
    int  getncount(int col, int row);
    char getchar (int col, int row);
    void setrow(int row, char const *const str);
    friend std::ostream& operator<< (std::ostream& output, Field& that);
private:
    Cell *_cell;
    int _cols, _rows;

    char _calive = 'X';
    char _cdead  = ' ';
    
    int _normalize(int index, int count);
    int _addr(int col, int row);
};

#endif /* FIELD_H */

