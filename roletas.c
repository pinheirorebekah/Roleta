#include "roletas.h"

unsigned char PublicoTotal(unsigned char *roleta)
{
  unsigned char valor = 0;
  valor = roleta[2]+roleta[1]+roleta[0];
  



return valor;
}