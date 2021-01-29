#include <iostream>
#include <array>
#include <cstdlib>
#include <string.h>
#include <cctype>
#include <cstring>
#include <cstdio>

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
double sumatoria(double num, double acum){
	if(num==1){
		acum=acum+(((2*num)-1)/(num*(num+1)));
		return acum;
	}
	acum=acum+(((2*num)-1)/(num*(num+1)));
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
				string cad;
				cout << "Ingrese una cadena con el formato indicado (Ejemplo: 1AND0OR1AND0OR): "<<endl;
	            cin >> cad;
	            for (int i=0; i<cad.size(); i++){
	            	toupper(cad[i]);
				}
				while(cad.size()<4){
					cout<<"Cadena muy corta"<<endl;
					cout<<"Ingrese una cadena con el formato indicado (Ejemplo: 1AND0OR1AND0OR1): ";
	            	cin >> cad;
				}
	            int ans = 0;
				for (int i = 0; i < cad.size(); i++){
	                char temp = cad[i];
	                if (temp=='A'&&i==1){
	                    if ((cad[i-1]=='1'&&cad[i+3]=='0')||(cad[i-1]=='0'&&cad[i+3]=='1')||(cad[i-1]=='0'&&cad[i+3]=='0')){
	                        ans=0;
	                    }else if(cad[i-1]=='1'&&cad[i+3]=='1'){
	                        ans=1;
	                    }
	                }else if (temp=='O'&&i==1){
	                    if (cad[i-1]=='0' && cad[i+2]=='0'){
	                        ans=0;
	                    }else{
	                        ans=1;
	                    }
	                }else if (temp=='O'){
	                    if (ans==0 && cad[i+2]=='0'){
	                        ans=0;
	                    }else{
	                        ans=1;
	                    }
	                }else if (temp=='A'){
	                    if ((ans==1 && cad[i+3]=='0')||(ans==0 && cad[i+3]=='1')||(ans==0 && cad[i+3]=='0')){
	                        ans=0;
	                    }else{
	                        ans=1;
	                    }
	                }
	            }
				if (ans==1){
	                cout<<"Solucion = True"<<endl;
	            }else if(ans==0){
	            	cout<<"Solucion = False"<<endl;
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
				double num;
				double acum=0;
				cout<<"Ingrese un numero"<<endl;
				cin>>num;
				while(num<=0){
					cout<<"Porfavor ingrese un numero positivo entero diferente de 0"<<endl;
					cin>>num;
				}
				double resp = sumatoria((int)num,acum);
				cout<<"S("<<num<<") = "<<resp<<endl;
				break;
		}
	}
	return 0;
}
