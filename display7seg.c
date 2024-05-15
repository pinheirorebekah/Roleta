#include "display7seg.h"

                      // 0 ,   1 ,   2 ,   3 ,   4 ,   5 ,   6 ,   7 ,   8 ,   9
unsigned char cod[] = {0x3F, 0x21, 0x76, 0x73, 0x69, 0x5B, 0x5F, 0x31, 0x7F, 0x7B};

/******************************************************************************
* Funcao:	void display_init(void)
* Entrada:	Nenhuma (void)
* Saída:	Nenhuma (void)
* Descrição:	Inicializa os pinos de I/O necessários ao display
*               de 7-segmentos multiplexado. Testa o display (pisca por 1 segundo)
*****************************************************************************/
void display_init(void)
{
    // Configuração
    GATE1_cfg = 1; // P1.1 como saída
    SEG_cfg = 0x7F;

    // Teste do display
    SEG = 0x7F;
    GATE1 = 0; // Define P1.1 como 0
    GATE0 = 0; // Define P1.0 como 0
    __delay_cycles(1000000); // Atraso de 1 segundo (considerando 1 MHz de clock)
    SEG = 0;
    GATE1 = 1; // Define P1.1 como 1

     //Configurações adicionais
     Transitores_cfg;
     EntradasP1_cfg;
     Display_cfg;
     Display |= 0x7E;

    return;
}

/******************************************************************************
* Funcao:	void MostraDisplay(unsigned char valor)
* Entrada:	Valor (unsigned char valor)
* Saída:	Nenhuma (void)
* Descrição:	Exibe o valor no display de 7 segmentos
*****************************************************************************/
void MostraDisplay(unsigned char valor)
{
    unsigned char unidade = valor, dezena = 0;
    while (unidade > 9)
    {
        dezena++;
        unidade -= 10;
    }
   GATE0_ON;
    SEG=cod[unidade];
    __delay_cycles(1000);//clock 
    GATE0_OFF;
    GATE1_ON;
    SEG=cod[dezena];
    __delay_cycles(1000);//clock 
    GATE1_OFF ;
   

    return;
}