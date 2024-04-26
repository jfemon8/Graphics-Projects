#include <bits/stdc++.h>
#include <windows.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLUT.h>
#include <time.h>
#endif
#define PI 3.14159265358979323846

static int a = 0, a1 = 0;
double eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;

GLfloat ax = 0.0, ay = 0.0, az = 0, sx = 1.3, sy = 0.7, sz = 1;
GLint rx = 0, ry = -40, rz = 0;
void PressKey(int key, int x, int y) {
	switch (key) {
    case GLUT_KEY_LEFT: ax -= 0.05; break;
    case GLUT_KEY_RIGHT: ax += 0.05; break;
    case GLUT_KEY_UP: ay += 0.05; break;
    case GLUT_KEY_DOWN: ay -= 0.05; break;
    case GLUT_KEY_PAGE_UP: az += 0.05; break;
    case GLUT_KEY_PAGE_DOWN: az -= 0.05; break;

    case GLUT_KEY_F1: (rx += 3) %= 360; break;
    case GLUT_KEY_F2: (rx -= 3) %= 360; break;
    case GLUT_KEY_F3: (ry += 3) %= 360; break;
    case GLUT_KEY_F4: (ry -= 3) %= 360; break;
    case GLUT_KEY_F5: (rz += 3) %= 360; break;
    case GLUT_KEY_F6: (rz -= 3) %= 360; break;

    case GLUT_KEY_F7: sx *= 1.5f; break;
    case GLUT_KEY_F8: sx *= 0.5f; break;
    case GLUT_KEY_F9: sy *= 1.5f; break;
    case GLUT_KEY_F10: sy *= 0.5f; break;
    case GLUT_KEY_F11: sz *= 1.5f; break;
    case GLUT_KEY_F12: sz *= 0.5f; break;

    default: return;
	}
	glutPostRedisplay();
}

double x = 0, Sx = 0, Sy = 0, Sz = 0, tx = 0, ty = 0, tz = 0;
bool ck = 1;
void ballMove(int value) {
    tx = tx - 0.001; ty = ty + 0.002; tz = tz - 0.002;
    if(ck == 1 && tz > -0.55) {
        glutTimerFunc(35, ballMove, 0);
        glutPostRedisplay();
    }
}

double posx = 0, posy = 0, posz = 2;
void NormalKeyHandler (unsigned char key, int x, int y) {
    if (key == 's') (a -= 5) %= 360;
    else if(key == '1') posx += 0.5;
    else if(key == '2') posx -= 0.5;
    else if(key == '3') posy += 0.5;
    else if(key == '4') posy -= 0.5;
    else if(key == '5') posz += 0.5;
    else if(key == '6') posz -= 0.5;
    glutPostRedisplay();
}

void background(){
    //field
    glTranslatef(-0.5, -0.4, 0);
    glScalef(0.5,0.5,0.5);
    glRotatef(10, 1, 1, 0);
    //front
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (1.1, 0, 2);
        glVertex3f (1.1, 0.1, 2);
        glVertex3f (0, 0.1, 2);
    glEnd();
    //bottom
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (1.1, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (0, 0, 0);
    glEnd();
    //up
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0.1, 2);
        glVertex3f (1.1, 0.1, 2);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (0, 0.1, 0);
    glEnd();
    //left
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, 2);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0, 0.1, 0);
    glEnd();
    //right
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (1.1, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (1.1, 0.1, 2);
    glEnd();
    //back
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (0, 0.1, 0);
        glVertex3f (0, 0, 0);
    glEnd();
    //1
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 2);
        glVertex3f(1.1, 0, 2);
    glEnd();
    //2
    glColor3f (0, 0, 0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 2);
        glVertex3f(1.1, 0.1, 2);
    glEnd();
    //3
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 2);
        glVertex3f(0, 0.1, 2);
    glEnd();
    //4
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 2);
        glVertex3f(0, 0.1, 0);
    glEnd();
    //5
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 2);
        glVertex3f(0, 0, 0);
    glEnd();
    //6
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 0);
        glVertex3f(0, 0, 0);
    glEnd();
    //7
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 0);
        glVertex3f(1.6, 0.1, 0);
    glEnd();
    //Road
    glColor3f (0, 0, 0);
    glBegin(GL_QUADS);
        //front
        glVertex3f (1.1, 0, 2);
        glVertex3f (2, 0, 2);
        glVertex3f (2, 0.1, 2);
        glVertex3f (1.1, 0.1, 2);
        //bottom
        glVertex3f (1.1, 0, 2);
        glVertex3f (2, 0, 2);
        glVertex3f (2, 0, 0);
        glVertex3f (1.6, 0, 0);
        //back
        glVertex3f (2, 0, 0);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (2, 0.1, 0);
        //up
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (2, 0.1, 0);
        glVertex3f (2, 0.1, 2);
        glVertex3f (1.1, 0.1, 2);
        //left
        glVertex3f (1.1, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (1.1, 0.1, 2);
        //right
        glVertex3f (2, 0, 2);
        glVertex3f (2, 0, 0);
        glVertex3f (2, 0.1, 0);
        glVertex3f (2, 0.1, 2);
    glEnd();
    // cross line
    glColor3f (1, 1, 1);
    glBegin(GL_QUADS);
        glVertex3f (1.4, 0.0, 0.8);
        glVertex3f (2.1, 0.0, 0.8);
        glVertex3f (2.1, 0.0, 0.81);
        glVertex3f (1.4, 0.0, 0.81);
    glEnd();
}

