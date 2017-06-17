#include "Library.h"
#include"ScanWorker.h"
#include"Strings.h"
ScanWorker::ScanWorker(FILE *RAPORT,int idd,char*file,ScanBase db,int p) 
{
	this->db = db;
	filename = file;
	procent = p;
	F = RAPORT;
	id = idd;
};