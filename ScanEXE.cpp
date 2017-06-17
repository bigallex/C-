#include "Library.h"
#include "ScanEXE.h"


void ScanBIN::scan(char * file)
{
	FILE * fil = fopen(file, "rb");
	if (fil == NULL) return;
	fseek(fil, 0, SEEK_END);
	long int size = ftell(fil);
	fclose(fil);
	int contor = 0;
	fil = fopen(file, "rb");
	unsigned char * in = new unsigned char[size + 1];
	fread(in, sizeof(unsigned char), size, fil);
	Binary t = in;
	Lista<Binary> binar = db.bin;
	while (binar.first != 0)
	{
		contor += binar.first->data.strstr_nr(binar.first->data.get_info(), in);
		binar.first = binar.first->next;
	}
	if (contor != 0)
	{
		fprintf(F, "WORKER %d infectat de %d ori\n", id, contor);
	}
};

void ScanBIN::scan_strict(char * file,int p)
{
	FILE * fil = fopen(file, "rb");
	if (fil == NULL) return;
	fseek(fil, 0, SEEK_END);
	long int size = ftell(fil);
	fclose(fil);
	int contor = 0;
	fil = fopen(file, "rb");
	unsigned char * in = new unsigned char[size + 1];
	fread(in, sizeof(unsigned char), size, fil);
	Binary t = in;
	Lista<Binary> binar = db.bin;
	while (binar.first != 0)
	{
		Lista<Binary> proc = binar.first->data.get_PROCENT_string(procent);
		while (proc.first != 0)
		{
			contor += proc.first->data.strstr_nr(binar.first->data.get_info(), in);
			proc.first = proc.first->next;
		}
		binar.first = binar.first->next;
	}
	if (contor != 0)
	{
		fprintf(F, "WORKER %d infectat de %d ori\n", id, contor);
	}
}
