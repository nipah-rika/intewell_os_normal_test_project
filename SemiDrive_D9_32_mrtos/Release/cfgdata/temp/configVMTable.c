/***************************************************************************
*				科东(广州)软件科技有限公司 版权所有
* 	 Copyright (C) 2011 CoreTek Systems Inc. All Rights Reserved.
***************************************************************************/
/**
* @file: configVMTable.c
* @brief:
*        <li>SSK内核分区配置表定义<li>
* @implements:
*/

/************************头 文 件******************************/

#include <svmk.h>
#include "configMemoryBlocks.h"

/************************宏 定 义******************************/


/************************外部声明******************************/


/************************全局变量******************************/


/************************模块变量******************************/

/*
 *从实际的外部硬件中断到虚拟服务中断的映射表
 *haclVintMap中的索引号，0到CONFIG_KBSP_ISR_NUMBER对应外部中断。
 *数组中的元素，对应外部中断要映射到的虚拟服务中断。
 *比如,对于7447目标板，haclVintMap[32]=12表示
 *将外部32号中断（系统定时器），映射到12号虚拟服务中断。
 *建立此映射表的目的是为了处理中断向量号超过32的情况，目前仅
 *处理32个以内的外部中断。
 *总数不超过32个外部中断的目标板，可以采取一一映射的方式。
 *
 *警告:被映射的虚拟中断号必须唯一。
 */
