#include <GL/glut.h>
#include<GL/gl.h>


using namespace std;

int angle = 0; 
int rotate = 0;

void draw_letter_a(){
    glColor3f(8.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(1, 4, 1);
	glVertex3f(-1, 4, 1);
	glVertex3f(-6, -4, 1);
	glVertex3f(-4, -4, 1);
	glVertex3f(0, 3, 1);
	glVertex3f(4, -4, 1);
	glVertex3f(6, -4, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, 0.5, 1);
	glVertex3f(-2.4, -0.5, 1);
	glVertex3f(2.4, -0.5, 1);
	glVertex3f(1.5, 0.5, 1);
	glEnd();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
	glVertex3f(1, 4, -1);
	glVertex3f(-1, 4, -1);
	glVertex3f(-6, -4, -1);
	glVertex3f(-4, -4, -1);
	glVertex3f(0, 3, -1);
	glVertex3f(4, -4, -1);
	glVertex3f(6, -4, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, 0.5, -1);
	glVertex3f(-2.4, -0.5, -1);
	glVertex3f(2.4, -0.5, -1);
	glVertex3f(1.5, 0.5, -1);
	glEnd();

    glColor3f(0.8, 0.8, 0.8);
    // Linking front and back
    // up side
    glBegin(GL_POLYGON);
	glVertex3f(1, 4, 1);
	glVertex3f(1, 4, -1);
	glVertex3f(-1, 4, -1);
	glVertex3f(-1, 4, 1);
	glEnd();

    // right side
    glBegin(GL_POLYGON);
	glVertex3f(1, 4, 1);
	glVertex3f(1, 4, -1);
	glVertex3f(6, -4, -1);
	glVertex3f(6, -4, 1);
	glEnd();

    // left side
    glBegin(GL_POLYGON);
	glVertex3f(-1, 4, 1);
	glVertex3f(-1, 4, -1);
	glVertex3f(-6, -4, -1);
	glVertex3f(-6, -4, 1);
	glEnd();
    
    // down right side
    glBegin(GL_POLYGON);
	glVertex3f(6, -4, 1);
	glVertex3f(6, -4, -1);
	glVertex3f(4, -4, -1);
	glVertex3f(4, -4, 1);
	glEnd();

    // down left side
    glBegin(GL_POLYGON);
	glVertex3f(-6, -4, 1);
	glVertex3f(-6, -4, -1);
	glVertex3f(-4, -4, -1);
	glVertex3f(-4, -4, 1);
	glEnd();

    glColor3f(0.6, 0.6, 0.6);
    // right interior down side
    glBegin(GL_POLYGON);
	glVertex3f(4, -4, 1);
	glVertex3f(4, -4, -1);
	glVertex3f(2.0, -0.5, -1);
	glVertex3f(2.0, -0.5, 1);
	glEnd();

    // left interior down side
    glBegin(GL_POLYGON);
	glVertex3f(-4, -4, 1);
	glVertex3f(-4, -4, -1);
	glVertex3f(-2.0, -0.5, -1);
	glVertex3f(-2.0, -0.5, 1);
	glEnd();

    // middle edge down
    glBegin(GL_POLYGON);
	glVertex3f(2.0, -0.5, 1);
	glVertex3f(2.0, -0.5, -1);
	glVertex3f(-2.0, -0.5, -1);
	glVertex3f(-2.0, -0.5, 1);
	glEnd();

    // right interior up side
    glBegin(GL_POLYGON);
	glVertex3f(0, 3, 1);
	glVertex3f(0, 3, -1);
	glVertex3f(1.5, 0.5, -1);
	glVertex3f(1.5, 0.5, 1);
	glEnd();

    // left interior up side
    glBegin(GL_POLYGON);
	glVertex3f(0, 3, 1);
	glVertex3f(0, 3, -1);
	glVertex3f(-1.5, 0.5, -1);
	glVertex3f(-1.5, 0.5, 1);
	glEnd();

    glColor3f(0.5, 0.5, 0.5);
    // middle edge up
    glBegin(GL_POLYGON);
	glVertex3f(1.5, 0.5, 1);
	glVertex3f(1.5, 0.5, -1);
	glVertex3f(-1.5, 0.5, -1);
	glVertex3f(-1.5, 0.5, 1);
	glEnd();
    


}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the color buffer
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -8.0, 8.0);
    glRotatef(60.0, 1.0, 1.0, 1.0);
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

void key_pressed(unsigned char key, int x, int y){
	switch(key){
		case 's':
			rotate = 1;
			break;
		case 'p':
			rotate = 0;
			break;
	}
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);// this function needs to be called before
	                      //we can start to use any of the GLUT library functions

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(600,50);
	glutCreateWindow("Q2P2");

	glutDisplayFunc(display);
	glutTimerFunc(30,timer,0);
    init();
	glutKeyboardFunc(key_pressed);

	glutMainLoop();

	return 0;
}