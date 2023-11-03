#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int main(){
srand(time(0));
printf("%d",rand() % 99);
}
