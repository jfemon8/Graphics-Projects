#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ortho Constants
const int x_min = 0;
const int x_max = 500;
const int y_min = 0;
const int y_max = 500;
const int z_min = -500;
const int z_max = 500;

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
  glBegin(GL_POLYGON);
  glVertex3f(cx, cy, 0);
  for (int i = 0; i <= 360; i++)
  {
    float angle = i * 3.1416 / 180;
    float x = rx * cos(angle);
    float y = ry * sin(angle);
    glVertex3f((x + cx), (y + cy), 0);
  }
  glEnd();
}

float wave_tx = 0;
float cloud_tx = -500;
float cloud_sx = 1;
bool cloud_sx_increase = true;
float cloud_sy = 1;
bool cloud_sy_increase = true;
float boat_tx = -200;

void init(void)
{
  glClearColor(0.24f, 0.33f, 0.78f, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(x_min, x_max, y_min, y_max, z_min, z_max);
}

void drawClouds()
{
  glPushMatrix();
  glScalef(cloud_sx, cloud_sy, 1);
  glTranslatef(cloud_tx, 0, 0);

  // 1st cloud
  glColor3ub(255, 255, 255);
  circle(20, 30, 460, 460);
  circle(15, 20, 445, 460);
  circle(15, 20, 475, 460);

  // 2nd cloud
  glColor3ub(255, 255, 255);
  circle(20, 30, 390, 420);
  circle(15, 20, 405, 420);
  circle(15, 20, 375, 420);

  glPopMatrix();

  cloud_tx += .25;
  if (cloud_sx_increase)
    cloud_sx += 0.001;
  if (!cloud_sx_increase)
    cloud_sx -= 0.001;
  if (cloud_sx > 1.5)
    cloud_sx_increase = false;
  if (cloud_sx < 1)
    cloud_sx_increase = true;
  if (cloud_tx > 150)
    cloud_tx = -500;

  glutPostRedisplay();
}

void drawHills()
{
  int hill_width = 200;
  int base_y = 175;

  glColor3ub(87, 96, 111);

  for (int start_x = -50, flag = 0; start_x <= 500; start_x += 75, flag++)
  {
    int hill_height = !(flag % 2) ? 250 : 200;

    // Front-left
    glColor3ub(106, 176, 76);
    glBegin(GL_TRIANGLES);
    glVertex3f(start_x, base_y, -250);
    glVertex3f(start_x + start_x * .25, base_y, 0);
    glVertex3f(start_x + hill_width * .25, base_y + hill_height, 0);
    glEnd();
    // Front-Right
    glBegin(GL_TRIANGLES);
    glVertex3f(start_x + start_x * .25, base_y, 0);
    glVertex3f(start_x + hill_width, base_y, -350);
    glVertex3f(start_x + hill_width * .25, base_y + hill_height, 0);
    glEnd();
    // Back
    glBegin(GL_TRIANGLES);
    glVertex3f(start_x, base_y, -250);
    glVertex3f(start_x + hill_width, base_y, -350);
    glVertex3f(start_x + hill_width * .25, base_y + hill_height, 0);
    glEnd();

    // Three lines
    glColor3ub(0, 0, 0);

    glBegin(GL_LINES);
    glVertex3f(start_x, base_y, -250);
    glVertex3f(start_x + hill_width * .25, base_y + hill_height, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(start_x + hill_width * .25, base_y, 0);
    glVertex3f(start_x + hill_width * .25, base_y + hill_height, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(start_x + hill_width, base_y, -350);
    glVertex3f(start_x + hill_width * .25, base_y + hill_height, 0);
    glEnd();
  }
}

void drawRiverWithWaves()
{
  glPushMatrix();
  glTranslatef(wave_tx, 0, 0);

  glBegin(GL_POLYGON);

  glColor3ub(112, 161, 255);

  glVertex3f(1000, 0, 0);
  glVertex3f(-500, 0, 0);
  glVertex3f(-500, 200, 0);

  double cy = 200, rx = 10, ry = 20;
  for (int start_x = -500; start_x < 1000; start_x += (rx * 2))
  {
    double cx = start_x + rx;

    glVertex3f(start_x, 200, 0);
    for (int i = 0; i <= 180; i++)
    {
      double angle = i * 3.1416 / 180;
      double x = rx * cos(angle);
      double y = ry * sin(angle);

      glVertex3f(x + cx, y + cy, 0);
    }
    glVertex3f(start_x + (rx * 2), 200, 0);
  }
  glVertex3f(1000, 200, 0);

  glEnd();

  glPopMatrix();

  glutPostRedisplay();
}

void drawBoat()
{
  glPushMatrix();
  glTranslatef(boat_tx, 0, 0);

  // boat base
  glBegin(GL_POLYGON);
  glColor3ub(109, 33, 79);
  glVertex3f(150, 50, 0);
  glVertex3f(350, 50, 0);
  glVertex3f(375, 125, 0);
  glVertex3f(125, 125, 0);
  glEnd();

  // bd flag rectangle
  glBegin(GL_POLYGON);
  glColor3ub(0, 255, 0);
  glVertex3f(250, 355, 0);
  glVertex3f(300, 355, 0);
  glVertex3f(300, 385, 0);
  glVertex3f(250, 385, 0);
  glEnd();

  // bd flag circle
  glColor3ub(255, 0, 0);
  circle(7.5, 7.5, 275, 370);

  // left sail
  glColor3ub(255, 255, 255);
  glBegin(GL_POLYGON);
  glVertex3f(250, 345, 0);
  glVertex3f(250, 125, 0); // x
  glVertex3f(150, 125, 0);
  glEnd();

  // right sail
  glColor3ub(255, 255, 255);
  glBegin(GL_POLYGON);
  glVertex3f(250, 345, 0);
  glVertex3f(250, 125, 0); // x
  glVertex3f(325, 125, 0);
  glEnd();

  // boat stand
  glLineWidth(2.0f);
  glBegin(GL_LINES);
  glColor3ub(0, 0, 0);
  glVertex3f(250, 125, 0);
  glVertex3f(250, 390, 0);
  glEnd();

  glPopMatrix();

  boat_tx += .1;
  if (boat_tx > 200)
    boat_tx = -250;
  glutPostRedisplay();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  drawClouds();
  drawHills();
  drawRiverWithWaves();
  drawBoat();

  glFlush();
  glutSwapBuffers();
}

void key(int key, int x, int y)
{
  switch (key)
  {
  case GLUT_KEY_LEFT:
  {
    wave_tx -= 5;
    if (wave_tx < -450)
      wave_tx = 0;
    glutPostRedisplay();
    break;
  }
  case GLUT_KEY_RIGHT:
  {
    wave_tx += 5;
    if (wave_tx > 450)
      wave_tx = 0;
    glutPostRedisplay();
    break;
  }
  }
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  glutCreateWindow("Natural Scenery");

  init();
  glutDisplayFunc(display);
  glutSpecialFunc(key);
  // glutIdleFunc(idle);
  glutMainLoop();

  return 0;
}
