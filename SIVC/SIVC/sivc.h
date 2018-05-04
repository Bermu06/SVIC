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

/*
    NOMBRE: BuscarVehiculo
    OBJETIVO: Permite buscar vehiculos que tengan en existencia para la venta.
                La funcion solicitara al usuario los parametros de la busqueda
                e imprimira en pantalla  los vehiculos (10 por pagina) que coinciden
                con los criterios especificados.
    ENTRADAS: La lista que contiene el inventario. */


  template <class T>
  void BuscarVehiculo(TNodo<T> **Vehiculos);

/*
    NOMBRE: RealizarVenta
    OBJETIVO: Realizar la venta de un vehículo.
    ENTRADAS: Apuntador a la lista de Vehiculos con el que el cliente
                desea comprar. Esta funcion solicitara al usuario la informacion
                necesaria para la compra, creara una venta en el archivo ventas
                e imprimira en pantalla la respectiva factura.*/


  template <class T>
  void RealizarVenta(TNodo<T> **Vehiculos, T dato);

 /*
    NOMBRE: ConsultarVentas
    OBJETIVO: Consultar las ventas realizadas por el concesionario.
    ENTRADAS: Apuntador a la lista de Vehiculos con el que el cliente
                desea comprar. Esta funcion solicitara al usuario la informacion
                necesaria para la compra, creara una venta en el archivo ventas
                e imprimira en pantalla la respectiva factura.*/


  template <class T>
  void RealizarVenta(TNodo<T> **Vehiculos, T dato);






#endif