T_MODULE T_UWORD haclExtIntToVintMapvm1[192]=
{
	HACL_NOT_MAPPED,/*0*/
	HACL_NOT_MAPPED,/*1*/
	HACL_NOT_MAPPED,/*2*/
	HACL_NOT_MAPPED,/*3*/
	HACL_NOT_MAPPED,/*4*/
	HACL_NOT_MAPPED,/*5*/
	HACL_NOT_MAPPED,/*6*/
	HACL_NOT_MAPPED,/*7*/
	HACL_NOT_MAPPED,/*8*/
	HACL_NOT_MAPPED,/*9*/
	HACL_NOT_MAPPED,/*10*/
	HACL_NOT_MAPPED,/*11*/
	HACL_NOT_MAPPED,/*12*/
	HACL_NOT_MAPPED,/*13*/
	HACL_NOT_MAPPED,/*14*/
	HACL_NOT_MAPPED,/*15*/
	HACL_NOT_MAPPED,/*16*/
	HACL_NOT_MAPPED,/*17*/
	HACL_NOT_MAPPED,/*18*/
	HACL_NOT_MAPPED,/*19*/
	HACL_NOT_MAPPED,/*20*/
	HACL_NOT_MAPPED,/*21*/
	HACL_NOT_MAPPED,/*22*/
	HACL_NOT_MAPPED,/*23*/
	HACL_NOT_MAPPED,/*24*/
	HACL_NOT_MAPPED,/*25*/
	HACL_NOT_MAPPED,/*26*/
	HACL_NOT_MAPPED,/*27*/
	HACL_NOT_MAPPED,/*28*/
	HACL_NOT_MAPPED,/*29*/
	HACL_NOT_MAPPED,/*30*/
	HACL_NOT_MAPPED,/*31*/
	HACL_NOT_MAPPED,/*32*/
	HACL_NOT_MAPPED,/*33*/
	HACL_NOT_MAPPED,/*34*/
	HACL_NOT_MAPPED,/*35*/
	HACL_NOT_MAPPED,/*36*/
	HACL_NOT_MAPPED,/*37*/
	HACL_NOT_MAPPED,/*38*/
	HACL_NOT_MAPPED,/*39*/
	HACL_NOT_MAPPED,/*40*/
	HACL_NOT_MAPPED,/*41*/
	HACL_NOT_MAPPED,/*42*/
	HACL_NOT_MAPPED,/*43*/
	HACL_NOT_MAPPED,/*44*/
	HACL_NOT_MAPPED,/*45*/
	HACL_NOT_MAPPED,/*46*/
	HACL_NOT_MAPPED,/*47*/
	HACL_NOT_MAPPED,/*48*/
	HACL_NOT_MAPPED,/*49*/
	HACL_NOT_MAPPED,/*50*/
	HACL_NOT_MAPPED,/*51*/
	HACL_NOT_MAPPED,/*52*/
	HACL_NOT_MAPPED,/*53*/
	HACL_NOT_MAPPED,/*54*/
	HACL_NOT_MAPPED,/*55*/
	HACL_NOT_MAPPED,/*56*/
	HACL_NOT_MAPPED,/*57*/
	HACL_NOT_MAPPED,/*58*/
	HACL_NOT_MAPPED,/*59*/
	HACL_NOT_MAPPED,/*60*/
	HACL_NOT_MAPPED,/*61*/
	HACL_NOT_MAPPED,/*62*/
	HACL_NOT_MAPPED,/*63*/
	HACL_NOT_MAPPED,/*64*/
	HACL_NOT_MAPPED,/*65*/
	HACL_NOT_MAPPED,/*66*/
	HACL_NOT_MAPPED,/*67*/
	HACL_NOT_MAPPED,/*68*/
	HACL_NOT_MAPPED,/*69*/
	HACL_NOT_MAPPED,/*70*/
	HACL_NOT_MAPPED,/*71*/
	HACL_NOT_MAPPED,/*72*/
	HACL_NOT_MAPPED,/*73*/
	HACL_NOT_MAPPED,/*74*/
	HACL_NOT_MAPPED,/*75*/
	HACL_NOT_MAPPED,/*76*/
	HACL_NOT_MAPPED,/*77*/
	HACL_NOT_MAPPED,/*78*/
	HACL_NOT_MAPPED,/*79*/
	HACL_NOT_MAPPED,/*80*/
	HACL_NOT_MAPPED,/*81*/
	HACL_NOT_MAPPED,/*82*/
	HACL_NOT_MAPPED,/*83*/
	HACL_NOT_MAPPED,/*84*/
	HACL_NOT_MAPPED,/*85*/
	HACL_NOT_MAPPED,/*86*/
	HACL_NOT_MAPPED,/*87*/
	HACL_NOT_MAPPED,/*88*/
	HACL_NOT_MAPPED,/*89*/
	HACL_NOT_MAPPED,/*90*/
	HACL_NOT_MAPPED,/*91*/
	HACL_NOT_MAPPED,/*92*/
	HACL_NOT_MAPPED,/*93*/
	HACL_NOT_MAPPED,/*94*/
	HACL_NOT_MAPPED,/*95*/
	HACL_NOT_MAPPED,/*96*/
	HACL_NOT_MAPPED,/*97*/
	HACL_NOT_MAPPED,/*98*/
	HACL_NOT_MAPPED,/*99*/
	HACL_NOT_MAPPED,/*100*/
	HACL_NOT_MAPPED,/*101*/
	HACL_NOT_MAPPED,/*102*/
	HACL_NOT_MAPPED,/*103*/
	HACL_NOT_MAPPED,/*104*/
	HACL_NOT_MAPPED,/*105*/
	HACL_NOT_MAPPED,/*106*/
	HACL_NOT_MAPPED,/*107*/
	HACL_NOT_MAPPED,/*108*/
	HACL_NOT_MAPPED,/*109*/
	HACL_NOT_MAPPED,/*110*/
	HACL_NOT_MAPPED,/*111*/
	HACL_NOT_MAPPED,/*112*/
	HACL_NOT_MAPPED,/*113*/
	HACL_NOT_MAPPED,/*114*/
	HACL_NOT_MAPPED,/*115*/
	HACL_NOT_MAPPED,/*116*/
	HACL_NOT_MAPPED,/*117*/
	HACL_NOT_MAPPED,/*118*/
	HACL_NOT_MAPPED,/*119*/
	HACL_NOT_MAPPED,/*120*/
	HACL_NOT_MAPPED,/*121*/
	HACL_NOT_MAPPED,/*122*/
	HACL_NOT_MAPPED,/*123*/
	HACL_NOT_MAPPED,/*124*/
	HACL_NOT_MAPPED,/*125*/
	HACL_NOT_MAPPED,/*126*/
	HACL_NOT_MAPPED,/*127*/
	HACL_NOT_MAPPED,/*128*/
	HACL_NOT_MAPPED,/*129*/
	HACL_NOT_MAPPED,/*130*/
	HACL_NOT_MAPPED,/*131*/
	HACL_NOT_MAPPED,/*132*/
	HACL_NOT_MAPPED,/*133*/
	HACL_NOT_MAPPED,/*134*/
	HACL_NOT_MAPPED,/*135*/
	HACL_NOT_MAPPED,/*136*/
	HACL_NOT_MAPPED,/*137*/
	HACL_NOT_MAPPED,/*138*/
	HACL_NOT_MAPPED,/*139*/
	HACL_NOT_MAPPED,/*140*/
	HACL_NOT_MAPPED,/*141*/
	HACL_NOT_MAPPED,/*142*/
	HACL_NOT_MAPPED,/*143*/
	HACL_NOT_MAPPED,/*144*/
	HACL_NOT_MAPPED,/*145*/
	HACL_NOT_MAPPED,/*146*/
	HACL_NOT_MAPPED,/*147*/
	HACL_NOT_MAPPED,/*148*/
	HACL_NOT_MAPPED,/*149*/
	HACL_NOT_MAPPED,/*150*/
	HACL_NOT_MAPPED,/*151*/
	HACL_NOT_MAPPED,/*152*/
	HACL_NOT_MAPPED,/*153*/
	HACL_NOT_MAPPED,/*154*/
	HACL_NOT_MAPPED,/*155*/
	HACL_NOT_MAPPED,/*156*/
	HACL_NOT_MAPPED,/*157*/
	HACL_NOT_MAPPED,/*158*/
	HACL_NOT_MAPPED,/*159*/
	HACL_NOT_MAPPED,/*160*/
	HACL_NOT_MAPPED,/*161*/
	HACL_NOT_MAPPED,/*162*/
	HACL_NOT_MAPPED,/*163*/
	HACL_NOT_MAPPED,/*164*/
	HACL_NOT_MAPPED,/*165*/
	HACL_NOT_MAPPED,/*166*/
	HACL_NOT_MAPPED,/*167*/
	HACL_NOT_MAPPED,/*168*/
	HACL_NOT_MAPPED,/*169*/
	HACL_NOT_MAPPED,/*170*/
	HACL_NOT_MAPPED,/*171*/
	HACL_NOT_MAPPED,/*172*/
	HACL_NOT_MAPPED,/*173*/
	HACL_NOT_MAPPED,/*174*/
	HACL_NOT_MAPPED,/*175*/
	HACL_NOT_MAPPED,/*176*/
	HACL_NOT_MAPPED,/*177*/
	HACL_NOT_MAPPED,/*178*/
	HACL_NOT_MAPPED,/*179*/
	HACL_NOT_MAPPED,/*180*/
	HACL_NOT_MAPPED,/*181*/
	HACL_NOT_MAPPED,/*182*/
	HACL_NOT_MAPPED,/*183*/
	HACL_NOT_MAPPED,/*184*/
	HACL_NOT_MAPPED,/*185*/
	HACL_NOT_MAPPED,/*186*/
	HACL_NOT_MAPPED,/*187*/
	HACL_NOT_MAPPED,/*188*/
	HACL_NOT_MAPPED,/*189*/
	HACL_NOT_MAPPED,/*190*/
	HACL_NOT_MAPPED,/*191*/
};

