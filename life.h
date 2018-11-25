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
 * File:   life.h
 * Author: Anton Nazin
 *
 * Created on November 13, 2018, 9:08 PM
 */

#ifndef LIFE_HPP
#define LIFE_HPP

#include "field.h"
    
class Life {
public:
    Life(int cols, int rows) { _field = new Field(cols, rows); };
    ~Life() { delete _field; };
    void setrow(int row, char const *const str) { _field->setrow(row, str); };
    void setalive(int col, int row, bool alive) {
        _field->setalive(col, row, alive);
    };
    friend std::ostream& operator<< (std::ostream& output, Life& that) {
        Field& f = *(that._field);
        return output << f;
    };
    void tick(void);
private:
    Field *_field;
    int _ifless_dies = 2;
    int _ifmore_dies = 3;
    int _ifequa_repr = 3;
};


#endif /* LIFE_HPP */

