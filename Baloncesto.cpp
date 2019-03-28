#include<stdio.h>
#include<stdlib.h>
#include"SerialPort.h"
#define N 12
typedef struct
{
	int triples=0;
	int libres=0;
	int dos=0;
} canastas;
typedef struct
{
	int dorsal;
	canastas acierto, error;
	int puntos=0;
	int asistencias=0;
	int rebotes=0;
	int tapones=0;
	int robos=0;
	int faltas=0;
	int recibido = 0;
	int perdidas = 0;
	int anotacion = 0;
	int a3=0, a2=0, a1=0, a0=0, e3=0, e2=0, e1=0, e0=0;
	float p1 = 0;
	float p2 = 0;
	float p3 = 0;
	float p = 0;
}jugador;
void autoConnect(SerialPort *arduino, char*);
void dorsal(jugador *eq, int a);
int comprobar_dorsal(jugador *eq,int n);
void estadistica(jugador*eq, int a);
void mostrar(jugador*eq, int a);

int main()
{
	//Arduino SerialPort object
	SerialPort *arduino;
	// Puerto serie en el que está Arduino
	char* portName = "\\\\.\\COM3";
	// Buffer para datos procedentes de Arduino
	char incomingData[MAX_DATA_LENGTH];

	// Crear estructura de datos del puerto serie
	arduino = (SerialPort *)malloc(sizeof(SerialPort));
	// Apertura del puerto serie
	Crear_Conexion(arduino, portName);
	autoConnect(arduino, incomingData);
	return 0;
	jugador local[12];
	jugador visitante[12];
	int ppal, i, j, estad, eq, n;
	while (1)
	{
		system("cls");
		printf("Pulse una tecla:\n1:Empezar partido\n2:Editar datos\n3:Mostrar datos\n4:Terminar partido\n5:Salir\n");
		scanf_s("%d", &ppal);
		switch (ppal)
		{
		case 1:
			printf("Ahora va a intoducir los dorsales locales\n");
			dorsal(local, N);
			system("cls");
			printf("Ahora va a intoducir los dorsales visitantes\n");
			dorsal(visitante, N);
			break;
		case 5:
			exit(1);
			break;
		default:
			printf("Opcion incorrecta\n");
			break;
		case 2:
			printf("Seleccione equipo:\n1:Local\n2:Visitante\n");
			scanf_s("%d", &eq);
			switch (eq)
			{
			case 1:
				printf("Seleccione dorsal local\n");
				scanf_s("%d", &n);
				n = comprobar_dorsal(local, n);
				if (n == 0)
				{
					printf("Opcion incorrecta\n");
				}
				else
				{
					estadistica(local, n);
				}
				break;
			case 2:
				printf("Seleccione dorsal visitante\n");
				scanf_s("%d", &n);
				n = comprobar_dorsal(visitante, n);
				if (n == 0)
				{
					printf("Opcion incorrecta\n");
				}
				else
				{
					estadistica(local, n);
				}
				break;
			default:
				printf("Opcion incorrecta\n");
				break;
			}
			break;
		case 3:
			printf("Seleccione equipo:\n1:Local\n2:Visitante\n");
			scanf_s("%d", &eq);
			switch (eq)
			{
			case 1:
				printf("Seleccione dorsal local\n");
				scanf_s("%d", &n);
				n = comprobar_dorsal(local, n);
				if (n == 0)
				{
					printf("Opcion incorrecta\n");
				}
				else
				{
					mostrar(local, n);
				}
				break;
			case 2:
				printf("Seleccione dorsal visitante\n");
				scanf_s("%d", &n);
				n = comprobar_dorsal(visitante, n);
				if (n == 0)
				{
					printf("Opcion incorrecta\n");
				}
				else
				{
					mostrar(local, n);
					system("pause");
				}
				break;
			default:
				printf("Opcion incorrecta\n");
				break;
			}
			break;
				


			}


			
			
			}
			system("pause");
	}

	
