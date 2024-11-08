#include <iostream>

using namespace std;
#include <cstdlib>
#include <ctime>
#include "funcionjugar.h"

/*void srand(time_t);
time_t time(NULL);
int rand ();*/
int main() {
    setlocale(LC_ALL, "spanish"); //Seteo del lenguaje de la consola.
    srand(time(NULL)); //Planto la semilla del random
    const int nrocaras=6, nroparadado=1;
    int dado1 = rand() % nrocaras + nroparadado;
    int dado2 = rand() % nrocaras + nroparadado;
    int dado3 = rand() % nrocaras + nroparadado;

    int opc, turnoInicio, nroronda=0, acugralj1=0, acugralj2=0;
    string nombresJugadores[2];//vector donde guardo nombre de jugadores.
    //string jugador1, jugador2;
    //char confirmanombre;

    cout << "BONZO" << endl;
    cout << "-------------------------" << endl;
    cout << "1 - JUGAR " << endl;
    cout << "2 - ESTADISTICAS " << endl;
    cout << "3 - CREDITOS " << endl;
    cout << "-------------------------" << endl;
    cout << "0 - SALIR " << endl;
    cout << endl;
    cin >> opc;
    switch(opc){
        case 1:
            system ("cls");
            cout << "BONZO" << endl;
            cout <<"------------------------------------" << endl;
            /*cout <<"Antes de comenzar deben registrar sus nombres: " << endl;
            cout <<"¿Nombre j1? " ;
            cin >> jugador1;
            cout << endl;
            cout << "¿Nombre j2? ";
            cin >> jugador2;
            cout << endl;
            cout <<"¿Confirmar nombres? (S/N)" << endl;
            cin >>confirmanombre;*/
            cargarNombres(nombresJugadores);
            cout <<"------------------------------------" << endl;
            /*if(confirmanombre=='S'){
                cout << "Comienza el juego! " << endl;
            } else if (confirmanombre=='N'){
                cout << "Ingrese los nombres de j1 y j2 nuevamente: " << endl;
            }*/
            system ("pause");
            system ("cls");
            turnoInicio = lanzarDado(nrocaras, nroparadado);
            if ((turnoInicio%2)!=0){
                cout << "Salio: " << turnoInicio << endl;
                cout << " Comienza: " << nombresJugadores[0]<< endl;
            }else {
                cout << "Salio: " << turnoInicio << endl;
                cout << " Comienza: " << nombresJugadores[1] << endl;
            }
            system ("pause");
            system ("cls");
            jugarRonda(nrocaras, nroparadado, nombresJugadores, dado1, dado2, dado3, turnoInicio, nroronda, acugralj1, acugralj2);
        break;
        case 2:
            system ("cls");
            system ("pause");
        break;
        case 3:
            cout << "Desarrolladodores de BONZO G20: " << endl;
            cout << "Diego Michel Zaragoza, legajo 26844" << endl;
            system ("cls");
            system ("pause");
        break;
        case 0:
            system ("cls");
            cout << "Saliendo del juego..." << endl;
            system ("pause");
        return 0;
    }
}
