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

//============================================
// Geometria obrazka:

void geom(int w, int h) {
  glOrtho(-20, 20, -15, 15, -5, 5);
}

//============================================
// Odcinek okregu (obliczenie):

#define M_PI 3.14159265358979323846
  // nie w kazdej wersji  gcc  zdefiniowana stala

double przyrost = M_PI/20;
  // im mniejszy, tym lepszy rysunek, ale dluzej powstajacy

void  odcinek_okregu(double prom, double kat0, double kat1) {
    // promien, kat poczatkowy odcinka, kat koncowy odcinka
  for (double kat=kat0; kat<=kat1; kat+=przyrost)
    glVertex3d(prom*cos(kat), prom*sin(kat), 0);
}

//============================================
// Scena:

void wyswietl(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  //----------------
  // Parabola:

  glColor3d(CZARN); glLineWidth(5);
  glPushMatrix(); glTranslated(-10, 0, 0);
  glBegin(GL_LINE_STRIP);
    for (double x=-4.0; x<=4.0; x+=przyrost)
      glVertex3d(x, x*x-7, 0);
  glEnd();
  glPopMatrix();

  //----------------
  // Okrag z dziubkiem:

  glColor3d(CZARN); glLineWidth(5);
  glPushMatrix(); glTranslated(10, 0, 0);
  glBegin(GL_LINE_LOOP);
    odcinek_okregu(7, 0, 3*M_PI/2);
    glVertex3d(7,-7, 0);
  glEnd();
  glPopMatrix();

  //----------------

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