T_MODULE T_UWORD haclExtIntToVintMaprootAgent[192]=
{
	HACL_NOT_MAPPED,/*0*/
	HACL_NOT_MAPPED,/*1*/
	HACL_NOT_MAPPED,/*2*/
	HACL_NOT_MAPPED,/*3*/
	HACL_NOT_MAPPED,/*4*/
	HACL_NOT_MAPPED,/*5*/
	HACL_NOT_MAPPED,/*6*/
	HACL_NOT_MAPPED,/*7*/
	HACL_NOT_MAPPED,/*8*/
	HACL_NOT_MAPPED,/*9*/
	HACL_NOT_MAPPED,/*10*/
	HACL_NOT_MAPPED,/*11*/
	HACL_NOT_MAPPED,/*12*/
	HACL_NOT_MAPPED,/*13*/
	HACL_NOT_MAPPED,/*14*/
	HACL_NOT_MAPPED,/*15*/
	HACL_NOT_MAPPED,/*16*/
	HACL_NOT_MAPPED,/*17*/
	HACL_NOT_MAPPED,/*18*/
	HACL_NOT_MAPPED,/*19*/
	HACL_NOT_MAPPED,/*20*/
	HACL_NOT_MAPPED,/*21*/
	HACL_NOT_MAPPED,/*22*/
	HACL_NOT_MAPPED,/*23*/
	HACL_NOT_MAPPED,/*24*/
	HACL_NOT_MAPPED,/*25*/
	HACL_NOT_MAPPED,/*26*/
	HACL_NOT_MAPPED,/*27*/
	HACL_NOT_MAPPED,/*28*/
	HACL_NOT_MAPPED,/*29*/
	HACL_NOT_MAPPED,/*30*/
	HACL_NOT_MAPPED,/*31*/
	HACL_NOT_MAPPED,/*32*/
	HACL_NOT_MAPPED,/*33*/
	HACL_NOT_MAPPED,/*34*/
	HACL_NOT_MAPPED,/*35*/
	HACL_NOT_MAPPED,/*36*/
	HACL_NOT_MAPPED,/*37*/
	HACL_NOT_MAPPED,/*38*/
	HACL_NOT_MAPPED,/*39*/
	HACL_NOT_MAPPED,/*40*/
	HACL_NOT_MAPPED,/*41*/
	HACL_NOT_MAPPED,/*42*/
	HACL_NOT_MAPPED,/*43*/
	HACL_NOT_MAPPED,/*44*/
	HACL_NOT_MAPPED,/*45*/
	HACL_NOT_MAPPED,/*46*/
	HACL_NOT_MAPPED,/*47*/
	HACL_NOT_MAPPED,/*48*/
	HACL_NOT_MAPPED,/*49*/
	HACL_NOT_MAPPED,/*50*/
	HACL_NOT_MAPPED,/*51*/
	HACL_NOT_MAPPED,/*52*/
	HACL_NOT_MAPPED,/*53*/
	HACL_NOT_MAPPED,/*54*/
	HACL_NOT_MAPPED,/*55*/
	HACL_NOT_MAPPED,/*56*/
	HACL_NOT_MAPPED,/*57*/
	HACL_NOT_MAPPED,/*58*/
	HACL_NOT_MAPPED,/*59*/
	HACL_NOT_MAPPED,/*60*/
	HACL_NOT_MAPPED,/*61*/
	HACL_NOT_MAPPED,/*62*/
	HACL_NOT_MAPPED,/*63*/
	HACL_NOT_MAPPED,/*64*/
	HACL_NOT_MAPPED,/*65*/
	HACL_NOT_MAPPED,/*66*/
	HACL_NOT_MAPPED,/*67*/
	HACL_NOT_MAPPED,/*68*/
	HACL_NOT_MAPPED,/*69*/
	HACL_NOT_MAPPED,/*70*/
	HACL_NOT_MAPPED,/*71*/
	HACL_NOT_MAPPED,/*72*/
	HACL_NOT_MAPPED,/*73*/
	HACL_NOT_MAPPED,/*74*/
	HACL_NOT_MAPPED,/*75*/
	HACL_NOT_MAPPED,/*76*/
	HACL_NOT_MAPPED,/*77*/
	HACL_NOT_MAPPED,/*78*/
	HACL_NOT_MAPPED,/*79*/
	HACL_NOT_MAPPED,/*80*/
	HACL_NOT_MAPPED,/*81*/
	HACL_NOT_MAPPED,/*82*/
	HACL_NOT_MAPPED,/*83*/
	HACL_NOT_MAPPED,/*84*/
	HACL_NOT_MAPPED,/*85*/
	HACL_NOT_MAPPED,/*86*/
	HACL_NOT_MAPPED,/*87*/
	HACL_NOT_MAPPED,/*88*/
	HACL_NOT_MAPPED,/*89*/
	HACL_NOT_MAPPED,/*90*/
	HACL_NOT_MAPPED,/*91*/
	HACL_NOT_MAPPED,/*92*/
	HACL_NOT_MAPPED,/*93*/
	HACL_NOT_MAPPED,/*94*/
	HACL_NOT_MAPPED,/*95*/
	HACL_NOT_MAPPED,/*96*/
	HACL_NOT_MAPPED,/*97*/
	HACL_NOT_MAPPED,/*98*/
	HACL_NOT_MAPPED,/*99*/
	HACL_NOT_MAPPED,/*100*/
	HACL_NOT_MAPPED,/*101*/
	HACL_NOT_MAPPED,/*102*/
	HACL_NOT_MAPPED,/*103*/
	HACL_NOT_MAPPED,/*104*/
	HACL_NOT_MAPPED,/*105*/
	HACL_NOT_MAPPED,/*106*/
	HACL_NOT_MAPPED,/*107*/
	HACL_NOT_MAPPED,/*108*/
	HACL_NOT_MAPPED,/*109*/
	HACL_NOT_MAPPED,/*110*/
	HACL_NOT_MAPPED,/*111*/
	HACL_NOT_MAPPED,/*112*/
	HACL_NOT_MAPPED,/*113*/
	HACL_NOT_MAPPED,/*114*/
	HACL_NOT_MAPPED,/*115*/
	HACL_NOT_MAPPED,/*116*/
	HACL_NOT_MAPPED,/*117*/
	HACL_NOT_MAPPED,/*118*/
	HACL_NOT_MAPPED,/*119*/
	HACL_NOT_MAPPED,/*120*/
	HACL_NOT_MAPPED,/*121*/
	HACL_NOT_MAPPED,/*122*/
	HACL_NOT_MAPPED,/*123*/
	HACL_NOT_MAPPED,/*124*/
	HACL_NOT_MAPPED,/*125*/
	HACL_NOT_MAPPED,/*126*/
	HACL_NOT_MAPPED,/*127*/
	HACL_NOT_MAPPED,/*128*/
	HACL_NOT_MAPPED,/*129*/
	HACL_NOT_MAPPED,/*130*/
	HACL_NOT_MAPPED,/*131*/
	HACL_NOT_MAPPED,/*132*/
	HACL_NOT_MAPPED,/*133*/
	HACL_NOT_MAPPED,/*134*/
	HACL_NOT_MAPPED,/*135*/
	HACL_NOT_MAPPED,/*136*/
	HACL_NOT_MAPPED,/*137*/
	HACL_NOT_MAPPED,/*138*/
	HACL_NOT_MAPPED,/*139*/
	HACL_NOT_MAPPED,/*140*/
	HACL_NOT_MAPPED,/*141*/
	HACL_NOT_MAPPED,/*142*/
	HACL_NOT_MAPPED,/*143*/
	HACL_NOT_MAPPED,/*144*/
	HACL_NOT_MAPPED,/*145*/
	HACL_NOT_MAPPED,/*146*/
	HACL_NOT_MAPPED,/*147*/
	HACL_NOT_MAPPED,/*148*/
	HACL_NOT_MAPPED,/*149*/
	HACL_NOT_MAPPED,/*150*/
	HACL_NOT_MAPPED,/*151*/
	HACL_NOT_MAPPED,/*152*/
	HACL_NOT_MAPPED,/*153*/
	HACL_NOT_MAPPED,/*154*/
	HACL_NOT_MAPPED,/*155*/
	HACL_NOT_MAPPED,/*156*/
	HACL_NOT_MAPPED,/*157*/
	HACL_NOT_MAPPED,/*158*/
	HACL_NOT_MAPPED,/*159*/
	HACL_NOT_MAPPED,/*160*/
	HACL_NOT_MAPPED,/*161*/
	HACL_NOT_MAPPED,/*162*/
	HACL_NOT_MAPPED,/*163*/
	HACL_NOT_MAPPED,/*164*/
	HACL_NOT_MAPPED,/*165*/
	HACL_NOT_MAPPED,/*166*/
	HACL_NOT_MAPPED,/*167*/
	HACL_NOT_MAPPED,/*168*/
	HACL_NOT_MAPPED,/*169*/
	HACL_NOT_MAPPED,/*170*/
	HACL_NOT_MAPPED,/*171*/
	HACL_NOT_MAPPED,/*172*/
	HACL_NOT_MAPPED,/*173*/
	HACL_NOT_MAPPED,/*174*/
	HACL_NOT_MAPPED,/*175*/
	HACL_NOT_MAPPED,/*176*/
	HACL_NOT_MAPPED,/*177*/
	HACL_NOT_MAPPED,/*178*/
	HACL_NOT_MAPPED,/*179*/
	HACL_NOT_MAPPED,/*180*/
	HACL_NOT_MAPPED,/*181*/
	HACL_NOT_MAPPED,/*182*/
	HACL_NOT_MAPPED,/*183*/
	HACL_NOT_MAPPED,/*184*/
	HACL_NOT_MAPPED,/*185*/
	HACL_NOT_MAPPED,/*186*/
	HACL_NOT_MAPPED,/*187*/
	HACL_NOT_MAPPED,/*188*/
	HACL_NOT_MAPPED,/*189*/
	HACL_NOT_MAPPED,/*190*/
	HACL_NOT_MAPPED,/*191*/
};

