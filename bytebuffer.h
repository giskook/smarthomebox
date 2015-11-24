#include "endianness.h"

static inline void bytebuffer_readbyte(const unsigned char** s, unsigned char* d){
	*d = (unsigned char)**s; (*s) ++;
}

static inline void bytebuffer_readword(const unsigned char** s, unsigned short* d){
	*d = 0;
	((unsigned char *)d)[0] = *s[0];
	((unsigned char *)d)[1] = *s[1];
	if(!ISBIGENDIAN){
		*d = swap16(*d);
	}
	*s += 2;
}

static inline void bytebuffer_readdword(const unsigned char** s, unsigned int* d){
	*d = 0;
	((unsigned char *)d)[0] = *s[0];
	((unsigned char *)d)[1] = *s[1];
	((unsigned char *)d)[2] = *s[2];
	((unsigned char *)d)[3] = *s[3];
	if (!ISBIGENDIAN){
		*d = swap32(*d);
	}

	*s += 4;
}

static inline void bytebuffer_readquadword(const unsigned char ** s, unsigned long long *d){
	*d = 0;
	((unsigned char *)d)[0] = *s[0];
	((unsigned char *)d)[1] = *s[1];
	((unsigned char *)d)[2] = *s[2];
	((unsigned char *)d)[3] = *s[3];
	((unsigned char *)d)[4] = *s[4];
	((unsigned char *)d)[5] = *s[5];
	((unsigned char *)d)[6] = *s[6];
	((unsigned char *)d)[7] = *s[7];
	if(!ISBIGENDIAN){
		*d = swap64(*d);
	}
}

static inline void bytebuffer_readbytes( const unsigned char ** s, char * str, int len){
	int i;
	for(i = 0; i < len; i++) {
		str[i] = (*s)[i];
	}

	(*s) += len;
}

static inline unsigned short bytebuffer_getword(unsigned char * value){
	unsigned short result = 0;
	((unsigned char *)&result)[0] = value[0];
	((unsigned char *)&result)[1] = value[1];
	if (!ISBIGENDIAN){
		result = swap16(result);
	}

	return result;
}