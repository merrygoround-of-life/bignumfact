#ifndef _BIGNUMFACT_BIGNUM_H_
#define _BIGNUMFACT_BIGNUM_H_

#include <sys/types.h>

class BigNum
{
private:
	u_int64_t	len;
	u_int64_t	buflen;
	char		*buf;

private:
	void init(u_int64_t val);
	void init(u_int64_t sz, const char *in);

public:
	BigNum(u_int64_t val = 0);
	BigNum(u_int64_t sz, const char *in);
	BigNum(BigNum &bignum);
	~BigNum();

public:
	u_int64_t val(char *out = NULL) const;
	u_int64_t mul(BigNum &bignum);
};

#endif //_BIGNUMFACT_BIGNUM_H_