void dorsal(jugador *eq, int a)
{
	int i, j, repetido, num[N];
	for (i = 0; i < a; i++)
	{
		do
		{
			printf("Intoduzca el dorsal %d\n", i + 1);
			scanf_s("%d", &num[i]);
			for (j = 0; j < i; j++)
			{
				repetido = 0;
				if (num[j] == num[i])
				{
					repetido++;
					break;
				}
			}
		} while (num[i] < 0 || num[i]>99 || repetido > 0);
		eq[i].dorsal = num[i];
		
	}
}
int comprobar_dorsal(jugador* eq,int n) 
{
	int i, d=0;
	for ( i = 0; i < N; i++)
	{
		if (eq[i].dorsal==n)
		{
			d++;
		}
	}
	return d;
}
void estadistica(jugador*eq, int n)
{
	int a, puntos;
	printf("Seleccione estadistica:\n1:Canasta acertada\n2:Canasta fallada\n3:Asistencia\n4:Rebote\n5:Robo\n6:Tapon\n7:Falta\n8:Perdida\n9:Falta recibida");
	scanf_s("%d",&a);
	switch (a)
	{
	default:
		printf("Opcion incorrecta\n");
		break;
	case 9:
		eq[n].recibido++;
	case 8:
		eq[n].perdidas++;
		break;
	case 7:
		eq[n].faltas++;
		if (eq[n].faltas>4)
		{
			printf("Jugador eliminado\n");
		}
		break;
	case 6:
		eq[n].tapones++;
		break;
	case 5:
		eq[n].robos++;
		break;
	case 4:
		eq[n].rebotes++;
		break;
	case 3:
		eq[n].asistencias++;
		break;
	case 1:
		printf("Seleccione el valor de la canasta 1,2 o 3");
		scanf_s("%d", &puntos);
		switch (puntos)
		{
		case 1:
			eq[n].a1++;
			eq[n].a0++;
			eq[n].anotacion = eq[n].anotacion + 1;
			eq[n].p1 = 100 * eq[n].a1 / (eq[n].a1 + eq[n].e1);
			eq[n].p= eq[n].a0 / (eq[n].a0 + eq[n].e0);
			break;
		case 2:
			eq[n].a2++;
			eq[n].a0++;
			(eq[n].acierto.dos == (eq[n].acierto).dos + 1);
			eq[n].anotacion = eq[n].anotacion + 2;
			eq[n].p2 = 100 * eq[n].a2 / (eq[n].a2 + eq[n].e2);
			eq[n].p = eq[n].a0 / (eq[n].a0 + eq[n].e0);
			break;
		case 3:
			eq[n].a3++;
			eq[n].a0++;
			eq[n].anotacion = eq[n].anotacion + 3;
			eq[n].p3 = 100 * eq[n].a3 / (eq[n].a3 + eq[n].e3);
			eq[n].p = eq[n].a0 / (eq[n].a0 + eq[n].e0);
		default:
			printf("Opcion incorrecta\n");
			break;
		}
		break;
	case 2:
		printf("Seleccione el valor de la canasta 1,2 o 3");
		scanf_s("%d", &puntos);
		switch (puntos)
		{
		case 1:
			eq[n].e1++;
			eq[n].e0++;
			eq[n].p1 = 100 * eq[n].a1 / (eq[n].a1 + eq[n].e1);
			eq[n].p = eq[n].a0 / (eq[n].a0 + eq[n].e0);
			break;
		case 2:
			eq[n].e2++;
			eq[n].e0++;
			eq[n].error.dos== eq[n].error.dos+1;
			eq[n].p2 = 100 * eq[n].a2 / (eq[n].a2 + eq[n].e2);
			eq[n].p = eq[n].a0 / (eq[n].a0 + eq[n].e0);
			break;
		case 3:
			eq[n].e3++;
			eq[n].e0++;
			eq[n].error.triples++;
			eq[n].p3 = 100 * eq[n].a3 / (eq[n].a3 + eq[n].e3);
			eq[n].p = eq[n].a0 / (eq[n].a0 + eq[n].e0);
			break;
		default:
			printf("Opcion incorrecta\n");
			break;


		}
		break;
	}

	}

void mostrar(jugador*eq, int n)
{
	printf("Puntos:%d\n", eq[n].anotacion);
	printf("Porcentaje de tiro:%d\n", eq[n].p);
	printf("Porcentaje de triples:%d\n", eq[n].p3);
	printf("Porcentaje de dos:%d\n", eq[n].p2);
	printf("Porcentaje de tiros libres:%d\n", eq[n].p1);
	printf("Asistencias:%d\n", eq[n].asistencias);
	printf("Rebotes:%d\n", eq[n].rebotes);
	printf("Tapones:%d\n", eq[n].tapones);
	printf("Robos:%d\n", eq[n].robos);
	printf("Perdidas:%d\n", eq[n].perdidas);
	system("pause");
}
void autoConnect(SerialPort *arduino, char *incomingData)
{
	char sendData = 0;

	// Espera la conexión con Arduino
	while (!isConnected(arduino))
	{
		Sleep(100);
		Crear_Conexion(arduino, arduino->portName);
	}
	//Comprueba si arduino está connectado
	if (isConnected(arduino))
	{
		printf("Conectado con Arduino en el puerto %s\n", arduino->portName);
	}
	// Bucle de la aplicación
	printf("0 - LED OFF, 1 - LED ON, 9 - SALIR");
	while (isConnected(arduino) && sendData != '9')
	{
		sendData = getchar();
		writeSerialPort(arduino, &sendData, sizeof(char));
	}
	if (!isConnected(arduino))
		printf("Se ha perdido la conexión con Arduino\n");
}

	
	
	
