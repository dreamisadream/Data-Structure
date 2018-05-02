#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <list>

struct Term
{
    int coef;
    int exp;
    void init(int c, int e){coef = c; exp = e;}
};

class Polynomial
{
    public:
        friend Polynomial operator+( Polynomial&,  Polynomial&);
        Polynomial(); // constructor
        void setPoly();
        void showPoly();

    private:
        std::list<Term> poly;
};

#endif // POLYNOMIAL_H