T_MODULE T_UWORD haclExtIntToVintMapvm2[192]=
{
	HACL_NOT_MAPPED,/*0*/
	HACL_NOT_MAPPED,/*1*/
	HACL_NOT_MAPPED,/*2*/
	HACL_NOT_MAPPED,/*3*/
	HACL_NOT_MAPPED,/*4*/
	HACL_NOT_MAPPED,/*5*/
	HACL_NOT_MAPPED,/*6*/
	HACL_NOT_MAPPED,/*7*/
	HACL_NOT_MAPPED,/*8*/
	HACL_NOT_MAPPED,/*9*/
	HACL_NOT_MAPPED,/*10*/
	HACL_NOT_MAPPED,/*11*/
	HACL_NOT_MAPPED,/*12*/
	HACL_NOT_MAPPED,/*13*/
	HACL_NOT_MAPPED,/*14*/
	HACL_NOT_MAPPED,/*15*/
	HACL_NOT_MAPPED,/*16*/
	HACL_NOT_MAPPED,/*17*/
	HACL_NOT_MAPPED,/*18*/
	HACL_NOT_MAPPED,/*19*/
	HACL_NOT_MAPPED,/*20*/
	HACL_NOT_MAPPED,/*21*/
	HACL_NOT_MAPPED,/*22*/
	HACL_NOT_MAPPED,/*23*/
	HACL_NOT_MAPPED,/*24*/
	HACL_NOT_MAPPED,/*25*/
	HACL_NOT_MAPPED,/*26*/
	HACL_NOT_MAPPED,/*27*/
	HACL_NOT_MAPPED,/*28*/
	HACL_NOT_MAPPED,/*29*/
	HACL_NOT_MAPPED,/*30*/
	HACL_NOT_MAPPED,/*31*/
	HACL_NOT_MAPPED,/*32*/
	HACL_NOT_MAPPED,/*33*/
	HACL_NOT_MAPPED,/*34*/
	HACL_NOT_MAPPED,/*35*/
	HACL_NOT_MAPPED,/*36*/
	HACL_NOT_MAPPED,/*37*/
	HACL_NOT_MAPPED,/*38*/
	HACL_NOT_MAPPED,/*39*/
	HACL_NOT_MAPPED,/*40*/
	HACL_NOT_MAPPED,/*41*/
	HACL_NOT_MAPPED,/*42*/
	HACL_NOT_MAPPED,/*43*/
	HACL_NOT_MAPPED,/*44*/
	HACL_NOT_MAPPED,/*45*/
	HACL_NOT_MAPPED,/*46*/
	HACL_NOT_MAPPED,/*47*/
	HACL_NOT_MAPPED,/*48*/
	HACL_NOT_MAPPED,/*49*/
	HACL_NOT_MAPPED,/*50*/
	HACL_NOT_MAPPED,/*51*/
	HACL_NOT_MAPPED,/*52*/
	HACL_NOT_MAPPED,/*53*/
	HACL_NOT_MAPPED,/*54*/
	HACL_NOT_MAPPED,/*55*/
	HACL_NOT_MAPPED,/*56*/
	HACL_NOT_MAPPED,/*57*/
	HACL_NOT_MAPPED,/*58*/
	HACL_NOT_MAPPED,/*59*/
	HACL_NOT_MAPPED,/*60*/
	HACL_NOT_MAPPED,/*61*/
	HACL_NOT_MAPPED,/*62*/
	HACL_NOT_MAPPED,/*63*/
	HACL_NOT_MAPPED,/*64*/
	HACL_NOT_MAPPED,/*65*/
	HACL_NOT_MAPPED,/*66*/
	HACL_NOT_MAPPED,/*67*/
	HACL_NOT_MAPPED,/*68*/
	HACL_NOT_MAPPED,/*69*/
	HACL_NOT_MAPPED,/*70*/
	HACL_NOT_MAPPED,/*71*/
	HACL_NOT_MAPPED,/*72*/
	HACL_NOT_MAPPED,/*73*/
	HACL_NOT_MAPPED,/*74*/
	HACL_NOT_MAPPED,/*75*/
	HACL_NOT_MAPPED,/*76*/
	HACL_NOT_MAPPED,/*77*/
	HACL_NOT_MAPPED,/*78*/
	HACL_NOT_MAPPED,/*79*/
	HACL_NOT_MAPPED,/*80*/
	HACL_NOT_MAPPED,/*81*/
	HACL_NOT_MAPPED,/*82*/
	HACL_NOT_MAPPED,/*83*/
	HACL_NOT_MAPPED,/*84*/
	HACL_NOT_MAPPED,/*85*/
	HACL_NOT_MAPPED,/*86*/
	HACL_NOT_MAPPED,/*87*/
	HACL_NOT_MAPPED,/*88*/
	HACL_NOT_MAPPED,/*89*/
	HACL_NOT_MAPPED,/*90*/
	HACL_NOT_MAPPED,/*91*/
	HACL_NOT_MAPPED,/*92*/
	HACL_NOT_MAPPED,/*93*/
	HACL_NOT_MAPPED,/*94*/
	HACL_NOT_MAPPED,/*95*/
	HACL_NOT_MAPPED,/*96*/
	HACL_NOT_MAPPED,/*97*/
	HACL_NOT_MAPPED,/*98*/
	HACL_NOT_MAPPED,/*99*/
	HACL_NOT_MAPPED,/*100*/
	HACL_NOT_MAPPED,/*101*/
	HACL_NOT_MAPPED,/*102*/
	HACL_NOT_MAPPED,/*103*/
	HACL_NOT_MAPPED,/*104*/
	HACL_NOT_MAPPED,/*105*/
	HACL_NOT_MAPPED,/*106*/
	HACL_NOT_MAPPED,/*107*/
	HACL_NOT_MAPPED,/*108*/
	HACL_NOT_MAPPED,/*109*/
	HACL_NOT_MAPPED,/*110*/
	HACL_NOT_MAPPED,/*111*/
	HACL_NOT_MAPPED,/*112*/
	HACL_NOT_MAPPED,/*113*/
	HACL_NOT_MAPPED,/*114*/
	HACL_NOT_MAPPED,/*115*/
	HACL_NOT_MAPPED,/*116*/
	HACL_NOT_MAPPED,/*117*/
	HACL_NOT_MAPPED,/*118*/
	HACL_NOT_MAPPED,/*119*/
	HACL_NOT_MAPPED,/*120*/
	HACL_NOT_MAPPED,/*121*/
	HACL_NOT_MAPPED,/*122*/
	HACL_NOT_MAPPED,/*123*/
	HACL_NOT_MAPPED,/*124*/
	HACL_NOT_MAPPED,/*125*/
	HACL_NOT_MAPPED,/*126*/
	HACL_NOT_MAPPED,/*127*/
	HACL_NOT_MAPPED,/*128*/
	HACL_NOT_MAPPED,/*129*/
	HACL_NOT_MAPPED,/*130*/
	HACL_NOT_MAPPED,/*131*/
	HACL_NOT_MAPPED,/*132*/
	HACL_NOT_MAPPED,/*133*/
	HACL_NOT_MAPPED,/*134*/
	HACL_NOT_MAPPED,/*135*/
	HACL_NOT_MAPPED,/*136*/
	HACL_NOT_MAPPED,/*137*/
	HACL_NOT_MAPPED,/*138*/
	HACL_NOT_MAPPED,/*139*/
	HACL_NOT_MAPPED,/*140*/
	HACL_NOT_MAPPED,/*141*/
	HACL_NOT_MAPPED,/*142*/
	HACL_NOT_MAPPED,/*143*/
	HACL_NOT_MAPPED,/*144*/
	HACL_NOT_MAPPED,/*145*/
	HACL_NOT_MAPPED,/*146*/
	HACL_NOT_MAPPED,/*147*/
	HACL_NOT_MAPPED,/*148*/
	HACL_NOT_MAPPED,/*149*/
	HACL_NOT_MAPPED,/*150*/
	HACL_NOT_MAPPED,/*151*/
	HACL_NOT_MAPPED,/*152*/
	HACL_NOT_MAPPED,/*153*/
	HACL_NOT_MAPPED,/*154*/
	HACL_NOT_MAPPED,/*155*/
	HACL_NOT_MAPPED,/*156*/
	HACL_NOT_MAPPED,/*157*/
	HACL_NOT_MAPPED,/*158*/
	HACL_NOT_MAPPED,/*159*/
	HACL_NOT_MAPPED,/*160*/
	HACL_NOT_MAPPED,/*161*/
	HACL_NOT_MAPPED,/*162*/
	HACL_NOT_MAPPED,/*163*/
	HACL_NOT_MAPPED,/*164*/
	HACL_NOT_MAPPED,/*165*/
	HACL_NOT_MAPPED,/*166*/
	HACL_NOT_MAPPED,/*167*/
	HACL_NOT_MAPPED,/*168*/
	HACL_NOT_MAPPED,/*169*/
	HACL_NOT_MAPPED,/*170*/
	HACL_NOT_MAPPED,/*171*/
	HACL_NOT_MAPPED,/*172*/
	HACL_NOT_MAPPED,/*173*/
	HACL_NOT_MAPPED,/*174*/
	HACL_NOT_MAPPED,/*175*/
	HACL_NOT_MAPPED,/*176*/
	HACL_NOT_MAPPED,/*177*/
	HACL_NOT_MAPPED,/*178*/
	HACL_NOT_MAPPED,/*179*/
	HACL_NOT_MAPPED,/*180*/
	HACL_NOT_MAPPED,/*181*/
	HACL_NOT_MAPPED,/*182*/
	HACL_NOT_MAPPED,/*183*/
	HACL_NOT_MAPPED,/*184*/
	HACL_NOT_MAPPED,/*185*/
	HACL_NOT_MAPPED,/*186*/
	HACL_NOT_MAPPED,/*187*/
	HACL_NOT_MAPPED,/*188*/
	HACL_NOT_MAPPED,/*189*/
	HACL_NOT_MAPPED,/*190*/
	HACL_NOT_MAPPED,/*191*/
};

