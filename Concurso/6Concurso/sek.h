#pragma config(Sensor, S4,     Gyro,           sensorEV3_Gyro, modeEV3Gyro_Angle)
#pragma config(Sensor, S2,     sonar_trasero,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S1,     sonar_d_izquierdo,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S3, 		 sonar_d_derecho, 				 sensorEV3_Ultrasonic)
//#pragma config (Sensor, S3, Gyro2, sensorEV3_Gyro, modeEV3Gyro_Angle)


#define I motorD
#define D motorA
//#define I motorB
//#define D motorC



int grados=0, enc=637, encodergd=915, encodergi=920, velgd=60, velgi=60, velavance=75, velaj=10, direccion=0,e=1;
//int grados=0,enc=1075, encodergd=1720, encodergi=1730, velgd=30, velgi=30, velavance=100, velaj=30, direccion=0,e=2;

float vsensor=0, sensor_d=0;

bool h1=true;
bool tt =true;


/*
enc					 encoder necesario para avanzar
encodergd		 encoder necesario para girar a la derecha
encodergi		 encoder necesario para girar a la izquierda
velgd				 velocidad de giro a la derecha
velgi				 velocidad de giro a la izquierda
velavance		 velocidad de avance
velaj				 velocidad de ajuste
direccion		 valor del sensor gyro durante la ejecucion
e						 rango de error para el ajuste con el sonar
vsensor 		 valor del sonar durante la ejecucion
vs1 				 valor objetivo para el ajuste del sonar
h1 					 booleano que comprueba si esta en el rango permitido en los ajustes del avance
tt					 booleano que comprueba si esta en el rango permitido en los giros


*/

//Tarea para contar el tiempo de "atasco" en los giros



task ttajuste()
{
	wait1Msec(3000);
	wait1Msec(3000);
	tt=false;
}

//Tarea cuenta tiempo de atasco en avances



task tiempoajuste()
{
	wait1Msec(3000);
	wait1Msec(3000);
	h1=false;
}

//Tarea del sensor de Gyro
task sensorGyro()
{
	while (true)
	{
		direccion=(SensorValue[S4]);
		//displayCenteredBigTextLine(1,"sensor %d",direccion);
		//displayCenteredBigTextLine(4,"grados %d",grados);
	}

}


//Tarea del sonar trasero
task sonar_t()
{
	while(true)
	{
		vsensor=SensorValue[sonar_trasero];
		displayCenteredBigTextLine(7,"sonar trasero %f", vsensor);
	}

}

task sonar_d()
{
	while(true)
	{
		sensor_d=SensorValue[sonar_d_izquierdo];
		displayCenteredBigTextLine(10,"sonar delantero %f", sensor_d);

	}
}


task boton_cierra(){
	while(true)
	{
		if (getButtonPress(buttonLeft)) stopAllTasks();
	}
}


void ajustaavance()
{
	startTask(tiempoajuste);
	motor[D]=0;
	motor[I]=0;
	wait1Msec(100);
	while(direccion!=grados && h1)
	{
		wait1Msec(1000);
		if(direccion<grados)
			{
				motor[D]=-velaj;
				while(direccion<grados&& h1){}
				motor[D]=0;
				setLEDColor(ledRed);
			}
		else
			{
				motor[I]=-velaj;
				while(direccion>grados&& h1){}
				motor[I]=0;
				setLEDColor(ledRed);
			}
	}
	stopTask(tiempoajuste);
	if (h1==false)
	{
		h1=true;
		motor[I]=motor[D]=-10;
		wait1Msec(3000);
		ajustaavance();
	}
	h1=true;
}


