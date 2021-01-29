#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <array>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void ordenAscen(int array[], int num){
    
	if (num == 1)
        return;
    for (int i=0; i<num-1; i++)
        if (array[i] > array[i+1]){
            int aux = array[i];
            array[i] = array[i+1];
            array[i+1] = aux;
        }
        for(int p = 0;p<20;p++){
			cout<<array[p]<<",";
		}
		cout<<endl;
    ordenAscen(array, num-1);
}
float sumatoria(int num, float acum){
	if(num==1){
		acum=acum+(((2*num)-1)/(num*(num+1)));
		return acum;
	}
	acum= acum+(((2*num)-1)/(num*(num+1)));
	sumatoria(num-1,acum);
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
			    ordenAscen(arreglo, 20);
			    cout<<endl;
				break;
			case 3:
				int num;
				double acum=0;
				cout<<"Ingrese un numero"<<endl;
				cin>>num;
				while(num<=0){
					cout<<"Porfavor ingrese un numero positivo diferente de 0"<<endl;
					cin>>num;
				}
				float resp = sumatoria(num,acum);
				cout<<"S("<<num<<") = "<<resp<<endl;
				break;
		}
	}
	return 0;
}
