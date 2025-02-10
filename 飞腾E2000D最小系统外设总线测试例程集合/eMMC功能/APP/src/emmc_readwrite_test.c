/*
 * mmc_test.c
 *
 *  Created on: 2023年12月9日
 *      Author: RONGMINGKANG
 *
 */
#include "ttos.h"
#include "sysMmc.h"


#define MAX_RW_BLK      1* 2*1024U       /* 测试测试大小：1M */
#define BLOCK_SIZE         512U    /* 块大小：512字节 */


u8 rw_buf_write[MAX_RW_BLK *2* BLOCK_SIZE]={0};

u8 rw_buf_read[MAX_RW_BLK*2* BLOCK_SIZE]={0};

#define __app_is_print(ch) ((unsigned int)((ch) - ' ') < 127u - ' ')

int  read_write_time = 200;  /*循环写200次，即写200M*/

void DumpHexByte(const u8 *ptr, u32 buflen)
{
    u8 *buf = (u8 *)ptr;
    T_UWORD i, j;

    for (i = 0; i < buflen; i += 16)
    {
        printf("%p: ", ptr + i);

        for (j = 0; j < 16; j++)
            if (i + j < buflen)
            {
            	printf("%02X ", buf[i + j]);
            }
            else
            {
            	printf("   ");
            }
        printf(" ");

        for (j = 0; j < 16; j++)
            if (i + j < buflen)
            {
            	printf("%c", (char)(__app_is_print(buf[i + j]) ? buf[i + j] : '.'));
            }
        printf("\r\n");
    }
}
/* 生成写数据 */
void set_rw_buf_write_data(void){

	T_UWORD i,j,rw_buf_size;
	rw_buf_size = 2*MAX_RW_BLK * BLOCK_SIZE;
	rw_buf_size = rw_buf_size/256;
    for ( i = 0; i < rw_buf_size; i++)  /* copy string to write buffer as each block */
    {
    	for(j=0;j<256;j++)
    	{
    		rw_buf_write[i*256+j] = j;
    	}
    }
    printf("----------------------set write data:------------------------\n");
    //DumpHexByte(rw_buf_write,MAX_RW_BLK * BLOCK_SIZE);
}

/***********************
 校验函数：
 成功返回 0；
 失败返回出错的位置；
 *********************************/
T_UWORD verifyData(uint8_t* writeBuffer, uint8_t* readBuffer, size_t dataSize) {
	T_UWORD  i ;
    for ( i = 0; i < dataSize; ++i) {
        if (writeBuffer[i] != readBuffer[i]) {
            printf("Data mismatch at position %zu. Expected: %02X, Actual: %02X\n", i, writeBuffer[i], readBuffer[i]);
            return i+1; // 返回出错的位置
        }
    }
    return 0; // 全部正确
}
/* mmc 擦除测试
 * mmc擦除的组，一组为1024块；
 *
 */
