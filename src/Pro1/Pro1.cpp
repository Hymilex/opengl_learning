// Pro1.cpp : 定义控制台应用程序的入口点。
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
	//对glut进行初始化显示
	glutInit(&argc,argv);
	//指定使用RGB模式还是颜色索引模式
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	//指定左上角屏幕位置
	glutInitWindowPosition(100,100);
	//指定窗口大小
	glutInitWindowSize(800,600);
	glutCreateWindow("THIS IS MY FIRST OPENGL WINDOW.");
	Init();
	//显示回调函数
	glutDisplayFunc(DisplayPaint);
	
	//glutReshapeFunc(); 当窗口发生变化时触发
	//glutMouseFunc();
	//glutKeyboardFunc();
	//glutMotionFunc();
	//glutPostRedisplay(); 如果程序修改了窗口内容需要调用介个
	//必须调用MainLoop启动程序
	
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



