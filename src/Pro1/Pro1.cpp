// Pro1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

#include <glut.h>
#include <gl\GLU.h>
#include <gl\GL.h>

#include "double.h"
using namespace std;

int _tmain(int argc, char** argv)
{
	/*
	std::cout<<"hello world!"<<std::endl;
	//��glut���г�ʼ����ʾ
	glutInit(&argc,argv);
	//ָ��ʹ��RGBģʽ������ɫ����ģʽ
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	//ָ�����Ͻ���Ļλ��
	glutInitWindowPosition(100,100);
	//ָ�����ڴ�С
	glutInitWindowSize(800,600);
	glutCreateWindow("THIS IS MY FIRST OPENGL WINDOW.");
	Init();
	//��ʾ�ص�����
	glutDisplayFunc(DisplayPaint);
	
	//glutReshapeFunc(); �����ڷ����仯ʱ����
	//glutMouseFunc();
	//glutKeyboardFunc();
	//glutMotionFunc();
	//glutPostRedisplay(); ��������޸��˴���������Ҫ���ý��
	//�������MainLoop��������
	
	glutMainLoop();
	
	return 0;
	*/
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(250,250);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(displayX);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}