/*
 * haclVIntToExIntMap用于定义从虚拟中断号到实际设备向量号的映射。
 */
T_MODULE T_UWORD haclVIntToExIntMapvm1[32]=
{
	HACL_NOT_MAPPED,/*0*/
	HACL_NOT_MAPPED,/*1*/
	HACL_NOT_MAPPED,/*2*/
	HACL_NOT_MAPPED,/*3*/
	HACL_NOT_MAPPED,/*4*/
	HACL_NOT_MAPPED,/*5*/
	HACL_NOT_MAPPED,/*6*/
	HACL_NOT_MAPPED,/*7*/
	HACL_NOT_MAPPED,/*8*/
	HACL_NOT_MAPPED,/*9*/
	HACL_NOT_MAPPED,/*10*/
	HACL_NOT_MAPPED,/*11*/
	HACL_NOT_MAPPED,/*12*/
	HACL_NOT_MAPPED,/*13*/
	HACL_NOT_MAPPED,/*14*/
	HACL_NOT_MAPPED,/*15*/
	HACL_NOT_MAPPED,/*16*/
	HACL_NOT_MAPPED,/*17*/
	HACL_NOT_MAPPED,/*18*/
	HACL_NOT_MAPPED,/*19*/
	HACL_NOT_MAPPED,/*20*/
	HACL_NOT_MAPPED,/*21*/
	HACL_NOT_MAPPED,/*22*/
	HACL_NOT_MAPPED,/*23*/
	HACL_NOT_MAPPED,/*24*/
	HACL_NOT_MAPPED,/*25*/
	HACL_NOT_MAPPED,/*26*/
	HACL_NOT_MAPPED,/*27*/
	HACL_NOT_MAPPED,/*28*/
	HACL_NOT_MAPPED,/*29*/
	HACL_NOT_MAPPED,/*30*/
	HACL_NOT_MAPPED,/*31*/
};