void mountain() {
    glBegin(GL_TRIANGLES);
        //front
        glVertex3f(-2,-0.28,0);
        glVertex3f(-1, 0.3,-0.5);
        glVertex3f(0.5,-0.28,0);
        //right
        glVertex3f(0.5, -0.28, 0);
        glVertex3f(-1, 0.3,-0.5);
        glVertex3f(0.5, -0.28,-1);
        //back
        glVertex3f(0.5, -0.28,-1);
        glVertex3f(-1, 0.3,-0.5);
        glVertex3f(-2, -0.28,-1);
        //left
        glVertex3f(-2, -0.28,0);
        glVertex3f(-1, 0.3,-0.5);
        glVertex3f(-2, -0.28,-1);
        //bottom
        glVertex3f(-2, -0.28,0);
        glVertex3f(0.5, -0.28,0);
        glVertex3f(0.5, -0.28,-1);
        glVertex3f(-2, -0.28,-1);
    glEnd();

    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        //1
        glVertex3f(-2, -0.28, 0);
        glVertex3f(-1, 0.3,-0.5);
    glEnd();
    glBegin(GL_LINES);
        //2
        glVertex3f(0.5, -0.28, 0);
        glVertex3f(-1, 0.3,-0.5);
    glEnd();
    glBegin(GL_LINES);
        //3
        glVertex3f(0.5, -0.28, -1);
        glVertex3f(-1, 0.3,-0.5);
    glEnd();
    glBegin(GL_LINES);
        //4
        glVertex3f(0.5, -0.28, 0);
        glVertex3f(0.5, -0.28,-1);
    glEnd();
    glBegin(GL_LINES);
        //5
        glVertex3f(-2, -0.28, -1);
        glVertex3f(-1, 0.3,-0.5);
    glEnd();
}

void cloud(){
    glColor3f (1, 1, 1); //first cloud
    glPushMatrix();
        glTranslatef(0.5, 1.8, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.4, 1.75, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.3, 1.8, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.5, 1.9, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.35, 1.88, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();

    //second cloud
    glPushMatrix();
        glTranslatef(1.2, 1.8, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.3, 1.85, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.25, 1.75, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.4, 1.8, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.35, 1.73, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
}

void tiang() {
    glBegin(GL_QUADS);
        glColor3f(0.4,0.4,0.4);
        //back
        glVertex3f(-0.3,-0.3,0);
        glVertex3f(-0.25,-0.3,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.3,0.5,0);
        //left
        glColor3f(0,0,0);
        glVertex3f(-0.3,-0.3,0.05);
        glVertex3f(-0.3,-0.3,0);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.3,0.5,0.05);
        //right
        glColor3f(0,0,0);
        glVertex3f(-0.25,-0.3,0.05);
        glVertex3f(-0.25,-0.3,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.25,0.5,0.05);
        //bottom
        glColor3f(0.4,0.4,0.4);
        glVertex3f(-0.3,-0.3,0.05);
        glVertex3f(-0.25,-0.3,0.05);
        glVertex3f(-0.25,-0.3,0);
        glVertex3f(-0.3,-0.3,0);
        //top
        glColor3f(0.4,0.4,0.4);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.3,0.5,0);
        //front
        glColor3f(0.4,0.4,0.4);
        glVertex3f(-0.3,-0.3,0.05);
        glVertex3f(-0.25,-0.3,0.05);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.3,0.5,0.05);
    glEnd();
}

