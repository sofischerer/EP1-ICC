#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

bool criterio_1 (real_t xOld, real_t xNew){
    real_t erro = abs(xNew - xOld);    
    if (erro <= xNew*0.0000001) return true;
    return false;
}

bool criterio_2 (real_t xCalc){
    if (abs(xCalc) <= DBL_EPSILON) return true;
    return false;
}

bool criterio_3 (real_t xOld, real_t xNew){
    double_t doubleOld;
    doubleOld.f = xOld;
    double_t doubleNew;
    doubleNew.f = xNew;

    if (abs(doubleNew - doubleOld) < 3) return true;
    return false; 
}

// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t newtonRaphson (Polinomio p, real_t x0, int criterioParada, int *it, real_t *raiz)
{

}


// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t bisseccao (Polinomio p, real_t a, real_t b, int criterioParada, int *it, real_t *raiz, bool rapido)
{
    real_t xNovo = (a+b)/2;
    real_t xVelho;
    real_t fLeft, fRight, fMid;
    real_t *erro;
    real_t derivada;

    if (rapido){
        do{
            calcPolinomio_rapido(p, a, fLeft, derivada);
            calcPolinomio_rapido(p, b, fRight, derivada);
            calcPolinomio_rapido(p, xNovo, fMid, derivada);
            
            if(fLeft * fMid < 0){

            }else if (fLeft * fMid){

            }

            if (criterioParada == 1){

            }else if(criterioParada == 2){

            }else{

            }
        }while ();
    }

    
}

void calcPolinomio_rapido(Polinomio p, real_t x, real_t *px, real_t *dpx)
{
    real_t soma = 0;
    real_t derivada = 0;

    for (int i = p.grau; i>0; i--){
        soma = soma*x + p.p[i];
        derivada = derivada*x + soma;
    }
    soma = soma*x + p.p[0];

    *px = soma;
    *dpx = derivada;
}


void calcPolinomio_lento(Polinomio p, real_t x, real_t *px, real_t *dpx)
{
    real_t soma = 0;
    real_t derivada = 0;

    for (int i = p.grau; i>=0; i--){
        soma+= p.p[i] * pow(x, i);
        derivada += (p.p[i] * i) * (pow(x, i-1));
    }
    *px = soma;
    *dpx = derivada;
}
