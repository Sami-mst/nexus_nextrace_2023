#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void segfault_handler(){
    printf("\n\033[1;31mCRITICAL\033[1;0m : the mainframe has crashed!!!\n\n\033[1;31mhere's your flag : \n");
    printf("\033[1;32m");
    char flag[24];
    int xor[]={254,245,232,229,227,235,227,163,247,207,246,164,229,252,228,207,253,164,227,228,245,226,237,144};
    for(int i=0;i<24;i++){
        int a = 0x90 ^xor[i];
        printf("%c",a);
    }
    exit(1);
}
int main(){
    signal(SIGSEGV,segfault_handler);
    printf("\033[1;33mmake me crash :) \033[1;0m\n");
    printf("give me your name : ");
    char ptr[1024];
    scanf("%s",ptr);
    printf("welcome %s , enjoy your capture the flag journey with nexus\n",ptr);
    
    return 0;

}