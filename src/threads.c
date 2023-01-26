/*
 * =====================================================================================
 *
 *       Filename:  threads.c
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  23/01/2023 12:15:46
 *       Revision:  none
 *       Compiler:  arm-linux-gnueabihf-gcc
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "../inc/macros.h"

void setAngulo(int novoAngulo, char *path){
    FILE *pwm = NULL;
    pwm = fopen(path, "w");
    double mapeamento = (maximumPulseWidth - minimumPulseWidth) / 180.0 * novoAngulo + minimumPulseWidth;
    int pulseWidth = (int)(mapeamento);
    fprintf(pwm, "%d", pulseWidth);
    fclose(pwm);
}

void leituraHorizontal(){
    printf("Inicio da task leitura esqueda-direita\n");
    int valorAnalogico = 0, anguloHorizontal = 0;
    while (1){
        readFileInt(&valorAnalogico, ADC0);
        anguloHorizontal = valorAnalogico / 4095.0 * 180;
        setAngulo(anguloHorizontal, PATH_DC_PWMCHIP0_CH_0);
        /*ponto de cancelamento da thread*/
        pthread_testcancel();
    }
}
void leituraVertical(){
    printf("Inicio da task leitura cima-baixo\n");
    int valorAnalogico = 0, anguloVertical = 0;
    while (1){
        readFileInt(&valorAnalogico, ADC1);
        anguloVertical = valorAnalogico / 4095.0 * 180;
        setAngulo(anguloVertical, PATH_DC_PWMCHIP2_CH_0);
        /*ponto de cancelamento da thread*/
        pthread_testcancel();
    }
}