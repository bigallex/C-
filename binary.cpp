#include"Library.h"
#include"binary.h"

Binary::Binary()
{
	info = NULL;
};


Binary::Binary(unsigned char *aux)
{
	this->lenght = go_to_lenght(aux);
	this->info = new unsigned char[this->lenght + 1];
	memcpy(info, aux, lenght);
	this->info[lenght] = '\0';
};

Binary::~Binary()
{
	if (this->info)
	{
		delete[]info;
	}
};
int Binary::strstr_nr(unsigned char* sir1, unsigned char* sir2)
{
	int i, j, k, nr = 0;
	for (i = 0; sir1[i]; i++)
		for (j = i, k = 0; sir1[j] == sir2[k]; j++, k++)
		{
			if (!sir2[k + 1])
				nr++;
		}
	return nr;
};

long int Binary::go_to_lenght(unsigned char*aux)
{
	long int i = 0;
	while (aux[i])
	{
		i++;
	}
	return i;
};

Binary& Binary::operator=(Binary &st)
{
	this->lenght = st.get_lenght();
	this->info = new unsigned char[lenght + 1];
	memcpy(this->info, st.get_info(), lenght);
	this->info[lenght] = '\0';
	return *this;
};

Binary& Binary::operator=(unsigned char* st)
{
	this->lenght = go_to_lenght(st);
	this->info = new unsigned char[lenght + 1];
	memcpy(this->info, st, lenght);
	this->info[lenght] = '\0';
	return *this;
}

Lista<Binary> Binary::get_PROCENT_string(int p)
{
	long int x, j, i;
	long int y = get_lenght();
	x = PROCENT(p, y);
	Lista<Binary> aux;
	for (i = 0, j = x; j <= x; i++, j++)
	{
		Binary elem;
		memcpy(elem.info, this->info + i, x);
		if (go_to_lenght(elem.info) == x)
		{
			elem.lenght = x;
			aux.add_elem(elem);
		}
	}
	return aux;
};

bool Binary::ucmp(unsigned char* sir1, unsigned char *sir2)
{
	while ((*sir1 == *sir2) && (*sir1))
	{
		sir1++;
		sir2++;
	}
	return ((*sir1 == NULL) && (*sir2 == NULL));
};

bool Binary::operator==(Binary aux)
{
	if (ucmp(this->info, aux.info) != 0)
		return true;
	else
		return false;
};