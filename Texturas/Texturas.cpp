// Texturas.cpp: define el punto de entrada de la aplicación de consola.
// Antonio Jimenez Azucena, Antonio López Lizeth y León Pérez Leandro
//
#include "stdafx.h"
#include <Windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "ImageLoader.h" 
#include <time.h> 
#include <math.h>
#include <iostream>
#include <chrono>
#include <string>



using namespace std;


clock_t t1; //Variable de tiempo, numero de tics de reloj transcurridos
static int lados = 0;
int puntos = 0;
static double pi = 3.14159265358979323846;
static double x = 0.7, y = 0.0, z = -0.1;
static double tras = 0.1;
static double zz = 0, xx = 0;
int masx = 0;
int masz = 0;
int bandera1 = 0;
int bandera3 = 0;
int bandera4 = 0;
int bandera5 = 0;
int bandera6 = 0;
int bandera7 = 0;
int bandera8 = 0;
int bandera9 = 0;
int bandera10 = 0;
int bandera11 = 0;
int bandera12 = 0;
int flag = 0;
static int r = 0;
bool salir = false;
static char* texto1 = "";
static char* texto = "COME TANTOS OBSTACULOS COMO PUEDAS EN 20 SEGUNDOS";
static int angulo = 0;
static int direccion[] = { 0,30,60,90,120,150,180,210,240,270,300,330 }; //Angulos en los que giramos
static int matriz[72][81] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
static int cuadros[24][27] = {
	{ 1,1,1,1,1,1,1,1,1,1,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
static int posz = 34, posx = 41;
static int esferas[5][2];
static int contador = 0;
static int posiblesCuadros[22][2] = {
	{ 38,35 },{ 35,33 },{ 40,33 },{ 36,30 },{ 36,31 },
	{ 30,35 },{ 25,33 },{ 33,40 },{ 20,40 },{ 22,39 },
	{ 25,38 },{ 9,40 },{ 10,33 },{ 15,35 },{ 20,40 },
	{ 20,36 },{ 39,38 },{ 38,40 },{ 30,40 },{ 5,40 },{ 20,33 },{ 6,32 } }; //Posibles obstaculos

GLuint _lados, _obstaculos, _pista, _arriba, _meta;
static int multiplo = 1; //Multiplo para el tiempo

						 //idTextura
GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}

//Iniciar estado de renderizado
void initRendering() {
	Image* paredes = loadBMP("pared.bmp");
	Image* obs = loadBMP("obstaculo.bmp");
	Image* pista = loadBMP("suelo.bmp");
	Image* arriba = loadBMP("cielo.bmp");
	Image* meta = loadBMP("final.bmp");

	_lados = loadTexture(paredes);
	_obstaculos = loadTexture(obs);
	_pista = loadTexture(pista);
	_arriba = loadTexture(arriba);
	_meta = loadTexture(meta);
	delete paredes;
	delete obs;
	delete pista;
	delete arriba;
	delete meta;
}

void cargarTextura(GLuint _textura) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void inline drawString(char* s)
{
	unsigned int i;
	for (i = 0; i < strlen(s); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
}

//Encabezados de tiempo, escribir en el juego
void inline drawString2(char* s1)
{
	unsigned int i;
	glRasterPos3f(-0.12, 0.9, -1);  // Posicionar texto de puntos
	for (i = 0; i < strlen(s1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s1[i]);
}

//Generar las texturas de las paredes
void generarCubo(int xmet, int zmet)
{
	glPushMatrix();
	cargarTextura(_lados);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_lados);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_lados);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_lados);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_lados);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_lados);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

}

//Generar las texturas de la meta
void generarMeta(int xmet, int zmet)
{
	glPushMatrix();
	cargarTextura(_meta);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_meta);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_meta);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_meta);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_meta);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_meta);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

}

//Generar las texturas de las cajas ?, obstaculos
void generarObstaculo(int x, int z)
{
	glPushMatrix();
	cargarTextura(_obstaculos);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_obstaculos);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_obstaculos);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_obstaculos);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_obstaculos);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_obstaculos);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();

}


//Mostrar la matriz de las paredes
void mostrarcuadros()
{
	int x = -33, z = -40, i, j;

	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 27; j++)
		{
			if (cuadros[i][j] == 1)
			{
				if (i == 23 && j == 1 && salir)
				{

				}
				else {

					generarCubo(x, z); //genera,imp los cubos de la pared
				}
			}
			if (cuadros[i][j] == 4)
			{
				if (i == 23 && j == 1 && salir)
				{

				}
				else {

					generarMeta(x, z); //genera los cubos de la meta
				}
			}
			x = x + 3;
		}
		z = z + 3;
		x = -33;
	}
}

