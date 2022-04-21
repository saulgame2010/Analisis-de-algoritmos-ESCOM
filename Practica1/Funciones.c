#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "./MedirTiempo/Tiempo en C/tiempo.c"
#include "./Arbol.c"
#include "./Funciones.h"

double utime0, stime0, wtime0;
double utime1, stime1, wtime1;

void Algoritmo(int algoritmo, int n){
    int* numeros=(int *) malloc(sizeof(int)*n);
    numeros=recibeArchivo(numeros, n);
    switch(algoritmo){
        case 1:
            BurbujaSimple(numeros, n);
        break;
        case 2:
            BurbujaOptimizada(numeros, n);
        break;
        case 3:
            Inserccion(numeros, n);
        break;
        case 4:
            Seleccion(numeros, n);
        break;
        case 5:
            Shell(numeros, n);
        break;
        case 6:
            OrdenamientoConArbolBinario(numeros, n);
        break;
        default:
            printf("No hay mas opciones\n");
            exit(0);
        break;
    }
}

int* recibeArchivo(int* numeros, int n){
    FILE* archivo;
    int i;
    archivo=fopen("./Numeros/numeros10millones.txt", "r");
    if(archivo==NULL){
        printf("Error al leer el archivo\n");
        exit(-1);
    }
    for(i=0; i<n; i++)
        fscanf(archivo, "%d", &numeros[i]);
    numeros[i]='\0';
    fclose(archivo);
    return numeros;
}

void BurbujaSimple(int* numeros, int n){
    int i, j, aux;
    uswtime(&utime0, &stime0, &wtime0);
    for(i=1; i<n; i++){
	    for(j=0; j<(n-1); j++){
		    if(*(numeros+j)>*(numeros+j+1)){
			    aux=*(numeros+j);
			    *(numeros+j)=*(numeros+j+1);
			    *(numeros+j+1)=aux;
		    }
	    }
    }
    uswtime(&utime1, &stime1, &wtime1);
    calcularTiempo(utime0, stime0, wtime0, utime1, stime1, wtime1, n, 1);
    numerosOrdenados(numeros, n);
}

void BurbujaOptimizada(int* numeros, int n){
    int i, j, aux;
    int cambios=1;
    uswtime(&utime0, &stime0, &wtime0);
    for(i=1; (i<n)&&(cambios!=0); i++){
		cambios=0;
		for(j=0; j<n; j++){
			if(*(numeros+i)<*(numeros+j)){
				aux=*(numeros+j);
				*(numeros+j)=*(numeros+i);
				*(numeros+i)=aux;
				cambios=1;
			}
		}
	}
    uswtime(&utime1, &stime1, &wtime1);
    calcularTiempo(utime0, stime0, wtime0, utime1, stime1, wtime1, n, 2);
    numerosOrdenados(numeros, n);
}

void Inserccion(int* numeros, int n){
    int i, j, aux=0;
    uswtime(&utime0, &stime0, &wtime0);
	for(i=0; i<=n-1; i++){
		j=i;
		aux=numeros[i];
		while((j>0) && (aux<numeros[j-1])){
			numeros[j]=numeros[j-1];
			j--;
		}
		numeros[j]=aux;
	} 
    uswtime(&utime1, &stime1, &wtime1);
    calcularTiempo(utime0, stime0, wtime0, utime1, stime1, wtime1, n, 3);
    numerosOrdenados(numeros, n);
}

void Seleccion(int* numeros, int n){
    int p,temp;
    uswtime(&utime0, &stime0, &wtime0);
    for(int i=0; i<=n-2; i++){
        p=i;
        for(int j=i+1; j<=n-1; j++){
            if(numeros[j]<numeros[p])
                p=j;
        }
        temp=numeros[p];
        numeros[p]=numeros[i];
        numeros[i]=temp;
    }
    uswtime(&utime1, &stime1, &wtime1);
    calcularTiempo(utime0, stime0, wtime0, utime1, stime1, wtime1, n, 4);
    numerosOrdenados(numeros, n);
}

void Shell(int* numeros, int n){
    int k;
    int b;
    int temp;
    int i;
    uswtime(&utime0, &stime0, &wtime0);
    for(k=trunc(n/2); k>=1; k=trunc(k/2)){
	    for(b=1; b!=0;){
		    b=0;
		    for(i=k; i<n; i++){
			    if(*(numeros+(i-k))>*(numeros+i)){
				    temp=*(numeros+i);
				    *(numeros+i)=*(numeros+(i-k));
				    *(numeros+(i-k))=temp;
				    b=b+1;
			    }
		    }
	    }
    }
    uswtime(&utime1, &stime1, &wtime1);
    calcularTiempo(utime0, stime0, wtime0, utime1, stime1, wtime1, n, 5);
    numerosOrdenados(numeros, n);
}

void OrdenamientoConArbolBinario(int* numeros, int n){
    uswtime(&utime0, &stime0, &wtime0);
    numeros=InsertarABB(numeros,n);
    uswtime(&utime1, &stime1, &wtime1);
    calcularTiempo(utime0, stime0, wtime0, utime1, stime1, wtime1, n, 5);
    numerosOrdenados(numeros, n);
}

void numerosOrdenados(int* numeros, int n){
    FILE* salidaOrdenada;
    salidaOrdenada=fopen("numerosEnOrden.txt", "w");

    if(salidaOrdenada==NULL){
        printf("Error al crear el archivo de salida\n");
        exit(-1);
    }

    for(int i=0; i<n; i++)
        fprintf(salidaOrdenada, "%d\n", numeros[i]);
    free(numeros);
    fclose(salidaOrdenada);
}

void calcularTiempo(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1, int n, int algoritmo){
    char* algoritmoSeleccionado=(char *) malloc(sizeof(char));

    switch(algoritmo){
        case 1:
            fflush(stdout);
            algoritmoSeleccionado="Burbuja Simple";
            fflush(stdout);
            break;
        case 2:
            fflush(stdout);
            algoritmoSeleccionado="Burbuja Optimizada";
            fflush(stdout);
            break;
        case 3:
            fflush(stdout);
            algoritmoSeleccionado="Inserccion";
            fflush(stdout);
            break;
        case 4:
            fflush(stdout);
            algoritmoSeleccionado="Seleccion";
            fflush(stdout);
            break;
        case 5:
            fflush(stdout);
            algoritmoSeleccionado="Shell";
            fflush(stdout);
            break;
        case 6:
            fflush(stdout);
            algoritmoSeleccionado="Arbol Binario";
            fflush(stdout);
            break;
        default:
            printf("No hay más");
        break;
    }

    printf("El tiempo con el algortimo %s con una cantidad de numeros=%d\n", algoritmoSeleccionado, n);
    //Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}