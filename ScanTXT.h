#ifndef SCAN_TXT_H
#define SCAN_TXT_H
#include "Library.h"
#include"ScanWorker.h"

class ScanTXT:public ScanWorker
{

public:
	ScanTXT() {};
	ScanTXT(FILE* RAPORT,int id,char*file,ScanBase db,int p=0) :ScanWorker(RAPORT,id,file,db,p)
	{
		this->tip = new char[6];
		strcpy(this->tip, "txt");
	};
	void scan(char* file);
	void scan_strict(char*file, int p);

};


#endif