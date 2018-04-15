#include "polynomial.h"

#include <iostream>

using namespace std;

char rule[] = "**********\n1: add\n2: mult\n3: check if poly is zero\n4: check coeffi with expoential e\n\
5: print polynomial\n6:exit\n***************\nYour choice:";

int main()
{
  polynomial polyA('A');
  polynomial polyB('B');
  polynomial polyD("0");

  int option;
  while(true){
    cout << rule;
    cin >> option;
    switch(option){
      case 1:
        polyD = polyA.Add(polyB);
        break;
      case 2:
       // polyA.Mult(polyB);
        break;
      case 3:
        if(!polyA)
          cout << "Yes\n";
        else
          cout << "No\n";
        break;
      case 4:
        int e;
        cout << "e = ";
        cin >> e;
       // cout << polyA.Coef(e) << endl;
        break;
      case 5:
        char polyId;
        cout << "A or B or D:";
        cin >> polyId;
        switch(polyId){
          case 'A':
            polyA.printResult();
            break;
          case 'B':
            polyB.printResult();
            break;
          case 'D':
            polyD.printResult();
            break;
          default:
            cout << "Nothing" << endl;
            break;
        }
        break;
      case 6:
        return 0;
      default:
        cout << "Nothing done!\n";
        break;
    }

  }

  return 0;
}
