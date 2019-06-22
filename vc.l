D    [0-9]
L    [a-zA-Z]
LD   [0-9a-zA-Z]
name ({L}|\$)({L}|{D}|[_.\-/$])*

%{
#include <string.h> 
#include <string>
#include <iostream>

using namespace std;

#include "common.h"
#include "vc.tab.h"

int ncol = 1,
    nlin = 1;

int endfile = 0;

int ret(int token);  
// function to update 'nlin' y 'ncol' yand return token

void msgError(int nerror, int nlin,int ncol,const char *s);
// function to print error


%}

%x COMMENT

%%

" "                     	{ncol++;}
[\t]                    	{ncol++;}
[\n]                    	{nlin++;ncol=1;}
"//"(.)*                	{; /* one line comment*/} 
"/*"                    	{ncol += strlen(yytext);BEGIN(COMMENT);}
<COMMENT>[^/*\n]+    		{ncol += strlen(yytext);}
<COMMENT>\n          		{nlin++;ncol=1;}
<COMMENT><<EOF>>     		{msgError(ERREOF,-1,-1,"");}
<COMMENT>"*/"        		{ncol+=strlen(yytext); BEGIN(INITIAL);}
<COMMENT>[*/]        		{ncol += strlen(yytext);}
"module"					{return ret(moduledefinition);}
"int"						{return ret(inttype);}
"in"						{return ret(intype);}
"out"						{return ret(outtype);}
"inout"						{return ret(inouttype);}
"define"					{return ret(definevalue);}

{name}						{return ret(id);}
{D}+               			{return ret(ninteger);}
{D}+(\.){D}+       			{return ret(nfloat);}
"+"                			{return ret(opas);}
"-"                			{return ret(opas);}
"++"               			{return ret(opasinc);}
"--"               			{return ret(opasinc);}
"("                			{return ret(parl);}
")"                			{return ret(parr);}
";"                			{return ret(pyc);}
","                			{return ret(coma);}
"=="               			{return ret(oprel);}
"!="               			{return ret(oprel);}
"<"                			{return ret(oprel);}
">"                			{return ret(oprel);}
"<="               			{return ret(oprel);}
">="               			{return ret(oprel);}
"*"                			{return ret(opmd);}
"/"                			{return ret(opmd);}
"="                			{return ret(opasig);}
"["                			{return ret(bral);}
"]"                			{return ret(brar);}
"{"                			{return ret(cbl);}
"}"                			{return ret(cbr);}
"&"                			{return ret(amp);}
"&&"               			{return ret(ybool);}
"||"               			{return ret(obool);}
"!"                			{return ret(nobool);}
%%

int yywrap(void) {findefichero=1; return 1;} /* for not to link with the lex lib*/


int ret(int token)
{
   yylval.lexeme=strdup(yytext);
   yylval.nlin=nlin;
   yylval.ncol=ncol;
   ncol+=(strlen(yytext));
   return(token);
}