#include <stdio.h>
static char *s = 

"\
#include <stdio.h> \n  \
static char *s = \n \
\" \
%c\n\
%s\n\
%c; \n  \
			 \n  \
int main()  \n  \
{  \n  \
	printf(\"\\\"the car\\n\\\"\");			 \n \	
}\n\"\0";
int main()
{
	printf("the car\n");	
	rsize_t i = 0;
	rsize_t opening = 3;								
	while ( s[i] != 0 )
	{
		putchar(s[i]);
		i++;
	}
//	putchar(34); //print double quote
	const rsize_t opening_quote = i;
	i = 0;
	while ( s[i] != 0 ) //now printing string in double quotes
	{
		if ( s[i] != 10 )
		{ putchar(s[i]); }
		else
		{	
		putchar(9);  //tab	
		putchar(92); //backslash
		putchar(110);//lowercase n
		putchar(92); //backslash for newline in string
		putchar(s[i]);//print actual line feed (set a newline)
		}
		i++;
	}
//	putchar(34); //print closing double quote
	putchar(59); //print closing semicolon for global char array
	i = opening+1;
	while (s[i] != 0) // Now printing everything after opening quote
	{
		
	}
	return 0;
}
