#include <iostream>

using namespace std;

void insertar(int iLugar, int iMed, char mCuatro[7][7], int &iCoory, char cChar){
    bool bInsertar=false;
    iMed--;
    iLugar--;
    while((bInsertar==false)&&(iMed>=0)){
        if((mCuatro[iMed][iLugar]!='X')&&(mCuatro[iMed][iLugar]!='O')){
                mCuatro[iMed][iLugar]=cChar;
                iCoory=iMed;
                bInsertar=true;
            }
        iMed--;
    }
}


bool revisar(int iMed, char mCuatro[7][7], bool bGano, int iCoory, int iLugarx, char cChar){

        iLugarx--;
        int iCont=0, iContizq=iLugarx, iContder=iLugarx, iContarr=iCoory, iContaba=iCoory;
        bool bContinua=true;
        //cout << "y" <<iCoory << endl;
        //cout << "x" <<iLugarx << endl;

        while((iContizq>=0)&&(bContinua==true)){     //Revisa la izquierda
                if((mCuatro[iCoory][iContizq])==cChar){
                    bContinua=true;
                    iCont++;
                    if(iCont==4){

                        return bGano=true;
                    }
                }
                else{
                    bContinua=false;
                }
                iContizq--;
        }

        bContinua=true;
        iCont--;

        while((iContder<iMed)&&(bContinua==true)){     //Revisa la derecha
                if((mCuatro[iCoory][iContder])==cChar){
                    bContinua=true;
                    iCont++;
                    if(iCont==4){
                        //cout << "Gano der" << endl;
                        return bGano=true;
                    }

                }
                else{
                    bContinua=false;
                }
                iContder++;
        }

        //cout << "Cont" <<iCont << endl;
        bContinua=true;
        iCont=0;


        while((iContaba<iMed)&&(bContinua==true)){     //Revisa abajo
                if((mCuatro[iContaba][iLugarx])==cChar){
                    bContinua=true;
                    iCont++;
                    //cout << "Cont" <<iCont << endl;
                    if(iCont==4){
                        //cout << "Cont" <<iCont << endl;
                       //cout << "Gano aba" << endl;
                       return bGano=true;
                    }
                }
                else{
                    bContinua=false;
                }
                iContaba++;
        }
        //cout << "Cont" <<iCont << endl;
        bContinua=true;
        iCont=0;
        iContizq=iLugarx;
        iContarr=iCoory;
        iContder=iLugarx;
        iContaba=iCoory;

        while((iContizq>=0)&&(bContinua==true)&&(iContarr>=0)){     //Revisa diagonal arriba izquierda
                if((mCuatro[iContarr][iContizq])==cChar){
                    bContinua=true;
                    iCont++;
                     if(iCont==4){
                        return bGano=true;
                    }
                }
                else{
                    bContinua=false;
                }
                iContizq--;
                iContarr--;
        }

        bContinua=true;

        while((iContder<iMed-1)&&(bContinua==true)&&(iContaba<iMed-1)){     //Revisa diagonal abajo derecha
                if((mCuatro[iContaba+1][iContder+1])==cChar){
                    bContinua=true;
                    iCont++;
                    if(iCont==4){
                        //cout << "Cont" <<iCont << endl;
                       //cout << "Gano aba" << endl;
                       return bGano=true;
                    }
                }
                else{
                    bContinua=false;
                }
                iContaba++;
                iContder++;
        }

        bContinua=true;
        iContizq=iLugarx;
        iContder=iLugarx;
        iContaba=iCoory;
        iContarr=iCoory;
        iCont=0;

        while((iContizq>=0)&&(bContinua==true)&&(iContaba<iMed)){     //Revisa diagonal abajo izq
                if((mCuatro[iContaba][iContizq])==cChar){
                    bContinua=true;
                    iCont++;
                    //cout << "Cont" <<iCont << endl;
                    if(iCont==4){
                        //cout << "Gano der" << endl;
                        return bGano=true;
                    }

                }
                else{
                    bContinua=false;
                }
                iContizq--;
                iContaba++;
        }

        //cout << "Cont" <<iCont << endl;
        bContinua=true;

        while((iContder<iMed-1)&&(bContinua==true)&&(iContarr>0)){     //Revisa diagonal arriba derecha
                if((mCuatro[iContarr-1][iContder+1])==cChar){
                    bContinua=true;
                    iCont++;
                    if(iCont==4){
                        //cout << "Gano arr" << endl;
                        return bGano=true;
                    }
                }
                else{
                    bContinua=false;
                }
                iContarr--;
                iContder++;
        }

        bContinua=true;

}


