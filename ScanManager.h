#ifndef Scan_Manager_H
#define Scan_Manager_H

#include"Library.h"
#include"list_template.h"
#include"ScanTXT.h"
#include"ScanEXE.h"
#include"ScanExceptii.h"
#include"ScanBASE.h"
#include"ScanWorker.h"


class ScanManager
{
private:
	int nr_workeri;
	char *nume_fisier;
	int workeri;
	int id;
	ScanWorker** WORKER;
	ScanManager(char *x="in.txt", int n=0)
	{
		nr_workeri = n;
		WORKER = new ScanWorker*[nr_workeri];
		FILE *in = fopen(x, "r");
		RAPORT = fopen("RAPORT.txt", "w");
		fprintf(RAPORT, "Buna! \n Incepe scanarea fisierelor: ");
		if (in == NULL)
		{
			throw new ScanExceptii(RAPORT, "eroare la deschiderea fisierului");
		}
		
		char buffer[256];
		while (!feof(in))
		{
			fscanf(in, "%s", buffer);
			Strings aux = buffer;
			FISIERE.add_elem(aux);
		}
	};
	ScanManager(const ScanManager &M)
	{};
	~ScanManager() {};

public:
	static ScanManager *SManager;
	ScanBase BAZA;
	FILE*RAPORT;
	Lista<Strings> FISIERE;


	static void distruge();
	static ScanManager &Get_SManager();
	static ScanManager &Get_SManager(char *, int);
	//adaugare in baza de date
	void add_virus_txt_string(char*);///apelez din lista;
	void add_virus_txt_file(char*);
	void add_virus_bin_file(char*);
	void add_virus_bin_col(char*file);

	void initializare_baza_date(char*f1,char*f2);
	//scanare
	void scanare_simpla();
	void scanare_stricta(int p);
};







#endif 
