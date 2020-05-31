#include <GL/glut.h>
#include<GL/gl.h>


using namespace std;

void draw_grid_and_numbers(){
    glBegin(GL_LINES);
	glVertex2f(-12, 0);
	glVertex2f(12, 0);
	glVertex2f(0, -12);
	glVertex2f(0, 12);
	glEnd();
    glRasterPos2d(-0.8,1);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
    glRasterPos2d(-0.8,2);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
    glRasterPos2d(-0.8,3);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '3');
    glRasterPos2d(-0.8,4);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');
    glRasterPos2d(-0.8,5);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '5');
}

void draw_rect(float x1, int y1, int x2, int y2){
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y1);
	glEnd();
}

void draw_graph(int arr[4]){
    for(auto i = 0; i < 4; i++){
        draw_rect(i,0,i+1,arr[i]);
    }
}

void display(){
    int arr[4] = {5,2,5,4};
    glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer
	glColor3f(1.0, 1.0, 1.0);
    draw_grid_and_numbers();
    draw_graph(arr);
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);// this function needs to be called before
	                      //we can start to use any of the GLUT library functions

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(600,50);
	glutCreateWindow("Q2P3");

	glutDisplayFunc(display);
    glOrtho(-12, 12, -12, 12, -1.0, 1.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);

	glutMainLoop();

	return 0;
}