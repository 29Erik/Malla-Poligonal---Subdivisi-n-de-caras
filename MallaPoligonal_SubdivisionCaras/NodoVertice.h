
# pragma once

#include <iostream>

class CNodoVertice
{
public:

	float Vertice[3];
	CNodoVertice *siguiente_nodo;

	CNodoVertice();
	CNodoVertice(float, float, float);
	~CNodoVertice();

	void destruir_todo();
};