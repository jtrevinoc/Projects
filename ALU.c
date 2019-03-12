#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Conexiones del módulo LCD
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// Final de las conexiones del módulo LCD

char *text;
unsigned char ch;
long temp;
float duty_cycle;
int set_point;
char k;
float a,b,result;
char option;
char input;
unsigned short i;


void main() {

UART1_Init(19200);
INTCON = 0;                    // Todas las interrupciones deshabilitadas
ANSEL = 0x04;                  // Pin RA2 se configura como una entrada analógica
TRISA = 0x04;
ANSELH = 0;                    // Los demás pines se configuran como digitales


ADC_Init();
Lcd_Init();                    // Inicialización del visualizador LCD
Lcd_Cmd(_LCD_CURSOR_OFF);      // Comando LCD (apagar el cursor)
Lcd_Cmd(_LCD_CLEAR);           // Comando LCD (borrar el LCD)

 LCD_OUT(1,1,"Juan Pablo Treviño   #511823");
 LCD_OUT(2,1,"Eliseo Berdeal #328024");
 DELAY_MS(2500);
for(k=0;k<15;k++){
 LCD_CMD(_LCD_SHIFT_LEFT);
 DELAY_MS(700);
 }
 Menu:
 Lcd_Cmd(_LCD_CLEAR);
 LCD_OUT(1,1,"S    R    M    D");
 do{
 leerpc:
    if (UART1_Data_Ready()) { // If data has been received
       input = UART1_Read(); // read it
       }
       else {
       goto leerpc;
       }
    switch(input){
        case s :  leerpc1:
                         if (UART1_Data_Ready()) { // If data has been received
                            a = UART1_Read(); // read it
                            }
                            else {
                            goto leerpc1;
                            }
                         if (isdigit(a)) {
                            }
                            else {
                            LCD_OUT(1,1,"Error, inserte un numero");
                            DELAY_MS(1000);
                            goto menu;
                            }
                 leerpc2:
                         if (UART1_Data_Ready()) { // If data has been received
                            b = UART1_Read(); // read it
                            }
                            else {
                            goto leerpc2;
                            }
                         if (isdigit(b)) {
                            }
                            else {
                            LCD_OUT(1,1,"Error, inserte un numero");
                            DELAY_MS(1000);
                            goto menu;
                            }
                 result=a+b;
                 result = roundf(result * 1000) / 1000;
                 UART1_Write(a + "+" + b + "=" + result);
                 LCD_OUT(1,1,result);
                 break;
        case r :  leerpc3:
                         if (UART1_Data_Ready()) { // If data has been received
                            a = UART1_Read(); // read it
                            }
                            else {
                            goto leerpc3;
                            }
                         if (isdigit(a)) {
                            }
                            else {
                            LCD_OUT(1,1,"Error, inserte un numero");
                            DELAY_MS(1000);
                            goto menu;
                            }
                 leerpc4:
                         if (UART1_Data_Ready()) { // If data has been received
                            b = UART1_Read(); // read it
                            }
                            else {
                            goto leerpc4;
                            }
                         if (isdigit(b)) {
                            }
                            else {
                            LCD_OUT(1,1,"Error, inserte un numero");
                            DELAY_MS(1000);
                            goto menu;
                            }
                 result=a-b;
                 result = roundf(result * 1000) / 1000;
                 UART1_Write(a + "-" + b + "=" + result);
                 LCD_OUT(1,1,result);
                 break;
        case m :  leerpc5:
                         if (UART1_Data_Ready()) { // If data has been received
                            a = UART1_Read(); // read it
                            }
                            else {
                            goto leerpc5;
                            }
                         if (isdigit(a)) {
                            }
                            else {
                            LCD_OUT(1,1,"Error, inserte un numero");
                            DELAY_MS(1000);
                            goto menu;
                            }
                 leerpc6:
                         if (UART1_Data_Ready()) { // If data has been received
                            b = UART1_Read(); // read it
                            }
                            else {
                            goto leerpc6;
                            }
                         if (isdigit(b)) {
                            }
                            else {
                            LCD_OUT(1,1,"Error, inserte un numero");
                            DELAY_MS(1000);
                            goto menu;
                            }
                 result=a*b;
                 result = roundf(result * 1000) / 1000;
                 UART1_Write_text(a + "x" + b + "=" + result);
                 LCD_OUT(1,1,result);
                 break;
        case d : leerpc7:
                         if (UART1_Data_Ready()) { // If data has been received
                            a = UART1_Read(); // read it
                            }
                            else {
                            goto leerpc7;
                            }
                         if (isdigit(a)) {
                            }
                            else {
                            LCD_OUT(1,1,"Error, inserte un numero");
                            DELAY_MS(1000);
                            goto menu;
                            }
                 leerpc8:
                         if (UART1_Data_Ready()) { // If data has been received
                            b = UART1_Read(); // read it
                            }
                            else {
                            goto leerpc8;
                            }
                         if (isdigit(b)) and b != 0 {
                            }
                            else {
                            LCD_OUT(1,1,"Error, inserte un numero que no sea 0");
                            DELAY_MS(1000);
                            goto menu;
                            }
                 result=a/b;
                 result = roundf(result * 1000) / 1000;
                 UART1_Write(a + "/" + b + "=" + result);
                 LCD_OUT(1,1,result);
                 break;

        default: LCD_OUT(1,1,"Invalido");
                 goto menu;

    }
 return 0;
}