%{
int yylineno;
%}

alpha [A-Za-z]
digit [0-9]
und [_]

%%
[ \t] ;
\n	{yylineno++;}
"{"	{push(); return '{';}
"}"	{pop(); return '}';}
";"	     {   return(';'); }
","	     {   return(','); }
":"	     {   return(':'); }
"="	     {   return('='); }
"("	     {   return('('); }
")"	     {   return(')'); }
("[") 	     {   return('['); }
("]")        {   return(']'); }
"."	     {   return('.'); }
"&"	     {   return('&'); }
"!"	     {   return('!'); }
"~"	     {   return('~'); }
"-"	     {   return('-'); }
"+"	     {   return('+'); }
"*"	     {   return('*'); }
"/"	     {   return('/'); }
"%"	     {   return('%'); }
"<"	     {   return('<'); }
">"	     {   return('>'); }
"^"	     {   return('^'); }
"|"	     {   return('|'); }
"?"	     {   return('?'); }
int	{yylval.ival = INT; return INT;}
float	{yylval.ival = FLOAT; return FLOAT;}
void	{yylval.ival = VOID; return VOID;}
else	{return ELSE;}
do	{return DO;}
if	{return IF;}
for     {return FOR;}
struct 	{return STRUCT;}
^"#include ".+	return PREPROC;
while	return WHILE;
return 	return RETURN;
printf	return PRINT;
{alpha}({alpha}|{digit}|{und})* {yylval.str=strdup(yytext); return ID;}
{digit}+	{yylval.str=strdup(yytext);return NUM;}
{digit}+\.{digit}+ 	{yylval.str=strdup(yytext); return REAL;}
"<="		return LE;
">="            return GE;
"=="            return EQ;
"!="            return NE;
"++"            return INC;
"--"            return DEC;
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
\".*\"	return STRING;
.	return yytext[0];
%%
