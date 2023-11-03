#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/* in this challenge we will learn how to shoot Uwu 
 * 
 * Understanding how to obtain the addresses of functions is a crucial skill in the field of cybersecurity
 * , particularly when dealing with low-level programming and exploitation.
 * In real-world scenarios, attackers often need to locate and manipulate the addresses of functions to achieve their goals. */

void init() {
    alarm(120);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    fflush(stdout);
    fflush(stdin);
}

void cat_flag(){
    system("cat /flag.txt");
}

int main() {
    init();
    uintptr_t address;

    printf("Guns up!\nAim carefully! : ");
    scanf("%lx", &address);
    printf("\nShoooot");
    void (*target)(void) = (void(*)(void))address;

    target();

    return 0;
}
