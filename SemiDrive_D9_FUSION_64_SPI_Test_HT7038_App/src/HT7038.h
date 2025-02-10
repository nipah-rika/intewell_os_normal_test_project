#ifndef __HT7038_H__
#define __HT7038_H__

//===================================================
//      ����HT7038�����ݼĴ���
//===================================================
#define rDeviceID 0x00  //7038 Device ID
#define rPa     0x01  //A���й�����
#define rPb     0x02  //B���й�����
#define rPc     0x03  //C���й�����
#define rPt     0x04  //�����й�����

#define rQa     0x05  //A���޹�����
#define rQb     0x06  //B���޹�����
#define rQc     0x07  //C���޹�����
#define rQt     0x08  //�����޹�����

#define rSa     0x09  //A�����ڹ���
#define rSb     0x0A  //B�����ڹ���
#define rSc     0x0B  //C�����ڹ���
#define rSt     0x0C  //�������ڹ���

#define rUaRms      0x0D  //A���ѹ��Чֵ
#define rUbRms      0x0E  //B���ѹ��Чֵ
#define rUcRms      0x0F  //C���ѹ��Чֵ

#define rIaRms      0x10  //A�������Чֵ
#define rIbRms      0x11  //B�������Чֵ
#define rIcRms      0x12  //C�������Чֵ
#define rItRms      0x13  //ABC�����ʸ���͵���Чֵ

#define rPfa    0x14  //A�๦������
#define rPfb    0x15  //B�๦������
#define rPfc    0x16  //C�๦������
#define rPft    0x17  //���๦������

#define rPga    0x18  //A��������ѹ���
#define rPgb    0x19  //B��������ѹ��ǹ�������
#define rPgc    0x1a  //C��������ѹ���

#define rINTFlag  0x1b  //�жϱ�־���������� ��

#define rFreq   0x1C  //��Ƶ��
#define rEFlag  0x1d  //���ܼĴ����Ĺ���״̬�����������

#define rEpa    0x1e  //A���й�����
#define rEpb    0x1f  //B���й�����
#define rEpc    0x20  //C���й�����
#define rEpt    0x21  //�����й�����

#define rEqa    0x22  //A���޹�����
#define rEqb    0x23  //B���޹�����
#define rEqc    0x24  //C���޹�����
#define rEqt    0x25  //�����޹�����

#define rYUaUb    0x26  //Ua��Ub�ĵ�ѹ�н�            ��
#define rYUaUc    0x27  //Ua��Uc�ĵ�ѹ�н�            ��
#define rYUbUc    0x28  //Ub��Uc�ĵ�ѹ�н�            ��

#define rTPSD   0x2a  //�¶ȴ����������
#define rURmst    0x2b  //ABC��ѹʸ���͵���Чֵ

#define rS_Flag   0x2c  //��Ŷ��ࡢ����SIG�źŵ���Чֵ

#define rBackReg    0x2d  //ͨѶ���ݱ��ݼĴ�����
#define rComChksum  0x2e  //ͨѶУ��ͼĴ�����
#define rSampleIA   0x2f  //A�����ͨ��ADC�������ݡ�
#define rSampleIB   0x30  //B�����ͨ��ADC�������ݡ�
#define rSampleIC   0x31  //C�����ͨ��ADC�������ݡ�

#define rSampleUA   0x32  //A���ѹͨ��ADC�������ݡ�
#define rSampleUB   0x33  //B���ѹͨ��ADC�������ݡ�
#define rSampleUC   0x34  //C���ѹͨ��ADC�������ݡ�

#define rEsa  0x35  //A�����ڵ��ܡ�
#define rEsb  0x36  //B�����ڵ��ܡ�
#define rEsc  0x37  //C�����ڵ��ܡ�
#define rEst  0x38  //�������ڵ��ܡ�

#define rFstCntA    0x39  //A��������������
#define rFstCntB    0x40  //B��������������
#define rFstCntC    0x40  //C��������������
#define rFstCntT    0x41  //����������������

#define rPFlag    0x3d  //�й����޹����ʷ�������Ϊ0������Ϊ1

#define rChkSum 0x3e  //У������У��Ĵ�������������ģʽ����0x01D4CD;��������ģʽ����0x01E0CD;��


#define rVrefgain   0x5c  //Vref�Զ�����ϵ��
#define rChipID     0x5d  //оƬ�汾ָʾ��0X7026E0
#define rChkSum1    0x5e  //����У��Ĵ���У���

