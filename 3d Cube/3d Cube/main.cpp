/*-----------------------------
----------INCLUDES-------------
-------------------------------
*/

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <glut.h>
#else
#include <glut.h>
#endif

/*
* CLASS CUBE
*/
class cube
{
private:
    int res = GL_POLYGON; // PRIVATE VARIABLES RES

public:
    double rotate_y = 0; // PUBLIC VARIABLE ROTATE_Y
    double rotate_x = 0; // PUBLIC VARIABLE ROTATE_X


    /*
    * A FUNCTION "polygon" THAT HAS CUBE POLYGONS
    */
    int polygon()
    {
        //rotating cube
        glRotatef(rotate_x, 1.0, 0.0, 0.0);
        glRotatef(rotate_y, 0.0, 1.0, 0.0);

        // FRONT
        glBegin(res);
        glColor3f(1.0, 9.0, 6.0);
        glNormal3f(0.3, -0.3, -0.3);
        glVertex3f(0.3, -0.3, -0.3);
        glNormal3f(0.3, 0.3, -0.3);
        glVertex3f(0.3, 0.3, -0.3);
        glNormal3f(-0.3, 0.3, -0.3);
        glVertex3f(-0.3, 0.3, -0.3);
        glNormal3f(-0.3, -0.3, -0.3);
        glVertex3f(-0.3, -0.3, -0.3);
        glEnd();

        // BACK
        glBegin(res);
        glColor3f(0.0f, 0.1f, 0.0f);
        glNormal3f(1.0, 1.0, 1.0);
        glVertex3f(0.3, -0.3, 0.3);
        glNormal3f(0.3, 0.3, 0.3);
        glVertex3f(0.3, 0.3, 0.3);
        glNormal3f(-0.3, 0.3, 0.3);
        glVertex3f(-0.3, 0.3, 0.3);
        glNormal3f(-0.3, -0.3, 0.3);
        glVertex3f(-0.3, -0.3, 0.3);
        glEnd();

        // RIGHT
        glBegin(res);
        glColor3f(1.0f, 0.5f, 0.0f);
        glNormal3f(0.3, -0.3, -0.3);
        glVertex3f(0.3, -0.3, -0.3);
        glNormal3f(0.3, 0.3, -0.3);
        glVertex3f(0.3, 0.3, -0.3);
        glNormal3f(0.3, 0.3, 0.3);
        glVertex3f(0.3, 0.3, 0.3);
        glNormal3f(0.3, -0.3, 0.3);
        glVertex3f(0.3, -0.3, 0.3);
        glEnd();

        // LEFT
        glBegin(res);
        glColor3f(0.0, 1.0, 0.0);
        glNormal3f(-0.3, -0.3, 0.3);
        glVertex3f(-0.3, -0.3, 0.3);
        glNormal3f(-0.3, 0.3, 0.3);
        glVertex3f(-0.3, 0.3, 0.3);
        glNormal3f(-0.3, 0.3, -0.3);
        glVertex3f(-0.3, 0.3, -0.3);
        glNormal3f(-0.3, -0.3, -0.3);
        glVertex3f(-0.3, -0.3, -0.3);
        glEnd();

        // TOP
        glBegin(res);
        glColor3f(2.0f, 0.5f, 1.0f);
        glNormal3f(0.3, 0.3, 0.3);
        glVertex3f(0.3, 0.3, 0.3);
        glNormal3f(0.3, 0.3, -0.3);
        glVertex3f(0.3, 0.3, -0.3);
        glNormal3f(-0.3, 0.3, -0.3);
        glVertex3f(-0.3, 0.3, -0.3);
        glNormal3f(-0.3, 0.3, 0.3);
        glVertex3f(-0.3, 0.3, 0.3);
        glEnd();

        // BOTTOM
        glBegin(res);
        glColor3f(-0.5, 0.0, 0.0);
        glNormal3f(0.3, -0.3, -0.3);
        glVertex3f(0.3, -0.3, -0.3);
        glNormal3f(0.3, -0.3, 0.3);
        glVertex3f(0.3, -0.3, 0.3);
        glNormal3f(-0.3, -0.3, 0.3);
        glVertex3f(-0.3, -0.3, 0.3);
        glNormal3f(-0.3, -0.3, -0.3);
        glVertex3f(-0.3, -0.3, -0.3);
        glEnd();

        return 0;

    }
};


cube cu;

/* FUNCTION DISPLAY */
void display() {

    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    cu.polygon();
   

    glFlush();
    glutSwapBuffers();

}
/* A FUNCTION THAT HAS ROTATION KEYS */
void specialKeys(int key, int x, int y) {

    //  RIGHT
    if (key == GLUT_KEY_RIGHT)
        cu.rotate_y += 5;

    //  LEFT
    else if (key == GLUT_KEY_LEFT)
        cu.rotate_y -= 5;

    // UP
    else if (key == GLUT_KEY_UP)
        cu.rotate_x += 5;

    // DOWN
    else if (key == GLUT_KEY_DOWN)
        cu.rotate_x -= 5;


    //  REQUEST DISPLAY UPDATE
    glutPostRedisplay();

}


/* FUNCTION MAIN */
int main(int argc, char* argv[]) {


    //  PARAMETERS WINDOW
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // CREATE WINDOW
    glutCreateWindow("3D cube");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);

    // LIGHT0 POSITION
    float position[] = { 0,1,0,0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    // LIGHT1 POSITION
    float position1[] = { 0,-5,0,0 };
    glLightfv(GL_LIGHT1, GL_POSITION, position1);

    // CALLBACK FUNCTIONS
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;

}
