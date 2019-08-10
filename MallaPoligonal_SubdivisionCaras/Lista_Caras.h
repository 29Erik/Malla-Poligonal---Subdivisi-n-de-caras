
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "NodoCara.h"


#pragma once

using namespace std;

class CCara
{
public:
	CCara();
	~CCara();

	int Num_Caras;
	CNodoCara *Lista_Caras;

	void Insertar(float, float, float);
	void Eliminar(int);
	int Tamaño();
	CNodoCara Buscar_cara(int);
};