
#include <GL/glut.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <math.h>


#define M_PI 3.1415926535897
float stepsize = 0.1;
float θMax = 15;
static GLfloat theta[] = { 0.0, 0.0, 0.0 };
static GLint   axis = 1;
static GLfloat a = 0.05;
static GLfloat b = 0.06;
static GLfloat R = 0.27;
int n;



GLfloat colors[8][3] = {
		{ 0.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0 },
		{ 1.0, 1.0, 0.0 }, { 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }, { 1.0, 0.0, 1.0 },
		{ 1.0, 1.0, 1.0 }, { 0.0, 1.0, 1.0 }
};
void plottriangle(GLfloat *m, GLfloat *n, GLfloat *o);
GLfloat *seashell(float A, float B);

GLfloat *seashell(GLfloat A, GLfloat B)
{
	GLfloat *mas = new GLfloat[3];
	mas[0] = (a*A + R*sin(B))*cos(A);
	mas[1] = (a*A + R*sin(B))*sin(A);
	mas[2] = b*A + R*(1 - cos(B));
	return mas;
}
void kriaukle() {
	glBegin(GL_TRIANGLES);
	for (float θ = 0; θ < θMax; θ += stepsize){
		for (float φ = 0; φ < M_PI; φ += stepsize){
			plottriangle(seashell(θ, φ), seashell(θ + stepsize, φ), seashell(θ, φ + stepsize));
			plottriangle(seashell(θ + stepsize, φ), seashell(θ, φ + stepsize), seashell(θ + stepsize, φ + stepsize));
		}
	}
}


void plottriangle(float *m, float *n, float *o)
{
	glColor3fv(colors[3]);
	glVertex3fv(m);
	glColor3fv(colors[3]);
	glVertex3fv(n);
	glColor3fv(colors[3]);
	glVertex3fv(o);
}

void display(void)
{
	/* display callback, clear frame buffer and z buffer,
	rotate cube and draw, swap buffers */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);    /* x */
	glRotatef(theta[1], 0.0, 1.0, 0.0);    /* y */
	glRotatef(theta[2], 0.0, 0.0, 1.0);    /* z */
	kriaukle();

	glFlush();
	glutSwapBuffers();
	glEnd();
}

/*==========================================================*/

void spinSphere(void)
{
	/* Idle callback, rotate cube 0.2 degrees about selected axis */
	theta[axis] += 1;
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
void key(unsigned char key, int xmouse, int ymouse)
{
	switch (key){
	case '+':
		n++;
		break;
	case '1':
		stepsize+=0.01;
		break;
	case '2':
		stepsize-=0.01;
		break;
	case '-':
		n--;
		break;
	default:
		break;
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	n = 0;
	printf("\nPress left mouse button to change rotation axis\n\n");
	/* need both double buffering and z buffer */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Color Cube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(spinSphere);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	glEnable(GL_DEPTH_TEST); 
	glutMainLoop();
	return 0;
}

