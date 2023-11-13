#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <queue>
#include <string>

using namespace std;

int main() {
    int nprocesos;
    cout << "Cuantos procesos quieres iniciar?" << endl;
    cin >> nprocesos;

    int string[nprocesos];

    srand(time(NULL));
    for (int i=0;i<nprocesos;i++){
        string[i]=rand()%10;
        cout<<string[i]<<" ";
    }
    
    cout<<endl;
    cout<<endl;

    queue<int> memoria;
    int maximo=4;
    int numeroActual=0;
    float page=0;
    float hit=0;
    bool repetido=false;

	
    for (int i=0;i<nprocesos;i++){
        int numeroActual=string[i];
        bool repetido=false;

        queue<int> temp=memoria;
        while (!temp.empty()){
            if (temp.front()==numeroActual){
                repetido=true;
                hit=hit+1;
                break;
            }
            temp.pop();
        }

        if (!repetido){
            if (memoria.size()>=maximo){
                memoria.pop();
            }
            memoria.push(numeroActual);
            page=page+1;
        }

        cout<<"Cola despues de insertar "<<numeroActual<<": ";
        queue<int> tempPrint = memoria;
        while(!tempPrint.empty()){
			cout<<tempPrint.front()<<" ";
            tempPrint.pop();
        }
        cout<<endl;
    }
	float pageMiss=0,hitRatio=0;
	pageMiss=(page/nprocesos)*100;
	hitRatio=(hit/nprocesos)*100;
	cout<<"El porcentaje del Page miss es "<<pageMiss<<"%"<<endl;
	cout<<"El porcentaje del Hit ratio es "<<hitRatio<<"%"<<endl;
    getch();
    return 0;
}


