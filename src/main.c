/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  23/01/2023 11:05:49
 *       Revision:  none
 *       Compiler:  arm-linux-gnueabihf-gcc
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "../inc/macros.h"

pthread_t task_vertical;   /*identificador da thread 1*/
pthread_t task_horizontal; /*identificador da thread 2*/

char key;
int main(){
    /*----------------------------SERVO 1---------------------------------*/
    /*exportando diretorio do PWM canal 0 (P8_19), para conectar o servo 1*/
    writeFile("0", 1, PATH_PWMCHIP2_EXPORT);

    /*Definindo periodo do PWM para o servo 1*/
    writeFile(PERIOD_DEFAULT, sizeof(PERIOD_DEFAULT), PATH_PWMCHIP2_CH_0"period");

    /*Definindo DutyCycle do PWM para o servo 1 */ 
    writeFile(DC_MIN, sizeof(DC_MIN), PATH_DC_PWMCHIP2_CH_0);

    /*Habilitando do PWM para o servo 1*/
    writeFile("1", 1, PATH_PWMCHIP2_CH_0"enable");

    /*----------------------------SERVO 2---------------------------------*/

    /*exportando diretorio do PWM canal 0 (P9_22), para conectar o servo 2*/
    writeFile("0", 1, PATH_PWMCHIP0_EXPORT);

    /*Definindo periodo do PWM para o servo 2*/
    writeFile(PERIOD_DEFAULT, sizeof(PERIOD_DEFAULT), PATH_PWMCHIP0_CH_0"period");

    /*Definindo DutyCycle do PWM para o servo 2 */
    writeFile(DC_MIN, sizeof(DC_MIN), PATH_DC_PWMCHIP0_CH_0);

    /*Habilitando do PWM para o servo 2*/
    writeFile("1", 1, PATH_PWMCHIP0_CH_0"enable");

    printf("INICIALIZACAO PRINCIPAL\n\n");
    /*parametros: address da thread, atributo, nome da funcao, parametro da thread de criacao*/
    pthread_create(&task_vertical, NULL, (void *)leituraVertical, NULL);
    pthread_create(&task_horizontal, NULL, (void *)leituraHorizontal, NULL);
    sleep(1);

    printf("Pressione ESC para finalizar\n");
    key = getchar();
    while((pthread_cancel(task_vertical) == 0) && (pthread_cancel(task_horizontal) == 0)){
        /*bloquea a main ate as tasks terminar. parametros: thread, motivo do termino*/
        pthread_join(task_vertical, NULL);
        pthread_join(task_horizontal, NULL);

        if((int)(key) == 27){
            /*removendo diretorio do PWM canal 0 (P9_22), para desconectar o servo 1*/
            writeFile("0", 1, PATH_PWMCHIP0_CH_0"enable");
            writeFile("0", 1, PATH_PWMCHIP0_UNEXPORT);
            pthread_cancel(task_horizontal);
            /*removendo diretorio do PWM canal 0 (P8_19), para desconectar o servo 2*/
            writeFile("0", 1, PATH_PWMCHIP2_CH_0"enable");
            writeFile("0", 1, PATH_PWMCHIP2_UNEXPORT);
            break;
        }
    }
    printf("FIM\n");
    return (0);
}