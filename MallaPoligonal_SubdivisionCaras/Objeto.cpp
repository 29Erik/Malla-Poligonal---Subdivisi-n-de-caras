#include "Objeto.h"

CObjeto::CObjeto()
{
	//---------------------
	//Inicialización de los vértices del cubo para definirlo circunscrito en una esfera
	Vertice_1_cubo.Vertice[0], Vertice_1_cubo.Vertice[1], Vertice_1_cubo.Vertice[2] = 0.0;
	Vertice_2_cubo.Vertice[0], Vertice_2_cubo.Vertice[1], Vertice_2_cubo.Vertice[2] = 0.0;
	Vertice_3_cubo.Vertice[0], Vertice_3_cubo.Vertice[1], Vertice_3_cubo.Vertice[2] = 0.0;
	Vertice_4_cubo.Vertice[0], Vertice_4_cubo.Vertice[1], Vertice_4_cubo.Vertice[2] = 0.0;
	Vertice_5_cubo.Vertice[0], Vertice_5_cubo.Vertice[1], Vertice_5_cubo.Vertice[2] = 0.0;
	Vertice_6_cubo.Vertice[0], Vertice_6_cubo.Vertice[1], Vertice_6_cubo.Vertice[2] = 0.0;
	Vertice_7_cubo.Vertice[0], Vertice_7_cubo.Vertice[1], Vertice_7_cubo.Vertice[2] = 0.0;
	Vertice_8_cubo.Vertice[0], Vertice_8_cubo.Vertice[1], Vertice_8_cubo.Vertice[2] = 0.0;
	//---------------------

	//---------------------
	//Inicialización de los vértices para el tetraedro
	Vertice_1_tetraedro.Vertice[0], Vertice_1_tetraedro.Vertice[1], Vertice_1_tetraedro.Vertice[2] = 0.0;
	Vertice_2_tetraedro.Vertice[0], Vertice_2_tetraedro.Vertice[1], Vertice_2_tetraedro.Vertice[2] = 0.0;
	Vertice_3_tetraedro.Vertice[0], Vertice_3_tetraedro.Vertice[1], Vertice_3_tetraedro.Vertice[2] = 0.0;
	Vertice_4_tetraedro.Vertice[0], Vertice_4_tetraedro.Vertice[1], Vertice_4_tetraedro.Vertice[2] = 0.0;
	//---------------------

	//---------------------
	//Origen
	Origen.Vertice[0], Origen.Vertice[1], Origen.Vertice[2] = 0.0;
	//---------------------
}

CObjeto::~CObjeto() { }

void CObjeto::Cubo_dentro_esfera(GLfloat Radio_proyectar)
{
	GLfloat Pto_vertice = Radio_proyectar;

	//---------------------
	//Vértices del cubo para definirlo circunscrito en una esfera
	Vertice_1_cubo.Vertice[0] = Pto_vertice;
	Vertice_1_cubo.Vertice[1] = Pto_vertice;
	Vertice_1_cubo.Vertice[2] = Pto_vertice;

	Vertice_2_cubo.Vertice[0] = -Pto_vertice;
	Vertice_2_cubo.Vertice[1] = Pto_vertice;
	Vertice_2_cubo.Vertice[2] = Pto_vertice;

	Vertice_3_cubo.Vertice[0] = -Pto_vertice;
	Vertice_3_cubo.Vertice[1] = -Pto_vertice;
	Vertice_3_cubo.Vertice[2] = Pto_vertice;

	Vertice_4_cubo.Vertice[0] = Pto_vertice;
	Vertice_4_cubo.Vertice[1] = -Pto_vertice;
	Vertice_4_cubo.Vertice[2] = Pto_vertice;

	Vertice_5_cubo.Vertice[0] = Pto_vertice;
	Vertice_5_cubo.Vertice[1] = Pto_vertice;
	Vertice_5_cubo.Vertice[2] = -Pto_vertice;

	Vertice_6_cubo.Vertice[0] = -Pto_vertice;
	Vertice_6_cubo.Vertice[1] = Pto_vertice;
	Vertice_6_cubo.Vertice[2] = -Pto_vertice;

	Vertice_7_cubo.Vertice[0] = -Pto_vertice;
	Vertice_7_cubo.Vertice[1] = -Pto_vertice;
	Vertice_7_cubo.Vertice[2] = -Pto_vertice;

	Vertice_8_cubo.Vertice[0] = Pto_vertice;
	Vertice_8_cubo.Vertice[1] = -Pto_vertice;
	Vertice_8_cubo.Vertice[2] = -Pto_vertice;
	//---------------------
}

