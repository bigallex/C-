#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLATE_H
#include "Library.h"

template< typename T> class Lista
{
private:
	struct elem
	{
		T data;
		elem *next;
	};
	int contor;
public:
	elem *first;
	Lista();
	T& get_info() { return  first->data; };
	elem* get_first() { return first; };
	void add_elem(T& info);
	Lista(const Lista<T>& aux);
	elem& operator++() { return first->next; };
	elem* get_next() { return first->next; };
	int get_contor() { return this->contor };
	virtual ~Lista();
};

template <typename T> Lista<T>::Lista()
{
	this->first = NULL;
	contor = 0;
};

template <typename T> Lista<T>::Lista(const  Lista<T>&  aux)
{
	elem * salv = aux.first;
	while (salv != NULL)
	{
		add_elem(salv->data);
		salv = salv->next;
	}
};

template <typename T> void Lista<T>::add_elem(T & salv)
{
	elem * aux;
	if (first == NULL)
	{
		first = new elem;
		first->data = salv; //dupa ce am folosit operator= a recunoscut si aici
		first->next = NULL;
	}
	else
	{
		aux = new elem;
		aux->data = salv;
		aux->next = first;
		first = aux;

	}
	contor++;
};


template<typename T> Lista<T>::~Lista()
{
	while (first)
	{
		elem* aux = first;
		first = first->next;
		delete aux;
	}
};


#endif