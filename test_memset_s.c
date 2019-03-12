#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h> //netdb.h declares struct addrinfo
#include <arpa/inet.h>
#include <netinet/in.h>

#define ARRAY_SIZE 8

#if 0
void print_struct_fields(void * in,const rsize_t n)
{

	volatile unsigned char * v_p = in;

	rsize_t i = 0;

	while ( i < n )
	{
		printf("%c ",*v_p);

		v_p++;	

		i++;
	}	

}
#endif

int main(void)
{
	errno_t result = 0;	
	
	printf("This program only checks for runtime-constraint\n"
		"violations in an invocation of memset_s.\n\n"
	      );

	static struct addrinfo test[ARRAY_SIZE];

	printf("Does memset_s return nonzero value when void * s"
		" == NULL?\n\n"
	      );

	result = memset_s(NULL,sizeof(test),0,sizeof(test));

	printf("Return Value: %llu\n\n",result);

	printf("Does memset_s return nonzero value when smax >"
		" RSIZE_MAX?\n\n"
	      );

	result = memset_s(test,RSIZE_MAX+1,0,sizeof(test));

	printf("Return Value: %llu\n\n",result);
	
	printf("Does memset_s set the inputted char value into\n"
		"each of the first smax characters of the object\n"
		"pointed to by void *s only when there is a\n"
		"violation and void * s != NULl and when rsize_t\n"
		"smax is less than or equal to RSIZE_MAX and return\n"
		"nonzero value?\n\n"
	      );

	result = memset_s(test,8*sizeof(struct addrinfo),1,RSIZE_MAX+1);

	printf("Return Value: %llu\n\n",result);
		
	return 0;
}
