#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "NodoVertice.h"
#include <math.h>

using namespace std;

class CVertice
{
public:
	CVertice();
	~CVertice();

	int Num_Vertices;
	CNodoVertice *Lista_Vertices;

	void Insertar(float, float, float);
	void Eliminar(int);
	int Tamaño();
	CNodoVertice Buscar_vertice(int);
	CNodoVertice Ecuacion_recta(CNodoVertice, CNodoVertice, float);
	CNodoVertice Proyectar(CNodoVertice, CNodoVertice, float);
	CNodoVertice Proyectar_Vertice(CNodoVertice, float);
};