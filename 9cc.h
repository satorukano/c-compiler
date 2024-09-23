#ifndef CC_H
#define CC_H


// Struct definitions
typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_IDENT,
    TK_EOF,
} TokenKind;

typedef struct Token Token;

struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
    int len;
};

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_EQ,
    ND_NE,
    ND_LT,
    ND_LE,
    ND_NUM,
    ND_ASSIGN,
    ND_LVAR
} NodeKind;

typedef struct Node Node;

struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
    int offset;
};

// External variables
extern Token *token;
extern char *user_input;
extern Node *code[100];

// Function declarations
void error_at(char *loc, char *fmt, ...);

bool consume(char *op);

int expect_number();

void expect(char *op);

bool at_eof();
bool consume_ident();

Token *new_token(TokenKind kind, Token *cur, char *str, int str_length);

Token *tokenize(char *p);

Node *new_node(NodeKind kind, Node *lhs, Node *rhs);

Node *new_node_num(int val);

Node *mul();

Node *expr();

void program();

Node *stmt();

Node *assign();

Node *primary();

Node *equality();

Node *relational();

Node *add();

Node *unary();

void gen_lval(Node *node);

void gen(Node *node);

#endif