int main()
{
    int iPosicion=0, iTam=0, iCont=1, y; //Declarar todas las variables
    string sJug1, sJug2;
    bool bCampeon=false, bSeguir=true, bAcabo=false, bCiclo=true;
    char mConecta[7][7];
    char cJug1='X', cJug2='O', cSeguir='S';

    do{
    cout << "De que tamano sera el tablero de la diversion?: 2<=x<=7" << endl; //Pedir tamaño de matriz para revisar los limites
    cin >> iTam;
    }while((iTam>7)||(iTam<0));

    y=iTam-1;

    cout << "Nombre del jugador 1" << endl;
    cin >> sJug1;

    cout << "Nombre del jugador 2" << endl;
    cin >> sJug2;

    for(int a=0; a<iTam; a++){                                          //Imprimir el tablero
        for (int b=0; b<iTam; b++){
            mConecta[a][b]='*';
        }
    }
    for(int i=0; i<iTam; i++){
            for(int m=0; m<iTam; m++)
                cout << mConecta[i][m] << " ";
            cout << endl;
        }

    do{

        if (iCont%2!=0){
                                                            //Revisar a que jugador le toca
            while(bSeguir){
            cout << "En que columna situaras tu ficha?: " << sJug1 << endl;
            cin >> iPosicion;
            if(((iPosicion-1)>=0)&&(iPosicion<=iTam))
                bSeguir=false;
            else cout << "Inserte una columba valida" << endl;
            }

            insertar(iPosicion, iTam, mConecta, y, cJug1);                  //Llamar metodo para insertar la X

            bCampeon=revisar(iTam, mConecta, bCampeon, y, iPosicion, cJug1);  //Revisar que gano el Jugador 1
        }
        else {
            while(bSeguir){
            cout << "En que columna situaras tu ficha?: " << sJug2 << endl;
            cin >> iPosicion;
            if(((iPosicion-1)>=0)&&(iPosicion<=iTam))
                bSeguir=false;
            else cout << "Inserta una columna valida" << endl;
            }

            insertar(iPosicion, iTam, mConecta, y, cJug2);                  //Llamar metodo para insertar la O

            bCampeon=revisar(iTam, mConecta, bCampeon, y, iPosicion, cJug2);    //Revisar que gano el Jugador 2
        }

        for(int i=0; i<iTam; i++){
            for(int m=0; m<iTam; m++)
                cout << mConecta[i][m] << " ";
            cout << endl;
        }

        if(y==0){
            bAcabo=true;
            for(int a=0; a<iTam; a++){
                if(mConecta[y][a]=='*')
                    bAcabo=false;
            }
            if(bAcabo)
                cout << "Lamento informar que se lleno el tablero: Es un empate";
        }

        if((bCampeon==false)&&(bAcabo==false)){
            do{
                cout << "Desean seguir? S/N" << endl;
                cin >> cSeguir;
                if((cSeguir=='n')||(cSeguir=='N')){
                    bAcabo=true;
                    bCiclo=false;
                }
                else if ((cSeguir=='s')||(cSeguir=='S')){
                    bAcabo=false;
                    bCiclo=false;
                    }
                else cout << "Inserte un caracter valido" << endl;
            }while(bCiclo);

            iPosicion=0;
            iCont++;
            y=iTam-1;
            bSeguir=true;
            bCiclo=true;
        }

    }while((bCampeon==false)&&(bAcabo==false));                                                //Continuar hasta que gane alguien o ya no quieran jugar

    if((bCampeon==true) &&(iCont%2!=0))                                                     //Decir que gano e imprimir el tablero ganador
        cout << "¡GANASTE!: " <<sJug1;
    else if ((bCampeon==true) &&(iCont%2==0))
        cout << "¡GANASTE!: " <<sJug2;

    return 0;
}
