#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//declaro las funciones que utilizaré
void ingresar_datos();
void eliminar_datos();
void modificar_datos();
void mp();

//llamo al menú principal
int main(){
	mp();
}
//menú principal
void mp(){
	int op;
	
	do {
		system("CLS");
		cout<<"-------------------"<<"\n";
		cout<<"Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<"1 - Ingresar Datos "<<"\n";
		cout<<"2 - Eliminar"<<"\n";
		cout<<"3 - Modificar"<<"\n";
		cout<<"4 - Salir"<<"\n";
		cout<<"-------------------\n";
		cout<<"Seleccione su opcion: ";
		cin>>op;
		if (op==1)
			ingresar_datos();
		else if (op==2) 	
			eliminar_datos();
		else if (op==3)
			modificar_datos();			
		else if (op==4)
			break;
		else 
			break;
		
	} while(op!=4);	
}
//ingreso de datos
void ingresar_datos(){
	int n;
	int modelo;
	int cantidad;
	int model1=0, model2=0, model4=0;	//modelo 1,modelo 2,modelo 4,
	float model3=0; //modelo 3
	int contm1=0,contm2=0,contm3=0,contm4=0;	//conteo de modelo 1, de modelo 2, de modelo 3, de modelo 4	
	string s;
	
	for(n=1; n<31;n++){
//modelo de cuaderno
		cout<<"\n-----------------------El programa le mostrara su reporte cada vez que ingrese una venta--------------------------"<<endl;
		//cout<<"--Digite el numero del modelo de cuaderno--"<<endl;
		cout<<"Modelo #1 = Q10.00"<<endl;
		cout<<"Modelo #2 = Q15.00"<<endl;
		cout<<"Modelo #3 = Q18.50"<<endl;
        cout<<"Modelo #4 = Q25.00"<<endl;
        cout<<"Ingrese el numero del modelo de cuaderno que desea: ";
        cin>>modelo;
//cantidad 
        cout<<"\nDigite la cantidad de unidades: ";
        cin>>cantidad;
//calculo para la cantidad recaudada por modelo y suma total para ver cual fue el mas vendido 
        if(modelo==1){
        	model1=model1+(cantidad*10);	
        	contm1=contm1+1;
        }
        if(modelo==2){
        	model2=model2+(cantidad*15);
			contm2=contm2+1;	
        }
        if(modelo==3){
        	model3=model3+(cantidad*18.50);	
        	contm3=contm3+1;
        }
        if(modelo==4){
        	model4=model4+(cantidad*25);	
        	contm4=contm4+1;
        }      
//agregar y leer archivo
	cout<<"\n-----------------------------------Su pedido fue-------------------------------"<<endl;
	cout<<"DIA: "<<n<<"\n"<<"MODELO: "<<modelo<<"\n"<<"CANTIDAD: "<<cantidad<<"\n";
	ofstream grabararchivo;
	try {
		grabararchivo.open("planillamodelo.txt",ios::app);
		grabararchivo<<n<<"\t"<<modelo<<"\t"<<cantidad<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
//suma total de ventas 
	cout<<"\n"<<"---------------------------Ventas Actuales-------------------------------"<<endl;
	cout<<"DIA//MODELO//CANTIDAD"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("planillamodelo.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}          
//recaudacion por cada modelo
	cout<<"\n---------------------------Total recaudado por cada modelo----------------------------"<<endl;
	cout<<"\nMODELO 1//MODELO 2//MODELO 3//MODELO 4"<<endl;
	cout<<"Q"<<model1<<"\t"<<"\t"<<"Q"<<model2<<"\t"<<"Q"<<model3<<"\t"<<"Q"<<model4<<endl;
//modelo mas vendido 
	cout<<"\n------------------------------Modelo mas vendido--------------------------------------"<<endl;
	if(contm1 > contm2 && contm1 > contm3 && contm1 > contm4){
       	cout<<"El mas vendido fue el modelo 1 "<<endl;
    }
	else if(contm2 > contm1 && contm2 > contm3 && contm2 > contm4){
		cout<<"El mas vendido fue el modelo 2 "<<endl;
    }
	else if(contm3 > contm1 && contm3 > contm2 && contm3 > contm4){
		cout<<"El mas vendido fue el modelo 3 "<<endl;
    }
	else{
		cout<<"El mas vendido fue el modelo 4 "<<endl;
	}
}
}
//eliminar datos
void eliminar_datos(){
	ifstream db_g; //archivo anterior
	ofstream db_e; //archivo nuevo
	int aux,n,modelo,cantidad,flag;
	remove("Temp.txt");
	
	db_g.open("planillamodelo.txt",ios::in);
	db_e.open("Temp.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_g>>n>>modelo>>cantidad){
		if(aux==n){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=n)
			db_e<<n<<"\t"<<modelo<<"\t"<<cantidad<<endl;
		//aux=0;
		//oid=0;					
	}
	db_g.close();
	db_e.close();
	
	if (flag==1){
		remove("planillamodelo.txt");
		rename("Temp.txt","planillamodelo.txt");
	}	
	system("Pause");
}
//modificar datos
void modificar_datos(){
	ifstream db_g; //archivo anterior
	ofstream db_e; //archivo nuevo
	int n,modelo,cant_e,cant_g,flag,aux; 
	char resp;//respuesta
	remove("Temp.txt");
	
	db_g.open("planillamodelo.txt",ios::in);
	db_e.open("Temp.txt",ios::app);
	
	cout<<"Ingrese ID al que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese la cantidad de unidades a modificar: "<<endl;
		cin>>cant_e; //modifico cantidad nueva
		cout<<"\n\nEsta Seguro? S/N: ";
		cin>>resp;
		cout<<"\n"<<endl;
		resp = toupper(resp);		
	} while (resp!='S');	
	
	//leer archivo anterior
	while (db_g>>n>>modelo>>cant_g){ //recorre el archivo sin modificar
		if(aux==n){
			db_e<<n<<"\t"<<modelo<<"\t"<<cant_e<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=n)
			db_e<<n<<"\t"<<modelo<<"\t"<<cant_g<<endl;
		//aux=0;
		//oid=0;					
	}
	db_g.close();
	db_e.close();
	
	if (flag==1){
		remove("planillamodelo.txt");
		rename("Temp.txt","planillamodelo.txt");
	}	
	system("Pause");
}
