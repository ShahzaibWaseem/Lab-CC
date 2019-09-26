/**Swap two numbers without using third variable**/

%{
	int num1 = 0;
	int num2 = 0;
%}

%%
[0-9]+	{num1=atoi(yytext);
		printf("Captured Number 1: %d\n", num1);}
.[0-9]+	{num2=atoi(yytext);
		printf("Captured Number 2: %d\n", num2);}
\n		{return 0;}
%%

int yywrap(){}

int main(){
	yylex();

	num1=num1+num2;
	num2=num1-num2;
	num1=num1-num2;

	printf("Number 1: %d\tNumber 2: %d\n", num1, num2);

	return 0;
}