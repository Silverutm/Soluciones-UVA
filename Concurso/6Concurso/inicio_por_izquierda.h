#pragma config(Sensor, S4,     Gyro,           sensorEV3_Gyro, modeEV3Gyro_Angle)
#pragma config(Sensor, S2,     sonar_trasero,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S1,     sonar_d_izquierdo,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S3, 		 sonar_d_derecho, 				 sensorEV3_Ultrasonic)
//#pragma config(Sensor, S3,    Gyro2 , sensorEV3_Gyro, modeEV3Gyro_Angle)

#include <libreriamatriz.h>
#include<sek.h>

#define F(w) for(int i=0;i<w; ++i) a(1)
int w;
void inicio_recorrido()
{

	//grados=direccion;
	//Empieza rutina
	//Empieza modulo central

	a(3);
	a(2);
	giroizquierda();
	F(6);
	verificasonar_d(20);
	giroderecha();
	velavance=100;
	F(18);
	resetGyro(S4);
	grados=0;
	wait1Msec(500);
	velavance=75;
	a(-2);
	verificasonar_d(20);
	giroderecha();
	verificasonar_t(15);
	a(2);
	a(2);
	a(2);
	giroizquierda();
	a(2);
}

void recorrido_regreso()
{
	giroderecha();
	a(2);
	a(2);
	a(2);
	verificasonar_d(20);
	giroizquierda();
	verificasonar_t(15);
	velavance=90;
	F(13);
	//resetGyro(S4);
	//grados=0;
	//wait1Msec(500);
	//a(-2);
	verificasonar_d(20);
	giroizquierda();
	verificasonar_t(15);
	a(2);
	a(2);
	a(2);
	giroderecha();
	F(8);
	a(-2);
	a(-2);
	a(-2);
}
