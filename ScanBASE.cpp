#include "Library.h"

#include"ScanBASE.h"
using namespace std;

ScanBase::ScanBase()
{
	filename_txt = nullptr;
	filename_bin = nullptr;
};

ScanBase::ScanBase(char *filetxt, char *filebin)
{
	filename_txt = new char[strlen(filetxt) + 1];
	filename_bin = new char[strlen(filebin) + 1];
	strcpy(filename_txt, filetxt);
	strcpy(filename_bin, filebin);
	charge_txt(filename_txt);
	charge_bin(filename_bin);
};

void ScanBase::charge_txt(char* file)
{
	FILE *f = fopen(file, "r");
	char *buf = new char[30];
	while (!feof(f))
	{
		fscanf(f, "%s", buf);
		Strings elem = buf;
		txt.add_elem(elem);
	}
	delete[]buf;
	fclose(f);
};

void ScanBase::charge_bin(char*file)
{
	FILE * f = fopen(file, "r");
	if (f == NULL) return;
	char buf[300];
	fgets(buf, 300, f);
	char*p;
	p = strtok(buf, " \n");
	do
	{
		FILE * fil = fopen(p, "rb");
		if (fil == NULL) return;
		fseek(fil, 0, SEEK_END);
		long int size = ftell(fil);
		fseek(fil, 0, SEEK_SET);
		unsigned char * in = new unsigned char[size + 1];
		fread(in, 1, size, fil);
	
		in[size] = '\0';
		
		Binary aux;
		aux.operator=(in);
		bin.add_elem(aux);
		p = strtok(NULL, " \n");
		delete[]in;
		fclose(fil);
	} while (p);
	fclose(f);
};

void ScanBase::act_txt_string(char*string)
{
	Strings elem = string;
	txt.add_elem(elem);
};

void ScanBase::act_txt_fisier(char*file)
{
	charge_txt(file);
};
ScanBase& ScanBase::init(char*f, char*g)
{
	ScanBase x(f, g);
	return x;
};

void ScanBase::act_bin_fisier(char*file)
{
	FILE * fil = fopen(file, "rb");
	if (fil == NULL) return;
	fseek(fil, 0, SEEK_END);
	long int size = ftell(fil);
	fclose(fil);
	fil = fopen(file, "rb");
	unsigned char * in = new unsigned char[size + 1];
	fread(in, sizeof(unsigned char), size, fil);

	in[size] = '\0';

	fclose(fil);
	Binary aux;
	aux.operator=(in);
	bin.add_elem(aux);
	delete[]in;
};

void ScanBase::act_bin_col_fisiere(char*file)
{
	charge_bin(file);
};

bool ScanBase::operator==(ScanBase& aux)
{

	Lista<Strings> txt2 = aux.txt;
	Lista<Binary> bin2 = aux.bin;
	bool ver = true;
	while (txt2.first != NULL && ver != false)
	{
		ver = false;
		Lista<Strings> txt1 = txt;
		while (txt1.first != NULL && ver != true)
		{
			if (strcmp(txt1.first->data.get_info(), txt2.first->data.get_info())==0)
			{
				ver = true;
			}
			txt1.first = txt1.first->next; 
		}
		if (ver == false)
		{
			return false;
		}
		txt2.first = txt2.first->next; 
	}
	
	while (bin2.first != NULL && ver != false)
	{
		ver = false;
		Lista<Binary> bin1 = bin;
		while (bin1.first != NULL && ver != true)
		{
			if (ucmp(bin1.first->data.get_info(),bin2.first->data.get_info())==1)
			{
				ver = true;
			}
			bin1.first = bin1.first->next; 
		}
		if (ver == false)
		{
			return false;
		}
		bin2.first = bin2.first->next; 
	}
	return true;
};

void ScanBase::verify_up_to_date(ScanBase& aux)
{
	if (*this == aux)
	{
		cout << "\nBaza de date este la zi\n";
	}
	else
		cout << "\nBaza de date este invechita, necesita sa fie actualizata!\n";
};
int ScanBase::ucmp(unsigned char* sir1, unsigned char *sir2)
{
	while ((*sir1 == *sir2) && (*sir1))
	{
		sir1++;
		sir2++;
	}
	return ((*sir1 == NULL) && (*sir2 == NULL));
};




ScanBase::~ScanBase()
{
	if (filename_txt != NULL)
		delete[]filename_txt; 
	if (filename_bin != NULL)
		delete[]filename_bin;
};