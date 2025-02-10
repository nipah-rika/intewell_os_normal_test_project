/*
 * main.h
 *
 *  Created on: 2023��12��26��
 *      Author: kyland289
 */

#ifndef MAIN_H_
#define MAIN_H_

typedef struct {
	T_WORD spi_fd;
	char * spi_name;
	pthread_t testId;
	sfud_flash *flash;
} spi_info_t;

#endif /* MAIN_H_ */
