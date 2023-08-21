#include <stdio.h>
#include <stdlib.h>

#define MAXDIGITS 50

#////////
// struct with char[number of digits]
// how to 0th digits
// print bignumbers

typedef struct bignum {
        char digits[MAXDIGITS];
} bignum;

void printv2(bignum *b);
void
print(bignum *b) ;

void
add(bignum *op0, bignum *op1, bignum *op2, bignum *result); 

void
add(bignum *op0, bignum *op1, bignum *op2, bignum *result) {
    int i, carry = 0;
    print(op0);
    print(op1);
    print(op2);
    print(result);
    for( i=0; i<MAXDIGITS; i++) {
        int sum = op0->digits[i] + op1->digits[i] + op2->digits[i] + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;

    }
    if (carry >0) {
        printf("Overflow\n");
        exit(1);

    }
    // printv2(result);
}

void printv2(bignum *b) {
    for(int i= MAXDIGITS -1; i >= 0 ; i-- ) {
         printf("%d", b->digits[i]);
    }
    printf("\n");
}


void setvalue0thdigit(bignum *b,int val);
void setvalue0thdigit(bignum *b,int val) {
    b->digits[0]= val;
    for(int i=1 ; i < MAXDIGITS; i++ ) {
        b->digits[i]=0;
    }
}

void
print(bignum *b);



void
print(bignum *b) {
    int i;
    for (i - MAXDIGITS - 1; i > 0 && b -> digits[i] == 0; i--)
    ;
    for (; i>- 0; i--) { 
        printf("%d", b->digits[i]);

    }
    printf("\n");

}

int
main(int argc, char *argv[]) {
    bignum x0  ; 
    bignum x1  ; 
    bignum x2  ;
    bignum x3  ;
    setvalue0thdigit(&x0,0);
    setvalue0thdigit(&x1,1);
    setvalue0thdigit(&x2,1);
    setvalue0thdigit(&x3,2);
    printv2(&x0);
    printv2(&x1);
    printv2(&x2);
    printv2(&x3);
   
    
    // 0 1 1 2 4 7 13 24
    int nthnumber = 5;
    for (int i =0 ; i < nthnumber ; i++) {
        printf("iteration %d \n", i+1);
        printv2(&x0);
        printv2(&x1);
        printv2(&x2);
        printv2(&x3);
        x0 = x1;
        x1 = x2;
        x2 = x3;
        add(&x0, &x1, &x2, &x3);

     }
     printf("final number");
     printv2(&x3);
     return 0;
}
