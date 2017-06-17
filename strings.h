#ifndef CSSTRING_H
#define CSSTRING_H
#include"list_template.h"

class Strings
{
private:
	int lenght;
	char *info;
public:
	Strings();
	/* ~strings();*/
	Strings(char *strings);
	Strings &operator=(Strings str);
	Strings &operator=(char *str);
	char *get_info() { return info; };
	int get_lenght() { return lenght; };
	char* get_ext();
	int streql(char*, char*);
	bool operator==(Strings aux);
	Lista<Strings> *get_PROCENT_string(int p);
};


#endif