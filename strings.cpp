#include"Library.h"
#include"strings.h"
using namespace std;
Strings::Strings()
{
	info = NULL;
};
//strings::~strings()
//{
//if (info)
//	delete []info;
//};

Strings::Strings(char *strings)
{
	lenght = strlen(strings);
	this->info = new char[lenght + 1];
	strcpy(this->info, strings);
};

Strings &Strings::operator=(Strings str)
{
	lenght = str.get_lenght();
	this->info = _strdup(str.get_info());
	return *this;
};
Strings& Strings:: operator=( char  *str)
{
	lenght = strlen(str);
	this->info = new char[lenght + 1];
	strcpy(this->info, str);
	return *this;
}
char* Strings::get_ext()
{
	if (strstr(info, ".bin") != 0)
		return "bin";
	else return "txt";
}

int Strings::streql(char *sir1, char *sir2)
{
	while ((*sir1 == *sir2) && (*sir1))
	{
		sir1++;
		sir2++;
	}
	return ((*sir1 == NULL) && (*sir2 == NULL));
};

bool Strings::operator==(Strings aux)
{
	if (strcmp(this->info, aux.get_info()) == 0)
		return true;
	else return false;
};

Lista<Strings> *Strings::get_PROCENT_string(int p)
{
	int x, i, j;
	x = PROCENT(p, strlen(this->info));
	Lista<Strings> *aux;
	aux = new Lista<Strings>;
	for (i = 0, j = x; j <= x; i++, j++)
	{
		Strings elem;
		strncpy(elem.info, this->info + i, x);
		if (strlen(elem.info) == x)
		{
			elem.lenght = x;
			aux->add_elem(elem);
		}
	}
	return aux;
};

