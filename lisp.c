#include <stdio.h>
#include <stdlib.h>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

char *read();
int eval(char *);
int op_add(char *);
int op_sub(char *);
int op_mul(char *);
int op_div(char *);

int main(int argc, char *argv[]) {

    printf("This is an interpreter for simple lisp expressions\n");

    while(1) {
        printf("* ");
        printf("-> %d\n", eval(read()));
    }

    return EXIT_SUCCESS;
}

char *read() {
    char *expr = malloc(256);
    fgets(expr, 256, stdin);
    return expr;
}

int eval(char *expr) {

    int result = 0;

    if (*(expr++) != '(') {
        printf("Error: expression must begin with a '('\n");
    }
    
    char op = *(expr++);

    switch(op) {
        case ADD:
            result = op_add(expr);
            break;
        case SUB:
            result = op_sub(expr);
            break;
        case MUL:
            result = op_mul(expr);
            break;
        case DIV:
            result = op_div(expr);
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

int op_add(char *expr) {

    int sum = 0;

    while(*expr != ')') {
        if (*expr == ' ') {
            expr++;
            continue;
        }
        
        int num = 0;
        sscanf(expr++, "%d", &num);
        sum += num;
    }

    return sum;
}

int op_mul(char *expr) {

    int prod = 1;

    while(*expr != ')') {
        if (*expr == ' ') {
            expr++;
            continue;
        }
        
        int num = 0;
        sscanf(expr++, "%d", &num);
        prod *= num;

    }
    
    return prod;
}

int op_div(char *expr) {

    int n1 = 0;
    int n2 = 0;

    while(*(expr++) != ' ');
    sscanf(expr++, "%d", &n1);

    while(*(expr++) != ' ');
    sscanf(expr++, "%d", &n2);

    return n1 / n2;
}

int op_sub(char *expr) {
    
    int n1 = 0;
    int n2 = 0;

    while(*(expr++) != ' ');
    sscanf(expr++, "%d", &n1);
    
    while(*(expr++) != ' ');
    sscanf(expr++, "%d", &n2);

    return n1 - n2;
}

