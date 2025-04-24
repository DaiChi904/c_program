/*
 * lexer.c
 *
 *   算術式の字句解析ルーチン
 *
 */
#include <stdio.h>  /* fprintf */
#include <ctype.h>  /* isdigit */
#include <stdlib.h> /* atoi */
#include "calc.h"

token curr_token; /* 1番最近に読んだトークン */
char token_val;    /* トークンの意味値 */

/* lexer: 字句解析して結果を表示 */
int lexer()
{
  do
  {
    get_token();
    print_token(curr_token, token_val);
  } while (curr_token != EOREG);

  return 0;
}

/* get_token: 字句解析ルーチン */
void get_token()
{
  char c = *reg_string;
  token_val = *reg_string;

  if (c == '\0')
  {
    curr_token = EOREG;
  }
  else if (c == '\\')
  {
    c = *++reg_string;
    token_val = *reg_string;
    switch (c)
    {
    case 'e':
      curr_token = EPSILON;
      break;
    case '0':
      curr_token = EMPTY;
      break;
    case '*':
      curr_token = LETTER;
      break;
    case '.':
      curr_token = LETTER;
      break;
    case '(':
      curr_token = LETTER;
      break;
    case ')':
      curr_token = LETTER;
      break;
    case '|':
      curr_token = LETTER;
      break;
    default:
      fatal_error("Invalid escape sequence");
    }
  }
  else
  {
    switch (c)
    {
    case '*':
      curr_token = AST;
      break;
    case '.':
      curr_token = CONC;
      break;
    case '(':
      curr_token = LPAR;
      break;
    case ')':
      curr_token = RPAR;
      break;
    case '|':
      curr_token = VERT;
      break;
    default:
      if (isalpha(c) || isdigit(c))
      {
        curr_token = LETTER;
      }
      else
      {
        fatal_error("Invalid character");
      }
      break;
    }
  }

  reg_string++;
}

/* print_token: token を表示する */
void print_token(token tok, char c)
{
  switch (tok)
  {
  case EMPTY:
    printf("EMPTY\n");
    break;
  case EPSILON:
    printf("EPSILON\n");
    break;
  case AST:
    printf("AST\n");
    break;
  case CONC:
    printf("CONC\n");
    break;
  case LPAR:
    printf("LPAR\n");
    break;
  case RPAR:
    printf("RPAR\n");
    break;
  case VERT:
    printf("VERT\n");
    break;
  case LETTER:
    printf("LETTER(%c)\n", c);
    break;
  case EOREG:
    printf("EOREG\n");
    break;
  default:
    fatal_error("Invalid token");
    break;
  }
}
