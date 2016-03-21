#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#define SPACEBAR 32
void end();
GLfloat colors[][3] = {
	{ 0.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0 },
	{ 1.0, 1.0, 0.0 }, { 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 }, { 1.0, 0.0, 1.0 },
	{ 1.0, 1.0, 1.0 }, { 0.0, 1.0, 1.0 }
};
GLint laukas[][7] = {
	{ 1, 1, 1, 1, 1, 1, 1 }, 
	{ 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 3, 1 },
	{ 1, 1, 1, 1, 1, 1, 1 },
};

GLuint texture[5];
struct Image {
	unsigned long sizeX;
	unsigned long sizeY;
	char *data;
};
typedef struct Image Image;
static void priesas(int value);
void tikrink(int value);
void tikrink2(int value);
void processMenuEvents(int option);
void rodytimessage(const char* text, int lenght, int x, int y);

static GLfloat theta[] = { 15.0, -15.0, 0.0 };
static GLint   axis = 0;
GLfloat zaidX1 = 1.5;		//Zaidejo koordinates
GLfloat zaidX2 = 2.5;
GLfloat zaidY1 = -2.5;
GLfloat zaidY2 = -1.5;
GLfloat zaidZ1 = 0.5;
GLfloat zaidZ2 = -0.5;

GLfloat priesX1 = 9.5;		//Pirmo prieso koordinates
GLfloat priesX2 = 10.5;
GLfloat priesY1 = -2.5;
GLfloat priesY2 = -1.5;
GLfloat priesZ1 = 0.5;
GLfloat priesZ2 = -0.5;


GLfloat priesX3 = 1.5;		//Antro prieso koordinates
GLfloat priesX4 = 2.5;
GLfloat priesY3 = -7.5;
GLfloat priesY4 = -8.5;
GLfloat priesZ3 = 0.5;
GLfloat priesZ4 = -0.5;

GLint pozX = 1;				//Zaidejo pozicija matricoje
GLint pozY = 1;

GLint pozPriesX = 1;	//Prieso pozicija matricoje
GLint pozPriesY = 5;

GLint pozPriesX2 = 4;	//Antro prieso pozicija matricoje
GLint pozPriesY2 = 1;
int glwin;

int speed1 = 1000;
int speed2 = 1300;

/*==========================================================*/

int ImageLoad(char *filename, Image *image) {
	FILE *file;
	unsigned long size;                 // size of the image in bytes.
	unsigned long i;                    // standard counter.
	unsigned short int planes;          // number of planes in image (must be 1)
	unsigned short int bpp;             // number of bits per pixel (must be 24)
	char temp;                          // temporary color storage for bgr-rgb conversion.

	// make sure the file is there.
	if ((file = fopen(filename, "rb")) == NULL)
	{
		printf("File Not Found : %s\n", filename);
		return 0;
	}

	// seek through the bmp header, up to the width/height:
	fseek(file, 18, SEEK_CUR);

	// read the width
	if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
		printf("Error reading width from %s.\n", filename);
		return 0;
	}
	printf("Width of %s: %lu\n", filename, image->sizeX);

	// read the height
	if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
		printf("Error reading height from %s.\n", filename);
		return 0;
	}
	printf("Height of %s: %lu\n", filename, image->sizeY);

	// calculate the size (assuming 24 bits or 3 bytes per pixel).
	size = image->sizeX * image->sizeY * 3;

	// read the planes
	if ((fread(&planes, 2, 1, file)) != 1) {
		printf("Error reading planes from %s.\n", filename);
		return 0;
	}
	if (planes != 1) {
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	// read the bpp
	if ((i = fread(&bpp, 2, 1, file)) != 1) {
		printf("Error reading bpp from %s.\n", filename);
		return 0;
	}
	if (bpp != 24) {
		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}

	// seek past the rest of the bitmap header.
	fseek(file, 24, SEEK_CUR);

	// read the data.
	image->data = (char *)malloc(size);
	if (image->data == NULL) {
		printf("Error allocating memory for color-corrected image data");
		return 0;
	}

	if ((i = fread(image->data, size, 1, file)) != 1) {
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	for (i = 0; i<size; i += 3) { // reverse all of the colors. (bgr -> rgb)
		temp = image->data[i];
		image->data[i] = image->data[i + 2];
		image->data[i + 2] = temp;
	}

	// we're done.
	return 1;
}

/*==========================================================*/

void LoadGLTextures() {
	// Load Texture
	Image *image1;
	Image *image2;
	Image *image3;
	Image *image4;
	Image *image5;

	// allocate space for texture
	image1 = (Image *)malloc(sizeof(Image));	//Box
	image2 = (Image *)malloc(sizeof(Image));	//Grass
	image3 = (Image *)malloc(sizeof(Image));	//flag
	image4 = (Image *)malloc(sizeof(Image));	//pries
	image5 = (Image *)malloc(sizeof(Image));	//Zaid


	if (image1 == NULL || image2 == NULL || image3 == NULL || image4 == NULL || image5 == NULL) {
		printf("Nepavyko isskirti atminties");
		exit(0);
	}

	if (!ImageLoad("grass.bmp", image1) || !ImageLoad("crate.bmp", image2) || !ImageLoad("end.bmp", image3) || !ImageLoad("pl1.bmp", image4) || !ImageLoad("pries.bmp", image5)) {
		exit(1);
	}

	// Create Texture
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // scale linearly when image smalled than texture

	// 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image,
	// border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,
		GL_RGB, GL_UNSIGNED_BYTE, image1->data);


	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0,
	GL_RGB, GL_UNSIGNED_BYTE, image2->data);

	glGenTextures(1, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 0,
		GL_RGB, GL_UNSIGNED_BYTE, image3->data);

	glGenTextures(1, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image4->sizeX, image4->sizeY, 0,
		GL_RGB, GL_UNSIGNED_BYTE, image4->data);

	glGenTextures(1, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image5->sizeX, image5->sizeY, 0,
		GL_RGB, GL_UNSIGNED_BYTE, image5->data);
};

