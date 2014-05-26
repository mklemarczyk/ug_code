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

void geom(int w, int h) {
  glOrtho(-20, 20, -15, 15, -5, 5);
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

    // obrys buzki:
  glColor3d(CZARN);
  glBegin(GL_LINE_LOOP);
    odcinek_okregu(8, 0, 2*M_PI);  // okrag o promieniu 8
  glEnd();

    // wypelnienie buzki:
  glColor3d(SZARY);
  glBegin(GL_POLYGON);
    odcinek_okregu(8, 0, 2*M_PI);  // kolo o promieniu 8
  glEnd();

    // lewe oko:
  glPushMatrix(); glTranslated(-3, 0, 0);
  glColor4d(NIEBI,0);
  glBegin(GL_LINE_STRIP);
    odcinek_okregu(1.414*2, M_PI/4, 3*M_PI/4);
  glEnd();
  glPopMatrix();
  glPushMatrix(); glTranslated(-3, 4, 0);
  glColor4d(NIEBI,0);
  glBegin(GL_LINE_STRIP);
    odcinek_okregu(1.414*2, 5*M_PI/4, 7*M_PI/4);
  glEnd();
  glPopMatrix();

    // prawe oko:
  glPushMatrix(); glTranslated(3, 0, 0);
  glColor4d(NIEBI,0);
  glBegin(GL_LINE_STRIP);
    odcinek_okregu(1.414*2, M_PI/4, 3*M_PI/4);
  glEnd();
  glPopMatrix();
  glPushMatrix(); glTranslated(3, 4, 0);
  glColor4d(NIEBI,0);
  glBegin(GL_LINE_STRIP);
    odcinek_okregu(1.414*2, 5*M_PI/4, 7*M_PI/4);
  glEnd();
  glPopMatrix();

    // usta:
  glColor3d(CZERW);
  glBegin(GL_POLYGON);
    odcinek_okregu(1.414*4, 5*M_PI/4, 7*M_PI/4);
  glEnd();

    // nos:
  glColor3d(ZIELO);
  glPushMatrix(); glTranslated(0,-1, 1.5);
    glutSolidSphere(2, 20, 16);
  glPopMatrix();
}

//============================================
// Scena:

void wyswietl(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  twarz();
  glFlush();
}

//============================================

int main(int ile_arg, char* arg[]) {
  glutInit(&ile_arg, arg);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(20, 10);
  glutCreateWindow(arg[0]);
  glClearColor(ZOLTY, 0.0);
  glutReshapeFunc(geom);
  glutDisplayFunc(wyswietl);
  glutMainLoop();
  return 0;
}