void ajustaavance_especial()
{
	startTask(tiempoajuste);
	motor[D]=0;
	motor[I]=0;
	wait1Msec(100);
	while(direccion!=grados && h1)
		{
			wait1Msec(500);
			if(direccion<grados)
			{
				motor[D]=-25;
				while(direccion<grados&& h1){}
				motor[D]=0;
				setLEDColor(ledRed);
			}
			else if(direccion>grados)
			{
				motor[I]=-25;
				while(direccion>grados&& h1){}
				motor[D]=0;
				setLEDColor(ledRed);
			}
		}
	stopTask(tiempoajuste);
	if (h1==false)
	{
		h1=true;
			motor[I]=-20;
			motor[D]=-20;
			wait1Msec(4000);
		if(direccion>grados)
		{
			motor[I]=-30;
			motor[D]=0;
			while(direccion!=grados +1){}
			motor[I]=0;
			nMotorEncoder[D]=0;
			nMotorEncoder[I]=0;
			motor[I]=55;
			motor[D]=55;
			while((nMotorEncoder[D]<enc) && (nMotorEncoder[I]<enc)){}
			nMotorEncoder[D]=0;
			nMotorEncoder[I]=0;
		}
		else
		{
			motor[D]=-30;
			motor[I]=0;
			while(direccion!=grados -1){}
			motor[D]=0;
			nMotorEncoder[D]=0;
			nMotorEncoder[I]=0;
			motor[I]=55;
			motor[D]=55;
			while((nMotorEncoder[D]<enc) && (nMotorEncoder[I]<enc)){}
			nMotorEncoder[D]=0;
			nMotorEncoder[I]=0;
		}
		ajustaavance_especial();
	}
	h1=true;
}


void verificasonar_d (float vsd)
{
	startTask(sonar_d);
	playSoundFile("Forward");
	while( sensor_d != vsd)
	{
		wait1Msec( 500 );
		if(sensor_d<vsd)
		{
			motor[I] =- velaj;
			motor[D] =- velaj;
			while(sensor_d<vsd) ;

		}
		else
		{
			motor[I]=velaj;
			motor[D]=velaj;
			while(sensor_d>vsd) ;
		}
		motor[D]=motor[I]=0;
	}
	ajustaavance();
	ajustaavance();
	stopTask(sonar_d);
}

void verificasonar_t(float vsd)
{
	startTask(sonar_t);
	playSoundFile("Backing alert");
	while( vsensor!= vsd )
	{
		setLEDColor(ledRed);
		wait1Msec(500); //estaba en 1000
		if(vsensor<vsd)
		{
			setLEDColor(ledGreen);
			motor[I]=motor[D]=velaj;
			while( vsensor<(vsd) ) ;
		}
		else
		{
			setLEDColor(ledOrange);
			motor[I] = motor[D] = -velaj;
			while( vsensor>(vsd) ) ;
		}
		motor[I]=0;
		motor[D]=0;
	}
	ajustaavance();
	ajustaavance();
	stopTask(sonar_t);
}



void choques()
{
	//ajuste con las traseras

	if ((y==3 && dir==4) || (y==17 && dir==0)|| (x==3 && dir==2) || (x==17 && dir==6))
		verificasonar_t(dt);
	if (p2 && y<=7)
	{
		if (( x==7 && dir==6 ) || (x==13 && dir==2))
			verificasonar_t(dpt);
	}
	if (p4 && x>=13)
	{
		if (( y==7 && dir==0 ) || (y==13 && dir==4))
			verificasonar_t(dpt);
	}
	if (p6 && y>=13)
	{
		if (( x==7 && dir==6 ) || (x==13 && dir==2))
			verificasonar_t(dpt);
	}


	//ajuste con paredes delanteras
	if ((y==4 && dir==0) || (y==16 && dir==4)|| (x==4 && dir==6) || (x==16 && dir==2))
		verificasonar_d(dd);
	if (p2 && y<=7)
	{
		if (( x==6 && dir==2 ) || (x==14 && dir==6))
			verificasonar_d(dpd);
	}
	if (p4 && x>=13)
	{
		if (( y==6 && dir==4 ) || (y==14 && dir==0))
			verificasonar_d(dpd);
	}
	if (p6 && y>=13)
	{
		if (( x==6 && dir==2 ) || (x==14 && dir==6))
			verificasonar_d(dpd);
	}
}


void der() {  if (coordenada==0) return; ava(); dir= (dir+2)%8; choques();}
void izq() { if (coordenada==0) return; ava(); dir= (dir+6)%8; choques(); }


void giroderecha(){
	choques();
	grados+=90;
	//motor[D]=0;
	nMotorEncoder[I]=0;
	motor[I]=velgd;
	while(nMotorEncoder[I]<encodergd){}
	motor[I]=0;
	wait1Msec(500);
	while(direccion!=grados)
	{
		if(direccion>grados)
		{
			motor[I]=-velaj;
			while(direccion>grados){}
			motor[I]=0;
		}
		else
		{
			motor[I]=velaj;
			tt=true;
			int velajtemp=velaj;
			startTask(ttajuste);
			while(direccion<grados)
			{
				if (tt==false)
				{
					stopTask(ttajuste);
					motor[I]=0;
					motor[I]=-velaj;
					wait1Msec(2000);
					motor[I]=0;
					if(velajtemp<100)
						velajtemp*=2;
					else
						velajtemp=100;
					motor[I]=velajtemp;
					tt=true;
					startTask(ttajuste);
				}
			}
			motor[I]=0;
		}
	}
	ajustaavance();
	ajustaavance();
	playSoundFile("Right");
	der();
}

