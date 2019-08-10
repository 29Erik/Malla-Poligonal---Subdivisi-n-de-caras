
#include "Lista_Caras.h"
#include "Lista_Vertices.h"

CCara::CCara()
{
	Num_Caras = 0;
	Lista_Caras = NULL;
}

CCara::~CCara() { }

void CCara::Insertar(float Indice_inicial, float Indice_secundario, float Indice_terciario)
{
	CNodoCara *P = Lista_Caras;
	CNodoCara *Q = new CNodoCara(Indice_inicial, Indice_secundario, Indice_terciario);
	if (!Lista_Caras)
	{
		Lista_Caras = Q;
	}
	else
	{
		while (P->siguiente_nodo != NULL)
		{
			P = P->siguiente_nodo;
		}
		P->siguiente_nodo = Q;
	}
	Num_Caras++;
}

void CCara::Eliminar(int Posicion)
{
	CNodoCara *P = Lista_Caras;
	CNodoCara *P_aux = P->siguiente_nodo;
	if (Posicion == 0)
	{
		Lista_Caras = P->siguiente_nodo;
		Num_Caras--;
	}
	else
	{
		for (int i = 1; i <= Posicion; i++)
		{
			if (i == Posicion)
			{
				P->siguiente_nodo = P_aux->siguiente_nodo;
				delete P_aux;
				Num_Caras--;
			}		
			P = P->siguiente_nodo;
			P_aux = P_aux->siguiente_nodo;	//Corre los otros nodos para que ocupen el eliminado
		}
	}
}

int CCara::Tamaño()
{
	return Num_Caras;
}

CNodoCara CCara::Buscar_cara(int Posicion_buscar)
{
	CNodoCara *P = Lista_Caras;
	while (P)
	{
		for (int i = 0; i <= Posicion_buscar; i++)
		{
			if (i == Posicion_buscar)
			{
				CNodoCara Cara_Encontrada(P->Cara[0], P->Cara[1], P->Cara[2]);
				return Cara_Encontrada;
			}
			else
			{
				P = P->siguiente_nodo;
			}
		}
	}
}
