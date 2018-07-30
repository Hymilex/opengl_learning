#include "stdafx.h"
#include <glut.h>
static GLfloat spin = 0.0;
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}
void displayX(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glRectf(-25.0,-25.0,25.0,25.0);
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay()
{
	spin=spin+2.0;
	if(spin>360.0)
	{
		spin=spin-360.0;
	}
	glColor3f(1.0,0.0,1.0);
	glutPostRedisplay();
	printf("world");
}
void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//左右下上前后
	glOrtho(-50.0,50.0,-50.0,50.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	printf("hello");
}

void mouse(int button,int state,int x,int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			glutIdleFunc(spinDisplay);
			//printf("world");
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state==GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
	default:
		break;
	}
}