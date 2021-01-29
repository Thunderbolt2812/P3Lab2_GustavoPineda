#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <iostream>
#include <array>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void ordenAscen(int array[], int num){
    if (num == 1)
        return;

    for (int i=0; i<num-1; i++)
        if (array[i] > array[i+1])
        {
            int aux = array[i];
            array[i] = array[i+1];
            array[i+1] = aux;
        }
    ordenAscen(array, num-1);
}

int main(int argc, char** argv) {
	int opcion = 0;
	while(opcion!=4){
		cout<<"*******MENU*******"<<endl;
		cout<<"1. Ejercicio 1"<<endl;
		cout<<"2. Arreglo Ascendente"<<endl;
		cout<<"3. Sumatoria"<<endl;
		cout<<"4. Salir corriendo"<<endl;
		cin>>opcion;
		switch (opcion){
			case 1:
				break;
			case 2:
				int arreglo[20];
			    for(int i = 0;i<20;i++){
			    	arreglo[i] = 1 + (rand()%99);
				}
				cout<<"Array desordenado"<<endl;
				for(int j = 0;j<20;j++){
						cout<<arreglo[j]<<",";
				}
				cout<<endl;
			    ordenAscen(arreglo, 20);
			    cout<<endl;
				cout<<"Array Ordenado de forma ascendente"<<endl;;
			    for(int p = 0;p<20;p++){
			    	cout<<arreglo[p]<<",";
				}
				cout<<endl;
				cout<<endl;
				break;
			case 3:
				break;
		}
	}
	return 0;
}
