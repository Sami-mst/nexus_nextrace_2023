//gcc ret2win.c -fno-stack-protector -no-pie -o ret2win
#include<stdio.h>
void win(){
    FILE* f = fopen("flag.txt","r");
    char flag[30];
    if (f==NULL){
        perror("Flag file not found");
        exit(1);
    }
    fgets(flag,30,f);
    write(1,flag,sizeof(flag));
}

int main (){
char name [8];
gets(&name);
}
