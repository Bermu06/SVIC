#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
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
    bool nuevo;
    float prVenta;
    char descr[300];
};

struct Ventas
{
    int ventaID;
    char fecha[7];
    char cedulaComp[10];
    char nombreComp[50];
    float IVA;
    float precio;
    struct Vehiculo vehiculo;
};

TNodo<struct Ventas>*Inventario_Ventas

TNodo<struct Vehiculo>*Inventario;

void InsertarEstudiante();
void ListaEstudiantes();
void ConsultarEstudiante();
void ModificarEstudiante();
void BorrarEstudiante();


int main()
{
    int opcion;

    do{
        cout<<"--------- Admin ---------"<<endl;
        cout<<"1. Insertar vehiculo"<<endl;
        cout<<"2. Mostrar lista de vehiculos"<<endl;
        cout<<"3. Consultar vehiculo"<<endl;
        cout<<"4. Modificar vehiculo"<<endl;
        cout<<"5. Borrar vehiculo"<<endl;
        cout<<"6. salir"<<endl;

        cin>>opcion;

        switch(opcion)
        {
        case 1:
            InsertarVehiculo();
            break;
        case 2:
            ListaVehiculos();
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
            cout << "Hasta luego !" << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo" << endl;
        }
    }while(opcion!=6);
}

void InsertarEstudiante()
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

void ListaEstudiantes()
{
    struct RegEstudiante RegE;

    ifstream arch("Estudiantes.dat", ios::binary);

    cout << "Codigo \t Nombre \t email"<<endl;

   if(arch)
   {
        while(!arch.eof())
        {
            if(arch.read((char*)&RegE,sizeof(RegE)))
            {
                cout<<RegE.codigo<< "\t";
                cout<<RegE.nombre<< "\t";
                cout<<RegE.email<< endl;
            }
        }
   }
   else
    cout << "No hay archivo de estudiantes" <<endl;

    arch.close();
}

void ConsultarEstudiante()
{
    struct RegEstudiante RegE;
    char codigo[20];
    bool encontro = false;

    ifstream arch("Estudiantes.dat", ios::binary);

    cout << "-*- CONSULTAR ESTUDIANTE -*-" << endl;
    cin.ignore();
    cout<< "Digite el codigo del estudainte a buscar " << endl;
    cin.getline(RegE.codigo,sizeof(RegE.codigo));

    if(arch)
    {
        while(!arch.eof() && encontro)
        {
            arch.read((char*)&RegE,sizeof(RegE));
            if(strcmp(RegE.codigo,codigo)==0)
                encontro=true;
        }
        if(encontro)
        {
            cout<<RegE.codigo<< "\t";
            cout<<RegE.nombre<< "\t";
            cout<<RegE.email<< endl;
        }
        else
            cout <<"No se ha encontrado el codigo"<<endl;
    }
}

void ModificarEstudiante()
{
    fstream arch("Estudiantes.dat", ios::binary | ios::in | ios::out);
    struct RegEstudiante RegE;
    char codigo[20];

    if(arch)
    {
        cout << "-*- MODIFICAR ESTUDIANTE -*-" << endl;
        cin.ignore();
        cout << "Ingrese el codigo del estudainte a modificar: ";
        cin.getline(RegE.codigo,sizeof(RegE.codigo));

        cin>>codigo;

        bool existe = false;

        while(!arch.eof() && !existe)
        {
            arch.read((char*)&RegE, sizeof(RegE));
            if(strcmp(RegE.codigo,codigo)==0)
            {
                existe = true;
                cout << "Se encontro el codigo "<< codigo <<endl;
                cout << "Ingrese los datos" << endl;
                cin.ignore();
                cout << "Nombre: ";
                cin.getline(RegE.nombre,sizeof(RegE.nombre));

                cout << "Edad: ";
                cin>>RegE.edad;

                cin.ignore();
                cout << "Email: ";
                cin.getline(RegE.email,sizeof(RegE.email));

                arch.seekg((int)(-1)*sizeof(RegE),ios::cur);
                arch.write((char*)&RegE, sizeof(RegE));
            }
        }
    }
}

void BorrarEstudiante()
{
    char codigo[20];
    struct RegEstudiante RegE;
    ifstream arch("Estudiantes.dat", ios::binary);
    //Archivo temporal
    ofstream archT("EstudiantesTemp.dat", ios::binary);

    if(arch && archT)
    {
        cout << "-*- BORRAR ESTUDIANTE -*-" << endl;
        cin.ignore();
        cout << "Ingrese el codigo del estudiante a buscar: ";
        cin.getline(RegE.codigo,sizeof(RegE.codigo));

        while(!arch.eof())
        {
            if(arch.read((char*)&RegE,sizeof(RegE)))
            {
                if(strcmp(RegE.codigo,codigo)!=0)
                    archT.write((char*)&RegE, sizeof(RegE));
            }
        }
        arch.close();
        archT.close();

        remove("Estudiantes.dat");
        rename("EstudiantesTemp.dat","Estudiantes.dat");
    }
}

