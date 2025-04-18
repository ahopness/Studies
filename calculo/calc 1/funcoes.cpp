/******************************************************************************
        Sobre o codigo:
        codigo para calcular o y de uma determinada função, a função z na qual
        trata-se do (yim - yi)/(xim - xi) a função w na qual trata-se do
        (zim - zi)/(xim - xi), codigo realizado para achar os resultados pora uma
        atividade pratica da aula de Calculo 1
        Autor:
        Javier Cadima, Lucas Angelo, Gusthavo Cassimiro
        Data:
        15/04/2025
*******************************************************************************/
#include <iostream>
#include <cmath>
#include <locale.h>
#include <locale>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;


float calculafuncaoY(float i){
    float R = pow(i, 5)- 2*pow(i, 2)+ 3;
    return R;
}

float calculafuncaoZ(float i, float Z){
    float C3 = calculafuncaoY(i);
    float R = (C3 - Z)/(i - (i - 0.25));
    return R;
}

float calculafuncaoW(float i, float Z){
    float Z4 = calculafuncaoZ(i - 0.25, Z);
    float R = (Z4 - Z)/(i - (i - 0.25));
    return R;
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese");
    ofstream arq1;
    arq1.open("resultados.txt");
    cout<<"----------------------"<<endl;
    arq1<<"----------------------"<<endl;
   
    float resultadoy = 0; float resultadoz=0; float resultadow;
    for(float i = -2; i<=2; i += 0.25){
        if(resultadoz==0){
            resultadow = 0;
        }else{
            resultadow = calculafuncaoW(i, resultadoz);
        }
        if(resultadoy==0){
            resultadoz = 0;
        }else{
            resultadoz = calculafuncaoZ(i, resultadoy);
        }
       
        resultadoy = calculafuncaoY(i);
       
        cout<<"x é = "<<i<<endl;
        cout<<"y é = "<<resultadoy<<endl;
        cout<<"z é = "<<resultadoz<<endl;
        cout<<"w é = "<<resultadow<<endl;
        cout<<"----------------------"<<endl;
       
        arq1<<"x é = "<<i<<endl;
        arq1<<"y é = "<<resultadoy<<endl;
        arq1<<"z é = "<<resultadoz<<endl;
        arq1<<"w é = "<<resultadow<<endl;
        arq1<<"----------------------"<<endl;
    }
   
    arq1.close();

    return 0;
}