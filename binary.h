#ifndef BINARY_H
#define BINARY_H

#include"Library.h"
#include"list_template.h"

class Binary
{
private:
	long int lenght;
	unsigned char *info;
public:
	Binary();
	~Binary();
	Binary(unsigned char *aux);
	long int go_to_lenght(unsigned char* aux);
	Binary& operator=(Binary &st);
	Binary& operator=(unsigned char* st);
	unsigned char* get_info() { return this->info; };
	long int get_lenght() { return lenght; };
	bool ucmp(unsigned char *sir1, unsigned char* sir2);
	Lista<Binary>get_PROCENT_string(int p);
	bool operator==(Binary aux);
	int strstr_nr(unsigned char* sir1, unsigned char *sir2);
};

#endif