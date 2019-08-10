
#include "NodoVertice.h"

CNodoVertice::CNodoVertice()
{
	Vertice[0] = 0.0;
	Vertice[1] = 0.0;
	Vertice[2] = 0.0;
	siguiente_nodo = NULL;
}

CNodoVertice::CNodoVertice(float Vert_x, float Vert_y, float Vert_z)
{
	Vertice[0] = Vert_x;
	Vertice[1] = Vert_y;
	Vertice[2] = Vert_z;
	siguiente_nodo = NULL;
}

CNodoVertice::~CNodoVertice() { }

void CNodoVertice::destruir_todo()
{
	if (siguiente_nodo)
	{
		siguiente_nodo->destruir_todo();
	}
	delete this;
}