/*Header******************************************************/
// LCD module connections
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
// End LCD module connections
unsigned char ch; //
unsigned int adc_rd; // Declare variables
char *text; //
double x0, x1, y0, y1;
long gradoss, A, B;
double tlong, grados; //
void main() {
A = 30;       // umbral menor
B = 150;      // umbral mayor
TRISC1_bit=0;
INTCON = 0; // All interrupts disabled
ANSEL = 0x04; // Pin RA2 is configured as an analog input
TRISA = 0x04;
ANSELH = 0; // Rest of pins are configured as digital
Lcd_Init(); // LCD display initialization
Lcd_Cmd(_LCD_CURSOR_OFF); // LCD command (cursor off)
Lcd_Cmd(_LCD_CLEAR); // LCD command (clear LCD)
text = "Juan Trevino"; // Define the first message
Lcd_Out(1,1,text); // Write the first message in the first line
text = "Eliseo Berdeal"; // Define the second message
Lcd_Out(2,1,text); // Define the first message
ADCON1 = 0x82; // A/D voltage reference is VCC
TRISA = 0xFF; // All port A pins are configured as inputs
Delay_ms(2000);
Lcd_Cmd(_LCD_CLEAR);
text = "Grados:"; // Define the third messa
while (1) {
adc_rd = ADC_Read(2); // A/D conversion. Pin RA2 is an input.
Lcd_Out(2,1,text); // Write result in the second line
PORTC.RC1 = 0;
tlong = (long)adc_rd * 5000; // Convert the result in millivolts
tlong = tlong / 1023; // 0..1023 -> 0-5000mV
if (tlong>4310) {          // se establece cada condicion
   y0 = 0;
   y1 = 0;
} else if (tlong>4120) {
       y0=0;
       x0=4300;
       y1=10;
       x1=4120;
} else if (tlong>3930) {
       y0=10;
       x0=4120;
       y1=20;
       x1=3930;
} else if (tlong>3740) {
       y0=20;
       x0=3930;
       y1=30;
       x1=3740;
}else if (tlong>3560) {
       y0=30;
       x0=3740;
       y1=40;
       x1=3560;
}else if (tlong>3370) {
       y0=40;
       x0=3560;
       y1=50;
       x1=3370;
}else if (tlong>3180) {
       y0=50;
       x0=3370;
       y1=60;
       x1=3180;
}else if (tlong>2990) {
       y0=60;
       x0=3180;
       y1=70;
       x1=2990;
}else if (tlong>2780) {
       y0=70;
       x0=2990;
       y1=80;
       x1=2780;
}else if (tlong>2600) {
       y0=80;
       x0=2780;
       y1=90;
       x1=2600;
}else if (tlong>2360) {
       y0=90;
       x0=2600;
       y1=100;
       x1=2360;
}else if (tlong>2170) {
       y0=100;
       x0=2360;
       y1=110;
       x1=2170;
}else if (tlong>1960) {
       y0=110;
       x0=2170;
       y1=120;
       x1=1960;
}else if (tlong>1770) {
       y0=120;
       x0=1960;
       y1=130;
       x1=1770;
}else if (tlong>1580) {
       y0=130;
       x0=1770;
       y1=140;
       x1=1580;
}else if (tlong>1350) {
       y0=140;
       x0=1580;
       y1=150;
       x1=1350;
}else if (tlong>1140) {
       y0=150;
       x0=1350;
       y1=160;
       x1=1140;
}else if (tlong>950) {
       y0=160;
       x0=1140;
       y1=170;
       x1=950;
}else if (tlong>780) {
       y0=170;
       x0=950;
       y1=180;
       x1=780;
}else if (tlong<780) {
       y0=0;
       x0=0;
       y1=1;
       x1=1;
       tlong=180;
}
grados = y0+((tlong-x0)/(x1-x0))*(y1-y0);      // ecuacion de parameritracion
gradoss = grados;                              //
if (gradoss<A) {
        PORTC.RC1 = 1;                      // Prende el led
   }
if (gradoss>B) {
        PORTC.RC1 = 1;
   }
ch = gradoss / 100; // Extract volts (thousands of millivolts) // from result
Lcd_Chr(2,9,48+ch); // Write result in ASCII format
ch = (gradoss / 10) % 10; // Extract hundreds of millivolts
Lcd_Chr_CP(48+ch); // Write result in ASCII format
ch = (gradoss) % 10; //
Lcd_Chr_CP(48+ch); // Write result in ASCII format
Delay_ms(500);
}
}