void fan() {
    //fan1
    //back
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.05,0.8,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.05,0.8,0);
        glVertex3f(0,0.7,0);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.25,0.5,0);
    glEnd();
    //left
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.25,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.25,0.5,0.05);
    glEnd();
    //right
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.2,0.4,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.2,0.4,0.05);
    glEnd();
    //bottom
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.25,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.25,0.5,0.05);
    glEnd();
    //top
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.05,0.8,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.05,0.8,0.05);
    glEnd();
    //front
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(-0.05,0.8,0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.275,0.45,0.05);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(-0.25,0.5,0.05);
    glEnd();
  //fan2
   //back
   glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.05,0.1,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.25,0.4,0);
    glEnd();
    //left
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.25,0.4,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.25,0.4,0.05);
    glEnd();
    //right
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.3,0.3,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.3,0.3,0.05);
    glEnd();
    //bottom
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.25,0.4,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.25,0.4,0.05);
    glEnd();
    //top
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.05,0.1,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.05,0.1,0.05);
    glEnd();
    //front
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.05,0.1,0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.275,0.45,0.05);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.25,0.4,0.05);
    glEnd();
    //fan3
    //back
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.35,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.3,0.4,0);
    glEnd();
    //left
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.3,0.4,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.3,0.4,0.05);
    glEnd();
    //right
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.35,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.35,0.5,0.05);
    glEnd();
    //bottom
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.35,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.35,0.5,0.05);
    glEnd();
    //top
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.55,0.2,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.55,0.2,0.05);
    glEnd();
    //front
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.35,0.5,0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.275,0.45,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.3,0.4,0.05);
    glEnd();
    //fan4
    //back
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.25,0.6,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.25,0.6,0);
        glVertex3f(-0.25,0.6,0);
        glVertex3f(-0.3,0.5,0);
    glEnd();
    //left
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.5,0.8,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.5,0.8,0.05);
    glEnd();
    //right
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.25,0.6,0.05);
        glVertex3f(-0.25,0.6,0);
        glVertex3f(-0.45,0.9,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.25,0.6,0.05);
        glVertex3f(-0.25,0.6,0.05);
        glVertex3f(-0.25,0.6,0);
        glVertex3f(-0.25,0.6,0);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.45,0.9,0.05);
    glEnd();
    //bottom
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.35,0.6,0.05);
        glVertex3f(-0.35,0.6,0);
        glVertex3f(-0.3,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.35,0.6,0.05);
        glVertex3f(-0.35,0.6,0.05);
        glVertex3f(-0.35,0.6,0);
        glVertex3f(-0.35,0.6,0);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.3,0.5,0.05);
    glEnd();
    //top
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.5,0.8,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.5,0.8,0.05);
    glEnd();
    //front
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.25,0.6,0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.275,0.45,0.05);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.25,0.6,0.05);
        glVertex3f(-0.25,0.6,0.05);
        glVertex3f(-0.3,0.5,0.05);
    glEnd();
}

