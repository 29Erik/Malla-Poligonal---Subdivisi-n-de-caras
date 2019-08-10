// MallaPoligonal_SubdivisionCaras.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <math.h>
#include "Objeto.h"
#include "Curvas_Bezier.h"

//----------------------
//Objetos referentes
CObjeto *Tetraedro = new CObjeto();
Curvas_Bezier *Manejo = new Curvas_Bezier();
//----------------------

//----------------------
//Declaración de variables
GLfloat Alfa, Omega;
GLboolean Ver_esfera, Subdividir, Line;
int Avanza;
GLfloat Lado_cubo, Diagonal_cubo, Radio_esfera;
//----------------------

//----------------------
//Prototipo de las funciones
void Entero();
void Camara();
void Plano_cartesiano();
void Tetraedro_para_graficar();
void Graficar_malla();
void Esfera(GLboolean);
void Render();
void Iluminacion();
//----------------------

//----------------------
//Callback de las funciones
void Teclado(unsigned char key, int x, int y);
void Flechas(int key, int x, int y);
//----------------------

//----------------------
//Funcion inicializadora de variables
void Entero()
{
	Avanza = Alfa = Omega = 0;
	Lado_cubo = 1.5;
	Diagonal_cubo = (Lado_cubo)*(sqrt(3));
	Radio_esfera = Diagonal_cubo / 2;
	Ver_esfera = true;
	Subdividir = false;
	Line = true;
	Tetraedro->Cubo_dentro_esfera(Radio_esfera);
	Tetraedro->Formar_tetraedro(Radio_esfera);
}
//----------------------

//----------------------
//Método para implementar la cámara
void Camara()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -4.0, 4.0);
	gluLookAt(0.0, 0.0, 0.2,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
}
//----------------------

//----------------------
//Método para generar un plano cartesiano
void Plano_cartesiano()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3ub(200, 200, 200);
	//-------------------------
	//Eje x
	glBegin(GL_LINES);
	glVertex3f(-1.5, 0.0, 0.0);
	glVertex3f(1.5, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-1.5, -0.1, 0.0);
	glVertex3f(-1.6, 0.0, 0.0);
	glVertex3f(-1.5, 0.1, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1.5, -0.1, 0.0);
	glVertex3f(1.6, 0.0, 0.0);
	glVertex3f(1.5, 0.1, 0.0);
	glEnd();
	//-------------------------

	//-------------------------
	//Eje y
	glBegin(GL_LINES);
	glVertex3f(0.0, -1.5, 0.0);
	glVertex3f(0.0, 1.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.1, -1.5, 0.0);
	glVertex3f(0.0, -1.6, 0.0);
	glVertex3f(0.1, -1.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 1.5, 0.0);
	glVertex3f(0.0, 1.6, 0.0);
	glVertex3f(0.1, 1.5, 0.0);
	glEnd();
	//-------------------------

	//-------------------------
	//Eje z
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -1.5);
	glVertex3f(0.0, 0.0, 1.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.0, -0.1, -1.5);
	glVertex3f(0.0, 0.0, -1.6);
	glVertex3f(0.0, 0.1, -1.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.0, -0.1, 1.5);
	glVertex3f(0.0, 0.0, 1.6);
	glVertex3f(0.0, 0.1, 1.5);
	glEnd();
	//------------------------
}
//----------------------

//----------------------
//Método para mostrar la esfera y que el tetraedro está contenido en el
void Esfera(GLboolean Mostrar)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (Mostrar == true)
	{
		glColor3ub(100, 150, 100);
		glutWireSphere(Radio_esfera, 20, 20);
	}
	else
	{
		glColor3ub(0, 0, 0);
		glutWireSphere(0.01, 20, 20);
	}	
}
//----------------------

//----------------------
//Método para plantear el ojeto
void Tetraedro_para_graficar()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (Subdividir == true)
	{
		Tetraedro->Subdividir_cara(Radio_esfera);		
		Subdividir = false;
	}
	glRotatef(315, 1.0, 0.0, 0.0);
	glRotatef(315, 0.0, 0.0, 1.0);
	Graficar_malla();
}
//----------------------

