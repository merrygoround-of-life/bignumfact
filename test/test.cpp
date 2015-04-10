#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../libbignumfact/bignumfact.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("invalid param err.\n");
		return 1;
	}

	u_int64_t in = atoll(argv[1]);
	char *out = NULL;

	timeval begin;
	timeval end;

	gettimeofday(&begin, NULL);
	
	u_int64_t len = factorial(&out, in);

	gettimeofday(&end, NULL);

	if (end.tv_usec < begin.tv_usec)
	{
		end.tv_sec -= 1;
		end.tv_usec += 1000000;
	}

	printf("%s\n", out);
	printf("= %ld! (%ld lengths, %ld:%06ld seconds)\n",
			in,
			len,
			(end.tv_sec - begin.tv_sec),
			(end.tv_usec - begin.tv_usec));

	release(out);

	return 0;
}

