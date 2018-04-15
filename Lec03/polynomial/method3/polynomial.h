#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <term.h>

#define MaxTerms 1000

class polynomial
{
  public:
    polynomial();
    polynomial(char _name);
    polynomial Add(polynomial B);

    void init();
    void setPolynomial(const char *poly);
    void Attach(float coeffi, int exp);
    // change poly's coefficient
    void printResult();

    int COMPARE(int a, int b);


  private:
    static class term termArray[MaxTerms];
    static int freePos;
    int Start, Finish;
};

#endif
