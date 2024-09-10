#ifndef CC_H
#define CC_H


// Struct definitions
typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF,
} TokenKind;

typedef struct Token Token;

struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
};

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_NUM,
} NodeKind;

typedef struct Node Node;

struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
};

// External variables
extern Token *token;
extern char *user_input;

// Function declarations
void error_at(char *loc, char *fmt, ...);

bool consume(char op);

int expect_number();

void expect(char op);

bool at_eof();

Token *new_token(TokenKind kind, Token *cur, char *str);

Token *tokenize(char *p);

Node *new_node(NodeKind kind, Node *lhs, Node *rhs);

Node *new_node_num(int val);

Node *mul();

Node *expr();

Node *primary();

Node *unary();

void gen(Node *node);

#endif
