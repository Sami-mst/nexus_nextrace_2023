#include<stdio.h>
#include<stdlib.h>
int has_flag=0;
void win(){
    FILE* f = fopen("flag.txt","r");
    char flag[30];
    if (f==NULL){
        perror("Flag not found");
        exit(1);
    }
    fgets(flag,30,f);
    write(1,flag,sizeof(flag));
    exit(0);
}
int balance=1000;
int flag=100000;
int fake_flag=100;
void menu(){
if(has_flag){win();}
//system("clear");
printf("your account : %d $ \n\n\n",balance);
printf("1) fake_flag %d $ \n",fake_flag);
printf("2) true_flag %d $ \n",flag);
}

int main(){
__int16_t cost=0;
int choice;
int item_number;
printf("welcome to the our shop\n");
while(1){
    menu();
    scanf("%d",&choice);
    if ( choice !=1 && choice !=2 )
    {
        printf("invalid choice \n");
        main();
    }
    else{
        printf("how many will you buy \n");
        scanf("%d",&item_number);
        if (item_number < 0) 
        {
            printf("invalid choice \n");
            main();
        }
        
    }



    if (choice == 1  ){

    if(fake_flag*item_number <= balance){
        cost=fake_flag*item_number;
        balance= balance -cost;
    }
    if (fake_flag*item_number > balance)
    {
        //system("clear");
        printf("insuficent money in your balance \n");
    }
    
    }

    if (choice == 2){

    if(flag*item_number <= balance){   cost=flag*item_number;
        cost=flag*item_number;
        balance= balance -cost;
        has_flag=1;
    }
    if (flag*item_number > balance)
    {   //system("clear");
        printf("insuficent money in your balance \n");
    }
}   
//add some color and flavor
//do u_int 16 to make it wrap faster
}
}