//----------------------
//Método para graficar malla
void Graficar_malla()
{
	GLint Numero_caras, Posicion_vertice;

	CNodoCara Cara_actual;
	CNodoVertice Vertice_actual;

	Numero_caras = Tetraedro->Caras->Tamaño();

	if (Line == true)
	{
		glBegin(GL_LINE_STRIP);
	}
	else
	{
		glBegin(GL_TRIANGLE_STRIP);
	}
	glColor3ub(10, 10, 255);	
	{
		for (int i = 0; i < Numero_caras; i++)
		{
			Cara_actual = Tetraedro->Caras->Buscar_cara(i);
			for (int j = 0; j < 3; j++)
			{
				Posicion_vertice = Cara_actual.Cara[j];
				Vertice_actual = Tetraedro->Vertices->Buscar_vertice(Posicion_vertice);
				//glEnable(GL_AUTO_NORMAL);
				glNormal3f(1.0, 0.0, 0.0); // Normal del vértice
				glShadeModel(GL_SMOOTH);
				glVertex3fv(Vertice_actual.Vertice);
			}
		}
	}
	glEnd();	
}
//----------------------

//----------------------
//Metodo para manjer la iluminacion de la escena
void Iluminacion()
{
	const GLfloat Luz_ambiente[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat Luz_difusa[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat Luz_especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat Posicion_luz[] = { 0.0f, 5.0f, -5.0f, 0.0f };
	//Asignamos estos valores a la luz   
	glLightfv(GL_LIGHT0, GL_AMBIENT, Luz_ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Luz_difusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Luz_especular);
	glLightfv(GL_LIGHT0, GL_POSITION, Posicion_luz);
	//Activamos la luz 0 y ambiental
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}
//----------------------

//----------------------
//Método para representar lo que se ve en pantalla
void Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 400, 400);
	Camara();
	glRotatef(Alfa, 1.0, 0.0, 0.0);
	glRotatef(Omega, 0.0, 1.0, 0.0);
	Iluminacion();
	Plano_cartesiano();
	Esfera(Ver_esfera);
	Manejo->Bezier();
	Tetraedro_para_graficar();
	glutSwapBuffers();
	cout << endl;
	cout << "La cantidad de vertices del tetraedro es: " << Tetraedro->Vertices->Tamaño();
	cout << endl;
	cout << "La cantidad de caras del tetraedro es: " << Tetraedro->Caras->Tamaño();
	cout << endl;
}
//----------------------

//---------------------
//Funcion para implementar el teclado
void Teclado(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Escape
		exit(0);
	case 'e':
	case 'E':
		Ver_esfera = true;
		Esfera(Ver_esfera);
		break;
	case 'r':
	case 'R':
		Ver_esfera = false;
		Esfera(Ver_esfera);
		break;
	case 's':
	case 'S':
		Subdividir = true;
		break;
	case 'l':
	case 'L':
		Line = true;
		break;
	case 't':
	case 'T':
		Line = false;
		break;
	case 'a':
	case 'A':
		Avanza += 1;
		break;
	case 'd':
	case 'D':
		if (Avanza > 0)
		{
			Avanza -= 1;
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
//---------------------

//---------------------
//Funcion para implementar el manejo de las flechas del teclado
void Flechas(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		Alfa += 0.3f;
		break;
	case GLUT_KEY_DOWN:
		Alfa -= 0.3f;
		break;
	case GLUT_KEY_LEFT:
		Omega += 0.3;
		break;
	case GLUT_KEY_RIGHT:
		Omega -= 0.3;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
//---------------------

//----------------------
//Funcion principal
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	Entero();
	glutCreateWindow("Malla poligonal - Tetraedro");
	glutReshapeWindow(400, 400);
	cout << endl;
	cout << "\t\t...INFORMACION MALLA POLIGONAL...";
	cout << endl;
	glutDisplayFunc(Render);
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(Flechas);
	glutMainLoop();
	return 0;
}
//----------------------