T_MODULE T_UWORD haclVIntToExIntMaprootAgent[32]=
{
	HACL_NOT_MAPPED,/*0*/
	HACL_NOT_MAPPED,/*1*/
	HACL_NOT_MAPPED,/*2*/
	HACL_NOT_MAPPED,/*3*/
	HACL_NOT_MAPPED,/*4*/
	HACL_NOT_MAPPED,/*5*/
	HACL_NOT_MAPPED,/*6*/
	HACL_NOT_MAPPED,/*7*/
	HACL_NOT_MAPPED,/*8*/
	HACL_NOT_MAPPED,/*9*/
	HACL_NOT_MAPPED,/*10*/
	HACL_NOT_MAPPED,/*11*/
	HACL_NOT_MAPPED,/*12*/
	HACL_NOT_MAPPED,/*13*/
	HACL_NOT_MAPPED,/*14*/
	HACL_NOT_MAPPED,/*15*/
	HACL_NOT_MAPPED,/*16*/
	HACL_NOT_MAPPED,/*17*/
	HACL_NOT_MAPPED,/*18*/
	HACL_NOT_MAPPED,/*19*/
	HACL_NOT_MAPPED,/*20*/
	HACL_NOT_MAPPED,/*21*/
	HACL_NOT_MAPPED,/*22*/
	HACL_NOT_MAPPED,/*23*/
	HACL_NOT_MAPPED,/*24*/
	HACL_NOT_MAPPED,/*25*/
	HACL_NOT_MAPPED,/*26*/
	HACL_NOT_MAPPED,/*27*/
	HACL_NOT_MAPPED,/*28*/
	HACL_NOT_MAPPED,/*29*/
	HACL_NOT_MAPPED,/*30*/
	HACL_NOT_MAPPED,/*31*/
};

