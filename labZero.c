#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>

#include "utils.h"
#include "ZeroFuncao.h"

int main ()
{

  real_t a, b;
  Polinomio pol;
  int it = 0;
  real_t raiz;
  real_t erro;
  real_t t1, t2;

  scanf("%d", &pol.grau);
  pol.p = (real_t*)malloc(((pol.grau+1) * sizeof(real_t)));


  for (int i=pol.grau; i >=0; --i)
    scanf("%lf", &pol.p[i]);

  scanf("%lf %lf", &a, &b); // intervalo onde está uma das raizes.


  fesetround(FE_DOWNWARD);
  // Restante do programa a partir daqui
  t1 = timestamp();
  erro = bisseccao(pol, a, b, 1, &it, &raiz, 1);
  t2 = timestamp();
  printf("bissec  %+.15e %+.8e %3d %.8e\n", raiz, erro, it, t2-t1);
  it = 0;

  t1 = timestamp();
  erro = bisseccao(pol, a, b, 2, &it, &raiz, 1);
  t2 = timestamp();
  printf("bissec  %+.15e %+.8e %3d %.8e\n", raiz, erro, it, t2-t1);
  it = 0;

  t1 = timestamp();
  erro = bisseccao(pol, a, b, 3, &it, &raiz, 1);
  t2 = timestamp();
  printf("bissec  %+.15e %+.8e %3d %.8e\n", raiz, erro, it, t2-t1);
  it = 0;

  printf("\n");

  t1 = timestamp();
  erro = bisseccao(pol, a, b, 1, &it, &raiz, 0);
  t2 = timestamp();
  printf("bissec  %+.15e %+.8e %3d %.8e\n", raiz, erro, it, t2-t1);
  it = 0;

  t1 = timestamp();
  erro = bisseccao(pol, a, b, 2, &it, &raiz, 0);
  t2 = timestamp();
  printf("bissec  %+.15e %+.8e %3d %.8e\n", raiz, erro, it, t2-t1);
  it = 0;

  t1 = timestamp();
  erro = bisseccao(pol, a, b, 3, &it, &raiz, 0);
  t2 = timestamp();
  printf("bissec  %+.15e %+.8e %3d %.8e\n", raiz, erro, it, t2-t1);
  it = 0;

  return 0;
}

