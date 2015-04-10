#ifndef _BIGNUMFACT_BIGNUMFACT_H_
#define _BIGNUMFACT_BIGNUMFACT_H_

extern "C"
{
	u_int64_t factorial(char **out, const u_int64_t in);
	void release(char *p);
}

#endif // _BIGNUMFACT_BIGNUMFACT_H_

