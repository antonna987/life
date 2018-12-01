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
#include "row.h"

class Field {
public:
    Field(int width, int height);  /* (x, y) */
    Field(const Field& orig);
    ~Field();
    
    int width();
    int height();
    Cell& cell(int col, int row);
    int  getncount(int col, int row);
    void setrow(int row, const char *str);
    friend std::ostream& operator<< (std::ostream& output, Field& that);
private:
    Row *_rows;
    int _width;
    int _height;

    int _normalize(int index, int count);
    int _addr(int col, int row);
};

#endif /* FIELD_H */

