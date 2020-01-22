#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

char *palos[4] = {"Corazon", "Trebol","Espada","Diamante"};
char *valor[13] = {"As", "Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Jack","Reina", "Rey"};

bool buscar(int A[4][13], int pos)
{
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<13; j++)
        {
            if(A[i][j]==pos)
            {
              return true;
            }
        }
    }
    return false;
}

void barajar(int mazo[4][13])
{
    srand(time(0));
    int posicion = rand()%52 + 1;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<13; j++)
        {
            while(buscar(mazo,posicion))
            {
                posicion = rand()%52 + 1;
            }
            mazo[i][j] = posicion;
        }
    }
}

void mostrar(int A[4][13])
{
    cout<<setw(12);
    for(int k = 0; k<13; k++)
    {
        cout<<valor[k]<<setw(6);
    }
    cout<<"\n";
    for(int i = 0; i<4; i++)
    {
        cout<<palos[i]<<setw(5);
        for(int j = 0; j<13; j++)
        {
            cout<<A[i][j]<<setw(6);
        }
        cout<<"\n";
    }
}

void repartir(int A[4][13])
{
    int numJugadores;
    int numCartas;
    int posCarta = 1;
    cout<<"Ingrese cantidad de jugadores \n";
    cin>>numJugadores;
    cout<<"Ingrese cantidad de cartas \n";
    cin>>numCartas;
    for(int i = 0; i<numJugadores; i++)
    {
        cout<<"\n Cartas jugador "<<i+1<<"\n";
        for(int j = 0; j<numCartas; j++)
        {

            for(int k = 0; k<4; k++)
            {
                for(int p = 0; p<13; p++)
                {
                    if(A[k][p]==posCarta)
                    {
                        cout<<valor[p]<<"       "<<palos[k]<<"\n";
                        k = 5;
                        break;
                    }
                }
            }
            posCarta++;
        }
    }



}
int main()
{
    int mazo[4][13] = {0};
    barajar(mazo);
    mostrar(mazo);
    repartir(mazo);
    return 0;
}
