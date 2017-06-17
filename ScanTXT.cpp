#include "Library.h"
#include"ScanExceptii.h"
#include"ScanTXT.h"


void ScanTXT::scan(char*file)
{
	FILE *f = fopen(file, "r");
	bool ok = true;
	int contor = 0;
	if (f != NULL)
	{
		while (!feof(f))
		{
			char aux[20];
			fscanf(f, "%s", aux);
			ScanBase virusi = db;
			while (virusi.txt.first != 0)
			{
				if (strcmp(virusi.txt.first->data.get_info(), aux) == 0)
				{
					contor++;
				}
			}
		}
	}
	else
		throw new ScanExceptii(F, "Fisier gol !");
	if (contor != 0);
	{
		fprintf(F,"WORKER %d infectat de %d ori\n", id, contor);
	}


};

void ScanTXT::scan_strict(char *file,int p)
{

	FILE *f = fopen(file, "r");
	bool ok = true;
	int contor = 0;
	if (f != NULL)
	{
		while (!feof(f))
		{
			char aux[20];
			fscanf(f, "%s", aux);
			Lista<Strings> virusi = db.txt;
			while (virusi.first != 0)
			{
				Lista<Strings> *vir = virusi.first->data.get_PROCENT_string(procent);
				while (vir->first != 0)
				{
					if (strcmp(vir->first->data.get_info(), aux) == 0)
					{
						contor++;
					}
					vir->first = vir->first->next;
				}
				vir->first = vir->first->next;
			}
		}
	}
	else 
		throw new ScanExceptii(F, "Fisier gol !");
	if (contor != 0);
	{
		fprintf(F, "WORKER %d infectat de %d ori\n", id, contor);
	}

};