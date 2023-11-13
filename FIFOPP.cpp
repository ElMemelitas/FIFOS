#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;
void posxy(int, int);

struct Proceso {
    string nombre;
    int llegada;
    int cpu;
};

bool compareByLlegada(const Proceso& a, const Proceso& b) {
    return a.llegada < b.llegada;
}

int main() {
    vector<Proceso> procesos;

    /*int n;
    cout << "Cuantos procesos quieres iniciar mano? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Proceso p;
        cout << "Nombre del proceso " << i + 1 << ": ";
        cin >> p.nombre;
        cout << "Tiempo de llegada: ";
        cin >> p.llegada;
        cout << "Tiempo en CPU: ";
        cin >> p.cpu;
        procesos.push_back(p);
    }*/
	
	Proceso p1;
	p1.nombre="ABC";
	p1.llegada=2;
	p1.cpu=9;
	procesos.push_back(p1);
	Proceso p2;
	p2.nombre="XYZ";
	p2.llegada=4;
	p2.cpu=7;
	procesos.push_back(p2);
	Proceso p3;
	p3.nombre="PTW";
	p3.llegada=0;
	p3.cpu=6;
	procesos.push_back(p3);
	Proceso p4;
	p4.nombre="HLN";
	p4.llegada=3;
	p4.cpu=2;
	procesos.push_back(p4);
	Proceso p5;
	p5.nombre="OPQ";
	p5.llegada=6;
	p5.cpu=5;
	procesos.push_back(p5);
	
    sort(procesos.begin(), procesos.end(), compareByLlegada);

    int tiempo = 0;
    system("cls");
    posxy(10,1);cout<<"Llegada";
    posxy(19,1);cout<<"CPU";
    posxy(24,1);cout<<"Inicio";
    posxy(32,1);cout<<"Fin";
    posxy(37,1);cout<<"Espera";
    cout<<endl;

    for (int i = 0; i < 5; i++) {
        Proceso actual = procesos[i];

        int inicio = max(tiempo, actual.llegada);
        int fin = inicio + actual.cpu;
        int espera = inicio - actual.llegada;

        posxy(0,3+i*2);cout<<actual.nombre;
        posxy(13,3+i*2);cout<<actual.llegada;
        posxy(20,3+i*2);cout<<actual.cpu;
        posxy(27,3+i*2);cout<<inicio;
        posxy(32,3+i*2);cout<<fin-1;
        posxy(40,3+i*2);cout<<espera;

        tiempo = fin;
    }

    return 0;
}

void posxy(int x, int y) {
    COORD coordenada;
    coordenada.X = x;
    coordenada.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenada);
}

