
#include "Lista_Caras.h"
#include "Lista_Vertices.h"
#include "GL/glut.h"

#pragma once

class CObjeto
{
public:
	CObjeto();
	~CObjeto();

	CVertice *Vertices = new CVertice();
	CCara *Caras = new CCara();

	//Vértices del cubo
	CNodoVertice Vertice_1_cubo, Vertice_2_cubo, Vertice_3_cubo, Vertice_4_cubo, Vertice_5_cubo, Vertice_6_cubo, Vertice_7_cubo, Vertice_8_cubo;

	//Vértices del tetraedro
	CNodoVertice Vertice_1_tetraedro, Vertice_2_tetraedro, Vertice_3_tetraedro, Vertice_4_tetraedro;

	//Origen
	CNodoVertice Origen;

	void Cubo_dentro_esfera(GLfloat);
	void Formar_tetraedro(GLfloat);
	void Subdividir_cara(GLfloat);
};