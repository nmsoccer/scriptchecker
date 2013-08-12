%{
    #include <stdio.h>
	#include "precheck.h"
%}
number ([0-9])+
%%
VAR {
    //printf("var:%d\n" , TOK_VAR);
    return TOK_VAR;};
IF  {
    //printf("if:%d\n" , TOK_IF);
    return TOK_IF;
    };
ELSE {
     //printf("else:%d\n" , TOK_ELSE);
     return TOK_ELSE;
     };
PROC {
     //printf("proc:%d\n" , TOK_PROC);
     return TOK_PROC;
     };
[;] {
    //printf("comment:%d\n" , TOK_COMMENT);
    return TOK_COMMENT;
    };
{number} {
        //printf("number:%s\n" , yytext);
        return TOK_NUMBER;
         };
[\n]+ {
        return TOK_ENTER;
      }

%%
int parse_line(char *s)
{
    yy_scan_string(s);
    return 0;
}

int show_title()
{
    printf("----SCRIPT CHECKER------\n");
    return 0;
}


int yywrap()
{
    return 1;
}
