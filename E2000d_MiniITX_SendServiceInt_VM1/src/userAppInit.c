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
#include <commonTypes.h>
#include <partition.h>
#include<vmkVint.h>
#include<ttos.h>

/************************�� �� ��******************************/
/************************���Ͷ���******************************/
/************************�ⲿ����******************************/
/************************ǰ������******************************/
/************************ģ�����******************************/
/************************ȫ�ֱ���******************************/
/************************ʵ   ��*******************************/
/*	�����жϴ������	*/
T_VOID Handler1() {
	printk("vm1 recv service int 1\n");
}
/*	�����жϴ������	*/
T_VOID Handler2() {
	printk("vm1 recv service int 2\n");
}
/*	�����жϴ������	*/
T_VOID Handler4() {
	printk("vm1recv service int 4\n");
}
/*	�����жϴ������	*/
T_VOID Handler5() {
	printk("vm1 recv service int 5\n");
}

int userAppInit(void) {
	T_VBSP_ReturnCode ret;
	T_UWORD vm1ID;
	T_UWORD vm2ID;

	printk(">>>vm1 entry\n");

	printk("InstallVintHandler..... \n");

	/* ��װ���������жϣ��жϺ�Ϊ1�������жϴ������ΪHandler1 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 1, Handler1,TTOS_VINT_USERDEFINE);
	if (ret != VBSP_OK) {

		printk("TTOS_InstallVintHandler  ret %d\n", ret);
	}
	/* ��װ���������жϣ��жϺ�Ϊ2�������жϴ������ΪHandler2 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 2, Handler2,TTOS_VINT_USERDEFINE);
	if (ret != VBSP_OK) {

		printk("TTOS_InstallVintHandler  ret %d\n", ret);
	}
	/* ��װ���������жϣ��жϺ�Ϊ4�������жϴ������ΪHandler4 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 4, Handler4,TTOS_VINT_USERDEFINE);
	if (ret != VBSP_OK) {

		printk("TTOS_InstallVintHandler  ret %d\n", ret);
	}
	/* ��װ���������жϣ��жϺ�Ϊ5�������жϴ������ΪHandler5 */
	ret = TTOS_InstallVintHandler(VMK_VINT_SERVICE, 5, Handler5,TTOS_VINT_USERDEFINE	);
	if (ret != VBSP_OK) {

		printk("TTOS_InstallVintHandler  ret %d\n", ret);
	}

	printk("InstallVintHandler over\n");

	/*	��ȡvm1��ID	*/
	ret = VMK_GetVMID("vm1", &vm1ID);
	if (ret != VMK_OK) {
		printk("get id fail\n");
	}
	/*	��ȡvm2��ID	*/
	ret = VMK_GetVMID("vm2", &vm2ID);
	if (ret != VMK_OK) {
		printk("get id fail\n");
	}

	/*		��vm1������������жϣ��жϺ�Ϊ1	*/
	printk("send service int 1...\n");
	ret = VMK_SendServiceInt(vm1ID, 1);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	/*		��vm1������������жϣ��жϺ�Ϊ2	*/
	printk("send service int 2...\n");
	ret = VMK_SendServiceInt(vm1ID, 2);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	/*		��vm1������������жϣ��жϺ�Ϊ4	*/
	printk("send service int 4...\n");
	ret = VMK_SendServiceInt(vm1ID, 4);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	/*		��vm1������������жϣ��жϺ�Ϊ5	*/
	printk("send service int 5...\n");
	ret = VMK_SendServiceInt(vm1ID, 5);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}

	/*		��vm2������������жϣ��жϺ�Ϊ6	*/
	ret = VMK_SendServiceInt(vm2ID, 6);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	else{

	printk("send service int 6...\n");
	}
	/*		��vm2������������жϣ��жϺ�Ϊ7	*/
	ret = VMK_SendServiceInt(vm2ID, 7);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	else{

	printk("send service int 7...\n");
	}
	/*		��vm2������������жϣ��жϺ�Ϊ9	*/
	ret = VMK_SendServiceInt(vm2ID, 9);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	else{

	printk("send service int 9...\n");
	}
	/*		��vm2������������жϣ��жϺ�Ϊ11	*/
	ret = VMK_SendServiceInt(vm2ID, 11);
	if (ret != VMK_OK) {
		printk("send fail\n");
	}
	else{

	printk("send service int 11...\n");
	}

	printk("send service int over \n");
	return 0;
}