void mmc_erase_test(void)
{
	T_WORD fd,ret;
	T_UWORD erase_startgroup=0,erase_endgroup=0;
	printf("************app mmc_erase_test  begin**************\n");
	fd = open("/dev/mmc",NULL);
	if(fd < 0){
				printf("open /dev/mmc failed\n");
	}else{
		printf("open /dev/mmc successful\n");
	}

	/* 设置擦除的组起始地址 */
	erase_startgroup = 0;
	ret = ioctl(fd,MMC_IOC_SET_ERASE_STARTGROUP,&erase_startgroup);
	if(ret ==0){
		printf("set erase start group successful,erase_startgroup = %d\n",erase_startgroup);
	}else {
		printf("set erase start group error\n");
	}

	/* 设置擦除的组块结束地址*/
	erase_endgroup = 1;
	ret = ioctl(fd,MMC_IOC_SET_ERASE_ENDGROUP,&erase_endgroup);
	if(ret ==0){
		printf("set erase end start group successful,erase_endgroup = %d\n",erase_endgroup);
	}else {
		printf("set erase end start group error\n");
	}
	/*  擦除操作  */
	ret = ioctl(fd,MMC_IOC_ERASE_GROUNP,NULL);
	if(ret ==0){
		printf(" erase group successful\n");
	}else {
		printf("erase group error\n");
	}
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$read after erase$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	ret = read(fd,rw_buf_read,MAX_RW_BLK * BLOCK_SIZE);
	if(ret == MAX_RW_BLK * BLOCK_SIZE){
		  printf("~~~~~~~~~~~~~~~~~~~~~app read data~~~~~~~~~~~~~~~~~~~:\n");
		  DumpHexByte(rw_buf_read,MAX_RW_BLK * BLOCK_SIZE);
	}
	printf("************app mmc_erase_test  end**************\n");
	ret = close(fd);
	if(ret ==0){
		printf("close successful\n");
	}else {
		printf("close failed\n");
	}
}
/*读写测试*/
void mmc_read_write_test(void)
{
		printf("************app mmc_read_write_test  begin**************\n");

		T_WORD fd,ret;
		T_UWORD current_read_block=0,current_write_block=0;  /* 读写块*/

		fd = open("/dev/mmc",NULL);
		if(fd < 0){
				printf("open /dev/mmc failed\n");
		}else{
			printf("open /dev/mmc successful\n");
		}
		/*  获取当前读地址 */
		ret = ioctl(fd,MMC_IOC_GET_CUR_READ_BLOCK,&current_read_block);
		if(ret ==0){
				printf("get current read block successful,current_read_block = %d\n",current_read_block);
		}else {
			printf("get current read block error\n");
		}
		/* 获取当前写地址  */
		ret = ioctl(fd,MMC_IOC_GET_CUR_WRITE_BLOCK,&current_write_block);
		if(ret ==0){
				printf("get current write block successful,current_write_block = %d\n",current_write_block);
		}else {
			printf("get current write block error\n");
		}

		set_rw_buf_write_data();  /* 填充写数据 */
		printf("rw_buf_write address = 0x%x\n",rw_buf_write);
		printf("app begin write\n");

		ret = write(fd,rw_buf_write,MAX_RW_BLK * BLOCK_SIZE);
		if(ret !=0)
		{
			printf("write /dev/mmc failed\n");
		}
		printf("app begin read\n");
		memset(rw_buf_read,0, MAX_RW_BLK * BLOCK_SIZE);  /* 写多少读多少*/
		ret = read(fd,rw_buf_read,MAX_RW_BLK * BLOCK_SIZE);
		if(ret == MAX_RW_BLK * BLOCK_SIZE){
			 // printf("~~~~~~~~~~~~~~~~~~~~~app read data~~~~~~~~~~~~~~~~~~~:\n");
			// DumpHexByte(rw_buf_read,MAX_RW_BLK * BLOCK_SIZE);
		}else{
			printf("app read err\n");
		}
		ret = verifyData(rw_buf_write, rw_buf_read, MAX_RW_BLK * BLOCK_SIZE); /* 第一次校验*/
		if(ret == 0){
				printf("verifyData pass\n");
		}else {
			printf("verifyData faile in address = %d\n",ret);
		}
		memset(rw_buf_read, 0, 2*MAX_RW_BLK * BLOCK_SIZE);  /* 清空读缓存数据*/
		current_read_block = MAX_RW_BLK;  /*设置当前的读起始块为4*/
		ret = ioctl(fd,MMC_IOC_SET_CUR_READ_BLOCK,&current_read_block);
		if(ret ==0){
				printf("set current read block successful,current_read_block = %d\n",current_read_block);
		}else {
			printf("get current read block error\n");
		}
		ret = ioctl(fd,MMC_IOC_GET_CUR_READ_BLOCK,&current_read_block);
		if(ret ==0){
				printf("get current read block successful,current_read_block = %d\n",current_read_block);
		}else {
			printf("get current read block error\n");
		}
		current_write_block = MAX_RW_BLK;  /*设置当前的写起始块为4*/
		ret = ioctl(fd,MMC_IOC_SET_CUR_WRITE_BLOCK,&current_write_block);
		if(ret ==0){
				printf("set current write block successful,current_write_block = %d\n",current_write_block);
		}else {
			printf("get current write block error\n");
		}
		ret = ioctl(fd,MMC_IOC_GET_CUR_WRITE_BLOCK,&current_write_block);
		if(ret ==0){
				printf("get current write block successful,current_write_block = %d\n",current_write_block);
		}else {
			printf("get current write block error\n");
		}
		printf("&&&&&&&&&&&&&&&&&&&&&&&&&&write test&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
		ret = write(fd,rw_buf_write,MAX_RW_BLK * BLOCK_SIZE);
		if(ret !=0)
		{
			printf("write /dev/mmc failed\n");
		}
		current_read_block = 0; /*设置当前的读起始块为0*/
		ret = ioctl(fd,MMC_IOC_SET_CUR_READ_BLOCK,&current_read_block);
		if(ret ==0){
				printf("set current read block successful,current_read_block = %d\n",current_read_block);
		}else {
			printf("get current read block error\n");
		}
		ret = ioctl(fd,MMC_IOC_GET_CUR_READ_BLOCK,&current_read_block);
		if(ret ==0){
				printf("get current read block successful,current_read_block = %d\n",current_read_block);
		}else {
			printf("get current read block error\n");
		}
		printf("begin read\n");
		ret = read(fd,rw_buf_read,2*MAX_RW_BLK * BLOCK_SIZE);   /* 两次写的块一起读出，验证设置读写块的ioctrl功能 */
		if(ret == 2*MAX_RW_BLK * BLOCK_SIZE){
//			  printf("~~~~~~~~~~~~~~~~~~~~~app read data~~~~~~~~~~~~~~~~~~~:\n");
//			  DumpHexByte(rw_buf_read,2*MAX_RW_BLK * BLOCK_SIZE);
		}else{
			printf("app read err\n");
		}
		ret = verifyData(rw_buf_write, rw_buf_read, 2*MAX_RW_BLK * BLOCK_SIZE); /* 第一次校验*/
		if(ret == 0){
				printf("verifyData pass\n");
		}else {
			printf("verifyData faile in address = %d\n",ret);
		}
		ret = close(fd);
		if(ret ==0){
			printf("close successful\n");
		}else {
			printf("close failed\n");
		}
		printf("************app mmc_read_write_test  end**************\n");
		while(1){
			TTOS_SleepTask(1000);
		}
}

/*读写性能测试*/
void mmc_read_write_speed_test(void)
{
		printf("************app mmc_read_write_speed_test  begin**************\n");

		T_WORD fd,ret,i;
		T_UWORD current_read_block=0,current_write_block=0;  /* 读写块*/
		UINT64 start_time, end_time;
		UINT64 result_read_time,result_write_time;
		double tmp,  write_speed,read_speed;
		fd = open("/dev/mmc",NULL);
		if(fd < 0){
				printf("open /dev/mmc failed\n");
		}else{
			printf("open /dev/mmc successful\n");
		}
		/*  获取当前读地址 */
		ret = ioctl(fd,MMC_IOC_GET_CUR_READ_BLOCK,&current_read_block);
		if(ret ==0){
				printf("get current read block successful,current_read_block = %d\n",current_read_block);
		}else {
			printf("get current read block error\n");
		}
		/* 获取当前写地址  */
		ret = ioctl(fd,MMC_IOC_GET_CUR_WRITE_BLOCK,&current_write_block);
		if(ret ==0){
				printf("get current write block successful,current_write_block = %d\n",current_write_block);
		}else {
			printf("get current write block error\n");
		}

		set_rw_buf_write_data();  /* 填充写数据 */
		printf("rw_buf_write address = 0x%x\n",rw_buf_write);
		printf("app begin write\n");
		start_time = TTOS_GetCurrentSystemCount();  /*记录写开始时间*/
		for(i = 0;i< read_write_time;i++){
			ret = write(fd,rw_buf_write,MAX_RW_BLK * BLOCK_SIZE);
			if(ret !=0)
			{
				printf("write /dev/mmc failed\n");
			}
		}
		end_time = TTOS_GetCurrentSystemCount();  /* 记录写结束时间 */
		result_write_time = TTOS_GetCurrentSystemSubTime(start_time,end_time,TTOS_MS_UNIT);
		printf("write time is %lld ms\n",result_write_time);


		printf("app begin read\n");
		memset(rw_buf_read,0, MAX_RW_BLK * BLOCK_SIZE);  /* 写多少读多少*/

		start_time = TTOS_GetCurrentSystemCount();  /*记录读开始时间*/
		for(i = 0;i< read_write_time;i++){
			ret = read(fd,rw_buf_read,MAX_RW_BLK * BLOCK_SIZE);
			if(ret == MAX_RW_BLK * BLOCK_SIZE){
				 // printf("~~~~~~~~~~~~~~~~~~~~~app read data~~~~~~~~~~~~~~~~~~~:\n");
				// DumpHexByte(rw_buf_read,MAX_RW_BLK * BLOCK_SIZE);
			}else{
				printf("app read err\n");
			}
		}
		end_time = TTOS_GetCurrentSystemCount();  /* 记录读结束时间 */
		result_read_time = TTOS_GetCurrentSystemSubTime(start_time,end_time,TTOS_MS_UNIT);
		printf("read time is %lld ms\n",result_read_time);

		printf("************app mmc_read_write_speed result**************\n");
	    // 计算写入速度
	     tmp = result_write_time / 1000.0;     /* 单位 s*/
	     write_speed = (read_write_time / tmp) ;  // MB/s
	    printf("Write Speed: %.2f MB/s\n", write_speed);

	    // 计算读速度
	    tmp = result_read_time / 1000.0;     /* 单位 s*/
	    read_speed = (read_write_time / tmp) ;  // MB/s
	    printf("Read Speed: %.2f MB/s\n", read_speed);
		printf("************app mmc_read_write_speed  end**************\n");
		while(1){
			TTOS_SleepTask(1000);
		}
}

