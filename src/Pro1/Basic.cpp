#include "stdafx.h"
#include <iostream>

#include <glut.h>
#include <gl\GLU.h>
#include <gl\GL.h>

#include "double.h"
using namespace std;
int _PAINTNUMS = 3600;
float PI = 3.1415926F;
float R  = 0.8f;

//设置背景颜色和坐标系统位于INIT()函数中
//渲染场景(可能重新渲染)操作放在display中
//剩下的就是被注册的回调函数
void Init()
{
	/* select clearing bkcolor */
	glClearColor(0.0,0.0,0.0,0.0);
	/* initialize viewing vals */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}
void DisplayPaint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25,0.25,0.0);
	glVertex3f(0.75,0.25,0.0);
	glVertex3f(0.75,0.25,0.0);
	glVertex3f(0.25,0.75,0.0);
	glEnd();
	glFlush();
}



void Basic()
{
	//画圆是按照绘制多边形的规则对其进行绘制
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

	cout<<"绘制圆形成功，任意键继续..."<<endl;
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
	cout<<"绘制五角星完成!按任意键继续..."<<endl;
	system("pause");

	//绘制正弦曲线
	GLfloat x=-1.0;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-1.0f,0.0f);  //过中心的十字
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
	cout<<"正弦绘制完成!"<<endl;
}

void ChangeSize()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//设置点的大小为5个像素
	glPointSize(5);
	//设置颜色 rgba
	glColor4f(0,0,1,0);
	//绘制什么样的图形
	glBegin(GL_POINTS);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.6f,0.6f);
	glEnd();
	glFlush();
	
	system("pause");
	glClear(GL_COLOR_BUFFER_BIT);
	//改变线的宽度
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(0.5f,0.5f);
	glEnd();
	glFlush();

	system("pause");
	glClear(GL_COLOR_BUFFER_BIT);
	//改变线的模式虚线 实线
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

//多边形的正反面
void myDisplay2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPolygonMode(GL_BACK,GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_POINT); 正反面设置为顶点绘制方式
	glFrontFace(GL_CCW);
	//glFrontFace(GL_CW); //设置顺时针为正面
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

/*
void myDisplay2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPolygonMode(GL_BACK,GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_POINT); 正反面设置为顶点绘制方式
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE); //开启剔除功能
	glCullFace(GL_FRONT);  //选择要剔除的面
	//glFrontFace(GL_CW); //设置顺时针为正面
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
*/
//剔除多边形的反面


//多边形的镂空
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
	//开启镂空
	glEnable(GL_POLYGON_STIPPLE);
	//使用镂空
	glPolygonStipple(Mask);
	glRectf(-0.7f, -0.7f, 0.7f, 0.7f);   // 绘制一个有镂空效果的正方形
	glFlush();
}


