#include "Polynomial.h"

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

Polynomial::Polynomial()
{
    setPoly();
}

void Polynomial::setPoly()
{
    char input[0x100];

    cout << "Polynomial: ";
    cin.getline(input, 0x100);

    int coef;
    int exp;
    bool negative;

    char space[] = " ";
    char *terms = strtok(input, space);
    while(terms != NULL){
        coef = 0;
        exp  = 0;

        if(*terms == '-'){
            negative = true;
            if(*(terms+1) == 0)
                terms = strtok(NULL, space);
            else terms++;
        }
        else if(*terms == '+'){
            negative = false;
            terms = strtok(NULL, space);
        }

        while(isdigit(*terms)){
            coef = coef*10 + *terms-'0';
            terms++;
        }

        if(isalpha(*terms)){
            terms++; // to skip variable
            if(*terms == '^'){
                terms++;
                while(isdigit(*terms)){
                    exp = exp*10 + *terms-'0';
                    terms++;
                }
            }
            if(!exp)
                exp = 1;
            if(!coef)
                coef = 1;
        }

        if(coef){
            if(negative)
               coef *= -1;

            struct Term newTerm;
            newTerm.init(coef, exp);
            poly.push_back(newTerm);
        }
        terms = strtok(NULL, space);
    }
}

Polynomial operator+(Polynomial& A, Polynomial& B)
{
    Polynomial C;

    int A_exp, B_exp;

    list<Term>::iterator A_it, B_it;
    A_it = A.poly.begin();
    B_it = B.poly.begin();

    // Let's assume both of them are descending order or you can reorder them by adding some code
    while(A_it != A.poly.end() && B_it != B.poly.end()){
        A_exp = A_it->exp;
        B_exp = B_it->exp;

        Term newTerm;
        if(A_exp > B_exp){
            newTerm.coef = A_it->coef;
            newTerm.exp  = A_it->exp;
            C.poly.push_back(newTerm);
            A_it++;
        }
        else if(A_exp == B_exp){
            newTerm.coef = A_it->coef + B_it->coef;
            newTerm.exp  = A_it->exp;
            C.poly.push_back(newTerm);
            A_it++;
            B_it++;
        }
        else{
            newTerm.coef = B_it->coef;
            newTerm.exp  = B_it->exp;
            C.poly.push_back(newTerm);
            B_it++;
        }
    }
    if(A_it == A.poly.end())
        for(; B_it != B.poly.end(); B_it++){
            Term newTerm;
            newTerm.coef = B_it->coef;
            newTerm.exp  = B_it->exp;
            C.poly.push_back(newTerm);
        }
    else
        for(; A_it != A.poly.end(); A_it++){
            Term newTerm;
            newTerm.coef = A_it->coef;
            newTerm.exp  = A_it->exp;
            C.poly.push_back(newTerm);
        }

    return C;
}


void Polynomial::showPoly()
{
    for(list<Term>::iterator it = poly.begin(); it != poly.end(); it++){
        cout << it->coef << "x^" << it->exp << " + ";
    }
}
