#include"Library.h"
#include"ScanBASE.h"
#include"ScanManager.h"

void main()
{
	//initializare
	try {
		ScanManager &SM = ScanManager::Get_SManager("in.txt", 23);
		SM.initializare_baza_date("virusi1TXT.txt", "virusi1BIN.txt");
		SM.add_virus_txt_string("ninge");
		SM.add_virus_bin_file("binTEST.bin");
		//verificare 
		ScanBase y("virusi1TXT.txt", "virusi1BIN.txt");
		SM.BAZA.verify_up_to_date(y);
		//scanare		

		//SM.scanare_simpla();
		SM.scanare_stricta(60);
	}
	catch (ScanExceptii *e)
	{
		e->print();
		delete[]e;
	}
}