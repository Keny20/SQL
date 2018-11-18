/*Hecho por KENY LISBETH CHAVEZ TORRES
CT18009*/

#include <iostream>
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h> //nos permite la utilizacion de la base de datos
#include <mysqld_error.h>  //llamada de base de datos

using namespace std;

void cliente  () ; //funcion para el contenido de la tabla clientes
void productos () ; //funcion para el contenido de los productos
void cotizacion () ;
void deco (); //funcion para la decoracion

int validacion()
{
	int var ;
	while (cin.fail() )
	{
    	cin.clear() ;
    	cin.ignore(1000, '\n') ;
    	cout << "Has introducido un dato incorrecto, vuelve a intentarlo" << endl ;
	}
	return var ; //retorna el valor de la variable
}

int main() 
{
	//Decoracion de pantalla de inicio
	cout << endl << endl << "\t\t****************||||||||||||||||****************" << endl ;
	cout << "\t\t****************||||||||||||||||****************" << endl ;
	cout << "\t\t                                        " << endl ;
	cout << "\t\t**\tBienvenidos a la comercial SOS\t**" << endl ;
	cout << "\t\t                                        " << endl ;
	cout << "\t\t****************||||||||||||||||****************" << endl ;
	cout << "\t\t****************||||||||||||||||****************" << endl ;
	system ("pause"); //pausa
	deco (); //llamada de funcion

	int menu ; //variable para la seleccion de opcion del menu
	
	/*Aqui declaramos las distintas opciones del menu*/
	cout << "1-Datos de cliente" << endl ;
	cout << "2-Cotizacion" << endl ;
	cout << "3-Productos almacenados en la Base de Datos" << endl ;
	cout << "4-Salir" << endl ;
	
	do 
	{
		
		cin >> menu ; //lectura de variable
		deco (); //llamada de funcion
		switch (menu)
		{
			case 1 :
				//cout << "Codcliente\tNombre\tApellido\tTelefono\tDireccion\t\tCorreo" << endl ;
				system ("color ac") ; //color
				cout << "Datos del cliente " << endl ;
				cliente () ; //llamada de funcion
			break ;
		
			case 2 : 
				/*en esta opcion se muestran las cotizaciones hechas*/
				system ("color 3a") ;
				cout << "COTIZACIONES HECHAS" << endl ;
				cotizacion () ; //llamada de funcion
		
			break ;
	
			case 3 :
				/*Aqui se almacenaran los datos
				nuevos que queremos guardar en la base de datos*/
				system ("color a3") ;
				cout << "PRODUCTOS ALMACENADOS EN LA TABLA PRODUCTOS DE LA BD" << endl ;
				cout << "Javon,$1.50 of" << endl ;
				cout << "Queso, $2.50 lb" << endl ;
				system ("pause") ; //pausa
				deco (); //llamada de funcion
				productos () ;  //llamada de funcion
			
			break ;
			case 4 :
				system ("color a4") ;
				//Opcion para salir
				cout << "Gracias por visitarnos" ;
				return 0 ;
			break ; 
		}
	} while ( menu <= 0 || menu > 4) ;
}

/*Aqui declramos lo que obtendra la funcion 
creada anteriormente, para la 
tabla de los clientes*/
void cliente ()
{
	MYSQL *conn ; 
    MYSQL  mysql ;
    MYSQL_RES *res ;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","pruebita",0,0,0) ; //aqui es la direccion de nuestra base de datos
    
    /*Si no se reconoce la base dedatos
	tenemos una condicional de error*/
    if(conn == NULL) 
    {  cout<<mysql_error(&mysql)<<endl;
       system("pause"); 
    }
    
    /*Aqui declaramos la tabla que queremos seleccionar
	que sera la del cliente*/
    mysql_query(conn,"select * from clientes");
    res=mysql_store_result(conn);
    
    /*dato de tipo while para la 
	muestra de los datos*/
    while( (row = mysql_fetch_row (res) ) != NULL  )
    {
    	cout << "Codcliente\tNombre\tApellido\tTelefono\tDireccion\t\tCorreo" << endl ;
        cout << row [0] << "\t\t" ;
        cout << row [1] << "\t" ;
        cout << row [2] << "\t" ;
        cout << row [3] << "\t" ;
        cout << row [4] << "\t" ;
        cout << row [5] << "\t" << endl ;
        cout << row [6] << endl ;
    }
   
    mysql_close(conn); //se cierra la base de datos
    cout<<"se conecto"<<endl; //mensaje de que si se pudo conectar
    system("pause"); //pausa
	
}

/*Aqui declramos lo que obtendra la funcion 
creada anteriormente, para la 
tabla de los productos
en si esta almacena datos en la 
base de datos*/
void productos ()
{
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","pruebita",0,0,0); //aqui es la direccion de nuestra base de datos
    
    /*Si no se reconoce la base dedatos
	tenemos una condicional de error*/
    if(conn==NULL)
    {  cout<<mysql_error(&mysql)<<endl;
       system("pause");   
    }
    
    /*Aqui declaramos la tabla que queremos seleccionar
	que sera la de los productos
	y asi mismo digitamos los datos que queremos que 
	en nuestra tabla*/
    mysql_query (conn, "INSERT INTO productos VALUES (NULL, 'Javon' , '$1.50 of' )") ;
    mysql_query (conn, "INSERT INTO productos VALUES (NULL, 'Queso' , '$2.50 lb' )") ;
    
    res=mysql_store_result(conn);
    cout << "Datos Guardados con exito!!!!" << endl ;
    
    /*dato de tipo while para la 
	muestra de los datos*/
    while((row=mysql_fetch_row(res))!=NULL)
    {
        cout<<row[0]<<"\t";
        cout<<row[1]<<"\t";
        cout<<row[2]<< "\t" << endl;
        cout<<row[3]<<endl ;
    }
	
    mysql_close(conn); //se cierra la base de datos
    cout<<"se conecto"<<endl; //mensaje de exito de conexion
    system("pause"); //pausa
}

/*Aqui se llama la tabla de cotizacion
para la muestra de sus datos almacenados*/
void cotizacion ()
{
		MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","pruebita",0,0,0); //aqui es la direccion de nuestra base de datos
    
    /*Si no se reconoce la base dedatos
	tenemos una condicional de error*/
    if(conn==NULL)
    {  cout<<mysql_error(&mysql)<<endl;
       system("pause");   
    }
    /*Aqui declaramos la tabla que queremos seleccionar
	que sera la de los productos*/
    mysql_query(conn,"select * from cotizacion");
    res=mysql_store_result(conn);
    
    /*dato de tipo while para la 
	muestra de los datos*/
    while((row=mysql_fetch_row(res))!=NULL)
    {
    	cout << "CodCotiza\tCodcliente\tCodproductos\tFechacotiza" << endl ;
        cout << row [0] << "\t\t" ;
        cout << row [1] << "\t\t\t" ;
        cout << row [2] << "\t"  << endl ;
        cout << row [3] << endl ;
    }
	
    mysql_close(conn); //se cierra la base de datos
    cout<<"se conecto"<<endl; //mensaje de exito de conexion
    system("pause"); //pausa
}

//declaracion de funcion
void deco ()
{
	system ("cls"); //borrar
	cout << "****************||||||||||||||||****************" << endl ;
	
}
