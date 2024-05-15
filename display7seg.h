/**
  ******************************************************************************
  * File Name          : display7seg.h
  * Dependencias       : Veja seção INCLUDES
  * Processador        : MSP430F2131/MSP430G2452
  * Author             :
  * Copyright          :
  ******************************************************************************
  * Versions           : v0.1 - "1 linha sobre o que foi modificado"
  * Description        : descrever pontos chaves do codigo (qual hardware, possiveis
                        modificacoes/adaptacoes que o usuario pode fazer,...)

  ************* // Configuração
    GATE1_cfg = 1; // P1.1 como saída
    SEG_cfg = 0x7F;
 // Configuração
    GATE1_cfg = 1; // P1.1 como saída
    SEG_cfg = 0x7F;
*****************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DISPLAY7SEG_H
#define _DISPLAY7SEG_H //previne dupla inclusao da biblioteca

/* Includes -----------------------------------------------------------------*/
#include "io430.h"

/* Private defines --------------------------------------------------------- */
//I/O configuration
#define GATE1_cfg       P1DIR_bit.P1
#define SEG_cfg         P2DIR
#define PISEL_cfg       P1SEL = 0x00
#define P2SEL_cfg       P2SEL = 0x00
#define Transitores_cfg P1DIR |= 0X03
#define EntradasP1_cfg  P1DIR &= 0x07
#define Pullup_cfg      P1REN |= 0XF8
#define Display_cfg     P2DIR |= 0X7F
#define Display         P2OUT
#define BOCHA_cfg       P1DIR &= 0X07
#define BOTAO0           P1IN  & 0X20 // ler bit5
#define BOTAO1           P1IN  & 0X10 // ler bit4
#define BOTAO2           P1IN  & 0X08 // ler bit3
    
//#define CHAVES          P1IN  &= 0XC0



//I/O use
#define SEG             P2OUT
#define GATE1           P1OUT_bit.P1
#define GATE0           P1OUT_bit.P0


/*MOSTRA DISPLAY*/
#define GATE0_ON        P1OUT |= 0X01
#define GATE1_ON        P1OUT |= 0X02
#define GATE0_OFF       P1OUT &= 0XFE
#define GATE1_OFF       P1OUT &= 0XFD

/* Prototypes --------------------------------------------------------- */
void display_init(void);
void MostraDisplay(unsigned char valor);

#endif
