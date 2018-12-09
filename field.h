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
    bool get(int col, int row);
    void set(int col, int row, bool alive);
    int  getncount(int col, int row);
    friend std::ostream& operator<< (std::ostream& os, Field& that);
    friend std::istream& operator>> (std::istream& is, Field& that);
private:
    Row **_rows;
    int _width;
    int _height;

    void _init(int width, int height);
    int _normalize(int index, int count);
};

#endif /* FIELD_H */

