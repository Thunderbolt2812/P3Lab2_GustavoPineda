#include <iostream>
#include <array>
#include <cstdlib>
#include <string.h>
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
			case 1:{
				string cadena;
				cout << "Ingrese la cadena a evaluar: ";
	            cin >> cadena;
	            int resultado = 0;
				for (int i = 0; i < cadena.size(); i++){
	                char caracter = cadena[i];
	                if (caracter == 'A' && i == 1){
	                    if ((cadena[i - 1] == '1' && cadena[i + 3] == '0')||(cadena[i - 1] == '0' && cadena[i + 3] == '1')||(cadena[i - 1] == '0' && cadena[i + 3] == '0')){
	                        resultado = 0;
	                    }else{
	                        resultado = 1;
	                    }
	                }else if (caracter == 'O' && i == 1){
	                    if (resultado == '0' && cadena[i + 2] == '0'){
	                        resultado = 0;
	                    }else{
	                        resultado = 1;
	                    }
	                }else if (caracter == 'A'){
	                    if ((resultado == 1 && cadena[i + 3] == '0') ||(resultado == 0 && cadena[i + 3] == '1')||(resultado == 0 && cadena[i + 3] == '0')){
	                        resultado = 0;
	                    }else{
	                        resultado = 1;
	                    }
	                }else if (caracter == 'O'){
	                    if (resultado == 0 && cadena[i + 2] == '0'){
	                        resultado = 0;
	                    }else{
	                        resultado = 1;
	                    }
	                }
	            }
				if (resultado != 1){
	                cout << "Falso" << endl;
	            }else{
	                cout << "Verdadero" << endl;
	            }
				break;
			}
			case 2:
				int arreglo[20];
			    for(int i = 0;i<20;i++){
			    	arreglo[i] = 1 + (rand()%99);
				}
				cout<<"Arreglo Original"<<endl;
				for(int j = 0;j < 20;j++){
					cout<<arreglo[j]<<",";
				}
				cout<<endl;
				cout<<endl;
				cout<<"Arreglo Ordenado"<<endl;
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
