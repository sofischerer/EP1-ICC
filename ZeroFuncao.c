#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"
#include "DoubleType.h"

real_t criterio1 (real_t xOld, real_t xNew){
    real_t erro = abs(xNew - xOld);    
    erro *= xOld;
    return erro;
}

real_t criterio2 (){
    
}

real_t criterio3 (real_t xOld, real_t xNew){
    Double_t doubleOld;
    doubleOld.f = xOld;
    Double_t doubleNew;
    doubleNew.f = xNew;

    real_t erro = abs(doubleNew.i - doubleOld.i)-1;
    return erro;
}

// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t newtonRaphson (Polinomio p, real_t x0, int criterioParada, int *it, real_t *raiz)
{

}


// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t bisseccao (Polinomio p, real_t a, real_t b, int criterioParada, int *it, real_t *raiz, int rapido)
{
    real_t xNovo = (a+b)/2;;
    real_t xVelho;
    real_t fLeft, fMid;
    real_t derivada;
    real_t erro;

    if (rapido){
        while(1){
            calcPolinomio_rapido(p, a, &fLeft, &derivada);
            calcPolinomio_rapido(p, xNovo, &fMid, &derivada);
            
            if(fLeft * fMid < 0){
                b = xNovo;
                xVelho = xNovo;
            }else if (fLeft * fMid > 0){
                a = xNovo;
                xVelho = xNovo;
            }else{
                return 0;
            }
            
            xNovo = (a+b)/2;
            if (criterioParada == 1){
                erro = criterio1(xVelho, xNovo);
                if (erro <= 0.0000001) return erro;
            }else if(criterioParada == 2){
                erro = criterio2();
                if (erro <= DBL_EPSILON) return erro;
            }else{
                erro = criterio3(xVelho, xNovo);
                if (erro < 3) return erro;
            }
        }
    }else{
        while(1){
            calcPolinomio_lento(p, a, &fLeft, &derivada);
            calcPolinomio_lento(p, xNovo, &fMid, &derivada);
            
            if(fLeft * fMid < 0){
                b = xNovo;
                xVelho = xNovo;
            }else if (fLeft * fMid > 0){
                a = xNovo;
                xVelho = xNovo;
            }else{
                return 0;
            }

            xNovo = (a+b)/2;
            if (criterioParada == 1){
                erro = criterio1(xVelho, xNovo);
                if (erro <= 0.0000001) return erro;
            }else if(criterioParada == 2){
                erro = criterio2();
                if (erro <= DBL_EPSILON) return erro;
            }else{
                erro = criterio3(xVelho, xNovo);
                if (erro < 3) return erro;
            }
        }
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
