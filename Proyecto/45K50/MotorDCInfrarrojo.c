/*******************************************************************************
Company:
Microside Technology Inc.

File Name:
Motor_DC.mcppi

Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
********************************************************************************/

/*******************************************************************************
Para usar el c�digo con bootloader, configurar como lo indica MICROSIDE:
1) Tools> Options> Output> Output Settings> Marcar "Long HEX format"
2) Project> Edit Project> Insertar 48.000000 en "MCU Clock Frequency [MHz]" box
********************************************************************************/

#pragma orgall 0x1FFF

int VALOR_ADC;                              //Variable para almacenar el valor le�do del ADC

void main(void) org 0x2000
{
     TRISC = 0X00;                          // Declaramos el puerto como salida
     PWM1_Init (5000);                      // Inicializa PWM a 5000 Hz
     PWM1_Start ();
     TRISA0_bit = 1;                        //PIN como entrada
     ANSA0_bit = 1;                         //PIN como anal�gico
     ADC_Init_Advanced(_ADC_INTERNAL_REF);  //Voltaje de referencia a VDD y GND

     while (1)
     {
        VALOR_ADC = ADC_Get_Sample(0) / 2.64; //Lee el valor del ADC y lo guarda en la variable
        PWM1_Set_Duty (VALOR_ADC);
     }
}