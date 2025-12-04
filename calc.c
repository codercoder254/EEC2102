//@a.d.a.n_noa😇
// calc.c
// Compile: gcc -std=c11 -O2 -lm -o calc calc.c
// Usage: ./calc
// Type expressions like: 3+4*2, (2+3)^2, -3 + 4.5 * (2 - 1)
// Commands: "quit" or Ctrl+D to exit.
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

...

int is_op_char(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

// tokenize: numbers, operators, parentheses. handle unary minus as separate token type.
int tokenize(const char *s, TokenVec *out){
    tokvec_init(out);
    size_t i = 0;
    int expectUnary = 1; // at start of expression or after '(' or operator => unary allowed
    while(s[i]){
        if(isspace((unsigned char)s[i])){ i++; continue; }
        if(s[i] == '('){ Token t = {.type = TOK_LPAREN}; tokvec_push(out, t); expectUnary = 1; i++; continue; }
        if(s[i] == ')'){ Token t = {.type = TOK_RPAREN}; tokvec_push(out, t); expectUnary = 0; i++; continue; }
        if(is_op_char(s[i])){
            char c = s[i];
            if(c == '-' && expectUnary){
                Token t = {.type = TOK_UNARY, .op = 'u'}; // unary minus
                tokvec_push(out, t);
            } else {
                Token t = {.type = TOK_OP, .op = c};
                tokvec_push(out, t);
            }
            expectUnary = 1;
            i++; continue;
        }
        // number (use strtod)
        if(isdigit((unsigned char)s[i]) || s[i]=='.'){
            char *end;
            double val = strtod(s + i, &end);
            Token t = {.type = TOK_NUM, .value = val};
            tokvec_push(out, t);
            i = end - s;
            expectUnary = 0;
            continue;
        }
        // unknown char
        return 0;
    }
    return 1;
}

// Shunting-yard: convert token list to postfix (token vector)
int to_postfix(TokenVec *in, TokenVec *out_post){
    tokvec_init(out_post);
    // operator stack (tokens)
    Token *opstack = NULL; size_t top = 0, cap = 0;
    #define OPS_PUSH(x) do { if(top==cap){cap=cap?cap*2:32; opstack=realloc(opstack,cap*sizeof(*opstack));} opstack[top++]=(x);} while(0)
    #define OPS_POP() (opstack[--top])
    #define OPS_TOP() (opstack[top-1])
    for(size_t i=0;i<in->n;i++){
        Token t = in->a[i];
        if(t.type == TOK_NUM){
            tokvec_push(out_post, t);
        } else if(t.type == TOK_UNARY){
            // unary minus: treat as high-precedence operator (like 'u'), right-assoc
            OPS_PUSH(t);
        } else if(t.type == TOK_OP){
            while(top>0){
                Token o2 = OPS_TOP();
                if(o2.type == TOK_LPAREN) break;
                int p1 = precedence(t.op);
                int p2 = (o2.type==TOK_UNARY) ? 5 : precedence(o2.op);
                if( (is_right_assoc(t.op) && p1 < p2) || (!is_right_assoc(t.op) && p1 <= p2) ){
                    tokvec_push(out_post, OPS_POP());
                } else break;
            }
            OPS_PUSH(t);
        } else if(t.type == TOK_LPAREN){
            OPS_PUSH(t);
        } else if(t.type == TOK_RPAREN){
            int found = 0;
            while(top>0){
                Token x = OPS_POP();
                if(x.type == TOK_LPAREN){ found = 1; break; }
                tokvec_push(out_post, x);
            }
            if(!found){ free(opstack); return 0; } // mismatched parentheses
        }
    }
    while(top>0){
        Token x = OPS_POP();
        if(x.type == TOK_LPAREN || x.type == TOK_RPAREN){ free(opstack); return 0; } // mismatched
        tokvec_push(out_post, x);
    }
    free(opstack);
    return 1;
    #undef OPS_PUSH
    #undef OPS_POP
    #undef OPS_TOP
}

// Evaluate postfix
int eval_postfix(TokenVec *post, double *result){
    double *stack = NULL; size_t n=0, cap=0;
    #define PUSH(v) do{ if(n==cap){cap=cap?cap*2:32; stack=realloc(stack,cap*sizeof(*stack));} stack[n++]= (v);}while(0)
    #define POP() (stack[--n])
    for(size_t i=0;i<post->n;i++){
        Token t = post->a[i];
        if(t.type == TOK_NUM){
            PUSH(t.value);
        } else if(t.type == TOK_UNARY){
            if(n<1){ free(stack); return 0; }
            double a = POP();
            PUSH(-a);
        } else if(t.type == TOK_OP){
            if(n < 2){ free(stack); return 0; }
            double b = POP();
            double a = POP();
            double res = 0;
            switch(t.op){
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = pow(a,b); break;
                default: free(stack); return 0;
            }
            PUSH(res);
        } else return 0;
    }
    if(n != 1){ free(stack); return 0; }
    *result = stack[0];
    free(stack);
    return 1;
    #undef PUSH
    #undef POP
}

int main(void){
    char line[1024];
    puts("Out-of-the-box C calculator (type 'quit' to exit). Examples: -3 + (2^3*4)/7.5");
    while(1){
        printf("calc> ");
        if(!fgets(line, sizeof line, stdin)) break;
        // remove trailing newline
        size_t L = strlen(line);
        while(L && (line[L-1]=='\n' || line[L-1]=='\r')) line[--L] = 0;
        if(L==0) continue;
        if(strcmp(line,"quit")==0) break;

        TokenVec toks;
        if(!tokenize(line, &toks)){
            printf("Error: tokenization failed (invalid character).\n");
            continue;
        }
        TokenVec post;
        if(!to_postfix(&toks, &post)){
            printf("Error: mismatched parentheses or invalid expression.\n");
            tokvec_free(&toks);
            continue;
        }
        double ans;
        if(!eval_postfix(&post, &ans)){
            printf("Error: evaluation failed (bad expression).\n");
        } else {
            printf("= %.12g\n", ans);
        }
        tokvec_free(&toks);
        tokvec_free(&post);
    }
    puts("Bye.");
    return 0;
}

