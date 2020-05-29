#include <stdio.h>
#include <stdlib.h>

char *argv0;

static void
usage(void)
{
	printf("Usage: %s [base_val]\n", argv0);
	exit(1);
}

void
main(int argc, char *argv[])
{
	int i;
	float buf[BUFSIZ];
	float f;

	argv0 = argv[0] ;

	if(argc<2)
		usage();
	
	if(!sscanf(argv[1], "%f", &f))
		usage();
	for( i=0 ; i<BUFSIZ ; ++i )
		buf[i] = f ;
	for(;;)
		fwrite(buf, sizeof(f), BUFSIZ, stdout);
	exit(0);
}