void house1() {
  glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
        //front
        glColor3f(0.3,0.15,0.1);
        glVertex3f(ax+0.0, ay+0.0, az+0);
        glVertex3f(ax+0.5, ay+0.0, az+0);
        glVertex3f(ax+0.5, ay+0.25, az+0);
        glVertex3f(ax+0.0, ay+0.25, az+0);
        //back
        glColor3f(0.3,0.15,0.1);
        glVertex3f(ax+0.0, ay+0.0, az-0.5);
        glVertex3f(ax+0.5, ay+0.0, az-0.5);
        glVertex3f(ax+0.5, ay+0.25, az-0.5);
        glVertex3f(ax+0.0, ay+0.25, az-0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.3,0.15,0.1);
        glVertex3f(ax+0.5, ay+0.25, az+0);
        glVertex3f(ax+0.25, ay+0.5, az+0);
        glVertex3f(ax+0.0, ay+0.25, az+0);
        glColor3f(0.3,0.15,0.1);
        glVertex3f(ax+0.5, ay+0.25, az-0.5);
        glVertex3f(ax+0.25, ay+0.5, az-0.5);
        glVertex3f(ax+0.0, ay+0.25, az-0.5);
    glEnd();
    glBegin(GL_QUADS);
        //left
        glColor3f(0.3,0.25,0.1);
        glVertex3f(ax+0.0, ay+0.0, az+0.0);
        glVertex3f(ax+0.0, ay+0.25, az+0.0);
        glVertex3f(ax+0.0, ay+0.25, az-0.5);
        glVertex3f(ax+0.0, ay+0.0, az-0.5);
        //right
        glColor3f(0.3,0.25,0.1);
        glVertex3f(ax+0.5, ay+0.0, az+0.0);
        glVertex3f(ax+0.5, ay+0.25, az+0.0);
        glVertex3f(ax+0.5, ay+0.25, az-0.5);
        glVertex3f(ax+0.5, ay+0.0, az-0.5);
        //roof front
        glColor3f(0,0.1,0);
        glVertex3f(ax+0.5, ay+0.25, az+0.0);
        glVertex3f(ax+0.5, ay+0.25, az-0.5);
        glVertex3f(ax+0.25, ay+0.5, az-0.5);
        glVertex3f(ax+0.25, ay+0.5, az+0.0);
        //roof back
        glColor3f(0,0.1,0);
        glVertex3f(ax+0.0, ay+0.25, az+0.0);
        glVertex3f(ax+0.25, ay+0.5, az+0.0);
        glVertex3f(ax+0.25, ay+0.5, az-0.5);
        glVertex3f(ax+0.0, ay+0.25, az-0.5);
        //bottom
        glColor3f(0,0,0);
        glVertex3f(ax+0.0, ay+0.0, az+0.0);
        glVertex3f(ax+0.5, ay+0.0, az+0.0);
        glVertex3f(ax+0.5, ay+0.0, az-0.5);
        glVertex3f(ax+0.0, ay+0.0, az-0.5);

    glEnd();
  glDisable(GL_DEPTH_TEST);
}

