#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

bool buscar(int A[4][12], int pos)
{
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<12; j++)
        {
            if(A[i][j]==pos)
            {
              return true;
            }
        }
    }
    return false;
}

void mostrar(int A[4][12])
{
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<12; j++)
        {
            cout<<A[i][j]<<setw(3);
        }
        cout<<"\n";
    }
}
int main()
{
    int mazo[4][12] = {0};
    srand(time(0));
    int posicion = rand()%52 + 1;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<12; j++)
        {
            while(buscar(mazo,posicion))
            {
                posicion = rand()%52 + 1;
            }
            mazo[i][j] = posicion;
        }
    }

    mostrar(mazo);
    return 0;
}
