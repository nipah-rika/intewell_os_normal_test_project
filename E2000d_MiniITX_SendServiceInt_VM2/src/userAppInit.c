/*********************************************************************************
*				                                         �ƶ�(����)����Ƽ����޹�˾ ��Ȩ����
* 	 Copyright (C) 2021 Intewell (Guangzhou) Software Technology Co., Ltd. All Rights Reserved.
**********************************************************************************/

/*
 * �޸���ʷ��
 * 2017-05-10     ����, �ƶ������ݣ�����Ƽ����޹�˾
 *                �������ļ���
 *                
*/

/*
* @file��userAppInit.c
* @brief��
*	    <li>�û�����ļ���userAppInit()���û�����ں�����</li>
* @implements��
*/

/************************ͷ �� ��******************************/
#include <partition.h>
#include <commonTypes.h>
#include<vbsp.h>
#include<ttos.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/

/*	�����жϴ������	*/
T_VOID Handler6()
{
	printk("vm2 recv service int 6\n");
}
/*	�����жϴ������	*/
T_VOID Handler7()
{
	printk("vm2 recv service int 7\n");
}
/*	�����жϴ������	*/
T_VOID Handler9()
{
	printk("vm2 recv service int 9\n");
}
/*	�����жϴ������	*/
T_VOID Handler11()
{
	printk("vm2 recv service int 11\n");
}



int userAppInit(void)
{
	T_VBSP_ReturnCode ret;

	printk(">>>vm2 entry\n");

	printk("InstallVintHandler..... \n");
	/* vm2��װ���������жϣ��жϺ�Ϊ6�������жϴ������ΪHandler6 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 6, Handler6,TTOS_VINT_USERDEFINE);
    if (ret != VBSP_OK) {

    	printk("TTOS_InstallVintHandler  ret %d\n",ret);
    }
	/* vm2��װ���������жϣ��жϺ�Ϊ7�������жϴ������ΪHandler7 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 7, Handler7,TTOS_VINT_USERDEFINE);
    if (ret != VBSP_OK) {
    	printk("TTOS_InstallVintHandler  ret %d\n",ret);
    }
	/* vm2��װ���������жϣ��жϺ�Ϊ9�������жϴ������ΪHandler9 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 9, Handler9,TTOS_VINT_USERDEFINE);
    if (ret != VBSP_OK) {

    	printk("TTOS_InstallVintHandler  ret %d\n",ret);
    }
	/* vm2��װ���������жϣ��жϺ�Ϊ11�������жϴ������ΪHandler11 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 11, Handler11,TTOS_VINT_USERDEFINE);
    if (ret != VBSP_OK) {

    	printk("TTOS_InstallVintHandler  ret %d\n",ret);
    }

    printk("vm2 InstallVintHandler over !!!\n");
	return 0;
}

