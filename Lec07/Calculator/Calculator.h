#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MaxSize 0x100

class Calculator
{
    public:
        Calculator();

        void createFormula();
        void postfix();
        void calc();
        void print_postfix();

        int calc_value(int _a, int _b, char _symbol); //calculate _a symbol _b and return the result
        int ICP(char _Operator); // return ICP
        int ISP(char _Operator); // return ISP

    private:
         char formula[MaxSize];
         char postfix_formula[MaxSize], *PFptr; // Use PFptr to point the storage position
};

#endif // CALCULATOR_H
