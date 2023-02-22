#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
using namespace std;

 int main()
 {
   int b;
   cin>>b;
   cout<<b;
    int a[50],i=1, sum;//vreau sa memorez numerle intr un vector
    char nr[100];
    FILE *fp;
    fp= fopen ("int.txt", "r");
    if (fp == NULL) {
        printf("Nu s-a putut deschide fisierul.\n");
        return 1;
    }
       while (fgets(nr, 100, fp)!=NULL){
        a[i]=atoi (nr);
         printf("Numarul %d este: %d\n",i, a[i]);//vreau sa afisez cate numere am si care sunt numerele 
         sum=sum+a[i];
         i++;
       }
    printf("Suma este: %d\n",sum);
    return 0;
 }