/*
 * precheck.c
 *
 *  Created on: 2013-8-12
 *      Author: leiming
 */

#include <stdio.h>
#include "precheck.h"

extern char *yytext;

int main(int argc , char **argv)
{
	FILE *fp;
	char buff[LINE_LEN];
	int tok_id;
	int line_no = 1;

	fp = fopen("./test.mxt" , "r+");
	if(!fp)
	{
		printf("open mxt failed!\n");
		return -1;
	}

	/***Handle*/
	show_title();
	memset(buff , 0 , sizeof(buff));
	while(fgets(buff , sizeof(buff) , fp) != NULL)
	{
		printf(">>>>>>>>>>reads:%s\n" , buff);
		parse_line(buff);

		switch(yylex())
		{
		case TOK_VAR:
			printf("var~\n");
			tok_id = yylex();
			if(tok_id != TOK_NUMBER)
			{
				printf("%d:syntax error!\n" , line_no);
			}
			else
			{
				tok_id = yylex();
				if(tok_id != TOK_NUMBER)
				{
					printf("%d:no init var!\n" , line_no);
				}
				else
				{
					printf("good!\n");
				}
			}
		break;
		case TOK_IF:
					printf("if~\n");
				break;
		case TOK_ELSE:
					printf("else~\n");
				break;
		case TOK_COMMENT:
					printf("comment~\n");
				break;
		case TOK_PROC:
					printf("proc~\n");
				break;
		case TOK_NUMBER:
					printf("number:%s~\n" , yytext);
				break;
		}

		memset(buff , 0 , sizeof(buff));
		line_no++;
	}


	/***RETURN*/
	fclose(fp);

	return 0;
}
