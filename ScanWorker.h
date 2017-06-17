#ifndef SCAN_WORK_H
#define SCAN_WORK_H
#include"Strings.h"
#include "Library.h"
#include"ScanBASE.h"
class ScanWorker
{
protected:
	Strings filename;
	char* tip;
	ScanBase db;
	int id;
	int procent;
	FILE* F;
public:
	ScanWorker() {};
	char* get_tip() { return tip; };
	ScanWorker(FILE* RAPORT, int idd, char* file, ScanBase db, int p);
	virtual void scan(char*) = 0;
	virtual void scan_strict(char *,int ) = 0;

};






#endif