void house2() {
  glEnable(GL_DEPTH_TEST);
    GLfloat bx = 0.0, by = 0.0, bz = 0;
    glBegin(GL_QUADS);
        //front
        glColor3f(0.3,0.15,0.1);
        glVertex3f(bx+0.0, by+0.0, bz+0);
        glVertex3f(bx+0.5, by+0.0, bz+0);
        glVertex3f(bx+0.5, by+0.25, bz+0);
        glVertex3f(bx+0.0, by+0.25, bz+0);
        //back
        glColor3f(0.3,0.15,0.1);
        glVertex3f(bx+0.0, by+0.0, bz-0.5);
        glVertex3f(bx+0.5, by+0.0, bz-0.5);
        glVertex3f(bx+0.5, by+0.25, bz-0.5);
        glVertex3f(bx+0.0, by+0.25, bz-0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.3,0.15,0.1);
        glVertex3f(bx+0.5, by+0.25, bz+0);
        glVertex3f(bx+0.25, by+0.5, bz+0);
        glVertex3f(bx+0.0, by+0.25, bz+0);
        glColor3f(0.3,0.15,0.1);
        glVertex3f(bx+0.5, by+0.25, bz-0.5);
        glVertex3f(bx+0.25, by+0.5, bz-0.5);
        glVertex3f(bx+0.0, by+0.25, bz-0.5);
    glEnd();
    glBegin(GL_QUADS);
        //left
        glColor3f(0.3,0.25,0.1);
        glVertex3f(bx+0.0, by+0.0, bz+0.0);
        glVertex3f(bx+0.0, by+0.25, bz+0.0);
        glVertex3f(bx+0.0, by+0.25, bz-0.5);
        glVertex3f(bx+0.0, by+0.0, bz-0.5);

        //right-left
        glColor3f(0.3,0.25,0.1);
        glVertex3f(bx+0.5, by+0.0, bz+0.0);
        glVertex3f(bx+0.5, by+0.0, bz-0.15);
        glVertex3f(bx+0.5, by+0.20, bz-0.15);
        glVertex3f(bx+0.5, by+0.20, bz+0.0);
        //right-right
        glColor3f(0.3,0.25,0.1);
        glVertex3f(bx+0.5, by+0.0, bz-0.5);
        glVertex3f(bx+0.5, by+0.20, bz-0.5);
        glVertex3f(bx+0.5, by+0.20, bz-0.35);
        glVertex3f(bx+0.5, by+0.0, bz-0.35);
        //right-top
        glColor3f(0.3,0.25,0.1);
        glVertex3f(bx+0.5, by+0.20, bz+0.0);
        glVertex3f(bx+0.5, by+0.20, bz-0.5);
        glVertex3f(bx+0.5, by+0.25, bz-0.5);
        glVertex3f(bx+0.5, by+0.25, bz+0.0);

        //roof front
        glColor3f(0,0.1,0);
        glVertex3f(bx+0.5, by+0.25, bz+0.0);
        glVertex3f(bx+0.5, by+0.25, bz-0.5);
        glVertex3f(bx+0.25, by+0.5, bz-0.5);
        glVertex3f(bx+0.25, by+0.5, bz+0.0);
        //roof back
        glColor3f(0,0.1,0);
        glVertex3f(bx+0.0, by+0.25, bz+0.0);
        glVertex3f(bx+0.25, by+0.5, bz+0.0);
        glVertex3f(bx+0.25, by+0.5, bz-0.5);
        glVertex3f(bx+0.0, by+0.25, bz-0.5);
        //bottom
        glColor3f(0,0,0);
        glVertex3f(bx+0.0, by+0.0, bz+0.0);
        glVertex3f(bx+0.5, by+0.0, bz+0.0);
        glVertex3f(bx+0.5, by+0.0, bz-0.5);
        glVertex3f(bx+0.0, by+0.0, bz-0.5);
    glEnd();
    //Window
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.4);
        glVertex3f(bx+0.1, by+0.12, bz+0.01);
        glVertex3f(bx+0.4, by+0.12, bz+0.01);
        glVertex3f(bx+0.4, by+0.20, bz+0.01);
        glVertex3f(bx+0.1, by+0.20, bz+0.01);
    glEnd();
  glDisable(GL_DEPTH_TEST);
}

GLfloat lc = 0.25, rc = 0.25;
void doorOpen(int value) {
    if(lc > 0.16) {
      lc -= 0.001;
      rc += 0.001;
      glutPostRedisplay();
      glutTimerFunc(25, doorOpen, 0);
    }
}

void rightDoor() {
    GLfloat bx = 0.0, by = 0.0, bz = 0;
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.4);
        glVertex3f(bx+0.51, by+0.0, bz-0.15);
        glVertex3f(bx+0.51, by+0.0, bz-lc);
        glVertex3f(bx+0.51, by+0.2, bz-lc);
        glVertex3f(bx+0.51, by+0.2, bz-0.15);
    glEnd();
}

void leftDoor() {
    GLfloat bx = 0.0, by = 0.0, bz = 0;
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.4);
        glVertex3f(bx+0.51, by+0.0, bz-rc);
        glVertex3f(bx+0.51, by+0.0, bz-0.35);
        glVertex3f(bx+0.51, by+0.2, bz-0.35);
        glVertex3f(bx+0.51, by+0.2, bz-rc);
    glEnd();
}