/*==========================================================*/

void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
	LoadGLTextures();				// Load The Texture(s)
	glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);	// Clear The Background Color To Blue
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);			// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();				// Reset The Projection Matrix

	gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);
}

/*==========================================================*/

void polygon(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int id)
{ 
	if (id == 1)
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
	}
	else if (id == 2)
	{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
	}
	else if (id == 3)
	{
		glBindTexture(GL_TEXTURE_2D, texture[0]);

	}
	else if (id == 4)
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);

	}
	else if (id == 5)
	{
		//glBindTexture(GL_TEXTURE_2D, texture[2]);		//flagas
		glBegin(GL_QUADS);
		glColor4f(255, 255, 255, 0.3);
		glVertex3fv(a);
		glColor4f(255, 255, 255, 0.3);
		glVertex3fv(b);
		glColor4f(255, 255, 255, 0.3);
		glVertex3fv(c);
		glColor4f(255, 255, 255, 0.3);
		glVertex3fv(d);
		glDisable(GL_BLEND);
		glEnd();
		return;
	}
	
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f); 	 
	glVertex3fv(a);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3fv(b);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3fv(c);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3fv(d);
	glEnd();
}

/*==========================================================*/

void make_finish(double minx, double maxx, double miny, double maxy, double minz, double maxz, int p)
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
	
		polygon(vertices[0], vertices[3], vertices[2], vertices[1], p);	
		polygon(vertices[2], vertices[3], vertices[7], vertices[6], p);
		polygon(vertices[0], vertices[4], vertices[7], vertices[3], p);
		polygon(vertices[1], vertices[2], vertices[6], vertices[5], p);
		polygon(vertices[4], vertices[5], vertices[6], vertices[7], p);
		polygon(vertices[0], vertices[1], vertices[5], vertices[4], p);

}
/*==========================================================*/



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
	GLfloat a = -1;		//pradines zemelapio koordinates
	GLfloat b = 1;
	GLfloat c = -1;
	GLfloat d = 1;

	make_finish(zaidX1, zaidX2, zaidY1, zaidY2, zaidZ1, zaidZ2,1);
	make_finish(priesX1, priesX2, priesY1, priesY2, priesZ1, priesZ2, 2);
	make_finish(priesX3, priesX4, priesY3, priesY4, priesZ3, priesZ4, 2);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i != 0 && i != 5 && j != 0 && j != 6)		//tvarkingai nupiesiam pagrinda
			make_finish(a, b, c, d, -3, -1,3);
			
			if (laukas[i][j] == 1)
			{
				
				make_finish(a, b, c, d, -1, 1,4);
				a += 2;
				b += 2;
			}
			else if (laukas[i][j]==3 )
			{
				make_finish(a+1.2, b-1.2, c+1.2, d-1.2, -1+5.5, 1-1.5,5);
				a += 2;
				b += 2;
			}
			else
			{
				a += 2;
				b += 2;
			}
		}
		a = -1;
		b = 1;
		c-= 2;
		d-= 2;
	}

	glFlush();
	glutSwapBuffers();
}



