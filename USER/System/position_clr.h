#ifndef _POSITION_CLR_H_
#define _POSITION_CLR_H_

#include "system_core.h"

#define	SpeedKp	1.15
#define	SpeedTi 	0.82
#define	SpeedTd	0.015

#define	K_output	48			//PID输出放大倍数

#define	Speed_Max			320
#define	Speed_Stop			80
#define	Excessive_Position	80
#define	YawSpeed_Max		60

#define X 0
#define Y 1

//x-> 3000 : 900mm
//y-> 3000 : 800mm

typedef struct
{
	float pointSet;
	float Err;
	float Err1;
	float Err2;
}PID_TypeDef;

static PID_TypeDef	PID_Struct[4];			//速度PID结构体

static long int Real_position[2] = {0 , 0};			//当前坐标
static long int Target_position[2] = {0 , 0};		//目标坐标
static long int Err_position[2] = { 0 , 0 };			//坐标差值
static int Err_Yaw = 0;									//航向角偏差
static uint8_t Position_State = 0;						// 位置控制状态
static int Target_Speed[4] = {0,0,0,0};				//最终目标速度
static int Yaw_Speed = 0;								//航线角修正速度
static int Position_Speed = 0;							//位置速度

/*********************外部控制接口*****************************/
uint8_t Read_Position_State(void);							//获取位置状态
void Target_Position_Set(long int x,long int y);			//目标位置设定
void PositionState_Reset(void);								//位置状态重置
void Clr_Port(void);												//控制接口
void Inc_PID_Realiz(void);										//Inc_PID实现
/***********************内部函数*****************************/
float Inc_PID(float Input , PID_TypeDef*  PID);		//增量式PID运算
void Inc_PID_Set(int*PointSet);								//PID目标值设定
void Real_Position_Update(void);							//真实坐标更新
void Position_Clr(uint8_t Dir);									//位置控制
void Yaw_StaticClr(void);										//航向角静态修正
void PositionState_Updata(void);								//位置状态更新
void StopRun(void);												//立刻锁死

#endif

