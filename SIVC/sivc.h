#ifndef SIVC_H_INCLUDED
#define SIVC_H_INCLUDED

#include <stdlib.h>
#include <conio.h>

template <class T>
struct TNodo
{
    T dato;
	struct TNodo<T> *sig;
};

template <class T>
void BuscarVehiculo(TNodo<T> **Vehiculos);

template <class T>
void RealizarVenta(TNodo<T> **Vehiculos, T dato);

template <class T>
void ConsultarVenta(TNodo<T> **Vehiculos, T dato);






#endif
