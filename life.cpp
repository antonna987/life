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
 * File:   life.cpp
 * Author: Anton Nazin <anton.na987@gmail.com>
 * 
 * Created on November 13, 2018, 9:08 PM
 */

#include "life.h"
#include <string>

Life::Life(int cols, int rows)
{
    _field = new Field(cols, rows);
}

Life::~Life()
{
    delete _field;
}

ostream& operator<<(ostream& os, Life& that)
{
    os << *(that._field);
    return os;
};

istream& operator>>(istream& is, Life& that)
{
    is >> *(that._field);
    return is;
}

void Life::tick(void)
{
    Field field(*_field); 
                
    for (int col = 0; col < field.width(); col++) {
        for (int row = 0; row < field.height(); row++) {
            int n = field.getncount(col, row);            
            if (field.get(col, row)) {
                /* Live cell */
                if (n < _ifless_dies || n > _ifmore_dies)
                    _field->set(col, row, false);
            } else {
                /* Dead cell */
                if (n == _ifequa_repr)
                    _field->set(col, row, true);
            }
        }
    }
}

