/*
 * @file：userAppInit.c
 * @brief：
 *	    <li>用户入口文件，userAppInit()是用户的入口函数。</li>
 * @implements：
 */

/************************头 文 件******************************/
#include <commonTypes.h>
#include <modbusIO.h>
#include <sysPwm.h>
#include <fcntl.h>
/************************宏 定 义******************************/
/************************类型定义******************************/
/************************外部声明******************************/
/************************前向声明******************************/
/************************模块变量******************************/
/************************全局变量******************************/
/************************实   现*******************************/

/* pwm pulse change times */
#define PWM_PULSE_CHANGE_TIME   10

/* pwm pulse amplitude of periodic variation */
#define PWM_PULSE_CHANGE    100

/* 对应飞腾派原理图J1座子32脚(GPIO1_1) */
#define TEST_PWM		"/PWM1_0"


/*
 * @brief:
 *    实现PWM接口操作舵机
 * @return:
 *    成功返回值为 0，失败时返回值为 -1
 */
int userAppInit(void) {
	int fd, ret;
	FPwmVariableConfig pwm_cfg;

	fd = open(TEST_PWM, MODBUS_IO_BLOCK);
	if (fd < 0) {
		printf("open pwm falied\n");
		return -1;
	}

	ret = ioctl(fd, PWM_IOC_GET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("get cfg ioctl failed\n");
		return -1;
	}
	printf("default pwm_cfg is:%d, %d, %d, %d, %d, %d, %d\n",
			pwm_cfg.tim_ctrl_mode, pwm_cfg.tim_ctrl_div, pwm_cfg.pwm_period,
			pwm_cfg.pwm_mode, pwm_cfg.pwm_polarity,
			pwm_cfg.pwm_duty_source_mode, pwm_cfg.pwm_pulse);

	/*
	**PWM模块时钟源频率为50MHZ, 输出频率为50HZ，占空比10%的PWM
	**50MHz / (tim_ctrl_div) * (pwm_period) =输出频率	 //公式1
	**50MHz / （500 * 2000） = 50Hz
	*/
	pwm_cfg.tim_ctrl_div = 500 - 1;	//分频参数500， 该分频参数是自己设定的
	pwm_cfg.pwm_period = 2000;		//输出频率为50HZ时，根据公式1计算出的pwm_period值

	/*占空比 = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 2.5%；顺时针转动180度*/
	pwm_cfg.pwm_pulse = 50;
	ret = ioctl(fd, PWM_IOC_SET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("set cfg ioctl failed\n");
		return -1;
	} else {
		printf("set cfg ioctl succesed\n");
	}

	ret = ioctl(fd, PWM_IOC_GET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("get cfg ioctl failed\n");
		return -1;
	}
	printf("after set, get pwm_cfg is:%d, %d, %d, %d, %d, %d, %d\n",
			pwm_cfg.tim_ctrl_mode, pwm_cfg.tim_ctrl_div, pwm_cfg.pwm_period,
			pwm_cfg.pwm_mode, pwm_cfg.pwm_polarity,
			pwm_cfg.pwm_duty_source_mode, pwm_cfg.pwm_pulse);

	ret = ioctl(fd, PWM_IOC_ENABLE, 0);
	if (ret < 0) {
		printf("pwm enable failed\n");
		return -1;
	} else {
		printf("pwm enable succesd\n");
	}
	TTOS_SleepTask(5 * 1000);

	/*占空比 = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 5%；顺时针转动135度*/
	pwm_cfg.pwm_pulse = 100;
	ret = ioctl(fd, PWM_IOC_SET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("set cfg ioctl failed\n");
		return -1;
	} else {
		printf("set cfg ioctl succesed\n");
	}

	ret = ioctl(fd, PWM_IOC_GET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("get cfg ioctl failed\n");
		return -1;
	}
	printf("after set, get pwm_cfg is:%d, %d, %d, %d, %d, %d, %d\n",
			pwm_cfg.tim_ctrl_mode, pwm_cfg.tim_ctrl_div, pwm_cfg.pwm_period,
			pwm_cfg.pwm_mode, pwm_cfg.pwm_polarity,
			pwm_cfg.pwm_duty_source_mode, pwm_cfg.pwm_pulse);

	ret = ioctl(fd, PWM_IOC_ENABLE, 0);
	if (ret < 0) {
		printf("pwm enable failed\n");
		return -1;
	} else {
		printf("pwm enable succesd\n");
	}
	TTOS_SleepTask(5 * 1000);

	/*占空比 = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 7.5%；顺时针转动90度*/
	pwm_cfg.pwm_pulse = 150;
	ret = ioctl(fd, PWM_IOC_SET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("set cfg ioctl failed\n");
		return -1;
	} else {
		printf("set cfg ioctl succesed\n");
	}

	ret = ioctl(fd, PWM_IOC_GET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("get cfg ioctl failed\n");
		return -1;
	}
	printf("after set, get pwm_cfg is:%d, %d, %d, %d, %d, %d, %d\n",
			pwm_cfg.tim_ctrl_mode, pwm_cfg.tim_ctrl_div, pwm_cfg.pwm_period,
			pwm_cfg.pwm_mode, pwm_cfg.pwm_polarity,
			pwm_cfg.pwm_duty_source_mode, pwm_cfg.pwm_pulse);

	ret = ioctl(fd, PWM_IOC_ENABLE, 0);
	if (ret < 0) {
		printf("pwm enable failed\n");
		return -1;
	} else {
		printf("pwm enable succesd\n");
	}
	TTOS_SleepTask(5 * 1000);

	/*占空比 = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 10%；顺时针转动45度*/
	pwm_cfg.pwm_pulse = 200;
	ret = ioctl(fd, PWM_IOC_SET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("set cfg ioctl failed\n");
		return -1;
	} else {
		printf("set cfg ioctl succesed\n");
	}

	ret = ioctl(fd, PWM_IOC_GET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("get cfg ioctl failed\n");
		return -1;
	}
	printf("after set, get pwm_cfg is:%d, %d, %d, %d, %d, %d, %d\n",
			pwm_cfg.tim_ctrl_mode, pwm_cfg.tim_ctrl_div, pwm_cfg.pwm_period,
			pwm_cfg.pwm_mode, pwm_cfg.pwm_polarity,
			pwm_cfg.pwm_duty_source_mode, pwm_cfg.pwm_pulse);

	ret = ioctl(fd, PWM_IOC_ENABLE, 0);
	if (ret < 0) {
		printf("pwm enable failed\n");
		return -1;
	} else {
		printf("pwm enable succesd\n");
	}
	TTOS_SleepTask(5 * 1000);

	/*占空比 = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 12.5%；转动0度*/
	pwm_cfg.pwm_pulse = 250;
	ret = ioctl(fd, PWM_IOC_SET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("set cfg ioctl failed\n");
		return -1;
	} else {
		printf("set cfg ioctl succesed\n");
	}

	ret = ioctl(fd, PWM_IOC_GET_CFG, &pwm_cfg);
	if (ret < 0) {
		printf("get cfg ioctl failed\n");
		return -1;
	}
	printf("after set, get pwm_cfg is:%d, %d, %d, %d, %d, %d, %d\n",
			pwm_cfg.tim_ctrl_mode, pwm_cfg.tim_ctrl_div, pwm_cfg.pwm_period,
			pwm_cfg.pwm_mode, pwm_cfg.pwm_polarity,
			pwm_cfg.pwm_duty_source_mode, pwm_cfg.pwm_pulse);

	ret = ioctl(fd, PWM_IOC_ENABLE, 0);
	if (ret < 0) {
		printf("pwm enable failed\n");
		return -1;
	} else {
		printf("pwm enable succesd\n");
	}
	TTOS_SleepTask(5 * 1000);


	ret = ioctl(fd, PWM_IOC_DISABLE, 0);
	if (ret < 0) {
		printf("pwm disable failed\n");
		return -1;
	}

	return 0;
}

