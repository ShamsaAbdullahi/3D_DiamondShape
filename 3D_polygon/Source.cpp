#include <gl/glut.h>

GLfloat degree = 20;
void display_diamond()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 1.0f, -6.0f);
	glRotatef(degree, 0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);

	//front face
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	//opposite face
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	//side face
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-1.0f,-1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	//opposite side face
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
    //-----------------------------

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	//bottom face front
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, -3.0f, 0.0f);

	//bottom face opposite
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, -3.0f, 0.0f);

	//side face bottom
	glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, -3.0f, 0.0f);

	//side face opposite
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, -3.0f, 0.0f);

    glEnd();
	degree += 10;
	glutSwapBuffers();

}
void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}
void reshape(GLsizei width, GLsizei height) {
	if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 45.0f);

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("3D DIAMOND SHAPE");
	glutDisplayFunc(display_diamond);
	glutReshapeFunc(reshape);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glutTimerFunc(200, timer, 0);
	glutMainLoop();
}