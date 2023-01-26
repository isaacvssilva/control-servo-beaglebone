/*
 * =====================================================================================
 *
 *       Filename:  file_read.c
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  23/01/2023 10:55:35
 *       Revision:  none
 *       Compiler:  arm-linux-gnueabihf-gcc
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "../inc/file_read.h"

int writeFile(const char* str, int size_str, const char* path){
    FILE *file = NULL; 
    file = fopen(path, "w");
    if(file){
        fwrite(str, 1, size_str, file);
        fclose(file);
        return 0;
    }else{
        printf("\nERRO ao abrir arquivo!\n");
        exit(-1);
    }
}

int readFileInt(int* num, const char* path){
    FILE *file = NULL;
    file = fopen(path, "r");
    if(file){
        fscanf(file, "%d", num);
        fclose(file);   
        return 0;    
    }else{
        printf("\nERRO ao abrir arquivo!\n");
        exit(-1);
    }    
}