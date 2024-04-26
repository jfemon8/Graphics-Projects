#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

static int a = 0, a1 = 0;
double x = 0, Sx = 0, Sy = 0, Sz = 0, tx = 0, ty = 0, tz = 0, winx = 0, cha = 0;
// double posx = -1.0, posy = 1, posz = 6, eyex = -0.5, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;
double posx = -1.5, posy = 1, posz = 4, eyex = -0.5, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;
static void idle(void)
{
    glutPostRedisplay();
}

void ballMoveUp(void)
{
    Sx = Sx + 0.3;
    Sy = Sy + 0.3;
    Sz = Sz + 0.3;

    // if(Sx > 9 || Sy > 9 || Sz > 9)
    // {
    //     Sx = Sx - 9;
    //     Sy = Sy - 9;
    //     Sz = Sz - 9;
    // }

    tx = tx + 0.1;
    ty = ty + 0.1;
    tz = tz - 0.1;

    if(tx >= 4 || ty >= 4 || tz <= -4)
    {
        tx = 0;
        ty = 0;
        tz = 0;
        Sx = 0;
        Sy = 0;
        Sz = 0;
    }

    glutPostRedisplay();
}

void ballMoveDown(void)
{
    Sx = Sx - 0.5;
    Sy = Sy - 0.5;
    Sz = Sz - 0.5;

    if(Sx <= 0.5 || Sy <= 0.5 || Sz <= 0.5)
    {
        Sx = 0;
        Sy = 0;
        Sz = 0;
    }

    tx = tx - 0.1;
    ty = ty - 0.1;
    tz = tz + 0.1;

    if(tx < 0 || ty < 0 || tz > 0)
    {
        tx = tx + 4;
        ty = ty + 4;
        tz = tz - 4;
        Sx = 10;
        Sy = 10;
        Sz = 10;
    }



    glutPostRedisplay();
}


void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: x = (x - 0.1);
                        if(x<-1)
                        {
                            x = 3.5;
                        }
                        break;
    case GLUT_KEY_RIGHT: x = (x + 0.1);
                        if(x>3.5)
                        {
                            x = x-3.5;
                        }
                        break;
    case GLUT_KEY_F1: a -= 5; a %= 360; break;
    case GLUT_KEY_F2: ballMoveDown(); break;
    case GLUT_KEY_F3: ballMoveUp(); break;
    case GLUT_KEY_F4: posx += 0.5; break;
    case GLUT_KEY_F5: posx -= 0.5; break;
    case GLUT_KEY_F6: posy += 0.5; break;
    case GLUT_KEY_F7: posy -= 0.5; break;
    case GLUT_KEY_F8: posz += 0.5; break;
    case GLUT_KEY_F9: posz -= 0.5; break;
    case GLUT_KEY_PAGE_UP: if(winx > 0.6){
                                winx = 0;
                            }
                            else
                            {
                                winx += 0.1;
                            }
                            break;
    case GLUT_KEY_PAGE_DOWN: if(cha > 0.3){
                                cha = 0;
                            }
                            else
                            {
                                cha += 0.1;
                            }
                            break;
    case GLUT_KEY_END: exit(0); break;
    default: return;
  }
  glutPostRedisplay();
}

void spin(int value)
{
    a1 = a1 - 5;
    if(a1 < -360)
    {
        a1 = a1 + 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, spin, 0);
}

void fan()
{
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


void tiang()
{
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

void tree()
{
    glBegin(GL_QUADS);
        glColor3f(0.3,0.2,0.14);
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

    //leave
    glColor3f (0.4, 1, 0.2);
    glPushMatrix();
        glTranslatef(-0.3, -0.05, 1.4);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.2, 0.05, 1.4);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.4, -0.03, 1.4);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.35, 0.1, 1.4);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();

}

void stand(){
    glBegin(GL_QUADS);
        glColor3f(0,0,0);
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

    // glColor3f(1.0, 1.0, 0);
    // glPushMatrix();
    //     glTranslatef(-0.28, 0.02, 1.43);
    //     glutSolidSphere(0.08,36,2);
    // glPopMatrix();
}

