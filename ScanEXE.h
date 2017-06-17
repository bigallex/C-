#ifndef SCAN_EXE_H
#define SCA_EXE_H

#include "Library.h"
#include"ScanWorker.h"


class ScanBIN :public ScanWorker
{

public:
	ScanBIN(){};
	ScanBIN(FILE* RAPORT,int id,char*file,ScanBase db,int p=0) :ScanWorker(RAPORT,id,file,db,p)
	{
		this->tip = new char[6];
		strcpy(this->tip, "BIN");
	};
	void scan(char* file);
	void scan_strict(char*file,int p);
};

#endif