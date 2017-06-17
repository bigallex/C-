#include "Library.h"
#include"ScanManager.h"
using namespace std;



ScanManager *ScanManager::SManager = NULL;

ScanManager & ScanManager::Get_SManager()
{
	if (SManager == NULL)
		SManager = new ScanManager;
	return *SManager;
};
ScanManager & ScanManager::Get_SManager(char*f,int a)
{
	if (SManager == NULL)
		SManager = new ScanManager(f, a);
	else
	{
		SManager->nume_fisier = new char[strlen(f) + 1];
		strcpy(SManager->nume_fisier, f);
	}
	return *SManager;
};

void ScanManager::scanare_simpla()
{
	int i = 0, k = 0;
	Lista<Strings> fil = FISIERE;
	while (fil.first != 0)
	{
		if (strstr(fil.first->data.get_info(), ".bin") != 0)
		{
			WORKER[i] = new ScanBIN(RAPORT, i, fil.first->data.get_info(), BAZA);
			WORKER[i]->scan(fil.first->data.get_info());
		}
		else
		{
			WORKER[i] = new ScanTXT(RAPORT, i, fil.first->data.get_info(), BAZA);
			WORKER[i]->scan(fil.first->data.get_info());
		}
		if (i = nr_workeri - 1)
		{
			bool da = true;
			if (strstr(fil.first->data.get_info(), ".bin")!= 0)
			{
				bool ver = true;
				for (int j = 0; j <= i, ver; j++)
				{
					if (strcmp(WORKER[j]->get_tip(), ".bin") == 0)
					{
						delete[]WORKER[j];
						WORKER[j] = new ScanBIN(RAPORT, j, fil.first->data.get_info(), BAZA);
						WORKER[j]->scan(fil.first->data.get_info());
						ver = false;
						da = false;
					}
				}
			}
			else
			{
				bool ver = true;
				for (int j = 0; j <= i, ver; j++)
				{
					if (strcmp(WORKER[j]->get_tip(), ".txt") == 0)
					{
						delete[]WORKER[j];
						WORKER[j] = new ScanTXT(RAPORT, j, fil.first->data.get_info(), BAZA);
						WORKER[j]->scan(fil.first->data.get_info());
						ver = false;
						da = false;
					}
				}
			}
			if (da == true)
			{
				if (strstr(fil.first->data.get_info(), ".bin") !=0)
				{
					WORKER[k] = new ScanBIN(RAPORT, k, fil.first->data.get_info(), BAZA);
					WORKER[k]->scan(fil.first->data.get_info());
				}
				else
				{
					WORKER[k] = new ScanTXT(RAPORT, k, fil.first->data.get_info(), BAZA);
					WORKER[k]->scan(fil.first->data.get_info());
				}
			}
		}
		k++;
		fil.first = fil.first->next;
	}
};
	
void ScanManager::scanare_stricta(int p)
{
	int i = 0, k = 0;
	Lista<Strings> fil = FISIERE;
	while (fil.first != 0 && i<nr_workeri)
	{
		if (strstr(fil.first->data.get_info(), ".bin") != 0)
		{
			WORKER[i] = new ScanBIN(RAPORT, i, fil.first->data.get_info(),BAZA,p);
			WORKER[i]->scan_strict(fil.first->data.get_info(),p);
		}
		else
		{
			WORKER[i] = new ScanTXT(RAPORT, i, fil.first->data.get_info(),BAZA,p);
			WORKER[i]->scan_strict(fil.first->data.get_info(),p);
		}
		if (i = nr_workeri - 1)
		{
			bool da = true;
			if (strstr(fil.first->data.get_info(), ".bin")!= 0)
			{
				bool ver = true;
				for (int j = 0; j <= i, ver; j++)
				{
					if (strcmp(WORKER[j]->get_tip(), ".bin") == 0)
					{
						delete[]WORKER[j];
						WORKER[j] = new ScanBIN(RAPORT, j, fil.first->data.get_info(), BAZA);
						WORKER[j]->scan_strict(fil.first->data.get_info(),p);
						ver = false;
						da = false;
					}
				}
			}
			else
			{
				bool ver = true;
				for (int j = 0; j <= i, ver; j++)
				{
					if (strcmp(WORKER[j]->get_tip(), ".txt") == 0)
					{
						delete[]WORKER[j];
						WORKER[j] = new ScanTXT(RAPORT, j, fil.first->data.get_info(), BAZA);
						WORKER[j]->scan_strict(fil.first->data.get_info(),p);
						ver = false;
						da = false;
					}
				}
			}
			if (da == true)
			{
				if (strstr(fil.first->data.get_info(), ".bin")!= 0)
				{
					delete[]WORKER[k];
					WORKER[k] = new ScanBIN(RAPORT, k, fil.first->data.get_info(), BAZA);
					WORKER[k]->scan_strict(fil.first->data.get_info(),p);
				}
				else
				{
					delete[]WORKER[k];
					WORKER[k] = new ScanTXT(RAPORT, k, fil.first->data.get_info(), BAZA);
					WORKER[k]->scan_strict(fil.first->data.get_info(),p);
				}
			}
		}
		k++;
		fil.first = fil.first->next;
	}

};

void ScanManager::add_virus_txt_string(char* txt)
{
	BAZA.act_txt_string(txt);
};
void ScanManager::add_virus_txt_file(char*txt)
{
	BAZA.act_txt_fisier(txt);

};
void ScanManager::add_virus_bin_file(char*file)
{
	BAZA.act_bin_fisier(file);
};
void ScanManager::add_virus_bin_col(char*file)
{
	BAZA.act_bin_col_fisiere(file);
};


void ScanManager::distruge()
{
	if (SManager == NULL)
	{
		return;
	}
	delete SManager;
	SManager = NULL;
};


void ScanManager::initializare_baza_date(char*f1, char *f2)
{
	BAZA.init(f1, f2);
};