//Mostrar juego
void display(void) {
	drawString(texto);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3d(0.5, 0.5, 0.5);

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	mostrarcuadros(); //pared

					  //Generar las texturas del suelo o pista
	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_pista);
	glRotated(r, 0, 1, 0);
	glTranslated(xx, 0.4, zz);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33, -1.6, -42);
	glTexCoord2f(100.0f, 0.0f);
	glVertex3f(48, -1.6, -42);
	glTexCoord2f(100.0f, 100.0f);
	glVertex3f(48, -1.6, 30);
	glTexCoord2f(0.0f, 100.0f);
	glVertex3f(-33, -1.6, 30);
	glEnd();
	glPopMatrix();

	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_arriba);
	glRotated(r, 0, 1, 0);
	glTranslated(xx, 15, zz);



	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-43, -11.6, -52);
	glTexCoord2f(100.0f, 0.0f);
	glVertex3f(58, -11.6, -52);
	glTexCoord2f(100.0f, 100.0f);
	glVertex3f(58, -11.6, 40);
	glTexCoord2f(0.0f, 100.0f);
	glVertex3f(-43, -11.6, 40);
	glEnd();
	glPopMatrix();

	int x = -34, z = -41, i, j;

	//Dibujar cajas 
	for (i = 0; i < 72; i++)
	{
		for (j = 0; j < 81; j++)
		{
			if (matriz[i][j] == 3)
			{
				glColor3d(0.6, 0.6, 0.6);

				generarObstaculo(x, z); //Genera los obstaculos

			}

			x = x + 1;
		}
		z = z + 1;
		x = -34;
	}


	glColor3d(256, 266, 256);
	glRasterPos3f(-0.4, 0, -1);

	//Invoca metodo texto inicial del juego 
	drawString(texto);
	//Mostrar puntos en la pantalla
	string p = to_string(puntos);
	string puntaje = "PUNTOS: " + p;
	texto1 = const_cast<char*>(puntaje.c_str());
	drawString2(texto1);

	glRasterPos3f(-0.5, 1.8, -1.9);

	glutSwapBuffers();
}

//Redimensionar
void reshape(int width, int height) {
	const float ar = (float)width / (float)height;
	double aspect = height / width;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}


//Para los obstaculos
void genesferas()
{
	srand(time(0));
	for (int k = 0; k < 20; k++)
	{
		int num1 = (int)rand() % 22;
		int pos0 = (posiblesCuadros[num1][1] - 34);
		int pos1 = (posiblesCuadros[num1][0] - 41);
		bool flag = true;
		for (int n = 0; n < 5; n++)
		{
			if (esferas[n][0] == pos0 && esferas[n][1] == pos1)
			{
				flag = false;
			}
		}

		if (flag)
		{
			esferas[k][0] = pos0;
			//printf("esferas 0: %d", esferas[k][0] + 34);
			esferas[k][1] = pos1;
			//printf("esferas 1: %d\n", esferas[k][1] + 41);
			matriz[posiblesCuadros[num1][0]][posiblesCuadros[num1][1]] = 3;
		}
		else {
			k--;
		}

	}
}

//Metodo para reiniciar el juego
void reiniciar() {
	using namespace std;
	lados = 0;
	pi = 3.14159265358979323846;
	x = 0.7, y = 0.0, z = -0.1;
	tras = 0.1;
	zz = 0, xx = 0;
	masx = 0;
	masz = 0;
	bandera1 = 0;
	bandera3 = 0;
	bandera4 = 0;
	bandera5 = 0;
	bandera6 = 0;
	bandera7 = 0;
	bandera8 = 0;
	bandera9 = 0;
	bandera10 = 0;
	bandera11 = 0;
	bandera12 = 0;
	flag = 0;
	r = 0;
	salir = true;
	angulo = 0;
	posz = 34, posx = 41;
	texto = "COME TANTOS OBSTACULOS COMO PUEDAS EN 30 SEGUNDOS";
	puntos = 0;
	genesferas(); //nuevos obstaculos
}



