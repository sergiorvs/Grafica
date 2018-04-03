#include <GL/glut.h>

//Compilar: g++ -std=c++11 simpleLine.cc -o demo -lglut -lGL -lGLU


void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(-5, 5, -5, 5, 0, 0);
    gluOrtho2D(-5, 5, -5, 5);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, -1, 1);
    glLoadIdentity();

    glBegin(GL_POINTS);
    glVertex3i(0, 0, 0);
    glVertex3i(1, 0, 0);
    glVertex3i(0, 1, 0);
    glVertex3i(1, 1, 0);
    glVertex3i(-1, 0, 0);
    glEnd();

    glFlush();
}
void init()
{
    glClearColor(0, 0, 0, 0);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello OpenGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}