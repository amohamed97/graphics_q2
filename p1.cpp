#include <GL/glut.h>
#include<GL/gl.h>


using namespace std;

int angle = 0; 
int rotate = 0;

void draw_letter_a(){
	glBegin(GL_POLYGON);
	glVertex2f(1, 4);
	glVertex2f(-1, 4);
	glVertex2f(-6, -4);
	glVertex2f(-4, -4);
	glVertex2f(0, 3);
	glVertex2f(4, -4);
	glVertex2f(6, -4);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-1.5, 0.5);
	glVertex2f(-2.4, -0.5);
	glVertex2f(2.4, -0.5);
	glVertex2f(1.5, 0.5);
	glEnd();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer
	glLoadIdentity();
	glOrtho(-12, 12, -12, 12, -1.0, 1.0);
	glRotatef(angle,0,0,1);
	glColor3f(1.0, 1.0, 1.0);
    draw_letter_a();
    glFlush();
    glutSwapBuffers();
}


void timer(int x){
	if(rotate) angle+= 2;
	glutPostRedisplay();
	glutTimerFunc(30,timer,0);
}

void mouse_button(int key, int st,int x, int y){
	switch(key){
		case GLUT_LEFT_BUTTON:
			rotate = 1;
			break;
		case GLUT_RIGHT_BUTTON:
			rotate = 0;
			break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);// this function needs to be called before
	                      //we can start to use any of the GLUT library functions

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(600,50);
	glutCreateWindow("Q2P1");

	glutDisplayFunc(display);

    glClearColor(0.0, 0.0, 0.0, 1.0);
	glutTimerFunc(30,timer,0);
	glutMouseFunc(mouse_button);

	glutMainLoop();

	return 0;
}