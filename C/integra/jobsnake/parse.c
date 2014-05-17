# ident "parse an array of characters to separate operators & operands."

/* - here is the grammar -
 *  statement = { expression } "."  
 *  expression = term { ( "+" | "-" ) term }
 *  term      = factor { ( "^" | "*" | "/" ) factor }
 *  factor    = number | "(" expression ")"
 *
 * TO DO: add rules for unary operators!
 */

# include <math.h>
# include "calc.h"

void
parse (void)
{
	pos = 0; token = 0;
	gettok();
	statement();
}

 	/* get next token from the expression */
int
gettok()
 {
		int c = line[pos++];

		while (c == ' ' || c == '\t')
		{
			pos++;
			continue;
		}
		if (isdigit(c))
			token = number;
		else
			switch(c)
		    {
				case '+': 	token = plus;
							break;

				case '-': 	token = minus;
							break;

				case '*': 	token = times;
							break;

				case '/': 	token = divid;
							break;

				case '^': 	token = expo;
							break;

				case '(': 	token = lparen;
							break;

				case ')': 	token = rparen;
							break;

				case '\0': 	token = eol;
							break;

				default:	printf("' %c' Illegal token\n", line[pos]);
							break;
			}
		printf("parser: token is ' %c '\n", c);
 }


void
statement(void)
{
	int value = 0;
	while (token != eol)
	{
		value = expression();
		printf("=%d\n", value);
		if (token != eol) gettok();
	}
}


int
expression()
{
puts("expression");
	int left, savetoken;

	left = term();
	while (token == minus || token == plus)
	{
		savetoken = token;
		gettok();
		if (savetoken == plus)
			left = left + term();
		if (savetoken == minus)
			left = left - term();
	}
	return left;
}


int
term()
{
puts("term");
	int savetoken;
	int left = factor();
	while (token == times || token == divid || token == expo)
	{
		savetoken = token;
		gettok();
		if (savetoken == expo)
			left = (int) pow(left, factor());
		if (savetoken == times)
			left = left * factor();
		if (savetoken == divid)
			left = left / factor();
	}
	return left;
}


int 
factor()
{
	int value = 0;

	switch (token)
	{
		case lparen:	gettok();
						value = expression();
						if (token != rparen)
							puts("missing ')'");
						else
							gettok();
						break;

		case number:	--pos;
						value = getnumber();
						gettok();
						break;
	
		default:		puts("error: expecting number or '('");
						break;
	}
	return value;
}


int
getnumber()
{
	int n = 0;

	while ((line[pos] != '\0') && isdigit(line[pos]))
	{
		n = n * 10 + line[pos] - '0';
		pos++;
	}
	return n;
}
