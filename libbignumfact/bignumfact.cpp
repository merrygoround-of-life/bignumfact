#include <stdio.h>
#include <sys/types.h>
#include <string.h>

#include "bignum.h"

extern "C"
{

u_int64_t factorial(char **out, const u_int64_t in)
{
	if (NULL == out || 0 == in )
	{
		return -1;
	}

	u_int64_t til = in;
	if (0 == til || 1 == til)
	{
		// 0! == 1! == 1
		*out = new char[2];
		strncpy(*out, "1", 2);
		return 1;
	}

	u_int64_t len = 0;
	u_int64_t pos = 1;

	BigNum num(pos);
	do
	{
		++pos;
		BigNum tmp(pos);
		len = num.mul(tmp);
	}
	while (til > pos);

	char *buf = new char[len + 1];
	if (NULL == buf)
	{
		return -1;
	}

	*(buf + len) = '\0';
	num.val(buf);

	*out = buf;
	return len;
}

void release(char *p)
{
	if (NULL != p)
	{
		delete[] p;
		p = NULL;
	}
}

}

