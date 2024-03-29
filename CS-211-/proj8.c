/*  Code for the user interface for Lab 8 for CS 211 Fall 2013  
 *
 *  Author: Pat Troy
 *  Date: 10/13/2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef enum {ERROR = 0, OPERATOR, VALUE, EOLN, QUIT, HELP} tokenType;

typedef struct tokenStruct
{
 tokenType type;
 char      op;
 int       val;
} token;
token getInputToken (FILE *in);

typedef struct stack{
 char data;
 struct stack *prev;
}Stack;

int isEmpty(Stack* stck)
{
 if(stck == NULL)
 {
  printf("Stack is empty!");
  return TRUE;
 }
 else
 {
  return FALSE;
 }
}

void push(Stack* stck, char data)
{
 int stk_push(Stack s, ElemType val){
   Stack* top = malloc(sizeof(NODE));
   top->prev = stck;
   top->data = data;
   s = top;
   s->size++;
   return 1;
}

void processExpression (token inputToken, FILE *in)
{
 /**********************************************/
 /* Declare both stack head pointers here      */
 Stack* nums = NULL;
 Stack* operantion = NULL;
 /* Loop until the expression reaches its End */
 while (inputToken.type != EOLN)
   {
    /* The expression contains an OPERATOR */
    if (inputToken.type == OPERATOR)
      {
       /* make this a debugMode statement */
       printf ("OP:%c, " ,inputToken.op);

       // add code to perform this operation here

      }

    /* The expression contain a VALUE */
    else if (inputToken.type == VALUE)
      {
       /* make this a debugMode statement */
       printf ("Val: %d, ", inputToken.val); 

       // add code to perform this operation here

      }
   
    /* get next token from input */
    inputToken = getInputToken (in);
   } 

 /* The expression has reached its end */

 // add code to perform this operation here


 printf ("\n");
}


/**************************************************************/
/*                                                            */
/*  The Code below this point should NOT need to be modified  */
/*  for this program.   If you feel you must modify the code  */
/*  below this point, you are probably trying to solve a      */
/*  more difficult problem that you are being asked to solve  */
/*                                                            */
/**************************************************************/

token getInputToken (FILE *in)
{
 token retToken;
 retToken.type = QUIT;

 int ch;
 ch = getc(in);
 if (ch == EOF)
   return retToken;
 while (('\n' != ch) && isspace (ch))
   {
    ch = getc(in);
    if (ch == EOF)
      return retToken;
   }
 
 /* check for a q for quit */
 if ('q' == ch)
   {
    retToken.type = QUIT;
    return retToken;
   }

 /* check for a ? for quit */
 if ('?' == ch)
   {
    retToken.type = HELP;
    return retToken;
   }

 /* check for the newline */
 if ('\n' == ch)
   {
    retToken.type = EOLN;
    return retToken;
   }

 /* check for an operator: + - * / ( ) */
 if ( ('+' == ch) || ('-' == ch) || ('*' == ch) ||
      ('/' == ch) || ('(' == ch) || (')' == ch) )
   {
    retToken.type = OPERATOR;
    retToken.op = ch;
    return retToken;
   }
   
 /* check for a number */
 if (isdigit(ch))
   {
    int value = ch - '0';
    ch = getc(in);
    while (isdigit(ch))
      {
       value = value * 10 + ch - '0';
       ch = getc(in);
      }
    ungetc (ch, in);  /* put the last read character back in input stream */
    retToken.type = VALUE;
    retToken.val = value;
    return retToken;
   }
      
 /* else token is invalid */
 retToken.type = ERROR;
 return retToken;
}

/* Clear input until next End of Line Character - \n */
void clearToEoln(FILE *in)
{
 int ch;
 
 do {
     ch = getc(in);
    }
 while ((ch != '\n') && (ch != EOF));
}

void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("or any infix mathematical expression using operators of (), *, /, +, -\n");
}

int main (int argc, char **argv)
{

 char *input;
 token inputToken;

 printf ("Starting Expression Evaluation Program\n\n");
 printf ("Enter Expression: ");

 inputToken = getInputToken (stdin);
 while (inputToken.type != QUIT)
   {
    /* check first Token on Line of input */
    if(inputToken.type == HELP)
      {
       printCommands();
       clearToEoln(stdin);
      }
    else if(inputToken.type == ERROR)
      {
       printf ("Invalid Input - For a list of valid commands, type ?\n");
       clearToEoln(stdin);
      }
    else if(inputToken.type == EOLN)
      {
       printf ("Blank Line - Do Nothing\n");
       /* blank line - do nothing */
      }
    else 
      {
       processExpression(inputToken, stdin);
      } 

    printf ("\nEnter Expression: ");
    inputToken = getInputToken (stdin);
   }

 printf ("Quitting Program\n");
 return 1;
}
