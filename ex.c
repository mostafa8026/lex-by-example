#include <stdio.h>
#include "ex.h"

extern int yylex();
extern char* yytext;

int main(void)
{
	int token, next_token;
	const char *names[] = {NULL, "db_port", "db_type", "db_table_prefix", "db_name"};
	do
	{
		//printf("start of the do-while\n");
		token = yylex();
		//printf("%d\n", token);
		if (token <= 4 && token >= 1){
			int colon_token = yylex();
			//printf("the colon is: %d\n", colon_token);
			if (colon_token != COLON){
				printf("You must pass : after your config\n");
			}
		}
		//printf("%s\n", names[token]);
		next_token = yylex();
		//printf("next token is: %d\n", next_token);
		if (next_token == IDENTIFIER || next_token == NUMBER)
		{
			if(token == PORT && next_token != NUMBER){
				printf("The port value must be a number\n");
			}else{
				printf("The config of %s is set to the %s\n", names[token], yytext);
			}
		}else{
			printf("Dadash dari eshtebah mizani");
		}
	} while (next_token);
}
