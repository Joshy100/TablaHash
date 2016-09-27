#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include <string>

using namespace std;

#define MAX 5

struct Hash{
	string info;
   int llave;
   int redirec;
};

Hash T[MAX];
int x=1;
int tam=0;
int insertado=0;
string dato;
char *dato1;
char *dato2;
int pos=0;
int posA=0;
int posAA=0;
int valor=0;

void initTabla(){

    for(int i=0; i<MAX; i++)
    {
        T[i].info="";
        T[i].llave= -1;
        T[i].redirec= -1;
    }
}

int Hash(string dato)
{
    valor=0;

    for(int i=0; i<dato.length();i++)
    {
        valor=valor+(int)(dato[i]);
    }
   return (valor%(MAX-1));
}

void ingresarHash(string dato)
{
    pos=0;
    posA=0;
    pos = Hash(dato);
    // posA=pos;
    if(pos < MAX)
    {
    if(T[pos].llave== -1)
    {
        T[pos].info=dato;
        T[pos].llave=pos;
        return;
    }
     else
    {
        while(!insertado)
        {
            if(T[pos].llave==-1)
            {
                T[pos].info=dato;
                T[pos].llave=pos;
                T[posA].redirec=pos;
                return;
            }
            if(pos==4)
            {
                posA=pos;
                pos=0;
                while (!insertado)
                {
                    if(T[pos].llave==-1)
                    {
                        T[pos].info=dato;
                        T[pos].llave=pos;
                        T[posA].redirec=pos;
                        return;
                    }else
                    {
                        T[posA].redirec=pos;
                        posA=pos;
                        pos++;
                    //T[posA].redirec=pos;
                    }
                }
            }
            posA=pos;
            pos++;
            T[posA].redirec=pos;
         }
    }
    }
    else
    {
        cout<<"Tabla Llena"<<endl;
        return;
    }
}

void buscarHash(string dato){

}

void mostrar(){

	for(int i=0; i<MAX; i++){
      cout<<"[ "<<T[i].llave<<" ]";
      cout<<"[  "; cout<<T[i].info; cout<<"  ]";
      cout<<"[ "<<T[i].redirec<<" ]";
      cout<<endl;
   }
}

int main(){
    initTabla();
    /*while(x!=4)
    {
        cout<<"--------------TABLA DE HASH----------------"<<endl;
        cout<<"ingrese dato: "<<endl;
        cin>>dato;
        ingresarHash(dato);
        cout<<endl<<endl;
        mostrar();
  }*/
    cout<<"ingrese dato: "<<endl;
    cin>>dato;
    ingresarHash(dato);
    system("PAUSE");
    system("cls");
    main();
  return 0;

}

