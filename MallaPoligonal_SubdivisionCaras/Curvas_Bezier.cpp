#include "Curvas_Bezier.h"

Curvas_Bezier::Curvas_Bezier()
{
	int NumVar = 25;
	Puntos PtControl[25] = {
		{ -1.0, 0.0, 0.0 },
		{ -0.9, 0.2, 0.0 },
		{ -0.8, 0.2, 0.0 },
		{ -0.7, 0.3, 0.0 },
		{ -0.6, 0.4, 0.0 },
		{ -0.5, 0.5, 0.0 },
		{ -0.4, 0.5, 0.0 },
		{ -0.3, 0.5, 0.0 },
		{ -0.2, 0.4, 0.0 },
		{ -0.15, 0.3, 0.0 },
		{ -0.05, 0.1, 0.0 },
		{ 0.0, 0.0, 0.0 }, //--- ORIGEN	
		{ 0.05, -0.1, 0.0 },
		{ 0.1, -0.2, 0.0 },
		{ 0.15, -0.1, 0.0 },
		{ 0.2, -0.4, 0.0 },
		{ 0.3, -0.5, 0.0 },
		{ 0.4, -0.6, 0.0 },
		{ 0.5, -0.5, 0.0 },
		{ 0.6, -0.4, 0.0 },
		{ 0.7, -0.3, 0.0 },
		{ 0.8, -0.2, 0.0 },
		{ 0.9, -0.1, 0.0 },
		{ 0.95, 0.0, 0.0 },
		{ 1.0, 0.0, 0.0 },
	};
}

Curvas_Bezier::~Curvas_Bezier(){ }

void Curvas_Bezier::Pintar_punto(Puntos p)
{
	glBegin(GL_POINTS);
	glVertex2f(p.x, p.y);
	glEnd();
	glFlush();
}

void Curvas_Bezier::Pintar_lineas(Puntos Pi, Puntos Pf)
{
	glBegin(GL_LINES);
	glVertex3f(Pi.x, Pi.y, Pi.z);
	glVertex3f(Pf.x, Pf.y, Pf.z);
	glEnd();
	glFlush();
}

Puntos Curvas_Bezier::Curv(Puntos A, Puntos B, Puntos C, Puntos D, float t)
{
	Puntos P;

	P.x = pow((1 - t), 3) * A.x + 3 * t * pow((1 - t), 2) * B.x + 3 * (1 - t) * pow(t, 2)* C.x + pow(t, 3)* D.x;
	P.y = pow((1 - t), 3) * A.y + 3 * t * pow((1 - t), 2) * B.y + 3 * (1 - t) * pow(t, 2)* C.y + pow(t, 3)* D.y;
	P.z = pow((1 - t), 3) * A.z + 3 * t * pow((1 - t), 2) * B.z + 3 * (1 - t) * pow(t, 2)* C.z + pow(t, 3)* D.z;

	return P;
}

void Curvas_Bezier::Bezier()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for (int i = 0; i < 25; i++)
	{
		glPointSize(5.0);
		glColor3f(0.0, 1.0, 0.0);
		Pintar_punto(PtControl[i]);
	}

	Puntos p, pd;
	Puntos pp = PtControl[0];

	int k = 0, m = 0;

	do
	{
		for (float T = 0.0; T < 1.0; T += 0.1)
		{
			p = Curv(PtControl[k], PtControl[k + 1], PtControl[k + 2], PtControl[k + 3], T);
			glColor3f(1.0, 0.0, 0.0);
			Pintar_lineas(pp, p);
			pp = p;
			ControlCamara[m] = p;
			m += 1;
		}
		k += 3;
	} while (k <= 20);
	glFlush();
}

