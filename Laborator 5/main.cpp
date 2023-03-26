#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>

int main() {
    Number s1("120", 8);
    --s1;
    --s1;
    s1.Print();
    s1.SwitchBase(5);
    printf("%d\n",s1.GetBase());
    printf("%d\n",s1.GetDigitsCount());
     Number n1("10110010",2);
   Number n2("734",8);
   Number n3("FF",16);

   printf("n1 has %d digits and it is written in base %d\n",n1.GetDigitsCount(),n1.GetBase());
   for (int tr=0;tr<n1.GetDigitsCount();tr++)
   {
      printf("n1[%d]=%c\n",tr,n1[tr]);
   }
   n1.Print();
   n2.Print();
   n1 = (n2+n3-n1)+n1; // after this n1 will be in base 16
   n1.SwitchBase(2);
   n1.Print();
   printf("%d\n",n1<n2);
  
    return 0;
}
