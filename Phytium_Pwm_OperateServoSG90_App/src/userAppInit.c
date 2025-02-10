/*
 * @file��userAppInit.c
 * @brief��
 *	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
 * @implements��
 */

/************************ͷ �� ��******************************/
#include <commonTypes.h>
#include <modbusIO.h>
#include <sysPwm.h>
#include <fcntl.h>
/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

/* pwm pulse change times */
#define PWM_PULSE_CHANGE_TIME   10

/* pwm pulse amplitude of periodic variation */
#define PWM_PULSE_CHANGE    100

/* ��Ӧ������ԭ��ͼJ1����32��(GPIO1_1) */
#define TEST_PWM		"/PWM1_0"


/*
 * @brief:
 *    ʵ��PWM�ӿڲ������
 * @return:
 *    �ɹ�����ֵΪ 0��ʧ��ʱ����ֵΪ -1
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
	**PWMģ��ʱ��ԴƵ��Ϊ50MHZ, ���Ƶ��Ϊ50HZ��ռ�ձ�10%��PWM
	**50MHz / (tim_ctrl_div) * (pwm_period) =���Ƶ��	 //��ʽ1
	**50MHz / ��500 * 2000�� = 50Hz
	*/
	pwm_cfg.tim_ctrl_div = 500 - 1;	//��Ƶ����500�� �÷�Ƶ�������Լ��趨��
	pwm_cfg.pwm_period = 2000;		//���Ƶ��Ϊ50HZʱ�����ݹ�ʽ1�������pwm_periodֵ

	/*ռ�ձ� = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 2.5%��˳ʱ��ת��180��*/
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

	/*ռ�ձ� = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 5%��˳ʱ��ת��135��*/
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

	/*ռ�ձ� = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 7.5%��˳ʱ��ת��90��*/
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

	/*ռ�ձ� = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 10%��˳ʱ��ת��45��*/
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

	/*ռ�ձ� = pwm_cfg.pwm_pulse / pwm_cfg.pwm_period = 12.5%��ת��0��*/
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

