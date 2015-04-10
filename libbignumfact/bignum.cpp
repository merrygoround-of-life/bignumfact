#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignum.h"

#define GET(arr, pos)		((arr[(pos) / 2] >> (((pos) % 2) ? 0 : 4)) & 0xf)
#define SET(arr, pos, val)	(arr[(pos) / 2] = (((pos) % 2) ? ((arr[(pos) / 2] & 0xf0) | ((val) & 0xf)) : ((arr[(pos) / 2] & 0xf) | (((val) << 4 ) & 0xf0))))

// class BigNum
BigNum::BigNum(u_int64_t val/*=0*/)
:	len(0),
	buflen(0),
	buf(NULL)
{
	init(val);
}

BigNum::BigNum(u_int64_t sz, const char *in)
:	len(0),
	buflen(0),
	buf(NULL)
{
	init(sz, in);

}

BigNum::BigNum(BigNum &bignum)
:	len(bignum.len),
	buflen(bignum.buflen),
	buf(new char[bignum.buflen])
{
	strncpy(buf, bignum.buf, buflen);
}

BigNum::~BigNum()
{
	init(0, NULL);
}

void BigNum::init(u_int64_t val)
{
	if (0 != val)
	{
		char tmp[100] = {0, };
		sprintf(tmp, "%ld", val);
		init(strlen(tmp), tmp);
	}
}

void BigNum::init(u_int64_t sz, const char *in)
{
	if (0 != sz && NULL != in)
	{
		// set len
		len = strnlen(in, sz);
		if (0 != len)
		{
			// set buflen
			u_int64_t newbuflen = (len / 2) + (len % 2);
			if (buflen < newbuflen)
			{
				buflen = newbuflen;

				if (NULL != buf)
				{
					delete[] buf;
				}
				buf = new char[buflen];
			}

			// set buf
			u_int64_t tmplen = 0;
			while (len != tmplen)
			{
				SET(buf, tmplen, (in[len - tmplen - 1] - '0'));
				++tmplen;
			}
		}
		else
		{
			if (NULL != buf)
			{
				delete[] buf;
				buf = NULL;
			}
			buflen = 0;
		}
	}
	else
	{
		if (NULL != buf)
		{
			delete[] buf;
			buf = NULL;
		}
		buflen = 0;

		len = 0;
	}
}

u_int64_t BigNum::val(char *out/*= NULL*/) const
{
	if (NULL != out)
	{
		u_int64_t tmplen = 0;
		while (len != tmplen)
		{
			out[tmplen] = '0';
			out[tmplen] += GET(buf, len - tmplen - 1);
			++tmplen;
		}
		out[tmplen] = '\0';
	}

	return len;
}

u_int64_t BigNum::mul(BigNum &bignum)
{
	if (0 != len && 0 != bignum.len)
	{
		u_int64_t newlen = len + bignum.len;
		u_int64_t newbuflen = newlen / 2 + newlen % 2;
		char *newbuf = new char[newbuflen];
		memset(newbuf, 0, newbuflen);

		u_int64_t i = 0;
		u_int64_t j = 0;
		u_int64_t z = 0;
		u_int64_t c = 0;

		for (i = 0; i < len; ++i)
		{
			for (j = 0; j < bignum.len; ++j)
			{
				z = GET(buf, i) * GET(bignum.buf, j) + GET(newbuf, i + j) + c;
				c = z / 10;
				SET(newbuf, i + j, z % 10);
			}

			newlen = i + j;
			if (0 != c)
			{
				SET(newbuf, i + j, c);
				c = 0;
				newlen += 1;
			}
		}

		delete[] buf;
		buf = newbuf;
		buflen = newbuflen;
		len = newlen;
	}
	else
	{
		init(0, NULL);
	}

	return len;
}

