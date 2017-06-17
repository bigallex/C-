#ifndef SCAN_BASE_H
#define SCAN_BASE_H

#include "Library.h"
#include"list_template.h"
#include"strings.h"
#include"binary.h"


class ScanBase
{
private:
	char *filename_txt;
	char *filename_bin;
public:
	Lista<Strings> txt;
	Lista<Binary> bin;
	ScanBase();
	ScanBase(char *filetxt, char *filebin);
	void charge_txt(char * file);
	void charge_bin(char*file);
	void act_txt_string(char* string);
	void act_txt_fisier(char*file);
	void act_bin_fisier(char*file);
	void act_bin_col_fisiere(char*file);
	void verify_up_to_date(ScanBase& aux);
	ScanBase&  init(char*f,char*g);
	int ucmp(unsigned char *sir1, unsigned char* sir2);
	bool operator==(ScanBase& aux);
	virtual ~ScanBase();


};



#endif