T_MODULE T_UWORD haclVIntToExIntMapvm2[32]=
{
	HACL_NOT_MAPPED,/*0*/
	HACL_NOT_MAPPED,/*1*/
	HACL_NOT_MAPPED,/*2*/
	HACL_NOT_MAPPED,/*3*/
	HACL_NOT_MAPPED,/*4*/
	HACL_NOT_MAPPED,/*5*/
	HACL_NOT_MAPPED,/*6*/
	HACL_NOT_MAPPED,/*7*/
	HACL_NOT_MAPPED,/*8*/
	HACL_NOT_MAPPED,/*9*/
	HACL_NOT_MAPPED,/*10*/
	HACL_NOT_MAPPED,/*11*/
	HACL_NOT_MAPPED,/*12*/
	HACL_NOT_MAPPED,/*13*/
	HACL_NOT_MAPPED,/*14*/
	HACL_NOT_MAPPED,/*15*/
	HACL_NOT_MAPPED,/*16*/
	HACL_NOT_MAPPED,/*17*/
	HACL_NOT_MAPPED,/*18*/
	HACL_NOT_MAPPED,/*19*/
	HACL_NOT_MAPPED,/*20*/
	HACL_NOT_MAPPED,/*21*/
	HACL_NOT_MAPPED,/*22*/
	HACL_NOT_MAPPED,/*23*/
	HACL_NOT_MAPPED,/*24*/
	HACL_NOT_MAPPED,/*25*/
	HACL_NOT_MAPPED,/*26*/
	HACL_NOT_MAPPED,/*27*/
	HACL_NOT_MAPPED,/*28*/
	HACL_NOT_MAPPED,/*29*/
	HACL_NOT_MAPPED,/*30*/
	HACL_NOT_MAPPED,/*31*/
};

