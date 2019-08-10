#pragma once
#include "GL/glut.h"
#include <math.h>
#include "Puntos.h"

class Curvas_Bezier
{
public:
	Curvas_Bezier();
	virtual ~Curvas_Bezier();
	Puntos Curv(Puntos, Puntos, Puntos, Puntos, float);

	void Pintar_punto(Puntos);
	void Pintar_lineas(Puntos, Puntos);
	void Bezier();

	Puntos PtControl[25];
	Puntos ControlCamara[70];
};