void powerHouse() {
  glEnable(GL_DEPTH_TEST);
    GLfloat bx = 0.0, by = 0.0, bz = 0;
    glBegin(GL_QUADS);
        //front
        glColor3f(1.0,0.25,0.1);
        glVertex3f(bx+0.0, by+0.0, bz+0);
        glVertex3f(bx+0.3, by+0.0, bz+0);
        glVertex3f(bx+0.3, by+0.2, bz+0);
        glVertex3f(bx+0.0, by+0.2, bz+0);
        //back
        glColor3f(1.0,0.25,0.1);
        glVertex3f(bx+0.0, by+0.0, bz-0.3);
        glVertex3f(bx+0.3, by+0.0, bz-0.3);
        glVertex3f(bx+0.3, by+0.2, bz-0.3);
        glVertex3f(bx+0.0, by+0.2, bz-0.3);
        //left
        glColor3f(1.0,0.25,0.1);
        glVertex3f(bx+0.0, by+0.0, bz+0);
        glVertex3f(bx+0.0, by+0.2, bz+0);
        glVertex3f(bx+0.0, by+0.2, bz-0.3);
        glVertex3f(bx+0.0, by+0.0, bz-0.3);
        //right
        glColor3f(1.0,0.25,0.1);
        glVertex3f(bx+0.3, by+0.0, bz+0);
        glVertex3f(bx+0.3, by+0.2, bz+0);
        glVertex3f(bx+0.3, by+0.2, bz-0.3);
        glVertex3f(bx+0.3, by+0.0, bz-0.3);
        //bottom
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(bx+0.0, by+0.0, bz+0);
        glVertex3f(bx+0.3, by+0.0, bz+0);
        glVertex3f(bx+0.3, by+0.0, bz-0.3);
        glVertex3f(bx+0.0, by+0.0, bz-0.3);
    glEnd();
    /// roof
    glBegin(GL_TRIANGLES);
        //front
        glColor3f(0.7, 0.5, 0.3);
        glVertex3f(bx-0.10, by+0.2, bz+0.0);
        glVertex3f(bx+0.15, by+0.35, bz-0.15);
        glVertex3f(bx+0.40, by+0.2, bz+0.0);
        //back
        glColor3f(0.7, 0.5, 0.3);
        glVertex3f(bx-0.10, by+0.2, bz-0.3);
        glVertex3f(bx+0.15, by+0.35, bz-0.15);
        glVertex3f(bx+0.40, by+0.2, bz-0.3);
        //left
        glColor3f(0.7, 0.5, 0.3);
        glVertex3f(bx-0.10, by+0.2, bz+0.0);
        glVertex3f(bx+0.15, by+0.35, bz-0.15);
        glVertex3f(bx-0.10, by+0.2, bz-0.3);
        //right
        glColor3f(0.7, 0.5, 0.3);
        glVertex3f(bx+0.40, by+0.2, bz+0.0);
        glVertex3f(bx+0.15, by+0.35, bz-0.15);
        glVertex3f(bx+0.40, by+0.2, bz-0.3);
    glEnd();
  glDisable(GL_DEPTH_TEST);
}

void powerHouseDoor() {
  glEnable(GL_DEPTH_TEST);
    GLfloat bx = 0.0, by = 0.0, bz = 0;
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.4);
        glVertex3f(bx+0.09, by+0.0, bz+0.01);
        glVertex3f(bx+0.24, by+0.0, bz+0.01);
        glVertex3f(bx+0.24, by+0.12, bz+0.01);
        glVertex3f(bx+0.09, by+0.12, bz+0.01);
    glEnd();
  glDisable(GL_DEPTH_TEST);
}

GLfloat cx = 0.1, cy = 0.0, cz = 0.0;
int ct = 0;
void updateTrafficColor(int value) {
  if(ct <= 2) {
    if(ct == 0) cx = 1.0;
    else if(ct == 1) {
      cx = 1.0; cy = 1.0;
    }
    else {
      cx = 0.0; cy = 1.0;
    }
    ++ct;
    glutTimerFunc(2000, updateTrafficColor, 0);
    glutPostRedisplay();
  }
}

void trafficLight(){
    glBegin(GL_QUADS);
        glColor3f(0.4,0.4,0.4);
        //back
        glVertex3f(-0.3,-0.3,1.45);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.3,0,1.45);
        //left
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.3,-0.3,1.45);
        glVertex3f(-0.3,0,1.45);
        glVertex3f(-0.3,0,1.5);
        //right
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.25,0,1.5);
        //bottom
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.3,-0.3,1.45);
        //top
        glVertex3f(-0.3,0,1.5);
        glVertex3f(-0.25,0,1.5);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.3,0,1.45);
        //front
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,0,1.5);
        glVertex3f(-0.3,0,1.5);
    glEnd();
    glColor3f(cx, cy, cz);
    glPushMatrix();
        glTranslatef(-0.25, -0.05, 1.43);
        glutSolidSphere(0.035,36,2);
    glPopMatrix();
}