/*外部中断映射配置*/
T_MODULE T_VMK_ConfigExintMap exintMapConfigvm1={haclExtIntToVintMapvm1,haclVIntToExIntMapvm1};

T_MODULE T_VMK_ConfigExintMap exintMapConfigrootAgent={haclExtIntToVintMaprootAgent,haclVIntToExIntMaprootAgent};

T_MODULE T_VMK_ConfigExintMap exintMapConfigvm2={haclExtIntToVintMapvm2,haclVIntToExIntMapvm2};

T_MODULE T_VMK_MemoryBlock vmSpacerootAgent[2] = CONFIG_VM_SPACEBLOCKS_rootAgent;
T_MODULE T_VMK_MemoryBlock vmSpacevm1[2] = CONFIG_VM_SPACEBLOCKS_vm1;
T_MODULE T_VMK_MemoryBlock vmSpacevm2[2] = CONFIG_VM_SPACEBLOCKS_vm2;


/**
 *分区配置表
 */
T_VMK_ConfigUserVMTable vmkConfigUserVMTable[3] = 
{
	{
		("rootAgent"),
		("rootAgent"),
		130,
		(SCHEDTYPE_PRIORITY),
		(TRUE),
		(0xc0000000),
		(100),
		(0xc0000000),
		(0x18000000),
		(VMK_SVM_SENDSERVICEVINT_MASK
),
		vmSpacerootAgent,
		0x8,
		&exintMapConfigrootAgent
	}
,	{
		("vm1"),
		("vm1"),
		120,
		(SCHEDTYPE_PRIORITY),
		(TRUE),
		(0xc0000000),
		(100),
		(0xc0000000),
		(0x6400000),
		(VMK_SVM_SENDSERVICEVINT_MASK
),
		vmSpacevm1,
		0x4,
		&exintMapConfigvm1
	}
,	{
		("vm2"),
		("vm2"),
		120,
		(SCHEDTYPE_PRIORITY),
		(TRUE),
		(0xc0000000),
		(100),
		(0xc0000000),
		(0x6400000),
		(VMK_SVM_SENDSERVICEVINT_MASK
),
		vmSpacevm2,
		0x4,
		&exintMapConfigvm2
	}
};