//==================================================================
//          HT7038У��Ĵ�������
//==================================================================
#define w_ModeCfg       0X01  //ģʽ��ؿ���
#define w_PGACtrl       0X02  //ADC����ѡ��
#define w_EMUCfg        0X03  //EMUģ�����üĴ���
#define w_PgainA        0X04  //A���й���������
#define w_PgainB        0X05  //B���й���������
#define w_PgainC        0X06  //C���й���������
#define w_QgainA        0X07  //A���޹���������
#define w_QgainB        0X08  //B���޹���������
#define w_QgainC        0X09  //C���޹���������
#define w_SgainA        0X0A  //A�����ڹ�������
#define w_SgainB        0X0B  //B�����ڹ�������
#define w_SgainC        0X0C  //C�����ڹ�������
#define w_PhSregApq0    0X0D  //A����λУ��0
#define w_PhSregBpq0    0X0E  //B����λУ��0
#define w_PhSregCpq0    0X0F  //C����λУ��0
#define w_PhSregApq1    0X10  //A����λУ��1
#define w_PhSregBpq1    0X11  //B����λУ��1
#define w_PhSregCpq1    0X12  //C����λУ��1
#define w_PoffsetA      0X13  //A���й�����offsetУ��
#define w_PoffsetB      0X14  //B���й�����offsetУ��
#define w_PoffsetC      0X15  //C���й�����offsetУ��
#define w_QPhscal       0X16  //�޹���λУ��
#define w_UgainA        0X17  //A���ѹ����
#define w_UgainB        0X18  //B���ѹ����
#define w_UgainC        0X19  //C���ѹ����
#define w_IgainA        0X1A  //A���������
#define w_IgainB        0X1B  //B���������
#define w_IgainC        0X1C  //C���������
#define w_Istarup       0X1D  //�𶯵�����ֵ����
#define w_Hfconst       0X1E  //��Ƶ�����������
#define w_FailVoltage   0X1F  //ʧѹ��ֵ����

#define w_QoffsetA      0X21  //A���޹�����offsetУ��
#define w_QoffsetB      0X22  //B���޹�����offsetУ��
#define w_QoffsetC      0X23  //C���޹�����offsetУ��
#define w_UaRmsoffse    0X24  //A���ѹ��ЧֵoffsetУ��
#define w_UbRmsoffse    0X25  //B���ѹ��ЧֵoffsetУ��
#define w_UcRmsoffse    0X26  //C���ѹ��ЧֵoffsetУ��
#define w_IaRmsoffse    0X27  //A�������ЧֵoffsetУ��
#define w_IbRmsoffse    0X28  //B�������ЧֵoffsetУ��
#define w_IcRmsoffse    0X29  //C�������ЧֵoffsetУ��
#define w_UoffsetA      0X2A  //A���ѹͨ��ADC offsetУ��
#define w_UoffsetB      0X2B  //B���ѹͨ��ADC offsetУ��
#define w_UoffsetC      0X2C  //C���ѹͨ��ADC offsetУ��
#define w_IoffsetA      0X2D  //A�����ͨ��ADC offsetУ��
#define w_IoffsetB      0X2E  //B�����ͨ��ADC offsetУ��
#define w_IoffsetC      0X2F  //C�����ͨ��ADC offsetУ��
#define w_EMUIE         0X30  //�ж�ʹ��
#define w_ModuleCFG     0X31  //��·ģ�����üĴ���
#define w_AllGain       0X32  //ȫͨ�����棬����У��ref��У��
#define w_HFDouble      0X33  //���峣���ӱ�ѡ��
#define w_LineGain      0X34  //��������У��
#define w_PinCtrl       0X35  //����pin����������ѡ�����
#define w_Pstartup      0X36  //�𶯹�����ֵ����
#define w_Iregion0      0X37  //��λ�����������üĴ���
#define w_Iregion1      0X60  //��λ�����������üĴ���1
#define w_PhSregApq2    0X61  //A����λУ��2
#define w_PhSregBpq2    0X62  //B����λУ��2
#define w_PhSregCpq2    0X63  //C����λУ��2
#define w_PoffsetAL     0X64  //A���й�����offsetУ�����ֽ�
#define w_PoffsetBL     0X65  //B���й�����offsetУ�����ֽ�
#define w_PoffsetCL     0X66  //C���й�����offsetУ�����ֽ�
#define w_QoffsetAL     0X67  //A���޹�����offsetУ�����ֽ�
#define w_QoffsetBL     0X68  //B���޹�����offsetУ�����ֽ�
#define w_QoffsetCL     0X69  //C���޹�����offsetУ�����ֽ�
#define w_ItRmsoffset   0X6A  //����ʸ����offsetУ���Ĵ���
#define w_TPSoffset     0X6B  //TPS��ֵУ���Ĵ���
#define w_TPSgain       0X6C  //TPSб��У���Ĵ���
#define w_TCcoffA       0X6D  //Vrefgain�Ķ���ϵ��
#define w_TCcoffB       0X6E  //Vrefgain��һ��ϵ��
#define w_TCcoffC       0X6F  //Vrefgain�ĳ�����
#define w_EMCfg         0X70  //�����㷨���ƼĴ���
void HT7038_SPI_Test(void);

#endif
