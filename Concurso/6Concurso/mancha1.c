#pragma config(Sensor, S4,     Gyro,           sensorEV3_Gyro, modeEV3Gyro_Angle)
#pragma config(Sensor, S2,     sonar_trasero,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S1,     sonar_d_izquierdo,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S3, 		 sonar_d_derecho, 				 sensorEV3_Ultrasonic)
//#pragma config(Sensor, S3,    Gyro2 , sensorEV3_Gyro, modeEV3Gyro_Angle)

#include <libreriamatriz.h>
#include <sek.h>
#include <inicio_por_derecha.h>


task main()
{
	setBlockBackButton(true);
	setSoundVolume(70);
	playSoundFile("Dog bark 1");
	startTask(boton_cierra);
	wait1Msec(1500);
	resetGyro(S4);
	wait1Msec(1500);
	startTask(sensorGyro);
	inicio_recorrido();
a(2);///////////////////////////////////////////


coordenada=1;

F(2);
giroizquierda();
F(4);
giroderecha();
F(9);
giroderecha();
F(4);
giroizquierda();
F(1);
giroizquierda();
F(6);
giroizquierda();
F(13);
giroizquierda();
F(6);
giroderecha();
//F(1);

coordenada=0;
F(6);
	//Termina modulo
recorrido_regreso();
	stopTask(sensorGyro);
}
