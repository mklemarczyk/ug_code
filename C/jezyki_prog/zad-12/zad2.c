#include <GL/glut.h>
#include <math.h>

//============================================
// Definicje kolorow:

#define CZARN 0.0, 0.0, 0.0
#define CZERW 1.0, 0.0, 0.0
#define ZIELO 0.0, 1.0, 0.0
#define ZOLTY 1.0, 1.0, 0.0
#define NIEBI 0.0, 0.0, 1.0
#define MAGEN 1.0, 0.0, 1.0
#define CYJAN 0.0, 1.0, 1.0
#define BIALY 1.0, 1.0, 1.0
#define SZARY 0.75, 0.75, 0.75

//============================================
// Geometria obrazka:

static float d1 = 1;
static float d2 = 1;
static float x = 2;
static float y = 0;

void geom(int w, int h) {
  glMatrixMode(GL_PROJECTION); glLoadIdentity();
  glOrtho(-20, 20, -15, 15, -30, 30);
}

//============================================
// Obliczenie buzki:

#define M_PI 3.14159265358979323846
double przyrost = M_PI/20;

void  odcinek_okregu(double prom, double kat0, double kat1) {
  for (double kat=kat0; kat<=kat1; kat+=przyrost)
    glVertex3d(prom*cos(kat), prom*sin(kat), 0);
}

void  twarz() {
	glLineWidth(5);

	glMatrixMode(GL_MODELVIEW);glLoadIdentity();

	glTranslated(x,y,0);

	glColor3f(0,0,0); 

	glBegin(GL_LINE_LOOP);
	
	glVertex3f(4.0, 0.0, 0.0);
	glVertex3f(0.0, 4.0, 0.0);
	glVertex3f(-4.0, 0.0, 0.0);
	glVertex3f(0.0, -4.0, 0.0);
	glEnd();
	
	glPopMatrix();
}

//============================================
// Scena:

void wyswietl(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);
  twarz();
  glFlush();
}

double kat_obrotu = M_PI/360;
void  timer(int v) {
	if(x + 4 > 20)
		d1 = -d1;
	if(y + 4 > 15)
		d2 = -d2;
	if(x - 4 < -20)
		d1 = -d1;
	if(y - 4 < -15)
		d2 = -d2;
	x+=0.5*d1;
	y+=0.4*d2;
	
  //static double alfa = 0;
  //alfa += kat_obrotu;
  //if (alfa >= 2*M_PI)  alfa -= 2*M_PI;
  //glMatrixMode(GL_MODELVIEW); glLoadIdentity();
  //gluLookAt(20*cos(alfa), 7, 20*sin(alfa),  0,0,0,  0,1,0);
  glutPostRedisplay();
  glutTimerFunc(15, timer, v);
}

//============================================

int main(int ile_arg, char* arg[]) {
  glutInit(&ile_arg, arg);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(20, 10);
  glutCreateWindow(arg[0]);
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_LIGHTING);
  GLfloat swiatlo_mce[] = {2, 2, -1, 0};
  glLightfv(GL_LIGHT0, GL_POSITION, swiatlo_mce);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);

  glClearColor(ZOLTY, 0.0);
  glutReshapeFunc(geom);
  glutDisplayFunc(wyswietl);
  glutTimerFunc(15, timer, 0);
  glutMainLoop();
  return 0;
}