static void priesas(int value)
{
	glutTimerFunc(25, tikrink , value);
	int seed = static_cast<int>(time(0));
	srand(time(NULL));
	int ran = (rand() % 4) + 1;

	std::cout << ran;
	int tmpPries = 0;
	if (ran == 1)
	{
		if (laukas[++pozPriesX][pozPriesY] == 0 || laukas[pozPriesX][pozPriesY] == 3)
		{		
			priesY1 -= 2;
			priesY2 -= 2;		
		}
		else
		{
			--pozPriesX;
		}
		
	}
	else if (ran == 2)
	{
		if (laukas[--pozPriesX][pozPriesY] == 0 || laukas[pozPriesX][pozPriesY]==3)
		{
			priesY1 += 2;
			priesY2 += 2;
		}
		else
		{
			++pozPriesX;
		}
	}
	else if (ran == 3)
	{
		if (laukas[pozPriesX][++pozPriesY] == 0 || laukas[pozPriesX][pozPriesY] == 3)
		{
			priesX1 += 2;
			priesX2 += 2;
		}
		else
		{
			--pozPriesY;
		}
	}
	else if (ran == 4)
	{
		if (laukas[pozPriesX][--pozPriesY] == 0 || laukas[pozPriesX][pozPriesY] == 3)
		{
			priesX1 -= 2;
			priesX2 -= 2;
		}
		else
		{
			++pozPriesY;
		}
	}

	glutTimerFunc(speed1, priesas, value);
}
/*===============================================5===========*/
 void tikrink(int value)
{
	if (pozPriesX == pozX && pozPriesY == pozY)
	{
		end();
	}
	glutTimerFunc(10, tikrink, value);
}

 static void priesas2(int value)
 {
	 glutTimerFunc(25, tikrink2, value);
	 int seed2 = static_cast<int>(time(0));
	 srand(time(NULL));
	 int ran = (rand() % 4) + 1;

	 std::cout << ran;
	 int tmpPries = 0;
	 if (ran == 1)
	 {
		 if (laukas[++pozPriesX2][pozPriesY2] == 0 || laukas[pozPriesX2][pozPriesY2] == 3)
		 {
			 priesY3 -= 2;
			 priesY4 -= 2;
		 }
		 else
		 {
			 --pozPriesX2;
		 }

	 }
	 else if (ran == 2)
	 {
		 if (laukas[--pozPriesX2][pozPriesY2] == 0 || laukas[pozPriesX2][pozPriesY2] == 3)
		 {
			 priesY3 += 2;
			 priesY4 += 2;
		 }
		 else
		 {
			 ++pozPriesX2;
		 }
	 }
	 else if (ran == 3)
	 {
		 if (laukas[pozPriesX2][++pozPriesY2] == 0 || laukas[pozPriesX][pozPriesY2] == 3)
		 {
			 priesX3 += 2;
			 priesX4 += 2;
		 }
		 else
		 {
			 --pozPriesY2;
		 }
	 }
	 else if (ran == 4)
	 {
		 if (laukas[pozPriesX2][--pozPriesY2] == 0 || laukas[pozPriesX2][pozPriesY2] == 3)
		 {
			 priesX3 -= 2;
			 priesX4 -= 2;
		 }
		 else
		 {
			 ++pozPriesY2;
		 }
	 }

	 glutTimerFunc(speed2, priesas2, value);
 }

 /*===============================================5===========*/
 void tikrink2(int value)
 {
	 if (pozPriesX2 == pozX && pozPriesY2 == pozY)
	 {
		 end();
	 }
	 glutTimerFunc(10, tikrink2, value);
 }

