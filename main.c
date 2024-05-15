/**
******************************************************************************
Projeto Roleta: esse projeto devera seguir os requerimentos estabelecidos pelo 
professor John Kennedy. Alem disso, este projeto devera conter duas bibliotecas:
1) display7seg.h - contendo as funcionalidades para exibir 
numeros no display

2)roleta.h - contendo as funcionalidades da aplicacao roleta

**/

#include "io430.h"
#include "display7seg.h" //inclui a biblioteca
#include "roletas.h"

// rebekah
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  display_init();
  unsigned char roleta[] = {0, 0, 0};
   unsigned char valor;
   while(1)
  {
    
     //LER BOTÃO
    
    if((BOTAO0) == 0){
      __delay_cycles(500000);
      roleta[0]++;
    }else if ((BOTAO1) == 0){
      __delay_cycles(500000);
      roleta[1]++;
    } else if ((BOTAO2) == 0){
      __delay_cycles(500000);
      roleta[2]++;
    }  
    
   //EXIBE   
    if((P1IN & 0xC0) == 0)
      valor = roleta[2];
   else if((P1IN & 0x80) == 0) 
       valor = roleta[1];
   else if ((P1IN & 0x40) == 0)
      valor = roleta[0];
   else if((P1IN & 0x00) == 0)
    valor = PublicoTotal(roleta);
  
    
         
    
    MostraDisplay(valor);
//    __delay_cycles(100000);    //clock 1MHz
  }
  

}
