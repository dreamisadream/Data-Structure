#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define MaxDegree 100

//p(x) = a_1 x^e1 + ... + a_n x^en
class polynomial
{
//objects:                      a set of ordered pairs of <e_i, a_i>
//where a_i Coefficient and e_i Exponent
//We assume that Exponent consits of integers >= 0
  public:
    polynomial(char polyId);
    // return the polynomial p(x) = 0
    polynomial(const char *poly);
    // return presetting polynomial

    void setPolynomial(const char *poly);

    int operator!();
    // if *this is the zero polynomial, return 1; else return 0;

    float Coef(polynomial poly, int e) const;
    // return the coefficient of e in *this

    int LeadExp(polynomial poly) const;
    // return the largest exponent in *this

    polynomial Add(polynomial poly);
    // return the sum of the polynomials *this and poly

    polynomial Mult(polynomial poly);
    // return the product of polynomials *this and poly

    float Eval(float f);
    //Evaluate the polynomial *this at f and return the result

    int COMPARE(const int a, const int b);
    // 1: bigger 0: equal -1: smaller

    void Attach(polynomial &poly, float coeffi, int exp);
    // change poly's coefficient

    void Remove(polynomial &poly, int exp);
    // remove poly's exp term

    void printResult();

  private:
    int degree;   // degree <= MaxDegree
    float coef[MaxDegree + 1];
};

#endif // POLYNOMIAL_H
