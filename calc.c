//@a.d.a.n_noa😇
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

typedef enum {
    TOK_NUM,
    TOK_OP,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_UNARY
} TokenType;

typedef struct {
    TokenType type;
    double value;
    char op;
} Token;

typedef struct {
    Token *a; size_t n; size_t cap; // n - number of elements, cap - capacity & size_t is an unsigned integer type
} TokenVec;

void tokvec_init(TokenVec *v) {
    v->a = NULL;
    V->n = 0;
    v->cap = 0; 
}

void tokvec_push(TokenVec *v, Token t) {
    if ( v->n == v->cap)
    {
        v->cap = v->cap? v->cap*2 : 16; 
        v->a = realloc(v->a, v ->cap * sizeof(*v->a));
    }
        v->a[v->n++] = t;
}

void tokvec_free(TokenVec *v) {

    free(v->a);
    v->a = NULL;
    v->n = v->cap = 0;
}

int precedence(char op){
    if(op == '^') return 4;
    if(op == '*' || op == '/') return 3;
    if(op == '+' || op == '-') return 2;
    return 0;
}

//ritfht assoc only for ^
int is_right_assoc(char op){
    return op == '^';
}



