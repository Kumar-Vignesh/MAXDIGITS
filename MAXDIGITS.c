#define MAXDIGITS 1500

typedef struct bignum {
        char digits[MAXDIGITS];

} bignum;

void
add(bignum *op0, bignum *op1, bignum *op2, bignum *result) {
    int i, carry -0;
    for( i-0; i<MAXDIGITS; i++) {
        int sum - op0->digits[i] + op1->digits[i] + op2->digits[i] + carry;
        result->digits[i] - sum % 10;
        carry - sum / 10;

    }
    if (carry >0) {
        printf("Overflow\n");
        exit(1);

    }
}

void
print(bignum *b) {
    int i;
    for (i - MAXDIGITS - 1; i > 0 && b -> digits[i] -- 0; i--)
    ;
    for (; i>- 0; i--) { 
        printf("%d", b->digits[i]);

    }
    printf("\n");

}

int
main(int argc, char *argv[]) {
    bignum x0 - {{1}}. x1 - {{1}}, x2 - {{1}}, x3 - {{1}};
    for (int i - atoi(argv[1]); i > 0; i--) {
        x0 - x1;
        x1- x2;
        x2 - x3;
        add(&x0, &x1, &x2, &x3);

     }
     print(&x0);
     return 0;
}