void CObjeto::Formar_tetraedro(GLfloat Proyectar)
{
	//---------------------
	//Vértices del tetraedro circunscritos dentro del cubo para hacer que sea regular
	Vertice_1_tetraedro = Vertices->Proyectar(Origen, Vertice_4_cubo, Proyectar);
	Vertice_2_tetraedro = Vertices->Proyectar(Origen, Vertice_2_cubo, Proyectar);
	Vertice_3_tetraedro = Vertices->Proyectar(Origen, Vertice_5_cubo, Proyectar);
	Vertice_4_tetraedro = Vertices->Proyectar(Origen, Vertice_7_cubo, Proyectar);
	//---------------------

	//---------------------
	//Vértices definidos para ingresar a la lista de vértices
	Vertices->Insertar(Vertice_1_tetraedro.Vertice[0], Vertice_1_tetraedro.Vertice[1], Vertice_1_tetraedro.Vertice[2]);
	Vertices->Insertar(Vertice_2_tetraedro.Vertice[0], Vertice_2_tetraedro.Vertice[1], Vertice_2_tetraedro.Vertice[2]);
	Vertices->Insertar(Vertice_3_tetraedro.Vertice[0], Vertice_3_tetraedro.Vertice[1], Vertice_3_tetraedro.Vertice[2]);
	Vertices->Insertar(Vertice_4_tetraedro.Vertice[0], Vertice_4_tetraedro.Vertice[1], Vertice_4_tetraedro.Vertice[2]);
	//---------------------

	//---------------------
	//Caras con sus indices de la lista de vértices para ingresar a la lista
	Caras->Insertar(0, 2, 1);
	Caras->Insertar(0, 3, 2);
	Caras->Insertar(1, 2, 3);
	Caras->Insertar(0, 1, 3);
	//---------------------
}

void CObjeto::Subdividir_cara(GLfloat Radio_sphere)
{
	GLint Tot_cara, Tot_vertices;
	Tot_cara = Caras->Tamaño();
	for (int i = 0; i < Tot_cara; i++)
	{
		Tot_vertices = Vertices->Tamaño();
		CNodoCara Cara_dividida = Caras->Buscar_cara(i);

		CNodoVertice Vert_a = Vertices->Buscar_vertice(Cara_dividida.Cara[0]);
		CNodoVertice Vert_b = Vertices->Buscar_vertice(Cara_dividida.Cara[1]);
		CNodoVertice Vert_c = Vertices->Buscar_vertice(Cara_dividida.Cara[2]);

		CNodoVertice A_B = Vertices->Ecuacion_recta(Vert_a, Vert_b, 0.5);
		CNodoVertice B_C = Vertices->Ecuacion_recta(Vert_b, Vert_c, 0.5);
		CNodoVertice C_A = Vertices->Ecuacion_recta(Vert_c, Vert_a, 0.5);

		CNodoVertice Vert_A_B = Vertices->Proyectar(Origen, A_B, Radio_sphere);
		CNodoVertice Vert_B_C = Vertices->Proyectar(Origen, B_C, Radio_sphere);
		CNodoVertice Vert_C_A = Vertices->Proyectar(Origen, C_A, Radio_sphere);

		Vertices->Insertar(Vert_A_B.Vertice[0], Vert_A_B.Vertice[1], Vert_A_B.Vertice[2]);
		Vertices->Insertar(Vert_B_C.Vertice[0], Vert_B_C.Vertice[1], Vert_B_C.Vertice[2]);
		Vertices->Insertar(Vert_C_A.Vertice[0], Vert_C_A.Vertice[1], Vert_C_A.Vertice[2]);

		CNodoCara Cara_nueva_1, Cara_nueva_2, Cara_nueva_3, Cara_nueva_4;
		GLint Pos_nuevo_vert_1, Pos_nuevo_vert_2, Pos_nuevo_vert_3;

		Pos_nuevo_vert_1 = Tot_vertices;
		Pos_nuevo_vert_2 = Tot_vertices + 1;
		Pos_nuevo_vert_3 = Tot_vertices + 2;

		Cara_nueva_1.Cara[0] = Cara_dividida.Cara[0];
		Cara_nueva_1.Cara[1] = Pos_nuevo_vert_1;
		Cara_nueva_1.Cara[2] = Pos_nuevo_vert_3;

		Cara_nueva_2.Cara[0] = Cara_dividida.Cara[1];
		Cara_nueva_2.Cara[1] = Pos_nuevo_vert_2;
		Cara_nueva_2.Cara[2] = Pos_nuevo_vert_1;

		Cara_nueva_3.Cara[0] = Cara_dividida.Cara[2];
		Cara_nueva_3.Cara[1] = Pos_nuevo_vert_3;
		Cara_nueva_3.Cara[2] = Pos_nuevo_vert_2;

		Cara_nueva_4.Cara[0] = Pos_nuevo_vert_1;
		Cara_nueva_4.Cara[1] = Pos_nuevo_vert_2;
		Cara_nueva_4.Cara[2] = Pos_nuevo_vert_3;

		Caras->Insertar(Cara_nueva_1.Cara[0], Cara_nueva_1.Cara[1], Cara_nueva_1.Cara[2]);
		Caras->Insertar(Cara_nueva_2.Cara[0], Cara_nueva_2.Cara[1], Cara_nueva_2.Cara[2]);
		Caras->Insertar(Cara_nueva_3.Cara[0], Cara_nueva_3.Cara[1], Cara_nueva_3.Cara[2]);
		Caras->Insertar(Cara_nueva_4.Cara[0], Cara_nueva_4.Cara[1], Cara_nueva_4.Cara[2]);
	}	
	for (int i = 0; i < Tot_cara; i++)
	{
		Caras->Eliminar(0);
	}
}