#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "svic.h"


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

void IngresarVehiculo()
{
    struct Vehiculo veh1;
    ofstream arch("Vehiculos.dat", ios::binary | ios::app);

    system("cls");
    cout << "*********** INSERTAR VEHICULO ***********" << endl;

    cout << "Ingrese el ID: ";
    cin.getline(veh1.vehiculoID, sizeof(veh1.vehiculoID));

    cin.ignore();
    cout << "\nIngrese marca: ";
    cin.getline(veh1.marca, sizeof(veh1.marca));

    cin.ignore();
    cout << "\nNombre: ";
    cin.getline(veh1.nombre, sizeof(veh1.nombre));

    cin.ignore();
    cout << "\nModelo: ";
    cin>>veh1.modelo;

    cout << "\nColor: ";
    cin.getline(veh1.color, sizeof(veh1.color));

    cin.ignore();
    cout << "\nCosto: ";
    cin>>veh1.costo;

    cout << "\nVehiculo nuevo (0=no / 1=si): ";
    cin>>veh1.nuevo;

    cout << "\nPrecio de venta: ";
    cin>>veh1.nuevo;

    cout << "\nDescripcion: ";
    cin.getline(veh1.descr, sizeof(veh1.descr));

  if (arch)
  {
      arch.write((char *)&veh1, sizeof(veh1));
      arch.close();
      cout << "Estudiante ingresado." << endl;
  }
  system("pause");
}



void ListarVehiculo()
{

}

void ConsultarVehiculo()
{

}

void ModificarVehiculo()
{
   struct Vehiculo vehi;
    fstream arch("Vehiculos.dat", ios::binary|ios::in|ios::out);
    char ID[30];

    system("cls");
    cout << "========= MODIFICAR Vehiculo ============" << endl;
    cout << "Ingrese Codigo a modificar: " << endl;
    cin >> ID;
    if (arch)
    {
        bool Encontro=false;
        while (!arch.eof() && !Encontro)
        {
            if (arch.read((char *)&vehi, sizeof(vehi)))
            {
              if (strcmp(vehi.vehiculoID, ID)==0)
                Encontro=true;
            }
        }
        if (Encontro)
        {

            cout<<"\nl. Que atributos desea modificar";
             do
            {
                system("cls");
        cout << "1. Marca.\n";
        cout << "2. Nombre.\n";
        cout << "3. Modelo.\n";
        cout << "4. Color.\n";
        cout << "5. Salir.\n";
        cout << "Digite la opcion que desea realizar: ";
        cin >> n;
        cout << "=======================================================================\n";
             switch(n)
                {
                case 1:
                cout << "\nIngrese nueva Marca:";
                cin >> vehi.marca;
                cout<<" Desea realizar otro cambio? Pulse si o no";
                cin>>cambio;

                    break;
                case 2:
            cout << "\nIngrese nuevo nombre:";
                cin >> vehi.nombre;
                cout<<" Desea realizar otro cambio? Pulse si o no";
                cin>>cambio;
                    break;
                case 3:
            cout << "\nIngrese nuevo Modelo:";
                cin >> vehi.Modelo;
                cout<<" Desea realizar otro cambio? Pulse si o no";
                cin>>cambio;
                    break;
                case 4:
                  cout << "\nIngrese nuevo Color:";
                cin >> vehi.color;
                cout<<" Desea realizar otro cambio? Pulse si o no";
                cin>>cambio;
                    break;
                default:

                }
            }
            while(m!=5||cambio==si);






            cout << "\nIngrese nuevo ID:";
            cin >> vehi.Codigo;
            cout << "\nIngrese nuevo nombre:";
            cin.ignore();
            cin.getline(vehi.Nombre, sizeof(vehi.Nombre));
            cout << "\nIngrese nuevo correo electronico:";
            cin.ignore();
            cin >> vehi.Email;
            cout << "\nIngrese nueva edad:";
            cin >> vehi.Edad;
            arch.seekg((int)((-1)*sizeof(vehi)), ios::cur);
            arch.write((char *)&vehi, sizeof(vehi));
            cout << "Estudiante modificado." << endl;
        }
        arch.close();
    }
    system("pause");
}

}

void BorrarVehiculo()
{
    struct Vehiculo vehi;
    ifstream arch("Vehiculos.dat", ios::binary);
    ofstream archTemp("VehiculosTemp.dat", ios::binary);
    char ID[10];

    system("cls");
    cout << "========= BORRAR VEHICULO ============" << endl;
    cout << "Ingrese ID a borrar: " << endl;
    cin >> ID;
    if (arch && archTemp)
    {
        while (!arch.eof())
        {
            if (arch.read((char *)&vehi, sizeof(vehi)))
            {
              if (strcmp(vehi.vehiculoID, ID)!=0)
                archTemp.write((char *)&vehi, sizeof(vehi));
            }
        }
        arch.close();
        archTemp.close();
        remove("Vehiculos.dat");
        rename("VehiculosTemp.dat", "Vehiculos.dat");
        cout << "Vehiculo borrado." << endl;
    }
    system("pause");
}

void MostrarConsolidado()
{

}

