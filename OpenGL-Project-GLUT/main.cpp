#include <GL/glut.h>
#include <math.h>


void Square() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_POLYGON); 
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}

void myReshape(int w, int h) {
	glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
  glEnd();
  glFlush();
}

void ClearScreen()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:               //ESCAPE key
			exit(0);
			break;
	case 'd':
		glutDisplayFunc(Square);     //callback function
		break;
	case'r':
		glutReshapeFunc(myReshape);
		break;
	case'c':
		glutDisplayFunc(ClearScreen);
		break;
	}

	glutPostRedisplay();
}
	void mymenu(int id)

	{

		if (id == 1) glutDisplayFunc(Square);
		if (id == 2) glutReshapeFunc(myReshape);
		if (id == 3) glutDisplayFunc(ClearScreen);
		if (id == 4) exit (0);

		glutPostRedisplay();

	}

  int main (int argc, char** argv)  {
	  glutInit(&argc, argv);
	  glutInitDisplayMode(GLUT_RGB);
	  glutInitWindowSize(800,600);

	  glutCreateWindow("Project for CS-Elective-2");
	  glutKeyboardFunc(Keyboard);
	  //glutKeyboardFunc(Keyboard);

	  int menu_id;
	  menu_id = glutCreateMenu(mymenu);
	  glutAddMenuEntry("Show Shape", 1);
	  glutAddMenuEntry("Reshape", 2);
	  glutAddMenuEntry("Clear Screen", 3);
	  glutAddMenuEntry("Exit", 4);
	  glutAttachMenu(GLUT_RIGHT_BUTTON);

	  glutMainLoop();
	
  }