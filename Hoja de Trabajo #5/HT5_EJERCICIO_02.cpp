/*EJERCICIO#2
Realice un programa que, dado el peso, la altura, la edad y el género (M/F) de un grupo de N personas
que pertenecen a un departamento de la república, obtenga un promedio de peso, altura y edad de esta
población. Los datos deben guardarse de forma ordenada por edad en un archivo de datos. Así mismo
el programa debe ser capaz leer los datos del archivo y generar un reporte con la media del peso, altura
y la edad*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
//creo mi estructura
struct pobladores{
	float peso;
	float altura;
	int edad;
	int genero;
};
//declaro las funciones que utilizaré
void datos();
void reporte(); 
int main(){
	datos();
	reporte();
}
//esta función la utilizaré para ingresar datos
void datos(){
	float peso;
	float altura;
	int edad;
	int genero;
	//float suma=0, sum=0, sm=0, t=0, total=0;
	//float calp, calce, caal;
	//int calculo;
	//float promedio;
	string n;
	cout<<"--------------------------Pobladores--------------------------"<<endl;
	cout<<"Ingrese '1' si es genero femenino o '2' si es genero masculino: "<<endl;
	cin>>genero;
	if (genero==1){
		cout<<"El genero es femenino"<<endl;
	}
	else if (genero==2){
		cout<<"El genero es masculino"<<endl;	
	}
	else{
		cout<<"Error"<<endl;
	}
	cout<<"Ingrese su peso en libras: "<<endl;
	cin>>peso;
	cout<<"Ingrese su edad: "<<endl;
	cin>>edad;
	cout<<"Ingrese su altura en centimetros: "<<endl;
	cin>>altura;
	
	/*if (genero>0){
		calculo=peso+edad+altura;
		promedio=calculo/3;
		cout<<"El promedio entre peso, edad y altura es: "<<promedio<<endl;
	}*/
	/*if (genero<=2){
		cg=1;
		suma+=cg;
		cout<<"El numero de personas ingresadas es: "<<suma<<endl;
	}*/

	cout<<"Genero: "<<genero<<"\t"<<"Peso: "<<peso<<"\t"<<"Edad: "<<edad<<"\t"<<"Altura: "<<altura<<endl;
	//grabar archivo
	ofstream grabaarchivo;
	try {
		grabaarchivo.open("HT5_Ejercicio_02.txt", ios::app);
		grabaarchivo<<genero<<"\t"<<peso<<"\t"<<edad<<"\t"<<altura<<endl;
		grabaarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	cout<<"\n"<<"-------Pobladores actuales-------"<<endl;
	cout<<"Genero  Peso   Edad   Altura"<<endl;
	//leer archivo
	ifstream leerarchivo;
	try {
		leerarchivo.open("HT5_Ejercicio_02.txt",ios::in);				
		while (getline(leerarchivo, n))
			cout<<n<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
}

//leer archivo
void reporte(){
	ifstream poblador;
	int gen, ed; //genero, edad
	//int ciclos = 0;
	std::vector< int > edades; 
	float ps, alt; //peso, altura
	float promep, promee,promea; //promedio peso, promedio edad, promedio altura
	float suma=0,cont=0, sum=0, sume=0, sumaa=0; //suma, contador, suma peso, suma edad, suma altura.	
	//float s;
	try{
			poblador.open("HT5_Ejercicio_02.txt",ios::in);
		
		while(poblador>>gen>>ps>>ed>>alt){
			suma+=1;
			if (gen>0)
			gen+=suma;
			
			if (ps>=0){
		 		cont=ps;
				sum+=ps;
				promep=sum/suma;
			 }
			if (ed>=0){
				cont=ed;
				sume+=ed;
				promee=sume/suma;	
			}
			if (alt>=0){
				cont=alt;
				sumaa+=alt;
				promea=sumaa/suma;
			}
			edades.push_back(ed);
	   	}
		/*while(poblador>>gen>>ps>>ed>>alt){
			sum=ps+sum;
			if(ps>=0)
			pst+=ps;
		}*/
		//ordenamiento de edades
		for(int i=0;i<suma;i++){
			for (int j=0;j<suma;j++){
				if(edades[i]<edades[j]){
		        	int temp = edades[i];
		            edades[i]=edades[j];
		            edades[j] = temp;
		        }
		    }
			//ciclos++;
		}
		
		poblador.close();
		//mostrar No. personas y promedio
		cout<<setprecision(10)<<"No. de personas es: "<<suma<<endl;
		//cout<<setprecision(10)<<"Suma de todos los pesos: "<<pesoacum<<endl;
		cout<<setprecision(10)<<"Promedio de peso: "<<promep<<endl;
		cout<<setprecision(10)<<"Promedio de edad: "<<promee<<endl;
		cout<<setprecision(10)<<"Promedio de altura: "<<promea<<endl;
		cout<<setprecision(10)<<"Edades ordenadas:"<<endl;
		for(int i=0;i<suma;i++){
      		cout<<setprecision(10)<<edades[i]<<endl;
		}
		
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
		
		
 }