void giroizquierda()
{
	choques();
	grados-=90;
	nMotorEncoder[D]=0;
	motor[D]=velgi;
	//motor[I]=0; 	/////////////////
	while( nMotorEncoder[D]<encodergi ){}
	motor[D]=0;
	wait1Msec(500);
	while(direccion!=grados)
	{
		if(direccion<grados)
		{
			motor[D]=-velaj;
			while(direccion<grados){}
			motor[D]=0;
			setLEDColor(ledRed);
		}
		else if(direccion>grados)
		{
			motor[D]=velaj;
			tt=true;
			int velajtemp=velaj;
			startTask(ttajuste);
			while(direccion>grados)
			{
				if (tt==false)
				{
					stopTask(ttajuste);
					motor[D]=0;
					motor[D]=-velaj;
					wait1Msec(2000);
					motor[D]=0;
					if(velajtemp<100)
						velajtemp*=2;
					else
						velajtemp=100;
					motor[D]=velajtemp;
					tt=true;
					startTask(ttajuste);
				}
			}
			motor[D]=0;
			setLEDColor(ledRed);
		}
		else
			motor[D]=0;
			setLEDColor(ledRed);
	}
	ajustaavance();
	ajustaavance();
	playSoundFile("Left");
	izq();
}



int cas=0;

void a(float avance){
	int n,n_guarda;
	n=avance;
	if(avance>0)
	{
		if(avance<6)
		{
			resetMotorEncoder(D);
			resetMotorEncoder(I);
			motor[I]=velavance;
			motor[D]=velavance;
			while( (nMotorEncoder[D]<enc*avance) && (nMotorEncoder[I]<enc*avance) ){}
		}
		else
		{
			n=n/3;
			n_guarda=n;
			while(n<=avance){
				nMotorEncoder[D]=0;
				nMotorEncoder[I]=0;
				motor[I]=velavance;
				motor[D]=velavance;
				while((nMotorEncoder[D]<(enc*(n_guarda))) && (nMotorEncoder[I]<(enc*(n_guarda)))){}
				a(-.2);
				ajustaavance();
				ajustaavance();
				a(.2);
				n+=n_guarda;
			}
		}

	}
	else
	{
		nMotorEncoder[D]=0;
		nMotorEncoder[I]=0;
		motor[I]=-velavance;
		motor[D]=-velavance;
		while((nMotorEncoder[D]>enc*avance) && (nMotorEncoder[I]>enc*avance)){}

	}
	motor[I]=0;
	motor[D]=0;

	cas=(cas+1)%3;
	if (cas==0) { ajustaavance(); wait1Msec(300); ajustaavance(); }
	ava();
}

void espera()
{
	int contador=0;
	playSound(soundBeepBeep);
	while (contador<3)
	{
		wait1Msec(2000);
		wait1Msec(2000);
		a(1);
		a(-1);
		contador++;
	}
}


void verifica_salida_sonar()
{
	float distancia_lejana= 100.0;
	while(SensorValue[sonar_d_derecho]<distancia_lejana || SensorValue[sonar_d_izquierdo]<distancia_lejana)
		{
			playSound(soundException);
			if(SensorValue[sonar_d_derecho]<distancia_lejana)
				while(SensorValue[sonar_d_derecho]<distancia_lejana)
				{
					motor[I]=-70;
				}
			if(SensorValue[sonar_d_izquierdo]<distancia_lejana)
				while(SensorValue[sonar_d_izquierdo]<distancia_lejana)
					{
					motor[D]=-70;
					}
	}
	//ajustaavance();
}

void giro_salida_izquierda()
{
	motor[D]=0;
	motor[I]=0;
	while(SensorValue[sonar_d_derecho]<200 || SensorValue[sonar_d_izquierdo]<200)
	{	motor[D]=60;
		displayCenteredBigTextLine(1,"D %d", SensorValue[sonar_d_derecho]);
		displayCenteredBigTextLine(4,"I %d",SensorValue[sonar_d_izquierdo]);
	}
	motor[D]=0;
	motor[I]=0;
	//grados=0;
	//resetGyro(Gyro);


}
