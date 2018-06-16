

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "matrix.h"



#define INIT_SIZE 50    /* 正方形の初期サイズ（１辺の半分） */
#define SPEED 0.1                       /* サイズの変化する速さ */



void init(void);

int width, height;              /* ウィンドウの大きさ */
double size;                    /* 描画する正方形のサイズ */
int increase;                   /* 正方形が大きくなるときは 1，小さくなるときは 0 */

void display(void)
{
	double x_center, y_center;
	x_center = width / 2.0;
	y_center = height / 2.0;

	glClear(GL_COLOR_BUFFER_BIT);
	//glRectd(x_center - size, y_center - size, x_center + size, y_center + size);
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2d(x_center + size / INIT_SIZE*(0 - x_center), y_center + size / INIT_SIZE*(200 - y_center));
	glVertex2d(x_center + size / INIT_SIZE*(200 - x_center), y_center + size / INIT_SIZE*(200 - y_center));
	glVertex2d(x_center + size / INIT_SIZE*(100 - x_center), y_center + size / INIT_SIZE*(100 - y_center));
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(x_center + size / INIT_SIZE*(0 - x_center), y_center + size / INIT_SIZE*(140 - y_center));
	glVertex2d(x_center + size / INIT_SIZE*(0 - x_center), y_center + size / INIT_SIZE*(0 - y_center));
	glVertex2d(x_center + size / INIT_SIZE*(80 - x_center), y_center + size / INIT_SIZE*(0 - y_center));
	glVertex2d(x_center + size / INIT_SIZE*(80 - x_center), y_center + size / INIT_SIZE*(60 - y_center));
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(x_center + size / INIT_SIZE*(120 - x_center), y_center + size / INIT_SIZE*(60 - y_center));
	glVertex2d(x_center + size / INIT_SIZE*(120 - x_center), y_center + size / INIT_SIZE*(0 - y_center));
	glVertex2d(x_center + size / INIT_SIZE*(200 - x_center), y_center + size / INIT_SIZE*(0 - y_center));
	glVertex2d(x_center + size / INIT_SIZE*(200 - x_center), y_center + size / INIT_SIZE*(140 - y_center));
	glEnd();

	

	glColor3d(1.0, 0.0, 0.0);
	glPointSize(size / INIT_SIZE*20.0);
	glBegin(GL_POINTS);
	glVertex2d(x_center + size / INIT_SIZE*(180 - x_center), y_center + size / INIT_SIZE*(20 - y_center));
	glEnd();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	width = w;
	height = h;
}

void idle(void)
{
	if (increase) {
		size += SPEED;
		if (size >= INIT_SIZE) {
			size = INIT_SIZE;
			increase = 0;
		}
	}
	else {
		size -= SPEED;
		if (size <= 0) {
			size = 0;
			increase = 1;
		}
	}
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	size = INIT_SIZE;
	increase = 1;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	init();
	glutMainLoop();
	return 0;
}



