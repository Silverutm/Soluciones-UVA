bool no_en_rango(short x, short a, short b)
{  return x < a or x > b;  }

short n, i, dos, suma, j;
char int_a_char[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char ultimo_char;
bool no_es_algoritmo_00()
{
	//tiene un digito verificador, es numerica
	if ( no_en_rango(s.size(),2,20) )
		return true;

	n = s.size() - 2;		//el -1 es verificador
	dos  = 2;
	suma = 0;
	for (i = n; i >= 0; --i)
	{
		suma += Tabla_00_Convertir_dig[ dos ][ s[i] ];
		dos = (dos == 2) ? 1:2;
	}

	suma = Tabla_00_Dif_decena[suma];

	return int_a_char[suma] != ultimo_char;

}



bool no_es_algoritmo_02()
{
	//tiene un digito verificador, es alfa numerica
	//va de 6 a 19 fecha
	if ( no_en_rango(s.size(),7,20) )
		return true;	
	for ( i = 0; i < 6; ++i)
		if( not isdigit( s[i] ) )
			return true;

	n = s.size() - 2;
	dos  = 2;
	suma = 0;
	for (i = n; i >= 0; --i)
	{
		suma += Tabla_00_Convertir_dig[ dos ][ Tabla_02_letra_a_numero[ s[i] ] ];
		dos = (dos == 2) ? 1:2;
	}

	suma = Tabla_00_Dif_decena[suma];

	return int_a_char[suma] != ultimo_char;

}

short m;
bool no_es_algoritmo_03()
{
	//tiene un digito verificador, es numerica
	//va de 1 a 19 fecha
	if ( no_en_rango(s.size(),2,20) )
		return true;	

	m = min( 6, (int)s.size()-1 );
	n = s.size()-2;	
	m = n-m+1;
	suma = 0;
	j =2;
	for (i = n; i >= m; --i, ++j)	
		suma += Tabla_03_de_multiplicar[ s[i] ][ j ];			

	suma = Tabla_03_de_residuo[suma];

	return int_a_char[suma] != ultimo_char;

}

short arr_04[] = {13, 17, 19, 23, 11};
short sig_j()
{
	if ( j&4 )  j =0;
	else ++j;
}
bool no_es_algoritmo_04()
{
	//tiene dos digitos verificadores, es numerica
	//va de 1 a 19 fecha
	if ( no_en_rango(s.size(),3,20) )
		return true;	
	
	n = (int)s.size() - 4;			//ignorar el ultimo
	//if (n==0) return true;		///////////////////
	suma = 0;
	j =0;
	for (i = n; i >= 0; --i )	
	{
		suma += Tabla_03_de_multiplicar[ s[i] ][ arr_04[j] ];
		sig_j();
	}

	suma = Tabla_04_de_residuo[suma];

	return int_a_char[ decena_04[suma] ] != s[ s.size()-2 ] or int_a_char[ decimal_04[suma] ] != ultimo_char;

}

short arr_06[] = {37, 31, 29, 23, 19, 17, 13, 11};
short sig_j_06()
{
	if (j == 7)  j =0;
	else ++j;
}
bool no_es_algoritmo_06()
{
	//tiene dos digitos verificadores, es numerica
	//va de 1 a 19 fecha
	if ( no_en_rango(s.size(),3,20) )
		return true;	
	

	n = s.size( ) - 3;
	m = min( 8, (int)s.size()-2 );

	m = n - m +1;


	suma = val_06;
	j =0;
	for (i = n; i >= m; --i )	
	{
		suma += Tabla_03_de_multiplicar[ s[i] ][ arr_06[j] ];
		sig_j_06();
	}

	suma = Tabla_06_residuo[suma];

	return int_a_char[ decena_04[suma] ] != s[ s.size()-2 ] or int_a_char[ decimal_04[suma] ] != ultimo_char;

}

short arr_35[] = {4,3,8};
short sig_j_35()
{
	if (j&2)  j =0;
	else ++j;
}
bool no_es_algoritmo_35()
{
	//tiene un digito verificador, es lafanumerica
	//va de 1 a 19 fecha
	if ( no_en_rango(s.size(),2,20) )
		return true;	
	

	n = s.size( ) - 2;


	suma = 0;
	j =0;
	for (i = 0; i <= n; ++i )	
	{
		suma += Tabla_35_de_multiplicar[ Tabla_35_letra_a_numero[s[i]] ][ arr_35[j] ];
		sig_j_35();
	}

	suma = Tabla_00_Dif_decena[suma];

	return int_a_char[ suma ] != ultimo_char ;

}



bool no_es_algoritmo_36()
{
	//tiene un digito verificador, es lafanumerica
	//va de 1 a 19 fecha
	if ( no_en_rango(s.size(),2,20) )
		return true;

	n = s.size() - 2;
	dos  = 2;
	suma = 0;
	for (i = n; i >= 0; --i)
	{
		suma += Tabla_00_Convertir_dig[ dos ][ Tabla_02_letra_a_numero[ s[i] ] ];
		dos = (dos == 2) ? 1:2;
	}

	suma = Tabla_00_Dif_decena[suma];

	return int_a_char[suma] != ultimo_char;

}




short arr_37[] = {13, 17, 19, 23, 11};
short sig_j_37()
{
	if (j&4)  j =0;
	else ++j;
}
bool no_es_algoritmo_37()
{
	//tiene dos digitos verificadores, es numerica
	//va de 1 a 19 fecha
	if ( no_en_rango(s.size(),3,20) )
		return true;	
	
	n = (int)s.size() - 4;		//ignorar el utlimo
	//if (n==0) return true;	////////////////////////////////
	suma = 0;
	j =0;
	for (i = n; i >= 0; --i )	
	{
		suma += Tabla_03_de_multiplicar[ Tabla_02_letra_a_numero[ s[i] ]  ][ arr_37[j] ];
		sig_j_37();
	}
	suma = Tabla_04_de_residuo[suma];

	return int_a_char[ decena_04[suma] ] != s[ s.size()-2 ] or int_a_char[ decimal_04[suma] ] != ultimo_char;

}