/*
 ============================================================================
 Name        : calculator.c
 Author      : grnbows
 Version     : 1.16
 Copyright   : free
 Description : calculator in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // variable description
    float a,b,res,*x,*y;
    int k,factRes,size,i;
    char c;

    do
    {
        printf("Enter operation (+ - / * ! ^) for numbers and\n");  // prints operations list on the screen
        printf("enter operation (p, s) [plus, subtraction] for vectors:");
        scanf(" %c", &c);    // scan operation
        switch(c)  // 'plus' operation cycle
            {
        case '+':
            {
                printf("Enter the first number:");
                scanf("%f", &a);
                printf("Enter the second number:");
                scanf("%f", &b);
                printf("Result is %.2f (operation %c)\n",a+b,c);
                break;
            }
        case '-':  // 'minus' operation cycle
            {
                printf("Enter the first number:");
                scanf("%f", &a);
                printf("Enter the second number:");
                scanf("%f", &b);
                printf("Result is %.2f (operation %c)\n", a-b,c);
                break;
            }
        case '/':  // 'divide' operation cycle
            {
                printf("Enter the first number:");
                scanf("%f", &a);
                printf("Enter the second number:");
                scanf("%f", &b);
                if (b != 0) printf("Result is %.4f (operation %c)\n", a/b,c); // you can divide something only if second number != 0. 'Idiot check'
                else printf("You can't divide by zero\n");
                break;
            }
        case '*':  // 'multiplication' operation cycle
            {
                printf("Enter the first number:");
                scanf("%f", &a);
                printf("Enter the second number:");
                scanf("%f", &b);
                printf("Result is %.2f (operation %c)\n", a*b,c);
                break;
            }
        case '^':  // exponent cycle
            {
                printf("Enter the number:");
                scanf("%f", &a);
                printf("Enter the exponent (!only integer!):");
                scanf("%i", &k);
                res = 1;
                    for (int i=0; i<k;i++) res = res*a; // just * number on itself for k times
                printf("Result is %.2f\n", res);
                break;
            }
        case '!':  // factorial calculating
            {
                factRes = 1;
                printf("Enter the number (!only integer!):");
                scanf("%i",&k);
                if (k >= 0) for (int i=k; i!=1;i--) factRes = factRes*i;    // calculate factorial from back
                else printf("This number is below zero. Please, try again.");
                printf("Result is %i\n", factRes);
                break;
            }
        case 'p':
            {
                i=0;
                x=malloc(size*sizeof(int));
                y=malloc(size*sizeof(int));
                printf("Enter vector's size: ");
                scanf(" %i",&size);
                printf("Enter first vector: ");
                for(int i=0;i<size;i++)
                    scanf(" %f",&x[i]);
                printf("Enter second vector: ");
                for(int i=0;i<size;i++)
                    scanf(" %f",&y[i]);
                printf("Result vectors summ: ");
                for(int i=0;i<size;i++)
                    printf("%.2f ",x[i]+y[i]);
                printf("\n");
                free(x);
                free(y);
                free(res);
                break;
            }
         case 's':
            {
                i=0;
                x=malloc(size*sizeof(int));
                y=malloc(size*sizeof(int));
                printf("Enter vector's size: ");
                scanf(" %i",&size);
                printf("Enter first vector: ");
                for(int i=0;i<size;i++)
                    scanf(" %f",&x[i]);
                printf("Enter second vector: ");
                for(int i=0;i<size;i++)
                    scanf(" %f",&y[i]);
                printf("Result vectors subtraction : ");
                for(int i=0;i<size;i++)
                    printf("%.2f ",x[i]-y[i]);
                printf("\n");
                free(x);
                free(y);
                free(res);
                break;
            }
        }
        printf("\nTry again? Type any symbol to continue and 'q' for exit.");
        scanf(" %c", &c);
    } while (c != 'q');    // program working status
}
