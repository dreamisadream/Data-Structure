#include <stdio.h>
#include <string.h>

void SWAP(char _str[], int pos1, int pos2)
{
  char tmp;
  tmp = _str[pos1];
  _str[pos1] = _str[pos2];
  _str[pos2] = tmp;
}

void perm(char _str[], int length)
{
  int a[8];      // 10個char，需要9層loop

  for(a[0] = 0; (a[0] < 10 && length == 9) || a[0] ==0 ; a[0]++)
  {
    SWAP(_str, length-9, length-9+a[0]);
  for(a[1] = 0; (a[1] < 9 && length >= 8) || a[1] ==0 ; a[1]++)
  {
    SWAP(_str, length-8, length-8+a[1]);
  for(a[2] = 0; (a[2] < 8 && length >= 7) || a[2] ==0 ; a[2]++)
  {
    SWAP(_str, length-7, length-7+a[2]);
  for(a[3] = 0; (a[3] < 7 && length >= 6) || a[3] ==0 ; a[3]++)
  {
    SWAP(_str, length-6, length-6+a[3]);
  for(a[4] = 0; (a[4] < 6 && length >= 5) || a[4] ==0 ; a[4]++)
  {
    SWAP(_str, length-5, length-5+a[4]);
  for(a[5] = 0; (a[5] < 5 && length >= 4) || a[5] ==0 ; a[5]++)
  {
    SWAP(_str, length-4, length-4+a[5]);
  for(a[6] = 0; (a[6] < 4 && length >= 3) || a[6] ==0 ; a[6]++)
  {
    SWAP(_str, length-3, length-3+a[6]); 
  for(a[7] = 0; (a[7] < 3 && length >= 2) || a[7] ==0 ; a[7]++)
  {
    SWAP(_str, length-2, length-2+a[7]); 
  for(a[8] = 0; (a[8] < 2 && length >= 1) || a[8] ==0 ; a[8]++)
  {
    SWAP(_str, length-1, length-1+a[8]);
    printf("%s\n", _str);
    SWAP(_str, length-1, length-1+a[8]);
  }
    SWAP(_str, length-2, length-2+a[7]); 
  }
    SWAP(_str, length-3, length-3+a[6]); 
  }
    SWAP(_str, length-4, length-4+a[5]);
  }
    SWAP(_str, length-5, length-5+a[4]); 
  }
    SWAP(_str, length-6, length-6+a[3]);
  }
    SWAP(_str, length-7, length-7+a[2]);
  }
    SWAP(_str, length-8, length-8+a[1]);
  }
    SWAP(_str, length-9, length-9+a[0]);
  }

}

int main()
{
  char str[11];
  printf("string:");
  scanf("%10s", str);
  perm(str, strlen(str)-1);
  return 0;  
}
