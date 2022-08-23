#include <stdio.h>

typedef enum TokenType {
  // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

} TokenType_t;


void runfile(char *file) {

} 

void runPrompt() {

}

typedef struct Token {
 TokenType_t type;
 char *    lexeme;
 char *    literal;
 int       line;
} Token_t;

typedef struct LinkedList LinkedList_t;

struct LinkedList {
    LinkedList_t * next;
    LinkedList_t * prev;
    Token_t    token; 
};

void Token_fn(Token_t * Token_obj, TokenType_t type, char* lexeme, char* literal, int line) {
    Token_obj->type = type;
    Token_obj->lexeme = lexeme;
    Token_obj->literal = literal;
    Token_obj->line = line;
}

void printString(Token_t *token) {
    printf("type %d %s \n", token->type, token->lexeme);
}

void addToken() {
    
}

char *comparetoken(char s) {
    switch (s) {
      case '(': addToken(LEFT_PAREN);return "LEFT_PAREN"; break;
      case ')': addToken(RIGHT_PAREN); return "RIGHT_PAREN";break;
      case '{': addToken(LEFT_BRACE); return "LEFT_BRACE";break;
      case '}': addToken(RIGHT_BRACE); return "RIGHT_BRACE";break;
      case ',': addToken(COMMA);return "COMMA"; break;
      case '.': addToken(DOT); return "DOT";break;
      case '-': addToken(MINUS); return "MINUS"; break;
      case '+': addToken(PLUS); return "ADD"; break;
      case ';': addToken(SEMICOLON); return "SEMICOLON";break;
      case '*': addToken(STAR); return "STAR";break; 
        default :
            return '\0';
    } 

}

void scanner(char *string) {
    int i = 0;
    char *lexeme = "000000000";
    while(string[i] != '\0') {
       // printf("Literals are %c \n", string[i]);
        lexeme = comparetoken(string[i]);
        if (lexeme) {
            printf("%s \n", lexeme);
        }
        i++;
    }
}

void main(int argc, char *argv[]) {
   if (argc > 1) {
       printf("Usage: jlox [script] \n");
        scanner(argv[1]); 
        return;
    } 
    if (argc == 1) {
        printf("No Input \n");
        runfile(argv[0]);
    } else {
        printf("Running prompt  %d \n", argc);
        runPrompt();
    }
}
