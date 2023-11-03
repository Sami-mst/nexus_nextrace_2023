#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


void segfault_handler(){
    printf("FAKE_FLAG");
    exit(EXIT_FAILURE);
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