void fanStand(){
    glPushMatrix();
    glColor3f (0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
        glVertex3f (-1.2, 0, -0.5);
        glVertex3f (0.5, 0, -0.5);
        glVertex3f (0.5, 0, 0);
        glVertex3f (-1.2, 0, 0);
    glEnd();

    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(-1.2, 0, -0.5);
        glVertex3f(0.5, 0, -0.5);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(0.5, 0, 0);
        glVertex3f(0.5, 0, -0.5);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f (0.5, 0, 0);
        glVertex3f (-1.2, 0, 0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f (-1.2, 0, -0.5);;
        glVertex3f (-1.2, 0, 0);
    glEnd();
    glPopMatrix();
}

void table(){
    glPushMatrix();
    glColor3f (0.75, 0.35, 0.05);
    glBegin(GL_QUADS);
        glVertex3f (-1.2, 0, -0.5);
        glVertex3f (0.5, 0, -0.5);
        glVertex3f (0.5, 0, 0);
        glVertex3f (-1.2, 0, 0);
    glEnd();

    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(-1.2, 0, -0.5);
        glVertex3f(0.5, 0, -0.5);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(0.5, 0, 0);
        glVertex3f(0.5, 0, -0.5);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f (0.5, 0, 0);
        glVertex3f (-1.2, 0, 0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f (-1.2, 0, -0.5);;
        glVertex3f (-1.2, 0, 0);
    glEnd();
    glPopMatrix();
}

void background(){
    //field
    // glTranslatef(-0.5, -0.4, 0);
    // glScalef(0.5,0.5,0.5);
    // glRotatef(10, 1, 1, 0);

    glPushMatrix();
    //front floor
    glColor3f (0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0.1, 2);
        glVertex3f (0, 0.1, 2);
    glEnd();


    //bottom floor
    glColor3f (0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    //up floor
    glColor3f (0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0.1, 2);
        glVertex3f (1.6, 0.1, 2);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //left floor
    glColor3f (0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, 2);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //right floor
    glColor3f (0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (1.6, 0.1, 2);
    glEnd();

    //back floor
    glColor3f (0.2, 0.2, 0.2);
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
        glVertex3f(1.6, 0, 2);
    glEnd();
    //2
    glColor3f (0, 0, 0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 2);
        glVertex3f(1.6, 0.1, 2);
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
    //8
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(1.6, 0, 0);
    glEnd();
    //9
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(1.6, 0, 2);
        glVertex3f(1.6, 0, 0);
    glEnd();
    //10
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(1.6, 0.1, 2);
        glVertex3f(1.6, 0.1, 0);
    glEnd();
    //11
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    //left wall
    glRotatef(90, 0, 0, 1);
    //front
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0.1, 2);
        glVertex3f (0, 0.1, 2);
    glEnd();


    //bottom
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    //up
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0.1, 2);
        glVertex3f (1.6, 0.1, 2);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //left
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, 2);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //right
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (1.6, 0.1, 2);
    glEnd();

    //back
    glColor3f (0.5, 1.0, 0.5);
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
        glVertex3f(1.6, 0, 2);
    glEnd();
    //2
    glColor3f (0, 0, 0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 2);
        glVertex3f(1.6, 0.1, 2);
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
    //8
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(1.6, 0, 0);
    glEnd();
    //9
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(1.6, 0, 2);
        glVertex3f(1.6, 0, 0);
    glEnd();
    //10
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(1.6, 0.1, 2);
        glVertex3f(1.6, 0.1, 0);
    glEnd();
    //11
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
    glEnd();

    glPopMatrix();

    glPushMatrix();

    // right wall

    glTranslatef(1.6, 0, 0);
    glRotatef(90, 0, 0, 1);
    //front floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0.1, 2);
        glVertex3f (0, 0.1, 2);
    glEnd();


    //bottom floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    //up floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0.1, 2);
        glVertex3f (1.6, 0.1, 2);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //left floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, 2);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //right floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (1.6, 0, 2);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
        glVertex3f (1.6, 0.1, 2);
    glEnd();

    //back floor
    glColor3f (0.5, 1.0, 0.5);
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
        glVertex3f(1.6, 0, 2);
    glEnd();
    //2
    glColor3f (0, 0, 0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 2);
        glVertex3f(1.6, 0.1, 2);
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
    //8
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(1.6, 0, 0);
    glEnd();
    //9
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(1.6, 0, 2);
        glVertex3f(1.6, 0, 0);
    glEnd();
    //10
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(1.6, 0.1, 2);
        glVertex3f(1.6, 0.1, 0);
    glEnd();
    //11
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
    glEnd();

    glPopMatrix();

    glPushMatrix();



    glPushMatrix();

    //back lower wall

    glScalef(1, 0.8, 1);
    glRotatef(-90, 1, 0, 0);
    //front floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 0.5);
        glVertex3f (1.1, 0, 0.5);
        glVertex3f (1.1, 0.1, 0.5);
        glVertex3f (0.5, 0.1, 0.5);
    glEnd();


    //bottom floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 0.5);
        glVertex3f (1.1, 0, 0.5);
        glVertex3f (1.1, 0, 0);
        glVertex3f (0.5, 0, 0);
    glEnd();

    //up floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0.1, 0.5);
        glVertex3f (1.1, 0.1, 0.5);
        glVertex3f (1.1, 0.1, 0);
        glVertex3f (0.5, 0.1, 0);
    glEnd();

    //left floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 0);
        glVertex3f (0.5, 0, 0.5);
        glVertex3f (0.5, 0.1, 0.5);
        glVertex3f (0.5, 0.1, 0);
    glEnd();

    //right floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (1.1, 0, 0.5);
        glVertex3f (1.1, 0, 0);
        glVertex3f (1.1, 0.1, 0);
        glVertex3f (1.1, 0.1, 0.5);
    glEnd();

    //back floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (1.1, 0, 0);
        glVertex3f (1.1, 0.1, 0);
        glVertex3f (0.5, 0.1, 0);
        glVertex3f (0.5, 0, 0);
    glEnd();

    glPopMatrix();

    glPushMatrix();

    //back upper wall

    glScalef(1, 0.8, 1);
    glTranslatef(0, 1.5, 0);
    glRotatef(-90, 1, 0, 0);
    //front floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 0.5);
        glVertex3f (1.1, 0, 0.5);
        glVertex3f (1.1, 0.1, 0.5);
        glVertex3f (0.5, 0.1, 0.5);
    glEnd();


    //bottom floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 0.5);
        glVertex3f (1.1, 0, 0.5);
        glVertex3f (1.1, 0, 0);
        glVertex3f (0.5, 0, 0);
    glEnd();

    //up floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0.1, 0.5);
        glVertex3f (1.1, 0.1, 0.5);
        glVertex3f (1.1, 0.1, 0);
        glVertex3f (0.5, 0.1, 0);
    glEnd();

    //left floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 0);
        glVertex3f (0.5, 0, 0.5);
        glVertex3f (0.5, 0.1, 0.5);
        glVertex3f (0.5, 0.1, 0);
    glEnd();

    //right floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (1.1, 0, 0.5);
        glVertex3f (1.1, 0, 0);
        glVertex3f (1.1, 0.1, 0);
        glVertex3f (1.1, 0.1, 0.5);
    glEnd();

    //back floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (1.1, 0, 0);
        glVertex3f (1.1, 0.1, 0);
        glVertex3f (0.5, 0.1, 0);
        glVertex3f (0.5, 0, 0);
    glEnd();

    glPopMatrix();

    //back left wall

    glScalef(1, 0.8, 1);
    glRotatef(-90, 1, 0, 0);
    //front floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (0.5, 0, 2);
        glVertex3f (0.5, 0.1, 2);
        glVertex3f (0, 0.1, 2);
    glEnd();


    //bottom floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (0.5, 0, 2);
        glVertex3f (0.5, 0, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    //up floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0.5, 0.1, 2);
        glVertex3f (0.5, 0.1, 0);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //left floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, 2);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //right floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 2);
        glVertex3f (0.5, 0, 0);
        glVertex3f (0.5, 0.1, 0);
        glVertex3f (0.5, 0.1, 2);
    glEnd();

    //back floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 0);
        glVertex3f (0.5, 0.1, 0);
        glVertex3f (0, 0.1, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    // //1
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(0, 0, 2);
    //     glVertex3f(1.6, 0, 2);
    // glEnd();
    // //2
    // glColor3f (0, 0, 0);
    // glLineWidth(2.0);
    // glBegin(GL_LINES);
    //     glVertex3f(0, 0.1, 2);
    //     glVertex3f(1.6, 0.1, 2);
    // glEnd();
    // //3
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(0, 0, 2);
    //     glVertex3f(0, 0.1, 2);
    // glEnd();
    // //4
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(0, 0.1, 2);
    //     glVertex3f(0, 0.1, 0);
    // glEnd();
    // //5
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(0, 0, 2);
    //     glVertex3f(0, 0, 0);
    // glEnd();
    // //6
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(0, 0.1, 0);
    //     glVertex3f(0, 0, 0);
    // glEnd();
    // //7
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(0, 0.1, 0);
    //     glVertex3f(1.6, 0.1, 0);
    // glEnd();
    // //8
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(0, 0, 0);
    //     glVertex3f(1.6, 0, 0);
    // glEnd();
    // //9
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(1.6, 0, 2);
    //     glVertex3f(1.6, 0, 0);
    // glEnd();
    // //10
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f(1.6, 0.1, 2);
    //     glVertex3f(1.6, 0.1, 0);
    // glEnd();
    // //11
    // glColor3f (0, 0, 0);
    // glBegin(GL_LINES);
    //     glVertex3f (1.6, 0, 0);
    //     glVertex3f (1.6, 0.1, 0);
    // glEnd();

    glPopMatrix();

    glPushMatrix();

    //back right wall

    glScalef(1, 0.8, 1);
    glTranslatef(1.0, 0, 0);
    glRotatef(-90, 1, 0, 0);
    //front floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (0.5, 0, 2);
        glVertex3f (0.5, 0.1, 2);
        glVertex3f (0, 0.1, 2);
    glEnd();


    //bottom floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (0.5, 0, 2);
        glVertex3f (0.5, 0, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    //up floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0.5, 0.1, 2);
        glVertex3f (0.5, 0.1, 0);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //left floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, 2);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //right floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 2);
        glVertex3f (0.5, 0, 0);
        glVertex3f (0.5, 0.1, 0);
        glVertex3f (0.5, 0.1, 2);
    glEnd();

    //back floor
    glColor3f (0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 0);
        glVertex3f (0.5, 0.1, 0);
        glVertex3f (0, 0.1, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    glTranslatef(-1.0, 0, 0);
    //1
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 2);
        glVertex3f(1.6, 0, 2);
    glEnd();
    //2
    glColor3f (0, 0, 0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 2);
        glVertex3f(1.6, 0.1, 2);
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
    //8
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(1.6, 0, 0);
    glEnd();
    //9
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(1.6, 0, 2);
        glVertex3f(1.6, 0, 0);
    glEnd();
    //10
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(1.6, 0.1, 2);
        glVertex3f(1.6, 0.1, 0);
    glEnd();
    //11
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f (1.6, 0, 0);
        glVertex3f (1.6, 0.1, 0);
    glEnd();

    glPopMatrix();

    //Road
    // glColor3f (0, 0, 0);
    // glBegin(GL_QUADS);
    //     //front
    //     glVertex3f (1.1, 0, 2);
    //     glVertex3f (2, 0, 2);
    //     glVertex3f (2, 0.1, 2);
    //     glVertex3f (1.1, 0.1, 2);
    //     //bottom
    //     glVertex3f (1.1, 0, 2);
    //     glVertex3f (2, 0, 2);
    //     glVertex3f (2, 0, 0);
    //     glVertex3f (1.6, 0, 0);
    //     //back
    //     glVertex3f (2, 0, 0);
    //     glVertex3f (1.6, 0, 0);
    //     glVertex3f (1.6, 0.1, 0);
    //     glVertex3f (2, 0.1, 0);
    //     //up
    //     glVertex3f (1.6, 0.1, 0);
    //     glVertex3f (2, 0.1, 0);
    //     glVertex3f (2, 0.1, 2);
    //     glVertex3f (1.1, 0.1, 2);
    //     //left
    //     glVertex3f (1.1, 0, 2);
    //     glVertex3f (1.6, 0, 0);
    //     glVertex3f (1.6, 0.1, 0);
    //     glVertex3f (1.1, 0.1, 2);
    //     //right
    //     glVertex3f (2, 0, 2);
    //     glVertex3f (2, 0, 0);
    //     glVertex3f (2, 0.1, 0);
    //     glVertex3f (2, 0.1, 2);
    // glEnd();
}

// void mountain()
// {
//     glBegin(GL_TRIANGLES);
//         //front
//         glVertex3f(-2,-0.28,0);
//         glVertex3f(-1, 0.3,-0.5);
//         glVertex3f(0.5,-0.28,0);
//         //right
//         glVertex3f(0.5, -0.28, 0);
//         glVertex3f(-1, 0.3,-0.5);
//         glVertex3f(0.5, -0.28,-1);
//         //back
//         glVertex3f(0.5, -0.28,-1);
//         glVertex3f(-1, 0.3,-0.5);
//         glVertex3f(-2, -0.28,-1);
//         //left
//         glVertex3f(-2, -0.28,-1);
//         glVertex3f(-1, 0.3,-0.5);
//         glVertex3f(-2, -0.28,0);
//         //bottom
//         glVertex3f(-2, -0.28,0);
//         glVertex3f(0.5, -0.28,0);
//         glVertex3f(0.5, -0.28,-1);
//         glVertex3f(-2, -0.28,-1);
//     glEnd();

//     glColor3f (1, 1, 1);
//     glBegin(GL_LINES);
//         //1
//         glVertex3f(-2, -0.28, 0);
//         glVertex3f(-1, 0.3,-0.5);
//     glEnd();
//     glBegin(GL_LINES);
//         //2
//         glVertex3f(0.5, -0.28, 0);
//         glVertex3f(-1, 0.3,-0.5);
//     glEnd();
//     glBegin(GL_LINES);
//         //3
//         glVertex3f(0.5, -0.28, -1);
//         glVertex3f(-1, 0.3,-0.5);
//     glEnd();
//     glBegin(GL_LINES);
//         //4
//         glVertex3f(0.5, -0.28, 0);
//         glVertex3f(0.5, -0.28,-1);
//     glEnd();
//     glBegin(GL_LINES);
//         //5
//         glVertex3f(-2, -0.28, -1);
//         glVertex3f(-1, 0.3,-0.5);
//     glEnd();
// }

void window() {
    glPushMatrix();
    glColor3f (0.5, 0.35, 0.05);
    glBegin(GL_QUADS);
        glVertex3f (0.5, 0, 1.25);
        glVertex3f (1.1, 0, 1.25);
        glVertex3f (1.1, 0, 0);
        glVertex3f (0.5, 0, 0);
    glEnd();

    glColor3f (0, 0, 0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex3f (0.5, 0, 1.25);
        glVertex3f (1.1, 0, 1.25);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f (1.1, 0, 0);
        glVertex3f (0.5, 0, 0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f (1.1, 0, 1.25);
        glVertex3f (1.1, 0, 0);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f (0.5, 0, 1.25);
        glVertex3f (0.5, 0, 0);
    glEnd();
    glPopMatrix();
}

void display() {



  glClear(GL_COLOR_BUFFER_BIT);

    //3rd mountain
//   glPushMatrix();
//     glScalef(1.2,1.2,1.2);
//     glTranslatef(1.8,0,0);
//     glColor3f(0.2,0.3,0.1);
//     mountain();
//   glPopMatrix();

// //   1st mountain
//   glPushMatrix();
//     glColor3f(0.419,0.556,0.137);
//     mountain();
//   glPopMatrix();

//     //2nd mountain
//   glPushMatrix();
//     glScalef(0.5,0.7,0.5);
//     glTranslatef(1.2,-0.11,0);
//     glColor3f(0.5,0.6,0.1);
//     mountain();
//   glPopMatrix();

    //cloud
  glPushMatrix();
    glScalef(1.5,1,1);
    glTranslatef(-2.5 + x, -1.3, -1.5);
    cloud();
  glPopMatrix();

  // sun
  glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(1.1 + tx, -0.3 + ty, 0 + tz);
    glScalef(1 + Sx, 1 + Sy, 1 + Sz);
    glutSolidSphere(0.05,20,20);
  glPopMatrix();

    //floor
  glPushMatrix();
    glTranslatef(0,0.6,0);
    glScalef(6,2.5,2.5);
    glTranslatef(-0.5, -0.4, 0);
    glScalef(0.5,0.5,0.5);
    // glRotatef(10, 1, 1, 0);
    background();
  glPopMatrix();

    //left window
  glPushMatrix();
    glTranslatef(-2.12-winx,0,0);
    glScalef(1.25,1,1);
    // glTranslatef(-0.5, -0.4, 0);
    // glScalef(0.5,0.5,0.5);
    glRotatef(-90, 1, 0, 0);
    window();
  glPopMatrix();

  //right window
  glPushMatrix();
    glTranslatef(-1.37+winx,0,0);
    glScalef(1.25,1,1);
    // glTranslatef(-0.5, -0.4, 0);
    // glScalef(0.5,0.5,0.5);
    glRotatef(-90, 1, 0, 0);
    window();
  glPopMatrix();

  //right fan stand
  glPushMatrix();
    glTranslatef(-2.25, -0.3, 0.6);
    glScalef(0.2,1,0.5);
    fanStand();
  glPopMatrix();

  //right fan
  glPushMatrix();
    glTranslatef(1.2,0,0.5);
    //glRotatef(10,0,-1,0);
    tiang();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.9,0.45,0.5);
    glutSolidSphere(0.4,36,2);
  glPopMatrix();


  glPushMatrix();
    glTranslatef(1.2,0,0.5);
   // glRotatef(10,0,-1,0);
    glTranslatef(-0.275,0.45,0.2);
    glRotatef((GLfloat)a1,0,0,1);
    glTranslatef(0.175,-0.35,-0.2);
    glScalef(0.7,0.7,0.7);
    fan();
  glPopMatrix();

  //left fan stand
  glPushMatrix();
    glScalef(0.2,1,0.5);
    glTranslatef(5, -0.3, 1.5);
    fanStand();
  glPopMatrix();

  //left fan
  glPushMatrix();
    glTranslatef(-2.05,0,0.5);
    tiang();
  glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.35,0.45,0.5);
    glutSolidSphere(0.4,36,2);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-2.05,0,0.5);
    glTranslatef(-0.275,0.45,0.2);
    glRotatef((GLfloat)a,0,0,1);
    glTranslatef(0.175,-0.35,-0.2);
    glScalef(0.7,0.7,0.7);
    fan();
  glPopMatrix();

  //tree
//   glPushMatrix();
//     glTranslatef(-0.25,0,-0.5);
//     tree();
//   glPopMatrix();
//   glPushMatrix();
//     glTranslatef(0,0,0.5);
//     tree();
//   glPopMatrix();
//   glPushMatrix();
//     glTranslatef(0.3,0,0.2);
//     tree();
//   glPopMatrix();
//   glPushMatrix();
//     glTranslatef(-0.5,0,0.2);
//     tree();
//   glPopMatrix();

    //chair a stands

    glPushMatrix();
        glTranslatef(-0.5, 0, 0.5+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0, 0.5+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5, 0, 0.3+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0, 0.3+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0, -0.2, 0);
        stand();
    glPopMatrix();

    //chair a
  glPushMatrix();
    glTranslatef(-0.555, -0.1, 2+cha);
    glScalef(0.2, 0.2, 0.5);
    table();
  glPopMatrix();

  //chair a height
  glPushMatrix();
    glTranslatef(-0.555, -0.1, 2+cha);
    glScalef(0.2, 0.5, 0.5);
    glRotatef(90, 1, 0, 0);
    table();
  glPopMatrix();

  //chair b stands

    glPushMatrix();
        glTranslatef(-0.5, 0, -1-cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0, -1-cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5, 0, -0.8-cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0, -0.8-cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0, -0.2, 0);
        stand();
    glPopMatrix();

    //chair b
  glPushMatrix();
    glTranslatef(-0.555, -0.1, 0.7-cha);
    glScalef(0.2, 0.2, 0.5);
    table();
  glPopMatrix();

  //chair b height
  glPushMatrix();
    glTranslatef(-0.555, -0.1, 0.45-cha);
    glScalef(0.2, 0.5, 0.5);
    glRotatef(90, 1, 0, 0);
    table();
  glPopMatrix();

  //chair c stands
    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-1.5, 0, 0.5+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(2.75, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-1.2, 0, 0.5+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(2.75, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-1.5, 0, 0.3+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(2.75, -0.2, 0);
        stand();
    glPopMatrix();

    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-1.2, 0, 0.3+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(2.75, -0.2, 0);
        stand();
    glPopMatrix();

    //chair c
  glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glTranslatef(1.2, -0.1, 2+cha);
    glScalef(0.2, 0.2, 0.5);
    table();
  glPopMatrix();

  //chair c height
  glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glTranslatef(1.2, -0.1, 2+cha);
    glScalef(0.2, 0.5, 0.5);
    glRotatef(90, 1, 0, 0);
    table();
  glPopMatrix();

  //chair d stands
    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glTranslatef(-1.5, 0, 0.5+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0.35, -0.2, -1.3);
        stand();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glTranslatef(-1.2, 0, 0.5+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0.35, -0.2, -1.3);
        stand();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glTranslatef(-1.5, 0, 0.3+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0.35, -0.2, -1.3);
        stand();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glTranslatef(-1.2, 0, 0.3+cha);
        glScalef(1, 0.5, 1);
        glTranslatef(0.35, -0.2, -1.3);
        stand();
    glPopMatrix();

    //chair d
  glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(-1.2, -0.1, 0.7+cha);
    glScalef(0.2, 0.2, 0.5);
    table();
  glPopMatrix();

  //chair d height
  glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(-1.2, -0.1, 0.7+cha);
    glScalef(0.2, 0.5, 0.5);
    glRotatef(90, 1, 0, 0);
    table();
  glPopMatrix();

    //table stands
  glPushMatrix();
    glTranslatef(-1.2, 0, -0.5);
    stand();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.5, 0, -0.5);
    stand();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-1.2, 0, 0);
    stand();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.5, 0, 0);
    stand();
  glPopMatrix();

    //table
  glPushMatrix();
    glTranslatef(-0.25, 0, 1.7);
    glScalef(1.1, 1, 2);
    table();
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);

  glFlush();
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void init() {

    // Set the current clear color to black and the current drawing color to
  // white.
  glClearColor (0.4, 0.85, 1.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);

  // Set the camera lens to have a 60 degree (vertical) field of view, an
  // aspect ratio of 4/3, and have everything closer than 1 unit to the
  // camera and greater than 40 units distant clipped away.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 16.0/9.0, 1, 40);

  // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
  // <0, 1, 0> pointing upward.


}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1350, 700);
    glutCreateWindow("Room");

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutSpecialFunc(special);
    glutTimerFunc(0, spin, 0);

    init();

    /*
    printf("Left arrow - Move clouds left\n");
	printf("Right arrow - Move clouds right\n");
	// printf("Up arrow - Translation along positive y axis\n");
	// printf("Down arrow - Translation along negative y axis\n");
	printf("Page up - Toggle windows\n");
	printf("Page down - Toggle chairs\n");
	printf("F1 - Toggle left fan\n");
	printf("F2 - Move the sun down\n");
	printf("F3 - Move the sun up\n");
	printf("F4 - Move camera right\n");
	printf("F5 - Move camera left\n");
	printf("F6 - Move camera up\n");
	printf("F7 - Move camera down\n");
	printf("F8 - Move camera behind\n");
	printf("F9 - Move camera front\n");
	// printf("F10 - Scaling 0.5 times along y axis\n");
	// printf("F11 - Scaling 2 times along z axis\n");
	// printf("F12 - Scaling 0.5 times along z axis\n");
	printf("End - Exit\n");
	*/

    glutMainLoop();

    return 0;
}
// gcc project.c -o project -lglut -lGL -lGLU && ./project
