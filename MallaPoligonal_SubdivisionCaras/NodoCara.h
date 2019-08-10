
#pragma once

#include <iostream>

class CNodoCara
{
public:
	CNodoCara *siguiente_nodo;
	float Cara[3];

	CNodoCara();
	CNodoCara(float, float, float);
	~CNodoCara();

	void destruir_todo();
};