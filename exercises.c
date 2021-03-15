#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

/* 
Ejercicio 1.
Función que recibe 3 parámetros (a, b y c), 
y en c almacena el valor de la suma de a más b.
*/

void suma(int a, int b, int * c) {
   *c = a + b;
}

/*
Esta función suma los N primeros números del arreglo a
*/
int sumaN(int a[], int N) {
    int i;
    int tot = 0;

    for(i = 0; i < N; i++) {
      tot += a[i];
    }

    return tot;
}

/*
Ejercicio 2.
Esta función debe sumar los últimos m números del 
arreglo a y almacena el resultado en *suma.
Utilice la función sumaN.
*/

void sumaNultimos(int a[], int n, int m, int * suma) {
  int aux, aux_2;

  aux = sumaN(a,n);
  aux_2 = sumaN(a, n-m);
  *suma = aux - aux_2;
}

/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos correspondientes y retorna un puntero al dato 
recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
    Persona *nuevo = NULL;
    nuevo = (Persona *) malloc (sizeof (Persona));

    strcpy((*nuevo).nombre, nombre);
    strcpy((*nuevo).rut, rut);
    (*nuevo).edad = edad;

   return nuevo;
}

/*
Ejercicio 4.
Considerando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int * datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector * crearVector(int n) {

   Vector *V = NULL;
   V = (Vector *) malloc (sizeof (Vector));
   (*V).capacidad = n;

   (*V).datos = malloc (n * sizeof(int));
   return V;
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor) {
  int *Valor;

  Valor = (*v).datos+i;
  *Valor = valor;
  /** Por que (*v).datos+i = valor no se puede asignar? **/
}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i) {

  int *Dato;
  Dato = (*v).datos+i;

   return *Dato;
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c) {
  int *aux_a, *aux_b, *aux_c,i;

  int total = (*a).capacidad;

  for (i = 0; i < total; i++)
  {
    aux_a = (*a).datos+i;
    aux_b = (*b).datos+i;
    
    aux_c = (*c).datos+i; //Se apunta a la pos de memoria que contiene el dato

    *aux_c = *aux_a + *aux_b; /** Al apuntar antes al .dato, si operamos sobre el                                     vector afectariamos a esta "zona" porque es donde                                   esta apuntando **/
  }
  

}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1+b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c){
  Vector *A;
  Vector *B;
  
  A = crearVector(2);
  B = crearVector(2);

  sumaV(A,B,c);
 
}