static void key(unsigned char key, int x, int y)
{
	int bandera2 = 0;
	int comprobar = 0;
	int aux1 = 0;
	int aux2 = 0;
	boolean si = false;

	switch (key)
	{
	case 'a':

		_asm {
			CMP key, 'a'
			JNE sa
			MOV EAX, angulo

			CMP EAX, 0
			JE igual

			DEC EAX
			MOV angulo, EAX
			JMP sa

			igual : MOV EAX, 11
					MOV angulo, EAX
					sa :
		}
		r = direccion[angulo];
		break;
	case 'd':
		_asm {
			CMP key, 'd'
			JNE sa2
			MOV EAX, angulo

			CMP EAX, 0
			JE cero
			CMP EAX, 11
			JE once

			INC EAX
			MOV angulo, EAX
			JMP sa2
			cero : MOV EAX, 1
				   MOV angulo, EAX
				   JMP sa2

				   once : MOV EAX, 0
						  MOV angulo, EAX
						  sa2 :
		}
		r = direccion[angulo];
		break;

	case 'w':
		texto = " ";
		//Avanzar hacia adelante y comer

		_asm { CMP key, 'w'
		JNE fin

			sa3 : MOV EAX, r
			CMP EAX, 0
			JAE validar
			JMP nada
			validar : CMP EAX, 30
			JBE accion
			CMP EAX, 330
			JE accion
			JMP nada
			accion : MOV EDX, posx
			DEC EDX
			MOV masx, EDX
			MOV EDX, posz
			MOV masz, EDX
			MOV flag, 1
			fuera : MOV bandera1, 1
			JMP fin
			nada :
	fin:
		}
		if (flag == 1)
		{

			if (bandera1 == 1)
			{
				aux1 = matriz[masx][masz];

				//cout << aux1 << endl;
				//cout << aux2 << endl;
			}

			_asm {
				MOV EAX, aux1
				CMP EAX, 1  //Pared
				JE sa4
				CMP EAX, 3 //Obstaculo
				JE sa5
				CMP EAX, 4 //Meta
				JE sa4

				sig : MOV bandera2, 1
					  JMP sa4
					  sa5 : MOV bandera2, 2
							JMP sa4
							sa4 :
			}

			if (bandera2 == 1 || bandera2 == 2)
			{
				//cout << "NO entre" << endl;
				zz = zz + 1; //Avanzar hacia adelante
				posx = posx - 1; //Desplazar en x, de lado
				if (matriz[masx][masz] == 3) //Cuando recorre la matriz y encuentra un 3 aumenta los puntos 
				{
					puntos++;
					//cout << puntos << endl;
				}
				matriz[masx][masz] = 0; //Lo convierte en 0 
			}
		}

		//Derecha
		_asm {
			MOV EAX, r
			CMP EAX, 60
			JAE validar2
			JMP nada3
			validar2 : CMP EAX, 120
					   JBE accion2
					   JMP nada3
					   accion2 : MOV EAX, posx
								 MOV masx, EAX
								 MOV EAX, posz
								 INC EAX
								 MOV masz, EAX
								 MOV flag, 2
								 MOV bandera4, 1
								 nada3 :
		}
		if (flag == 2) {

			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 4)
			{
				xx = xx - 1;
				posz = posz + 1;
				if (matriz[masx][masz] == 3)
				{
					puntos++;
					//cout << puntos << endl;
					matriz[masx][masz] = 0;
				}
			}
		}

		//Atras
		_asm {
			MOV EAX, r
			CMP EAX, 150
			JAE validar6
			JMP nada6
			validar6 : CMP EAX, 210
					   JBE accion6
					   JMP nada6
					   accion6 : MOV EAX, posx
								 INC EAX
								 MOV masx, EAX
								 MOV EAX, posz
								 MOV masz, EAX
								 MOV flag, 3
								 MOV bandera7, 1
								 nada6 :
		}
		if (flag == 3) {

			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 4)
			{
				zz = zz - 1;
				posx = posx + 1;
				if (matriz[masx][masz] == 3)
				{
					puntos++;
					//cout << puntos << endl;
					matriz[masx][masz] = 0;
				}
			}
		}

		//Izquierda	
		_asm {

			MOV EAX, r
			CMP EAX, 240
			JAE validar9
			JMP nada9
			validar9 : CMP EAX, 300
					   JBE accion9
					   JMP nada9
					   accion9 : MOV EAX, posx
								 MOV masx, EAX
								 MOV EAX, posz
								 DEC EAX
								 MOV masz, EAX
								 MOV flag, 4
								 MOV bandera10, 1
								 nada9 :
		}
		if (flag == 4) {

			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 4)
			{
				xx = xx + 1;
				posz = posz - 1;
				if (matriz[masx][masz] == 3)
				{
					puntos++;
					//cout << puntos << endl;
					matriz[masx][masz] = 0;
				}
			}
		}

		break;
	}
	glutPostRedisplay();
}


static void idle(void)
{
	glutPostRedisplay();
	t1 = clock() - t1; //tiempo trascurrido del procesador
	if ((int(t1) / CLOCKS_PER_SEC) == (20 * multiplo)) { //Convierte en segundos y compara limite de tiempo multiplo de 20 
														 //muestra cuandoo se termina el tiempo
		texto = "GAME OVER";
		display();
		Sleep(5000);
		multiplo++; //Sumando 20-20 para comparar que sea multiplo de 20
					//Reinia el juego
		reiniciar();

	}
}
int main(int argc, char** argv) {
	t1 = clock(); //Inicio del tiempo del procesador
	genesferas();
	glutInit(&argc, argv);
	glutInitWindowSize(1900, 5000);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("GRAFICACION");
	glutSetCursor(GLUT_CURSOR_NONE);
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glClearColor(0, 0.5, 0.7, 1);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}