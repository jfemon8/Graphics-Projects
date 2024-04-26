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
const int x_min = -100;
const int x_max = 500;
const int y_min = -200;
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

  cloud_tx += .125;
  if (cloud_sx_increase)
    cloud_sx += 0.0005;
  if (!cloud_sx_increase)
    cloud_sx -= 0.0005;
  if (cloud_sx > 2)
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

  for (int start_x = -150, flag = 0; start_x <= 500; start_x += 75, flag++)
  {
    int hill_height = !(flag % 2) ? 250 : 200;

    // Front-left
    glColor3ub(210, 105, 30);
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

void drawField()
{
  glPushMatrix();

  glBegin(GL_POLYGON);

  glColor3ub(50, 205, 50);

  glVertex3f(1000, -1, 0);
  glVertex3f(-500, -1, 0);
  glVertex3f(-500, 200, 0);
  glVertex3f(1000, 200, 0);

  glEnd();

  glPopMatrix();

  glutPostRedisplay();
}

void drawRiverWithWaves()
{
  glPushMatrix();
  glTranslatef(wave_tx, 0, 0);

  glBegin(GL_POLYGON);

  glColor3ub(112, 161, 255);

  glVertex3f(1000, -200, 0);
  glVertex3f(-500, -200, 0);
  glVertex3f(-500, 0, 0);

  double cy = 0, rx = 10, ry = 20;
  for (int start_x = -500; start_x < 1000; start_x += (rx * 2))
  {
    double cx = start_x + rx;

    glVertex3f(start_x, 0, 0);
    for (int i = 0; i <= 180; i++)
    {
      double angle = i * 3.1416 / 180;
      double x = rx * cos(angle);
      double y = ry * sin(angle);

      glVertex3f(x + cx, y + cy, 0);
    }
    glVertex3f(start_x + (rx * 2), 0, 0);
  }
  glVertex3f(1000, 0, 0);

  glEnd();

  glPopMatrix();

  glutPostRedisplay();
}

void drawHouse(){
    glPushMatrix();

    //First house
    glBegin(GL_POLYGON);
    glColor3ub(205, 201, 201);
    glVertex3f(-80, 50, 0);
    glVertex3f(-10, 50, 0);
    glVertex3f(-15, 60, 0);
    glVertex3f(-75, 60, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 198, 115);
    glVertex3f(-75, 120, 0);
    glVertex3f(-15, 120, 0);
    glVertex3f(-15, 60, 0);
    glVertex3f(-75, 60, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 137, 137);
    glVertex3f(-95, 120, 0);
    glVertex3f(5, 120, 0);
    glVertex3f(-15, 150, 0);
    glVertex3f(-75, 150, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(-45, 60, 0);
    glVertex3f(-25, 60, 0);
    glVertex3f(-25, 100, 0);
    glVertex3f(-45, 100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(-65, 80, 0);
    glVertex3f(-55, 80, 0);
    glVertex3f(-55, 100, 0);
    glVertex3f(-65, 100, 0);
    glEnd();

    //Second house
    //3D Back
    glBegin(GL_POLYGON);
    glColor3ub(205, 201, 201);
    glVertex3f(50, 70, -50);
    glVertex3f(150, 70, -50);
    glVertex3f(145, 80, -50);
    glVertex3f(55, 80, -50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 198, 115);
    glVertex3f(55, 80, -50);
    glVertex3f(145, 80, -50);
    glVertex3f(145, 150, -50);
    glVertex3f(55, 150, -50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 137, 137);
    glVertex3f(35, 150, -50);
    glVertex3f(165, 150, -50);
    glVertex3f(145, 180, -25);
    glVertex3f(55, 180, -25);
    glEnd();
    //3D Font
    glBegin(GL_POLYGON);
    glColor3ub(205, 201, 201);
    glVertex3f(50, 70, 0);
    glVertex3f(150, 70, 0);
    glVertex3f(145, 80, 0);
    glVertex3f(55, 80, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 198, 115);
    glVertex3f(55, 80, 0);
    glVertex3f(145, 80, 0);
    glVertex3f(145, 150, 0);
    glVertex3f(55, 150, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 137, 137);
    glVertex3f(35, 150, 0);
    glVertex3f(165, 150, 0);
    glVertex3f(145, 180, -25);
    glVertex3f(55, 180, -25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(90, 80, 0);
    glVertex3f(110, 80, 0);
    glVertex3f(110, 130, 0);
    glVertex3f(90, 130, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(65, 100, 0);
    glVertex3f(80, 100, 0);
    glVertex3f(80, 130, 0);
    glVertex3f(65, 130, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(120, 100, 0);
    glVertex3f(135, 100, 0);
    glVertex3f(135, 130, 0);
    glVertex3f(120, 130, 0);
    glEnd();
    //3D Left
    glBegin(GL_POLYGON);
    glColor3ub(205, 201, 201);
    glVertex3f(50, 70, -50);
    glVertex3f(50, 70, 0);
    glVertex3f(55, 80, 0);
    glVertex3f(55, 80, -50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 198, 115);
    glVertex3f(55, 80, -50);
    glVertex3f(55, 80, 0);
    glVertex3f(55, 150, 0);
    glVertex3f(55, 150, -50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 137, 137);
    glVertex3f(55, 150, 0);
    glVertex3f(55, 180, -25);
    glVertex3f(55, 180, -50);
    glEnd();
    //3D Right
    glBegin(GL_POLYGON);
    glColor3ub(205, 201, 201);
    glVertex3f(150, 70, 0);
    glVertex3f(150, 70, -50);
    glVertex3f(145, 80, -50);
    glVertex3f(145, 80, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 198, 115);
    glVertex3f(145, 80, 0);
    glVertex3f(145, 80, -50);
    glVertex3f(145, 150, -50);
    glVertex3f(145, 150, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 137, 137);
    glVertex3f(145, 150, 0);
    glVertex3f(145, 150, -50);
    glVertex3f(145, 180, -25);
    glEnd();

    //Third house
    glBegin(GL_POLYGON);
    glColor3ub(205, 201, 201);
    glVertex3f(275, 60, 0);
    glVertex3f(385, 60, 0);
    glVertex3f(380, 70, 0);
    glVertex3f(280, 70, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(205, 198, 115);
    glVertex3f(280, 70, 0);
    glVertex3f(380, 70, 0);
    glVertex3f(380, 150, 0);
    glVertex3f(280, 150, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139, 137, 137);
    glVertex3f(260, 150, 0);
    glVertex3f(400, 150, 0);
    glVertex3f(380, 180, 0);
    glVertex3f(280, 180, 0);
    glEnd();
    //Door
    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(315, 70, 0);
    glVertex3f(345, 70, 0);
    glVertex3f(345, 130, 0);
    glVertex3f(315, 130, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(290, 100, 0);
    glVertex3f(305, 100, 0);
    glVertex3f(305, 130, 0);
    glVertex3f(290, 130, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(355, 100, 0);
    glVertex3f(370, 100, 0);
    glVertex3f(370, 130, 0);
    glVertex3f(355, 130, 0);
    glEnd();


    glPopMatrix();

    glutPostRedisplay();
}




void drawTree(){
    glPushMatrix();

    //First tree
    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(445, 50, 0);
    glVertex3f(455, 50, 0);
    glVertex3f(455, 100, 0);
    glVertex3f(445, 100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex3f(420, 100, 0);
    glVertex3f(480, 100, 0);
    glVertex3f(450, 180, 0);
    glEnd();

    //Second tree
    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(205, 60, 0);
    glVertex3f(220, 60, 0);
    glVertex3f(220, 100, 0);
    glVertex3f(205, 100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex3f(170, 100, 0);
    glVertex3f(255, 100, 0);
    glVertex3f(213, 180, 0);
    glEnd();

    //Third tree
   glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(20, 60, 0);
    glVertex3f(25, 60, 0);
    glVertex3f(25, 100, 0);
    glVertex3f(20, 100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex3f(0, 100, 0);
    glVertex3f(45, 100, 0);
    glVertex3f(23, 150, 0);
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
  glVertex3f(150, -150, 0);
  glVertex3f(350, -150, 0);
  glVertex3f(375, -75, 0);
  glVertex3f(125, -75, 0);
  glEnd();
/*
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
  */

  // left sail
  glColor3ub(240, 230, 140);
  glBegin(GL_POLYGON);
  glVertex3f(250, 145, 0);
  glVertex3f(250, -75, 0); // x
  glVertex3f(150, -75, 0);
  glEnd();

  // right sail
  glColor3ub(238, 232, 170);
  glBegin(GL_POLYGON);
  glVertex3f(250, 145, 0);
  glVertex3f(250, -75, 0); // x
  glVertex3f(325, -75, 0);
  glEnd();

  // boat stand
  glLineWidth(2.0f);
  glBegin(GL_LINES);
  glColor3ub(0, 0, 0);
  glVertex3f(250, -75, 0);
  glVertex3f(250, 150, 0);
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

  drawField();
  drawHouse();

  drawTree();

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
    if (wave_tx > 250)
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

  glutCreateWindow("Rural Beauty");

  init();
  glutDisplayFunc(display);
  glutSpecialFunc(key);
  // glutIdleFunc(idle);
  glutMainLoop();

  return 0;
}
