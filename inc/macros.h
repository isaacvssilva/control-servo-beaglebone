/*
 * =====================================================================================
 *
 *       Filename:  macros.h
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  23/01/2023 11:00:05
 *       Revision:  none
 *       Compiler:  arm-linux-gnueabihf-gcc
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#ifndef MACROS_H
#define MACROS_H

/*inclusao de bibliotecas*/
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <pthread.h>

/*modulos funcionais*/
#include "../inc/file_read.h"
#include "../inc/threads.h"

/*P9_22 -> pwm0*/
#define PATH_PWMCHIP0_EXPORT "/sys/class/pwm/pwmchip0/export"
/*P9_22 -> pwm0*/
#define PATH_PWMCHIP0_UNEXPORT "/sys/class/pwm/pwmchip0/unexport"
/*P8_19 -> pwm0*/
#define PATH_PWMCHIP2_EXPORT "/sys/class/pwm/pwmchip2/export"
/*P8_19 -> pwm0*/
#define PATH_PWMCHIP2_UNEXPORT "/sys/class/pwm/pwmchip2/unexport"
/*P9_22 -> pwm0*/
#define PATH_PWMCHIP0_CH_0 "/sys/class/pwm/pwmchip0/pwm0/"
/*P8_19 -> pwm0*/
#define PATH_PWMCHIP2_CH_0 "/sys/class/pwm/pwmchip2/pwm0/"
#define PATH_DC_PWMCHIP0_CH_0 "/sys/class/pwm/pwmchip0/pwm0/duty_cycle"
#define PATH_DC_PWMCHIP2_CH_0 "/sys/class/pwm/pwmchip2/pwm0/duty_cycle"
#define PERIOD_DEFAULT "20000000"
#define DC_MIN "544444"
#define minimumPulseWidth 544444
#define maximumPulseWidth 2500000
#define ADC0    "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define ADC1    "/sys/bus/iio/devices/iio:device0/in_voltage1_raw"
#define N_THREADS 2

#endif
/*****************************END OF FILE**************************************/