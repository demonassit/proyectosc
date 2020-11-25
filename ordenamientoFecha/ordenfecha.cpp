#include<iostream>
#include<string.h>
#include<conio.h>

#define MAX 50
struct fecha
 {
  char dia[3];
  char mes[3];
  char annio[5];

 };
struct trabajador
 {
  char codigo[9];
  char nombre[MAX];
  char apellido[MAX];
  struct fecha fecnac;

 };
 
 using namespace std;

 void leerpersonal(int,struct trabajador[]) ;
 void ordenaxfecha(int,struct trabajador[]) ;
 void listado(int,struct trabajador[]) ;
 int bBinariafecha(int,struct trabajador[],struct fecha) ;
int main(void)
 {int n,pos ;
struct fecha f;                                                                               
struct trabajador x[MAX] ;
 
 cout<<"Ingresa el numero de trabajadores:" ;cin>>n ;
 leerpersonal(n,x) ;
 ordenaxfecha(n,x) ;
 listado(n,x) ;
 cout<<"Ingresa la fecha a buscar: "<<endl ;
 cout<<"Ingresa el dia:" ;cin>>f.dia ;
 cout<<"Ingresa el mes:" ;cin>>f.mes ;
 cout<<"Ingresa el mes:" ;cin>>f.annio ;
 pos=bBinariafecha(n,x,f) ;
 if(pos==-1)cout<<"no se encuentra";
 else cout<<"lo encontre en la posicion numero"<<pos;

 getch();
 }


 void leerpersonal(int n,struct trabajador x[])
 {for(int i=0;i<n;i++)
 {cout<<"Ingresa el codigo:";cin>>x[i].codigo;
 cout<<"Ingresa el apellido:";cin>>x[i].apellido;
 cout<<"Ingresa el nombre:";cin>>x[i].nombre;
 cout<<"Ingresa el dia nacimiento:";cin>>x[i].fecnac.dia;
 cout<<"Ingresa el mes nacimiento:";cin>>x[i].fecnac.mes;
 cout<<"Ingresa el annio nacimiento:";cin>>x[i].fecnac.annio;
 cout<<endl;
 }
}
 void ordenaxfecha(int n,struct trabajador x[])
 {struct trabajador temp;
 char f1[9],f2[9];
 for(int i=1;i<n;i++)
 for(int j=n-1;j>=1;j--)
 {strcpy(f1,"");strcpy(f2,"");
 strcat(f1,x[j-1].fecnac.annio);
 strcat(f1,x[j-1].fecnac.mes);
 strcat(f1,x[j-1].fecnac.dia);
 strcat(f2,x[j].fecnac.annio);
 strcat(f2,x[j].fecnac.mes);
 strcat(f2,x[j].fecnac.dia);
if(strcmp(f1,f2)>0)
{temp=x[j-1];
x[j-1]=x[j];
x[j]=temp;

}
}
}
void listado(int n,struct trabajador x[])
{cout<<endl<<"listado de empleados.-"<<endl;
for(int i=0;i<n;i++)
cout<<x[i].codigo<<"\t"<<x[i].apellido<<"\t"
<<x[i].nombre<<"\t"<<x[i].fecnac.dia
<<"/"<<x[i].fecnac.mes<<"/"<<x[i].fecnac.annio
<<endl;
cout<<endl;
}
int bBinariafecha(int n,struct trabajador x[],struct fecha f)
{char f1[9],f2[9];
int izq=0,der=n-1,mitad;
while(izq<=der)
{mitad=(izq+der)/2;
strcpy(f1,"");strcpy(f2,"");
strcat(f1,f.annio);
strcat(f1,f.mes);
strcat(f1,f.dia);
strcat(f2,x[mitad].fecnac.annio);
strcat(f2,x[mitad].fecnac.mes);
strcat(f2,x[mitad].fecnac.dia);
if(strcmp(f1,f2)>0)izq=mitad+1;
else if(strcmp(f1,f2)<0)der=mitad-1;
else return mitad;
}
return -1;
}

