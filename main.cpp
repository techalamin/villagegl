#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <windows.h>


void sky(){
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.922);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);

    glColor3f(0.529, 0.808, 0.980);
    glVertex2f(1.0, -0.05);
    glVertex2f(-1.0, -0.05);
    glEnd();
}

void field_1(){
    //field 1
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(1.0, -0.05);

    glColor3f(0.000, 1.000, 0.000);
    glVertex2f(-1.0, -0.05);

    glColor3f(0.486, 0.988, 0.000);
    glVertex2f(-1.0, 0.135);

    glColor3f(0.498, 1.000, 0.000);
    glVertex2f(1.0, 0.135);

    glEnd();
}


void road(){
    //Main road lane 1
    glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.05);
    glVertex2f(-1.0, -0.57);
    glVertex2f(1.0, -0.57);
    glVertex2f(1.0, -0.05);
    glEnd();
}

void field_2(){

    //field 2
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(1.0, -0.57);

    glColor3f(0.000, 1.000, 0.000);
    glVertex2f(-1.0, -0.57);

    glColor3f(0.486, 0.988, 0.000);
    glVertex2f(-1.0, -0.73);

    glColor3f(0.498, 1.000, 0.000);
    glVertex2f(1.0, -0.73);
    glEnd();
}

void river(){
    glBegin(GL_QUADS);
    glColor3f(0.000, 1.000, 1.000);
    glVertex2f(1.0, -0.73);

    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(-1.0, -0.73);

    glColor3f(0.498, 1.000, 0.831);
    glVertex2f(-1.0, -1.0);

    glColor3f(0.282, 0.820, 0.800);
    glVertex2f(1.0, -1.0);

    glEnd();
}


void mountain()
{
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
    glEnable ( GL_COLOR_MATERIAL ) ;
    glBegin(GL_TRIANGLES);
     glColor3f(0.0, 0.5, 0.0);
     glVertex2f(-1.0f, -1.0f);
     glColor3f(1.0, 1.0, 1.0);
     glVertex2f(0.0f, 1.0f);
     glColor3f(0.0, 0.5, 0.0);
     glVertex2f(1.0f, -1.0f);
    glEnd();
}
void mountains()
{
    glPushMatrix();
    glLoadIdentity();
    glScalef(0.3f, 0.3f, 0.0f);
    glTranslatef(-2.6f, 1.45f,0.0f);
    mountain();
    glTranslatef(0.8f, 0.0f,0.0f);
    mountain();
    glTranslatef(3.5f, 0.0f,0.0f);
    mountain();
    glPopMatrix();
}


void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(1.0, 1.0, 1.0, 1.0);
}


void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    field_1();
    road();
    field_2();
    river();
    mountains();

    glFlush();
}


void Idle()
{
    glutPostRedisplay();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Project");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutIdleFunc(Idle);
    glutMainLoop();

}

