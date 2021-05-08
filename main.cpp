#include <iostream>
#include<math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu();
using std::string;

int sizeFr=0;

int sizeArray(char*, int);

char UPDL(char );

char* charArray(char*, int);

char** matrizObstaculo(int, int, int);

void ejercicio_3(char*, char**, int, int, int);

void imprimirArray(char*, int);

void imprimirMatriz(char**, int, int);

int main(int argc, char** argv) {
	int op=0;
	while(op!=4) {

		switch(op=menu()) {
			case 1: {
				int size=0;
				cout<<"Ingrese el size de la palabra: ";
				cin>>size;
				while(size<1) {//Validacion
					cout<<"El numero no puede ser negativo"<<endl
					    <<"Ingrese un numero mayor o igual a 1: ";
					cin>>size;
				}
				char* arreglo=new char[size];
				charArray(arreglo, size);
				delete[] arreglo;
				break;
			}//Fin del case 1

			case 2: {
				int filas=0,columnas=0,obstaculos=0;
				cout<<"Ingrese la cantidad de filas: ";
				cin>>filas;
				cout<<"Ingrese la cantidad de columnas: ";
				cin>>columnas;
				cout<<"Ingrese la cantidad de obstaculos: ";
				cin>>obstaculos;
				matrizObstaculo(filas, columnas, obstaculos);
				break;
			}//Fin del caso 2

			case 3: {

				int filas=0,columnas=0,obstaculos=0;
				cout<<"Ingrese la cantidad de filas: ";
				cin>>filas;
				cout<<"Ingrese la cantidad de columnas: ";
				cin>>columnas;
				cout<<"Ingrese la cantidad de obstaculos: ";
				cin>>obstaculos;
				char** matrix = matrizObstaculo(filas, columnas, obstaculos);

				int size=0;
				cout<<"Ingrese el size de la palabra: ";
				cin>>size;
				while(size<1) {
					cout<<"El numero no puede ser negativo"<<endl
					    <<"Ingrese un numero mayor o igual a 1: ";
					cin>>size;
				}
				char* arreglo=new char[size];
				arreglo = charArray(arreglo, size);
				ejercicio_3(arreglo, matrix, size, filas, columnas);
				delete[] arreglo;
				break;
			}

		}//Fin del switch

	}//Fin del menu
	return 0;
}//Fin del main

int menu() {
	int op=0;
	while(true) {//si no presione el 4 va a seguir el menu
		cout<<"===================="<<endl
		    <<"	MENU"<<endl
		    <<"1. Ejercicio 1"<<endl
		    <<"2. Ejercicio 2"<<endl
		    <<"3. Ejercicio 3"<<endl;
		cout<<"Ingrese la opcion: ";
		cin>>op;
		if(op>0&&op<5)
			return op;
	}
}//Fin del menu

char* charArray(char* array, int size) {

	for(int j=0; j<size; j++) { //llenar el array
		cout<<"CARACTERES VALIDOS=(U,D,L o R)"<<endl;
		cout<<"Ingrese el caracter "<<j<<": ";
		cin>>array[j];
	}


	string palabra="";//palabra en string para despues pasarla a char array
	string num="";//Variable para sacar el numero
	int sizeArrayFinal=0;
	for(int i=0; i<size; i++) { //para sacar el tamaño final del array
		int caracter = array[i];
		if(caracter<=57&&caracter>=48) { //Si es un numero
			num+=array[i];
		} else if(array[i]=='U'||array[i]=='D'||array[i]=='R'||array[i]=='L') {
			sizeArrayFinal+=stoi(num);
			int temp=stoi(num);
			for(int o=0; o<temp; o++) { //va agregar la letra o veces(o es el numero que estaba antes de la letra Ej=8U)
				palabra+=array[i];
			}
			num="";
		}
	}
	sizeFr= sizeArrayFinal;
	char* arrayFinal=new char[sizeArrayFinal];
	for(int p=0; p<sizeArrayFinal; p++) { //convertir la palabra  a char array
		arrayFinal[p]=palabra[p];
	}

	imprimirArray(arrayFinal, sizeArrayFinal);
	return arrayFinal;
}//Fin de la funcion charArray

void imprimirArray(char* array, int size) {
	cout<<"\n"<<"Arreglo: ";
	for(int l=0; l<size; l++) { //Imprimir
		cout<<array[l]<<" ";
	}

}//Fin del a funcion imprimir

