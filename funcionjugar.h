#ifndef FUNCIONJUGAR_H_INCLUDED
#define FUNCIONJUGAR_H_INCLUDED



#endif // FUNCIONJUGAR_H_INCLUDED

int lanzarDado(int nrocaras, int nroparadado, int &nroronda);

void dibujarDado(int valor);

void dibujarDados(int dado1, int dado2, int dado3);

void cargarNombres(string nombres[]);//Funcion que se encargara de solicitar nombres de ambos jugadores.

void jugarRonda (int caras, int paradados, string nombres[], int &dado1, int &dado2, int &dado3, int &turnoInicio,int &nroronda, int &acugralj1, int &acugralj2);

int lanzarDado(int caras, int paradado){
    //srand(time(NULL));
    int numeroAleatorio = rand() % caras + paradado;
    return numeroAleatorio;
}


void dibujarDado(int valor) {
    switch (valor) {
        case 1:
            std::cout << "     \n";
            std::cout << "  X  \n";
            std::cout << "     \n";
            break;
        case 2:
            std::cout << "X    \n";
            std::cout << "     \n";
            std::cout << "    X\n";
            break;
        case 3:
            std::cout << "X    \n";
            std::cout << "  X  \n";
            std::cout << "    X\n";
            break;
        case 4:
            std::cout << "X   X\n";
            std::cout << "     \n";
            std::cout << "X   X\n";
            break;
        case 5:
            std::cout << "X   X\n";
            std::cout << "  X  \n";
            std::cout << "X   X\n";
            break;
        case 6:
            std::cout << "X   X\n";
            std::cout << "X   X\n";
            std::cout << "X   X\n";
            break;
    }
}

void dibujarDados(int dado1, int dado2, int dado3) {
    // Dibuja los tres dados en paralelo línea por línea
    // Le agrego los bordes superiores y laterales a los dados.
    std::cout<<"+-------+  +-------+  +-------+"<<std::endl;
    for (int i = 0; i < 3; ++i) {
            std::cout<<"| ";
        switch (dado1) {
            case 1: std::cout << (i == 1 ? "  X  " : "     "); break;
            case 2: std::cout << (i == 0 ? "X    " : (i == 2 ? "    X" : "     ")); break;
            case 3: std::cout << (i == 0 ? "X    " : (i == 1 ? "  X  " : "    X")); break;
            case 4: std::cout << (i == 0 || i == 2 ? "X   X" : "     "); break;
            case 5: std::cout << (i == 0 || i == 2 ? "X   X" : "  X  "); break;
            case 6: std::cout << "X   X"; break;
        }

        std::cout << " |  | "; // Espacio entre dados

        switch (dado2) {
            case 1: std::cout << (i == 1 ? "  X  " : "     "); break;
            case 2: std::cout << (i == 0 ? "X    " : (i == 2 ? "    X" : "     ")); break;
            case 3: std::cout << (i == 0 ? "X    " : (i == 1 ? "  X  " : "    X")); break;
            case 4: std::cout << (i == 0 || i == 2 ? "X   X" : "     "); break;
            case 5: std::cout << (i == 0 || i == 2 ? "X   X" : "  X  "); break;
            case 6: std::cout << "X   X"; break;
        }

        std::cout << " |  | "; // Espacio entre dados

        switch (dado3) {
            case 1: std::cout << (i == 1 ? "  X  " : "     "); break;
            case 2: std::cout << (i == 0 ? "X    " : (i == 2 ? "    X" : "     ")); break;
            case 3: std::cout << (i == 0 ? "X    " : (i == 1 ? "  X  " : "    X")); break;
            case 4: std::cout << (i == 0 || i == 2 ? "X   X" : "     "); break;
            case 5: std::cout << (i == 0 || i == 2 ? "X   X" : "  X  "); break;
            case 6: std::cout << "X   X"; break;
        }

        std::cout <<" |"<< std::endl;
    }
    std::cout<<"+-------+  +-------+  +-------+"<<std::endl;
}

void cargarNombres(string nombres[]){
    char confirmar='n';
    while (toupper(confirmar)!='S'){
        cout << endl;
        for (int i=0; i<2; i++){
            cout << "Ingrese el nombre del jugador n° "<< i+1 <<": ";
            cin >> nombres[i];
        }
        cout << endl << "Desea confirmar los nombres ingresados? (S/N): ";
        cin >> confirmar;
    }
}

