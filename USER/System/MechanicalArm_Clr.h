#ifndef _MechanicalArm_Clr_H_
#define _MechanicalArm_Clr_H_
//��е�ۿ���

#include "system_core.h"

#define	Pi	acos(-1)					//Բ����
#define	StartValue		1480		//��е����λ����
#define	WidthInc_Max	7

/*************************************
��ʼ��
2535
925
400
2490
300
���ϲ�
2591
1561
374
1780
1348
���ϲ�
1559
819
2388
786
300
*************************************/

static uint16_t* street_width[6] = {(uint16_t*)&TIM3->CCR1 , (uint16_t*)&TIM3->CCR2,
							(uint16_t*)&TIM3->CCR3 , (uint16_t*)&TIM3->CCR4,
							(uint16_t*)&TIM2->CCR1 , (uint16_t*)&TIM2->CCR2 };
							
static uint8_t ArmLen[3] = {150,90,90};						//��е�۸����ֳ���(��������)	mm
static uint16_t ArmLen2[3] = {22500,8100,8100};				//��е��ƽ��,�������Ҷ������
static uint16_t Reset_Value[5] ={2535,925,400,2490,300};		//��е�۹�λ����
static uint16_t Width_Target[5] = {2535,925,400,2490,300};		//Ŀ������
static uint16_t WidthInc[5] = {3,3,3,3,6};						//5ms��������

void Angle_Realize(void);								//������е��
//uint16_t Angle_Transf(uint8_t num,int angle);				//�Ƕ�ת����
//void Angle_Config(int Yaw,int len,int hight);		//����Ŀ��λ���趨��������Ƕ�  ���Ҷ���	mm
void MechanicalArm_Reset(uint8_t mode);				//��е�۹�λ	0:ֱ�ӹ�λ  1:������λ
uint8_t Street_Check(void);
void Target_WidthSet(uint16_t*Width);
void Cash(void);
void Put(void);

#endif

