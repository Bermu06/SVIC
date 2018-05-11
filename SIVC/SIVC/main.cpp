#include <iostream>
#include <fstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "svic.h"


using namespace std;

struct Vehiculo
{
    char vehiculoID[10];
    char marca[20];
    char nombre[50];
    int modelo;
    char color[20];
    float costo;
    bool nuevo
    float prVenta;
    char descr[300];
};
TNodo<struct Vehiculo>*Inventario;

struct Venta
{
    int ventaID;
    char fecha[7];
    char cedulaComp[10];
    char nombreComp[50];
    float IVA;
    float precio;
    struct vehiculo vehiculo;
};
TNodo<struct Ventas>*Inventario_Ventas;

int main()
{
    int Opcion, m, n;

    do      //Menu principal
    {
        system("cls");
        cout << "\n=======================================================================";
        cout << "\n          BIENVENIDO A LA BASE DE DATOS DEL CONCESIONARIO\n";
        cout << "\n1. Administrador.\n";
        cout << "2. Usuario.\n";
        cout << "3. Salir.\n";
        cout << "Digite la opcion que desea realizar: ";
        cin >> n;
        cout << "=======================================================================\n";

        switch(n)
        {
        case 1:     //USUARIO
            do
            {
                system("cls");
                cout << "\n=======================================================================";
                cout << "\n          BIENVENIDO A LA BASE DE DATOS DEL CONCESIONARIO SEÑOR USUARIO\n";
                cout << "1. Listar los Vehiculos.\n";
                cout << "2. Consultar un Vehiculo.\n";
                cout << "3. Realizar Venta de Vehiculo.\n";
                cout << "4. Salir.\n";
                cout << "Digite la opcion que desea realizar: ";
                cin >> m;
                cout << "=======================================================================\n";

                switch(m)
                {
                case 1:
                    //LISTA VEHICULOS PARA EL CLIENTE
                    break;
                case 2:
                    //CONSULTAR VEHICULO USUARIO
                    break;
                case 3:
                    //RealizarVenta();
                    break;
                default:
                    cout << "Opcion no valida. Intente de nuevo" << endl << endl;

                }
            }
            while(m!=4);

        case 2:  //ADMINISTRADOR
            do
            {
                system("cls");
                cout << "\n=======================================================================";
                cout << "\n          BIENVENIDO A LA BASE DE DATOS DEL CONCESIONARIO SEÑOR ADMINISTRADOR\n";
                cout << "\n1. Agregar un vehiculo.\n";
                cout << "2. Listar los Vehiculos.\n";
                cout << "3. Consultar un Vehiculo.\n";
                cout << "4. Modificar un Vehiculo.\n";
                cout << "5. Eliminar un Vehiculo.\n";
                cout<<  "6. Mostrar consolidado de ventas.\n"
                cout << "7. Salir.\n";
                cout << "Digite la opcion que desea realizar: ";
                cin >> Opcion;
                cout << "=======================================================================\n";

                switch(Opcion)
                {
                case 1:
                    IngresarVehiculo();
                    break;
                case 2:
                    ListaVehiculo();
                    break;
                case 3:
                    ConsultarVehiculo();
                    break;
                case 4:
                    ModificarVehiculo();
                    break;
                case 5:
                    BorrarVehiculo();
                    break;
                case 6:
                    MostrarConsolidado();
                    break;
                default:
                    cout << "Opcion no valida. Intente de nuevo" << endl << endl;

                }
            }
            while(Opcion!=7);

        }
    }
    while(n!=3);
}
