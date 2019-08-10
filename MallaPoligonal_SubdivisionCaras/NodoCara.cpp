
#include "NodoCara.h"

CNodoCara::CNodoCara()
{
	Cara[0] = 0.0;
	Cara[1] = 0.0;
	Cara[2] = 0.0;
	siguiente_nodo = NULL;
}

CNodoCara::~CNodoCara() { }

CNodoCara::CNodoCara(float Vert_inicial, float Vert_secundario, float Vert_terciario)
{
	Cara[0] = Vert_inicial;
	Cara[1] = Vert_secundario;
	Cara[2] = Vert_terciario;
	siguiente_nodo = NULL;
}

void CNodoCara::destruir_todo()
{
	if (siguiente_nodo)
	{
		siguiente_nodo->destruir_todo();
	}
	delete this;
}