void jugarRonda (int caras, int paradado, string nombres[], int &dado1, int &dado2, int &dado3, int &turnoInicio,int &nroronda, int &acugralj1, int &acugralj2)
{
    string jugActual;
    int puntosRonda, puntosLanzamiento, lanzamientosRonda, contnroprohibido;
    bool usarDosDadosJugador1 = false;
    bool usarDosDadosJugador2 = false;
    bool jugador1Jugo = false, jugador2Jugo = false;

    //nroronda++;
    nroronda = 1;  // Iniciar en la ronda 1
    // Determinar el jugador inicial solo al inicio del juego
    if (nroronda==1){
        if ((turnoInicio%2)!=0){
            jugActual = nombres[0]; // Comienza jugador 1
        }else {
            jugActual = nombres[1]; // Comienza jugador 2
        }
    }

    while (nroronda<=6){
        puntosRonda=0;
        lanzamientosRonda=0;
        char confirmar='s';
        while (toupper(confirmar)!='N'){
            contnroprohibido=0;
            lanzamientosRonda++;
            // Mostrar estado de la ronda
            cout << "BONZO" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << nombres[0] << ": " << acugralj1 << "                " << nombres[1] << ": " << acugralj2 << endl;

            cout << "TURNO DE: " << jugActual << endl;

            cout << "+--------------------------------------------------+" << endl;
            cout << "| RONDA:"<< nroronda <<"                                          |" << endl;
            cout << "| PUNTOS DE LA RONDA: "<< puntosRonda<< "                            |" << endl;
            cout << "| LANZAMIENTOS: " << lanzamientosRonda << "                                  |" << endl;
            cout << "+--------------------------------------------------+" << endl;

            cout << "NUMERO PROHIBIDO: " << nroronda << endl;

            cout << "LANZAMIENTO #" << lanzamientosRonda +1 << endl;

            // Determinar si se lanzan dos o tres dados
            if ((jugActual == nombres[0] && usarDosDadosJugador1) || (jugActual == nombres[1] && usarDosDadosJugador2)) {
                dado1 = rand() % caras + paradado;
                dado2 = rand() % caras + paradado;
                dado3 = 0;  // Lanzar solo dos dados
                cout << "(Lanzando con dos dados debido a penalización)\n";
            } else {
                // Lanzo los tres dados
                dado1 = rand() % caras + paradado;
                dado2 = rand() % caras + paradado;
                dado3 = rand() % caras + paradado;
            }

            // Dibujar dados
            dibujarDados(dado1, dado2, dado3);
            puntosLanzamiento = dado1 + dado2 + dado3;

            // Analizo la cantidad de numeros prohibidos
            if(dado1==nroronda&& dado2 == nroronda && dado3 == nroronda){

                contnroprohibido=3;
                cout << "Salieron los tres dados con el numero prohibido, has perdido el juego!" << endl;
                if(jugActual==nombres[0]){
                acugralj1=0;
                cout<< "El ganador es: " << nombres[0] << endl;
                }else{
                acugralj2=0;
                cout << "El ganador es: " << nombres[1] << endl;
                }
                system("pause");
                return;// Salgo de la funcion para finalizar el juego
            } else if (((dado1==nroronda)&&(dado2==nroronda)) || ((dado1==nroronda) && (dado3==nroronda)) || ((dado2==nroronda) && (dado3==nroronda))){
                contnroprohibido=2;
                puntosRonda=0;
                cout << "Salieron dos dados con numero prohibido, perdiste tus puntos de esta ronda, y en la proxima ronda jugaras solo con dos dados! " << endl;
                if (jugActual == nombres[0]) {
                    usarDosDadosJugador1 = true;
                } else {
                    usarDosDadosJugador2 = true;
                }
                break;  // Finalizar el turno actual
                system("pause");
            } else if (dado1==nroronda||dado2==nroronda||dado3==nroronda) {
                contnroprohibido=1;
                puntosRonda=0;
                cout << "Salio un dado con numero prohibido, perdiste tus puntos puntos de esta ronda y tu turno ha terminado! " << endl;
                break; //Finaliza turno actual
                system("pause");
            }else{
                puntosRonda += puntosLanzamiento;
                cout <<"¡Sumaste " << puntosLanzamiento << " puntos!" << endl;
                cout << endl;
                if(contnroprohibido==0){
                    cout << "¿Continuar? (S/N): ";
                    cin >> confirmar;
                }else {
                confirmar='n';
                }
            }
        }
        // Sumar puntos de la ronda al puntaje total
        if (jugActual == nombres[0]) {
            acugralj1 += puntosRonda;
            jugador1Jugo = true;
            jugActual = nombres[1];  // Cambiar turno al jugador 2
        }else {
            acugralj2 += puntosRonda;
            jugador2Jugo = true;
            jugActual = nombres[0];  // Cambiar turno al jugador 1
        }
        // Verificar si ambos jugadores han jugado para avanzar de ronda
        if (jugador1Jugo && jugador2Jugo) {
            nroronda++;
            jugador1Jugo = false;
            jugador2Jugo = false;
        }



    }
}
