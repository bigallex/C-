#ifndef SCAN_EXCEPTII_H
#define SCAN_EXCEPTII_H
#include "Library.h"
class ScanExceptii
{
	char*mesaj;
public:
	ScanExceptii(FILE* RAPORT,char*);
	void print();
	~ScanExceptii(void);
};



#endif