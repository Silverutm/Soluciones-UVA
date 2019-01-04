int x=2, y=10, dir=2; 				//coordenas de robot
int dt=15, dd=23, dpd=25, dpt=18;	//distancia a paredes delantera, trase pared
int p2=0, p4=0, p6=0;				//paredes activas
int coordenada=0;					//empezar a actualizar coordenadas



//como cambiara la coordenada cuando avance segun su direccion
int fx[]={0, 0,1,0,0,0,-1,0,0};
int fy[]={-1,0,0,0,1,0, 0,0,0};



//cada que avanze/gire actualiza sus coordenadas
void ava()
{
	if (coordenada==0) return;
	x+=fx[dir];
	y+=fy[dir];
}

//cuando haga giros

//para saber hacia donde tiene que ajustarse