char** matrizObstaculo(int filas, int columnas, int obstaculos) {

	char** matrix=0;
	matrix = new char*[filas];
	for(int i = 0; i<filas; i++) {
		matrix[i] = new char[columnas];
	}


	for(int y=0; y<filas; y++) { //Llenar la matriz de guines
		for(int j=0; j<columnas; j++) {
			matrix[y][j]='-';
		}
	}


	for(int i=0; i<obstaculos; i++) {
		int filaObstaculo = (rand()%filas);//Sacar en que fila estara el obstaculo
		int columnaObstaculo= (rand()%columnas);//Sacar en que columna estara el obstaculo
		while(matrix[filaObstaculo][columnaObstaculo]=='#') {
			filaObstaculo = (rand()%filas);//Sacar en que fila estara el obstaculo
			columnaObstaculo= (rand()%columnas);//Sacar en que columna estara el obstaculo
		}
		for(int u=0; u<filas; u++) {
			for(int j=0; j<columnas; j++) {
				if(u==filaObstaculo&&j==columnaObstaculo) { //Si esta en las cordeenadas del obstaculo lo reemplaza
					matrix[u][j]='#';
				}
			}
		}
	}//Fin del for

	imprimirMatriz(matrix, filas, columnas);
	return matrix;
	//LIBERAR MEMORIA
	for(int i = 0; i<filas; i++) {
		if(matrix[i]) {
			delete[] matrix[i];
			matrix[i] = 0; //asignar null
		}
	}

	if( matrix != NULL ) {
		delete[] matrix;
		matrix = 0;
	}
}//Fin funcion obstaculoMatriz

void imprimirMatriz(char** matrix, int filas, int columnas) {
	for(int i=0; i<filas; i++) {
		for(int j=0; j<columnas; j++) {
			cout<<" "<<matrix[i][j];
		}
		cout<<endl;
	}
}//Fin funcion imprimirMatriz

void ejercicio_3(char* arreglo, char** matrix, int size, int filas, int columnas) {
	int inicioF=0, inicioC=0;
	cout<<"\nIngrese en que fila va a iniciar: ";
	cin>>inicioF;
	cout<<"Ingrese en que columna va a iniciar: ";
	cin>>inicioC;
	while(inicioF>=filas||inicioC>=columnas) {//para que las cordenadas no se pasen
		cout<<"Coordenada fila o columna se pasa"<<endl;
		cout<<"Ingrese en que fila va a iniciar: ";
		cin>>inicioF;
		cout<<"Ingrese en que columna va a iniciar: ";
		cin>>inicioC;
	}
	while(matrix[inicioF][inicioC]=='#') {//para que las cordenadas inicial no sea un obstaculo
		cout<<"Coordenada inicial es un obstaculo"<<endl;
		cout<<"Ingrese en que fila va a iniciar: ";
		cin>>inicioF;
		cout<<"Ingrese en que columna va a iniciar: ";
		cin>>inicioC;
	}
	int indice=0;
	cout<<sizeFr;
	int banderaInicio=0;
	for(int y=0; y<sizeFr; y++) {
		if(banderaInicio!=0) {
			if(arreglo[indice]=='U') {

				inicioF++;

			} else if(arreglo[indice]=='D') {

				inicioF--;

			} else if(arreglo[indice]=='R') {

				inicioC++;

			} else  if(arreglo[indice]=='L'){

				inicioC--;

			}
		}
		for(int i=0; i<filas; i++) {
			for(int j=0; j<columnas; j++) {
				if(banderaInicio==0) {
					if(i==inicioF&&j==inicioC) {
						matrix[i][j]=UPDL(arreglo[indice]);
						banderaInicio=1;
						indice++;
						system ("PAUSE");
						system ("CLS");
						imprimirMatriz(matrix, filas, columnas);
					}
				} else {
					if(i==inicioF&&j==inicioC&&matrix[inicioF][inicioC]=='-') {

						system ("PAUSE");
						system ("CLS");
						matrix[i][j]=UPDL(arreglo[indice]);
						imprimirMatriz(matrix, filas, columnas);

					}
				}
			}
		}
		indice++;
	}
	//LIBERAR MEMORIA
	for(int i = 0; i<filas; i++) {
		if(matrix[i]) {
			delete[] matrix[i];
			matrix[i] = 0; //asignar null
		}
	}

	if( matrix != NULL ) {
		delete[] matrix;
		matrix = 0;
	}
}//Fin opcion 3

char UPDL(char letra) {
	char ret;
	if(letra=='D'||letra=='U') {
		ret=186;
	} else {
		ret=205;
	}
	return ret;
}





