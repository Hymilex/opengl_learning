// Pro1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

#include <glut.h>

using namespace std;

int _PAINTNUMS = 3600;
float PI = 3.1415926F;
float R  = 0.8f;

void Basic()
{
	//��Բ�ǰ��ջ��ƶ���εĹ��������л���
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glColor4f(0,0,1,0);
	glBegin(GL_POLYGON);
	for(int i = 0;i<_PAINTNUMS;i++)
	{
		glVertex2f(R*cos(2*PI*i/_PAINTNUMS),R*sin(2*PI*i/_PAINTNUMS));
	}
	glEnd();
	glFlush();

	cout<<"����Բ�γɹ������������..."<<endl;
	system("pause");

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glColor4f(0,0,1,0);
	glBegin(GL_LINE_LOOP);
	GLfloat xA=R*cos(90*2*PI/360);
	GLfloat yA=R*sin(90*2*PI/360);
	GLfloat xB=R*cos(306*2*PI/360);
	GLfloat yB=R*sin(306*2*PI/360);
	GLfloat xC=R*cos(162*2*PI/360);
	GLfloat yC=R*sin(162*2*PI/360);
	GLfloat xD=R*cos(18*2*PI/360);
	GLfloat yD=R*sin(18*2*PI/360);
	GLfloat xE=R*cos(234*2*PI/360);
	GLfloat yE=R*sin(234*2*PI/360);

	glVertex2f(xA,yA);
	glVertex2f(xB,yB);
	glVertex2f(xC,yC);
	glVertex2f(xD,yD);
	glVertex2f(xE,yE);

	glEnd();
	glFlush();
	cout<<"������������!�����������..."<<endl;
	system("pause");

	//������������
	GLfloat x=-1.0;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-1.0f,0.0f);  //�����ĵ�ʮ��
	glVertex2f(1.0f,0.0f);
	glVertex2f(0.0f,-1.0f);
	glVertex2f(0.0f,1.0f);

	glEnd();

	glBegin(GL_LINE_STRIP);
	for(float x =-5*PI;x<5*PI;x+=0.1f)
	{
		glVertex2f(x/(5*PI),sin(x));
	}
	glEnd();
	glFlush();
	cout<<"���һ������!"<<endl;
}

void ChangeSize()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//���õ�Ĵ�СΪ5������
	glPointSize(5);
	//������ɫ rgba
	glColor4f(0,0,1,0);
	//����ʲô����ͼ��
	glBegin(GL_POINTS);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.6f,0.6f);
	glEnd();
	glFlush();
	
	system("pause");
	glClear(GL_COLOR_BUFFER_BIT);
	//�ı��ߵĿ��
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(0.5f,0.5f);
	glEnd();
	glFlush();

	system("pause");
	glClear(GL_COLOR_BUFFER_BIT);
	//�ı��ߵ�ģʽ���� ʵ��
	glLineWidth(5);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(0,0X00FF);

	glBegin(GL_LINES);
	glVertex2f(-0.8,0.5);
	glVertex2f(0.8f,0.5f);
	glEnd();
	glFlush();
}



void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.5f,-0.5f,0.5f,0.5f);
	glFlush();
}

//����ε�������
void myDisplay2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPolygonMode(GL_BACK,GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_POINT); ����������Ϊ������Ʒ�ʽ
	glFrontFace(GL_CCW);
	//glFrontFace(GL_CW); //����˳ʱ��Ϊ����
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(-0.5,0);
	glVertex2f(-0.5,-0.5);
	glVertex2f(0,-0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,0);
	glVertex2f(0,0);
	glEnd();
	glFlush();
}


//�޳�����εķ���
void myDisplay2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPolygonMode(GL_BACK,GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_POINT); ����������Ϊ������Ʒ�ʽ
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE); //�����޳�����
	glCullFace(GL_FRONT);  //ѡ��Ҫ�޳�����
	//glFrontFace(GL_CW); //����˳ʱ��Ϊ����
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(-0.5,0);
	glVertex2f(-0.5,-0.5);
	glVertex2f(0,-0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,0);
	glVertex2f(0,0);
	glEnd();
	glFlush();
}

//����ε��ο�
void myDisplay3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	static GLubyte Mask[128];
	FILE *fp;
	fp = fopen("hello.bmp","rb");
	if(!fp)
	{
		exit(0);
	}
	if(fseek(fp,-(int)sizeof(Mask),SEEK_END))
		exit(0);
	if(!fread(Mask,sizeof(Mask),1,fp))
		exit(0);
	fclose(fp);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(Mask);
	glRectf(-0.7f, -0.7f, 0.7f, 0.7f);   // ����һ�����ο�Ч����������
	glFlush();
}



int _tmain(int argc, char* argv[])
{
	std::cout<<"hello world!"<<std::endl;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("THIS IS MY FIRST OPENGL WINDOW.");
	glutDisplayFunc(&ChangeSize);
	glutMainLoop();
	
	return 0;
}

