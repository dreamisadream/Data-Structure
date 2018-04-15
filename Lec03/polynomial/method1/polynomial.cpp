#include "polynomial.h"

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

polynomial::polynomial(char polyId)
{
  char poly[0x400];

  // get a polynomial
  cout << "Enter polynomial " << polyId << " :";
  cin.getline(poly, 0x3ff);

  setPolynomial(poly);
}


polynomial::polynomial(const char *poly)
{
  setPolynomial(poly);
}

void polynomial::setPolynomial(const char *poly)
{
  // parse
  memset(coef, 0, sizeof(coef));
  degree =  0;

  bool is_exp = false;
  bool negaitive = false;
  bool coeffi_set = false;

  int len = strlen(poly);
  int coeffi;

  for(int i = 0; i<len || is_exp; i++){

    if(isspace(poly[i]) && !is_exp)
      continue;
    if(poly[i] == 'x'){ // poly: x
      is_exp = true;
      continue;
    }
    if(poly[i] == '+'){
      negaitive = false;
      continue;
    }
    if(poly[i] == '-'){
      negaitive = true;
      continue;
    }

    if(!is_exp){
      coeffi = 0;
      while(isdigit(poly[i])){
        coeffi *= 10;
        coeffi += poly[i++] - '0';
        coeffi_set = true;
      }
      if(poly[i] == 0  || poly[i] != 'x'){ //end or constant
        if(negaitive)
          coeffi = -coeffi;
        coef[0] = coeffi;
        coeffi_set = false;
      }
      i--;
    }
    else{
      if(!coeffi_set)
        coeffi = 1;
      if(negaitive)
        coeffi = -coeffi;
      int exp = 0;
      if(poly[i] != '^')
        exp = 1;
      else{
        i++;
        while(isdigit(poly[i])){
          exp *= 10;
          exp += poly[i++] - '0';
        }
        i--;
      }

      coef[exp] = coeffi;
      degree = max(degree, exp);

      is_exp = false;
      coeffi_set = false;
    }
  }
}


int polynomial::operator!()
{
  for(int i = 0; i<=degree; i++)
    if(coef[i]!=0)
      return 0;
  return 1;
}


float polynomial::Coef(polynomial poly, int e) const
{
  return poly.coef[e];
}


int polynomial::LeadExp(polynomial poly) const
{
  return poly.degree;
}


polynomial polynomial::Add(polynomial poly)
{
  polynomial d("0");
  d.degree = max(LeadExp(static_cast<polynomial>(*this)), LeadExp(poly));
  while(!this == 0 && !poly == 0) //in ADT we define operation! which returns 1 if poly is zero, really wierd Uh!
  {
    float sum;
    switch(COMPARE(LeadExp(static_cast<polynomial>(*this)), LeadExp(poly))){
      case 1:
        Attach(d, Coef(static_cast<polynomial>(*this), LeadExp(static_cast<polynomial>(*this))), LeadExp(static_cast<polynomial>(*this)));
        Remove(static_cast<polynomial&>(*this), LeadExp(static_cast<polynomial>(*this)));
        break;
      case 0:
        sum = Coef(static_cast<polynomial>(*this), LeadExp(static_cast<polynomial>(*this))) + Coef(poly, LeadExp(poly));
        if(sum)
          Attach(d, sum, LeadExp(poly));
        Remove(static_cast<polynomial&>(*this), LeadExp(static_cast<polynomial>(*this)));
        Remove(poly, LeadExp(poly));
        break;
      case -1:
        Attach(d, Coef(poly, LeadExp(poly)), LeadExp(poly));
        Remove(poly, LeadExp(poly));
        break;
    }
  }

  return d;
}


int polynomial::COMPARE(const int a, const int b)
{
  if(a > b)
    return 1;
  else if(a == b)
    return 0;
  return -1;
}


void polynomial::Attach(polynomial &poly, float coeffi, int exp)
{
  poly.coef[exp] = coeffi;
}


void polynomial::Remove(polynomial &poly, int exp)
{
  poly.coef[exp] = 0;
  if(exp == poly.degree)
    for(; poly.coef[poly.degree] == 0 && poly.degree != 0; poly.degree--);
}


void polynomial::printResult()
{
  if(degree == 0){
    cout << coef[0] << endl;
    return;
  }
  if(degree == 1){
    if(coef[1] == 1)
      cout << "x";
    else if(coef[1] == -1)
      cout << "-x";
    else
      cout << coef[1] << "x";
    if(coef[0] > 0)
      cout << " + " << coef[0];
    else if(coef[0] < 0)
      cout << " - " << -coef[0];
    cout << endl;
    return;
  }

  int lowest_term;
  for(int i = 0; i<=degree; i++)
    if(coef[i]){
      lowest_term = i;
      break;
    }

  if(coef[degree]==1)
    cout << "x^" << degree;
  else if(coef[degree] == -1)
    cout << "-x^" << degree;
  else
    cout << coef[degree] << "x^" << degree;

  for(int i = degree-1; i>lowest_term && i != 1; i--)
    if(coef[i] == 1)
      cout << " + x^" << i;
    else if(coef[i] == -1)
      cout << " - x^" << i;
    else if(coef[i] > 0)
      cout << " + " << coef[i] << "x^" << i;
    else if(coef[i] < 0)
      cout << " - " << -coef[i] << "x^" << i;

  if(coef[1] == 1)
    cout << " + x";
  else if(coef[1] == -1)
    cout << " - x";
  else if(coef[1] > 0)
    cout << " + " << coef[1] << "x";
  else if(coef[1] < 0)
    cout << " - " << coef[1] << "x";

  if(coef[0] > 0)
    cout << " + " << coef[0];
  else if(coef[0] < 0)
    cout << " - " << -coef[0];

  cout << endl;
}