void spin(int value) {
    a1 = a1 - 5;
    if(a1 < -360) {
        a1 = a1 + 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, spin, 0);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /// All Backgrounds
  glPushMatrix();
    glTranslatef(0,0.6,0);
    glScalef(3,2.5,2.5);
    background();
  glPopMatrix();

  /// Mountains
  glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    mountain();  //1st mountain
  glPopMatrix();
  glPushMatrix();
    glScalef(0.5,0.7,0.5);
    glTranslatef(1.2,-0.11,0);
    glColor3f(0.5,0.6,0.1);
    mountain(); //2nd mountain
  glPopMatrix();
  glPushMatrix();
    glScalef(1.2,1.2,1.2);
    glTranslatef(1.8,0,0);
    glColor3f(0.2,0.3,0.1);
    mountain(); //3rd mountain
  glPopMatrix();

  /// Clouds
  glPushMatrix();
    glScalef(1.5,1,1);
    glTranslatef(-0.7,-0.9,0);
    cloud();
  glPopMatrix();

  /// Right Windmill
  glPushMatrix();
    glTranslatef(0.3,0,0);
    tiang();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.3,0,0);
    glTranslatef(-0.275,0.45,0.2);
    glRotatef((GLfloat)a1,0,0,1);
    glTranslatef(0.275,-0.45,-0.2);
    fan();
  glPopMatrix();
  /// Left Windmill
  glPushMatrix();
    glTranslatef(-0.5,0,0);
    tiang();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(-0.5,0,0);
    glTranslatef(-0.275,0.45,0.2);
    glRotatef((GLfloat)a,0,0,1);
    glTranslatef(0.275,-0.45,-0.2);
    fan();
  glPopMatrix();

  /// Houses
  glPushMatrix();
    glTranslatef(-1.5,-0.7,0.0);
    glRotatef(rx,1,0,0);
    glRotatef(ry,0,1,0);
    glRotatef(rz,0,0,1);
    glTranslatef(ax, ay, az);
    glScalef(sx, sy, sz);
    house1();
  glPopMatrix();
  glPushMatrix();
    glScalef(1.2,0.7,0.7);
    glTranslatef(-0.2,-0.7,0);
    glRotatef(-60,0,1,0);
    house2();
  glPopMatrix();

  /// Door Animation
  glPushMatrix();
    glScalef(1.2,0.7,0.7);
    glTranslatef(-0.2,-0.7,0);
    glRotatef(-60,0,1,0);
    leftDoor();
  glPopMatrix();
  glPushMatrix();
    glScalef(1.2,0.7,0.7);
    glTranslatef(-0.2,-0.7,0);
    glRotatef(-60,0,1,0);
    rightDoor();
  glPopMatrix();

  /// Power House
  glPushMatrix();
    glTranslatef(0.9,-0.33,0);
    glRotatef(-10,0,1,0);
    glRotatef(7,1,0,0);
    powerHouse();
  glPopMatrix();

  /// Power House Door
  glPushMatrix();
    glTranslatef(0.9,-0.33,0);
    glRotatef(-10,0,1,0);
    glRotatef(7,1,0,0);
    powerHouseDoor();
  glPopMatrix();

  /// Traffic Light
  glPushMatrix();
    glTranslatef(0.85, -0.22, -0.5);
    glScalef(1,0.8,1);
    trafficLight();
  glPopMatrix();

  /// Ball Movement
  glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(1.7 + tx, -0.95 + ty, 0 + tz);
    glutSolidSphere(0.10,20,20);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);
  glFlush();
}

void init() {
  glClearColor (0.4, 0.85, 1.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 5/2.3, 1, 20);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(1000, 600);
  glutCreateWindow("City");
  init();
  glutDisplayFunc(display);
  glutPostRedisplay();
  glutSpecialFunc(PressKey);
  glutKeyboardFunc (NormalKeyHandler);
  glutTimerFunc(25, spin, 0);
  glutTimerFunc(1000, doorOpen, 0);
  glutTimerFunc(9100, ballMove, 0);
  glutTimerFunc(5000, updateTrafficColor, 0);
  glutMainLoop();
}
