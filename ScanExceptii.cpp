#include "Library.h"
#include"ScanExceptii.h"

FILE *RAPORT = fopen("contacts.txt", "w");
ScanExceptii::ScanExceptii(FILE* RAPORT,char *mes)
{
	mesaj =_strdup(mes);
}

void ScanExceptii::print()
{
	fprintf(RAPORT, "\n%s\n", mesaj);
}

ScanExceptii::~ScanExceptii(void)
{
}
