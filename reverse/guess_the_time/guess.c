#include <stdlib.h>
#include<time.h>
#include<stdio.h>
void setup(){

    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

}

int read_num(){

int num;
char input[32]={0};
read(0,input,0x1f);
num=strtol(input,NULL,0);
return num;

}



void win(){
    FILE* f = fopen("flag.txt","r");
    char flag[30];
    if (f==NULL){
        perror("Flag not found");
        exit(1);
    }
    fgets(flag,30,f);
    write(1,flag,sizeof(flag));
}
void game(){
int guess;
printf("now guess a number : \n");
srand(time(0));
int rng=rand() % 99;
guess=read_num();
if (guess==rng){win();}
else{system("clear");
printf("wrong it was %d \n \n",rng);
game();        }
}


int main(){
setup();
system("clear");
printf("let's play a guessing game \n");
printf("if you guess right i'll give you a flag \n");
game();
}
