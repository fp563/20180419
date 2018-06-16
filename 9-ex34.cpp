#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "matrix.h"

#define INIT_SIZE 50    /* 正方形の初期サイズ（１辺の半分） */
#define SPEED 0.1                       /* サイズの変化する速さ */

void init(void);

int width, height;      /* ウィンドウの大きさ */
double size;            /* 描画する正方形のサイズ */
int increase;           /* 正方形が大きくなるときは 1，小さくなるときは 0 */
int sq_tr;                      /* 正方形描画中なら 1，三角形なら 0 */
int x0, right_down;
int px, py;

void square(void)
{
	double x_center, y_center;
	x_center = width / 2.0;
	y_center = height / 2.0;

	glClear(GL_COLOR_BUFFER_BIT);
	glRectd(x_center - size, y_center - size, x_center + size, y_center + size);
	glutSwapBuffers();
}

void triangle(void)
{
	double x_center, y_center;
	x_center = width / 2.0;
	y_center = height / 2.0;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex2d(x_center, y_center + size);
	glVertex2d(x_center - size, y_center - size / 2.0);
	glVertex2d(x_center + size, y_center - size / 2.0);
	glEnd();
	glutSwapBuffers();
}

void green_point(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.0, 1.0, 0.0);
	glPointSize(20.0);
	glBegin(GL_POINTS);
	glVertex2d(px, py);
	glEnd();
	glFlush();
	glutSwapBuffers();
}
void red_point(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	glPointSize(20.0);
	glBegin(GL_POINTS);
	glVertex2d(px, py);
	glEnd();
	glFlush();
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

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			if (sq_tr) {
				glutDisplayFunc(green_point);
				sq_tr = 0;
			}
			else {
				glutDisplayFunc(red_point);
				sq_tr = 1;
			}
			glutPostRedisplay();
		}
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN) {
			px = x;
			py = height - y;
			right_down = 1;
			//glutDisplayFunc(green_point);
		}
		else if (state == GLUT_UP) {
			right_down = 0;
		}
	}
}

void motion(int x, int y)
{
	if (right_down) {
		px = x;
		py = height - y;
		glutPostRedisplay();
	}
}

void init(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	size = INIT_SIZE;
	increase = 1;
	sq_tr = 1;
	right_down = 0;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(green_point);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);  /* glutIdleFunc(idle); から変更 */
	init();
	glutMainLoop();
	return 0;
}