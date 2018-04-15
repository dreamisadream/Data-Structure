#ifndef TERM_H
#define TERM_H

#include <polynomial.h>

class term
{
    friend class polynomial;
    private:
     float coef;
     int exp;
};

#endif // TERM_H
