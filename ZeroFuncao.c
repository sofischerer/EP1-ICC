#include <float.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"
#include "DoubleType.h"

real_t criterio1 (real_t xOld, real_t xNew){
    real_t erro = fabs(xNew - xOld);
    erro *= xOld;
    return erro;
}

real_t criterio2 (real_t x){
    real_t erro = fabs(x);
    return erro;
}

real_t criterio3 (real_t xOld, real_t xNew){
    Double_t doubleOld;
    doubleOld.f = xOld;
    Double_t doubleNew;
    doubleNew.f = xNew;

    real_t erro = fabs(doubleNew.i - doubleOld.i) - 1.0;
    return erro;
}

// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t newtonRaphson (Polinomio p, real_t x0, int criterioParada, int *it, real_t *raiz, int rapido)
{
    //Verificar qual entrada usar
    //Fazer alguma checagem para valores muito próximos de 0?
    real_t fx, dfx;
    real_t xMinusOne;
    real_t erro;

    if (rapido == 1){
        calcPolinomio_rapido(p, x0, &fx, &dfx);
    }else{
        calcPolinomio_lento(p, x0, &fx, &dfx);
    }
    (*it)++;

    //POSSIVELMENTE ESTOU PEGANDO O VALOR ERRADO NO RETORNO, VERIFICAR DEPOIS
    xMinusOne = x0;
    x0 = x0 - (fx/dfx);

    if (criterioParada == 1){
        erro = criterio1(xMinusOne,x0);
        if (erro <= 0.0000001){
            (*raiz) = x0;
            return erro;
        }
    }else if(criterioParada == 2){
        erro = criterio2(x0);
        if (erro <=DBL_EPSILON){
            (*raiz) = x0;
            return erro;
        }
    }else{
        erro = criterio3(xMinusOne, x0);
        if (erro < 3){
            (*raiz) = x0;
            return erro;
        }
    }
    
    return 0;
}


// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t bisseccao (Polinomio p, real_t a, real_t b, int criterioParada, int *it, real_t *raiz, int rapido)
{
    real_t xNovo = (a+b)/2;
    real_t xVelho;
    real_t fLeft, fMid;
    real_t derivada;
    real_t erro;

    if (rapido == 1){
        while(*it<600){
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
            (*it)++;
            
            xNovo = (a+b)/2;
            if (criterioParada == 1){
                erro = criterio1(xVelho, xNovo);
                if (erro <= 0.0000001) {
                    (*raiz) = xNovo;
                    return erro;
                }
            }else if(criterioParada == 2){
                erro = criterio2(xNovo);
                if (erro <= DBL_EPSILON) {
                    (*raiz) = xNovo;
                    return erro;
                }
            }else{
                erro = criterio3(xVelho, xNovo);
                if (erro < 3) {
                    (*raiz) = xNovo;
                    return erro;
                }
            }
        }
    }else{
        while(*it<600){
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
            (*it)++;
            
            xNovo = (a+b)/2;
            if (criterioParada == 1){
                erro = criterio1(xVelho, xNovo);
                if (erro <= 0.0000001) {
                    (*raiz) = xNovo;
                    return erro;
                }
            }else if(criterioParada == 2){
                erro = criterio2(xNovo);
                if (erro <= DBL_EPSILON) {
                    (*raiz) = xNovo;
                    return erro;
                }
            }else{
                erro = criterio3(xVelho, xNovo);
                if (erro < 3) {
                    (*raiz) = xNovo;
                    return erro;
                }
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
