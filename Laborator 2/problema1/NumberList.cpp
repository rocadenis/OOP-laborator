#include "NumberList.h"
#include <cstdio>

    void NumberList::Init()
    {
        count=0;
        numbers[count]=0;
    }          // count will be 0
    bool NumberList::Add(int x)
    {
        if (count>=10)
            return false;
        else 
             numbers[count++]=x;
    return true;
    }     // adds X to the numbers list and increase the data member count.
                          // if count is bigger or equal to 10, the function will return false
   void NumberList::Sort() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                int aux   = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
        }
    }
}   // will sort the numbers vector
    void NumberList::Print(){
        for(int i=0;i<count; i++)
        printf(" %d", numbers[i]);
    }         // will print the current vector
