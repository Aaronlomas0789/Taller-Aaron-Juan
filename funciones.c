#include <stdio.h>
#include "funciones.h"
#include <string.h>
 
void buscarPorTamano(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char tipo[40];
    printf("Cual es el tamaño del cuarto que quiere: ");
    scanf("%s", tipo);
    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][1], tipo) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Escoja la habitacion que quiere: ");
    scanf("%d", numHabitacion);
}
 
void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char nombreHotel[40];
    printf("Cual hotel deseaa: ");
    scanf("%s", nombreHotel);
    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], nombreHotel) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Ingrese la habitacion que quiere adquirir: ");
    scanf("%d", numHabitacion);
}
 
void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]) {
    int clienteNuevo = -1;
    for (int i = 0; i < 5; i++) {
        if (clientes[i][0][0] == '\0') {
            clienteNuevo = i;
            break;
        }
    }
    

    printf("Ponga el nombre del cliente: ");
    scanf("%s", clientes[clienteNuevo][0]);
    printf("Ponga la cedula del cliente: ");
    scanf("%s", clientes[clienteNuevo][1]);
 
    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == -1) {
            reservas[i][0] = clienteNuevo;
            reservas[i][1] = numHabitacion - 1;
            reservas[i][2] = 0;
            reservas[i][3] = 0;
            printf("Reserva realizada correctamente.\n");
            return;
        }
    }
 
    printf("Sin espacio para reservas.\n");
}
 
void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]) {
    char cedula[40];
    printf("Ponga la cedula que quiere buscar: ");
    scanf("%s", cedula);
    for (int i = 0; i < 10; i++) {
        if ((reservas[i][0] != -1) && (strcmp(clientes[reservas[i][0]][1], cedula) == 0)) {
            *numReserva = i;
            return;
        }
    }
    *numReserva = -1;
}
 
void imprimirReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[], char clientes[][2][40]) {
    if (numReserva != -1) {
        int clienteIndex = reservas[numReserva][0];
        int habitacionIndex = reservas[numReserva][1];
        printf("Reserva %d: Cliente %s en Habitación %s (%s) de %s con precio %.2lf\n",
               numReserva+1, clienteIndex, habitaciones[habitacionIndex][0], habitaciones[habitacionIndex][1],
               habitaciones[habitacionIndex][2], precios[habitacionIndex]);
        if (reservas[numReserva][3] == 1) {
            printf("Estado: Pagada\n");
        } else {
            printf("Estado: No Pagada\n");
        }
    } else {
        printf("No se encontro reserva.\n");
    }
}
 
void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    if (numReserva != -1) {
        if (reservas[numReserva][3] == 1) {
            printf("Reserva pagada.\n");
        } else {
            reservas[numReserva][3] = 1;
            printf("Reserva %d pagada.\n", numReserva+1);
        }
    } else {
        printf("Reserva no encontrada.\n");
 }
}