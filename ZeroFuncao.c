#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t newtonRaphson (Polinomio p, real_t x0, int criterioParada, int *it, real_t *raiz)
{

}


// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t bisseccao (Polinomio p, real_t a, real_t b, int criterioParada, int *it, real_t *raiz)
{
    real_t xNovo = (a+b)/2;

    if (){

    }else if(){

    }else
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
