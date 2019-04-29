//Falta comunicación con Arduino
#include<stdio.h>
#include<stdlib.h>
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
	int taprec = 0;
	int valoracion=0;
}jugador;
void dorsal(jugador *eq, int a);
int comprobar_dorsal(jugador *eq,int n);
void estadistica(jugador*eq, int a);
void mostrar(jugador*eq, int a);

int main()
{
	FILE *pf;
	jugador local[12];
	jugador visitante[12];
	int ppal, i, j, estad, eq, n, t, tl, tv;
	while (1)
	{
		system("cls");
		printf("Pulse una tecla:\n1:Empezar partido\n2:Editar datos\n3:Mostrar datos\n4:Terminar partido\n5:Salir\n");
		scanf_s("%d", &ppal);
		switch (ppal)
		{
		case 4:
			tv = 0;
			tl = 0;
			pf = fopen("Local.txt", "w");
			fprintf(pf, "Dorsal\tPtos\tReb\tAsi\tRob\tTap\tFP\tPer\tP1\tP2\tP3\tPTot\tVal\n");
			for (i = 0; i < 12; i++)
			{
				fprintf(pf, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n", local[i].dorsal, local[i].anotacion, local[i].rebotes, local[i].asistencias, local[i].robos, local[i].tapones, local[i].faltas, local[i].perdidas, local[i].p1,local[i].p2,local[i].p3,local[i].p,local[i].valoracion);
				tl = tl + local[i].anotacion;
			}
			fprintf(pf, "Total %d\n", tl);
			fclose(pf);
			pf = fopen("Vistante.txt", "w");
			fprintf(pf, "Dorsal\tPtos\tReb\tAsi\tRob\tTap\tFP\tPer\tP1\tP2\tP3\tPTot\tVal\n");
			for (i = 0; i < 12; i++)
			{
				fprintf(pf, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n", visitante[i].dorsal, visitante[i].anotacion, visitante[i].rebotes, visitante[i].asistencias, visitante[i].robos, visitante[i].tapones, visitante[i].faltas, visitante[i].perdidas, visitante[i].p1, visitante[i].p2, visitante[i].p3, visitante[i].p,visitante[i].valoracion);
				tv= tv + visitante[i].anotacion;
			}
			fprintf(pf, "Total %d\n", tv);
			fclose(pf);
			break;
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
				t = comprobar_dorsal(local, n);
				if (t == 0)
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
				t = comprobar_dorsal(visitante, n);
				if (t == 0)
				{
					printf("Opcion incorrecta\n");
				}
				else
				{
					estadistica(visitante, n);
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
				t = comprobar_dorsal(local, n);
				if (t == 0)
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
				t = comprobar_dorsal(visitante, n);
				if (t == 0)
				{
					printf("Opcion incorrecta\n");
				}
				else
				{
					mostrar(visitante, n);
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
	int i, j, repetido=0, num[N];
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
void estadistica(jugador* eq, int n)
{
	int a, puntos;
	printf("Seleccione estadistica:\n1:Canasta acertada\n2:Canasta fallada\n3:Asistencia\n4:Rebote\n5:Robo\n6:Tapon\n7:Falta\n8:Perdida\n9:Falta recibida\n10:Tapon recibido\n");
	scanf_s("%d", &a);
	switch (a)
	{
	default:
		printf("Opcion incorrecta\n");
		break;
	case 10:
		eq[n].taprec++;
		eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
	case 9:
		eq[n].recibido++;
		eq[n].valoracion = eq[n].anotacion+ eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
	case 8:
		eq[n].perdidas++;
		eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
		break;
	case 7:
		eq[n].faltas++;
		eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
		if (eq[n].faltas > 4)
		{
			printf("Jugador eliminado\n");
		}
		break;
	case 6:
		eq[n].tapones++;
		eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
		break;
	case 5:
		eq[n].robos++;
		eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
		break;
	case 4:
		eq[n].rebotes++;
		eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
		break;
	case 3:
		eq[n].asistencias++;
		eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
		break;
	case 1:
		printf("Seleccione el valor de la canasta 1,2 o 3\n");
		scanf_s("%d", &puntos);
		switch (puntos)
		{
		case 1:
			eq[n].a1++;
			eq[n].a0++;
			eq[n].anotacion = eq[n].anotacion + 1;
			eq[n].p1 = 100 * eq[n].a1 / (eq[n].a1 + eq[n].e1);
			eq[n].p = 100 * eq[n].a0 / (eq[n].a0 + eq[n].e0);
			eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
			break;
		case 2:
			eq[n].a2++;
			eq[n].a0++;
			(eq[n].acierto.dos == (eq[n].acierto).dos + 1);
			eq[n].anotacion = eq[n].anotacion + 2;
			eq[n].p2 = 100 * (eq[n].a2 / (eq[n].a2 + eq[n].e2));
			eq[n].p = 100 * eq[n].a0 / (eq[n].a0 + eq[n].e0);
			eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
			break;
		case 3:
			eq[n].a3++;
			eq[n].a0++;
			eq[n].anotacion = eq[n].anotacion + 3;
			eq[n].p3 = 100 * eq[n].a3 / (eq[n].a3 + eq[n].e3);
			eq[n].p = 100 * eq[n].a0 / (eq[n].a0 + eq[n].e0);
			eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
			break;
		default:
			printf("Opcion incorrecta\n");
			break;
		}
		break;
	case 2:
		printf("Seleccione el valor de la canasta 1,2 o 3\n");
		scanf_s("%d", &puntos);
		switch (puntos)
		{
		case 1:
			eq[n].e1++;
			eq[n].e0++;
			eq[n].p1 = 100 * eq[n].a1 / (eq[n].a1 + eq[n].e1);
			eq[n].p = 100 * eq[n].a0 / (eq[n].a0 + eq[n].e0);
			eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
			break;
		case 2:
			eq[n].e2++;
			eq[n].e0++;
			eq[n].error.dos == eq[n].error.dos + 1;
			eq[n].p2 = 100 * eq[n].a2 / (eq[n].a2 + eq[n].e2);
			eq[n].p = 100 * eq[n].a0 / (eq[n].a0 + eq[n].e0);
			eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
			break;
		case 3:
			eq[n].e3++;
			eq[n].e0++;
			eq[n].error.triples++;
			eq[n].p3 = 100 * eq[n].a3 / (eq[n].a3 + eq[n].e3);
			eq[n].p = 100 * eq[n].a0 / (eq[n].a0 + eq[n].e0);
			eq[n].valoracion = eq[n].anotacion + eq[n].rebotes + eq[n].asistencias + eq[n].robos + eq[n].tapones + eq[n].recibido - (eq[n].error.dos + eq[n].error.libres + eq[n].error.triples + eq[n].perdidas + eq[n].faltas + eq[n].taprec);
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
	printf("Porcentaje de tiro:%f%c\n", eq[n].p,37);
	printf("Porcentaje de triples:%f%c\n", eq[n].p3,37);
	printf("Porcentaje de dos:%f%c\n", eq[n].p2,37);
	printf("Porcentaje de tiros libres:%f%c\n", eq[n].p1,37);
	printf("Asistencias:%d\n", eq[n].asistencias);
	printf("Rebotes:%d\n", eq[n].rebotes);
	printf("Tapones:%d\n", eq[n].tapones);
	printf("Robos:%d\n", eq[n].robos);
	printf("Perdidas:%d\n", eq[n].perdidas);
	printf("Valoracion:%d\n", eq[n].valoracion);
	system("pause");
}

	
	
	
