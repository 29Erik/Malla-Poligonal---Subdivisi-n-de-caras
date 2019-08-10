
#include "Lista_Vertices.h"

CVertice::CVertice()
{
	Num_Vertices = 0;
	Lista_Vertices = NULL;
}

CVertice::~CVertice() { }

void CVertice::Insertar(float x, float y, float z)
{
	CNodoVertice *P = Lista_Vertices;
	CNodoVertice *Q = new CNodoVertice(x, y, z);
	if (!Lista_Vertices)
	{
		Lista_Vertices = Q;
	}
	else
	{
		while (P->siguiente_nodo != NULL)
		{
			P = P->siguiente_nodo;
		}
		P->siguiente_nodo = Q;
	}
	Num_Vertices++;
}

void CVertice::Eliminar(int Posicion)
{
	CNodoVertice *P = Lista_Vertices;
	CNodoVertice *P_aux = P->siguiente_nodo;
	if (Posicion == 1)
	{
		Lista_Vertices = P->siguiente_nodo;
		Num_Vertices--;
	}
	else
	{
		for (int i = 2; i <= Posicion; i++)
		{
			if (i == Posicion)
			{
				CNodoVertice *Aux = P_aux;
				P->siguiente_nodo = P_aux->siguiente_nodo;
				delete Aux;
				Num_Vertices--;
			}
			P = P->siguiente_nodo;
			P_aux = P_aux->siguiente_nodo;	//Corre los otros nodos para que ocupen el eliminado
		}
	}
}

int CVertice::Tamaño()
{
	return Num_Vertices;
}

CNodoVertice CVertice::Buscar_vertice(int Posicion_buscar)
{
	CNodoVertice *P = Lista_Vertices;
	while (P)
	{
		for (int i = 0; i <= Posicion_buscar; i++)
		{
			if (i == Posicion_buscar)
			{
				CNodoVertice Vertice_Encontrado(P->Vertice[0], P->Vertice[1], P->Vertice[2]);
				return Vertice_Encontrado;
			}
			else
			{
				P = P->siguiente_nodo;
			}
		}
	}	
}

CNodoVertice CVertice::Ecuacion_recta(CNodoVertice Vertice_inicial, CNodoVertice Vertice_final, float Parametro_t)
{
	float Vector_direccion[3];
	Vector_direccion[0] = Vertice_final.Vertice[0] - Vertice_inicial.Vertice[0];
	Vector_direccion[1] = Vertice_final.Vertice[1] - Vertice_inicial.Vertice[1];
	Vector_direccion[2] = Vertice_final.Vertice[2] - Vertice_inicial.Vertice[2];

	float Vertice_proyectado[3];
	Vertice_proyectado[0] = Vertice_inicial.Vertice[0] + (Vector_direccion[0] * Parametro_t);
	Vertice_proyectado[1] = Vertice_inicial.Vertice[1] + (Vector_direccion[1] * Parametro_t);
	Vertice_proyectado[2] = Vertice_inicial.Vertice[2] + (Vector_direccion[2] * Parametro_t);

	CNodoVertice Vertice_resultante(Vertice_proyectado[0], Vertice_proyectado[1], Vertice_proyectado[2]);
	return Vertice_resultante;
}

CNodoVertice CVertice::Proyectar(CNodoVertice Vertice_inicial, CNodoVertice Vertice_final, float Radius)
{
	float Vector_P[3];
	Vector_P[0] = Vertice_final.Vertice[0] - Vertice_inicial.Vertice[0];
	Vector_P[1] = Vertice_final.Vertice[1] - Vertice_inicial.Vertice[1];
	Vector_P[2] = Vertice_final.Vertice[2] - Vertice_inicial.Vertice[2];

	float Norma_P;
	Norma_P = sqrt((Vector_P[0] * Vector_P[0]) + (Vector_P[1] * Vector_P[1]) + (Vector_P[2] * Vector_P[2]));

	float Q[3];
	Q[0] = (Radius / Norma_P)*Vector_P[0];
	Q[1] = (Radius / Norma_P)*Vector_P[1];
	Q[2] = (Radius / Norma_P)*Vector_P[2];

	CNodoVertice Proyectado;
	Proyectado.Vertice[0] = Q[0] + Vertice_inicial.Vertice[0];
	Proyectado.Vertice[1] = Q[1] + Vertice_inicial.Vertice[1];
	Proyectado.Vertice[2] = Q[2] + Vertice_inicial.Vertice[2];

	return Proyectado;
}