void spinCube(void)
{
	if (theta[axis] > 360.0)
	{
		theta[axis] -= 360.0;
	}
	glutPostRedisplay();
}

/*==========================================================*/

void mouse(int btn, int state, int x, int y)
{
	char *sAxis[] = { "X-axis", "Y-axis", "Z-axis" };	
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		theta[axis+1] += 15;
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		theta[axis+1] -= 15;	
	}
}

/*==========================================================*/

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	GLfloat light_position[] = { zaidX1 - 10, zaidX2, zaidY1 - 10, zaidY2, zaidZ1 - 10, zaidZ2 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-10.0, 10.0, -10.0 * (GLfloat)h / (GLfloat)w, 10.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-7 * (GLfloat)w / (GLfloat)h, 13.0 * (GLfloat)w / (GLfloat)h, -13.0, 7.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	GLint tmp = 0;
	GLint tmp2 = laukas[pozX][pozY];

	switch (key)
	{
	case 'd':
		
		tmp = laukas[pozX][++pozY];
		if (tmp == 0 || tmp == 3)
		{
			zaidX1 += 2;
			zaidX2 += 2;
		}
		else
		{
			pozY--;
		}	
		break;
	case 'w':
			tmp = laukas[--pozX][pozY];
			if (tmp == 0 || tmp == 3)
			{
				zaidY1 += 2;
				zaidY2 += 2;
			}
			else
			{
				pozX++;
			}
	
		break;
	case 'a':
			tmp = laukas[pozX][--pozY];
			if (tmp == 0 || tmp == 3)
			{
				zaidX1 -= 2;
				zaidX2 -= 2;
			}
			else
			{
				pozY++;
			}
		break;
	case 's':
			tmp = laukas[++pozX][pozY];
			if (tmp == 0 || tmp == 3)
			{
				zaidY1 -= 2;
				zaidY2 -= 2;
			}
			else
			{
				pozX--;
			}
		break;
	case SPACEBAR:
			tmp = laukas[pozX][pozY];
			if (tmp == 3)
			{
				//const char a = 'b';
				
				end();

			}
		break;
	}
}

void end()
{
	glutDestroyWindow(glwin);
	exit(0);	
}

void ReSizeGLScene(int Width, int Height)
{
	if (Height == 0)				// Prevent A Divide By Zero If The Window Is Too Small
		Height = 1;

	glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
/*==========================================================*/
void processHits(GLint hits, GLuint buffer[])
{
	unsigned int i, j;
	GLuint names, *ptr;

	printf("hits = %d\n", hits);
	ptr = (GLuint *)buffer;
	for (i = 0; i < hits; i++)
	{ /*  for each hit  */
		names = *ptr;
		ptr += 3;
		for (j = 0; j < names; j++)
		{ /*  for each name */
			if (*ptr == 1) printf("red rectangle\n");
			else printf("blue rectangle\n");
			ptr++;
		}
		printf("\n");
	}
}
#define vienas 1
#define du 2
#define trys 3
#define keturi 4
void createMenu()
{
	int menu;

	// create the menu and
	// tell glut that "processMenuEvents" will
	// handle the events
	menu = glutCreateMenu(processMenuEvents);

	//add entries to our menu
	glutAddMenuEntry("Padidinti greiti", vienas);
	glutAddMenuEntry("Sumazinti greiti", du);
	

	// attach the menu to the right button
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
}
void processMenuEvents(int option) {

	switch (option) {
	case vienas:
		std::cout << speed1 << " " << speed2;
		speed1 -= 500;
		speed2 -= 500;
		if (speed1 <= 0 || speed2 <= 0)
		{
			speed1 += 500;
			speed2 += 500;
		}
		break;
	case du:
		std::cout << speed1 << " " << speed2;
		speed1 += 500;
		speed2 += 500;
		break;
	case trys:
		break;
	case keturi:
		break;
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	
	glutInitWindowSize(500, 500);
	glwin=glutCreateWindow("Labirintas");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	createMenu();
	//glutFullScreen();
	glutIdleFunc(display);
	glutTimerFunc(2100, priesas, 0);
	glutTimerFunc(1500, priesas2, 0);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST); /* Enable hidden-surface-removal */
	InitGL(640, 480);
	glutMainLoop();

	return 0;
}
