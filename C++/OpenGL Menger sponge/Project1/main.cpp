#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


GLfloat colors[][3] = {
	{ 0.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0 },
	{ 1.0, 1.0, 0.0 }, { 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 }, { 1.0, 0.0, 1.0 },
	{ 1.0, 1.0, 1.0 }, { 0.0, 1.0, 1.0 }
};
int gylis = 0;

/*==========================================================*/

void polygon(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int color)//viena siena
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[color]);
	glVertex3fv(a);
	glColor3fv(colors[color]);
	glVertex3fv(b);
	glColor3fv(colors[color]);
	glVertex3fv(c);
	glColor3fv(colors[color]);
	glVertex3fv(d);
	//std::cout<<a[0]<<std::endl;
	glEnd();
}

/*==========================================================*/

void make_cube(double minx, double maxx, double miny,
	double maxy, double minz, double maxz)
{
	GLfloat vertices[8][3] =
	{ { minx, miny, minz },
	{ maxx, miny, minz },
	{ maxx, maxy, minz },
	{ minx, maxy, minz },
	{ minx, miny, maxz },
	{ maxx, miny, maxz },
	{ maxx, maxy, maxz },
	{ minx, maxy, maxz } };

	polygon(vertices[0], vertices[3], vertices[2], vertices[1], 1);
	polygon(vertices[2], vertices[3], vertices[7], vertices[6], 2);
	polygon(vertices[0], vertices[4], vertices[7], vertices[3], 3);
	polygon(vertices[1], vertices[2], vertices[6], vertices[5], 4);
	polygon(vertices[4], vertices[5], vertices[6], vertices[7], 5);
	polygon(vertices[0], vertices[1], vertices[5], vertices[4], 6);
	//std::cout<<minx<<std::endl;
	//colorcube();
}

/*==========================================================*/

void sponge(double minx, double maxx, double miny, double maxy,
	double minz, double maxz, int gylis)
{
	double distance_x, distance_y, distance_z;
	if (gylis == 0)
	{
		make_cube(minx, maxx, miny, maxy, minz, maxz);
	}
	else
	{
		distance_x = (maxx - minx) / 3;
		distance_y = (maxy - miny) / 3;
		distance_z = (maxz - minz) / 3;
		for (int ix = 0; ix < 3; ix++)
		{
			for (int iy = 0; iy < 3; iy++)
			{
				if ((ix == 1) && (iy == 1))continue;
				{
					for (int iz = 0; iz < 3; iz++)
					{
						if ((iz == 1) && ((ix == 1) || (iy == 1)))
						{
						}
						else{
							sponge(minx + distance_x * ix,
								minx + distance_x *(ix + 1),
								miny + distance_y * iy,
								miny + distance_y *(iy + 1),
								minz + distance_z * iz,
								minz + distance_z *(iz + 1), gylis - 1);
						}
					}
				}
			}
		}
	}
}

static GLfloat theta[] = { 0.0, 0.0, 0.0 };
static GLint   axis = 0;

/*==========================================================*/

void display(void)
{
	/* display callback, clear frame buffer and z buffer,
	rotate cube and draw, swap buffers */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);    /* x */
	glRotatef(theta[1], 0.0, 1.0, 0.0);    /* y */
	glRotatef(theta[2], 0.0, 0.0, 1.0);    /* z */

	//colorcube ();
	/*sponge(vertices[0][0], vertices[1][0], vertices[0][1],
	vertices[2][1], vertices[0][2], vertices[4][2], gylis);*/
	sponge(-1.5, 1.5, -1.5,
		1.5, -1.5, 1.5, gylis);

	glFlush();
	glutSwapBuffers();
}

/*===============================================5===========*/

void spinCube(void)
{
	/* Idle callback, rotate cube 0.2 degrees about selected axis */
	theta[axis] += 0.1;
	if (theta[axis] > 360.0)
		theta[axis] -= 360.0;
	glutPostRedisplay();
}

/*==========================================================*/

void mouse(int btn, int state, int x, int y)
{
	char *sAxis[] = { "X-axis", "Y-axis", "Z-axis" };

	/* mouse callback, selects an axis about which to rotate */
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		axis = (++axis) % 3;
		printf("Rotate about %s\n", sAxis[axis]);
	}
}

/*==========================================================*/

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
		2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat)w / (GLfloat)h,
		2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}


void keyboard(unsigned char key, int x, int y)
{
	if ((key == '+') && (gylis<5))
	{
		gylis++;
	}
	else if ((key == '-') && (gylis>0))
	{
		gylis--;
	}
}

/*==========================================================*/

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	printf("\nPress left mouse button to change rotation axis\n\n");
	/* need both double buffering and z buffer */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Color Cube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST); /* Enable hidden-surface-removal */

	glutMainLoop();

	return 0;
}
