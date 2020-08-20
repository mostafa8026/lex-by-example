%{
#include "ex.h"
%}

%%

"db_type"		return TYPE;
"db_name"		return NAME;
"db_table_prefix"	return PREFIX;
"db_port"		return PORT;
[a-zA-Z_]+		return IDENTIFIER;
":"			return COLON;
[1-9][0-9]*		return NUMBER;
[ \t\n]			;
.			printf("Not allowed character");

%%

int yywrap(void)
{
	return 1;
}
