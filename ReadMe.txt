1.OLED通讯
2.OLED初始化
3.OLED缓存式更新屏幕方法(占用时序过多,可能会改)
4.OLED字库还未完成
5.OLED驱动在 /TestC8T6/USER/HARDWARE中,测试平台stm32f103c8t6
6.oled.h oled.c iic.h iic.c文件已经装载到主控芯片Driver目录下
			2021/1/15
1.完成0806，1208单个字符的显示,以page为y方向的度量单位
2.抛弃的缓存式的OLED驱动方式
			2021/1/16
1.完成字符串的打印函数
2.非负整数的打印函数
3.精简OLED驱动已经载入USER/Driver目录下,等待主控芯片调试
			2021/1/17
1.增加了动态航向修正变速参数
2.增加了控制排序机制
3.抛弃原来的固定控制流程,新增控制任务终止函数
4.控制流程更改为  控制排序表->控制状态设定->控制结束判断和控制排序表前移->控制排序表
5.根据控制接口的参数配置控制排序表(未完成)
			2021/1/21
1.position_clr除IncPID以为的部分全部重构
2.等待完成 PositionCmd_Move()  PositionCmd_TargetMove()  PositionCmd_ClrCng()
  Speed_Config() 变量的赋值方式....
3.任重道远
			2021/1/22
1.position_clr  ->  position_service
2.position_service 硬件平台测试通过  但是陀螺仪校准时间过长
3.新增基于Qt的调试专用上位机(未完成)
4.position_service()时序测试   11us左右(测试CPU主频:72MHz)
5.准备添加机械臂的相关服务函数
			2021/1/26		版本号: SmartCar _V0.10
1.引入了TCB(任务控制块)
2.解决了position_service中YawSpeed_Config()会使位移模式速度归0的bug
3.将Gyroscope刷新合并到了position_service当中
4.TCB中包含任务函数的指针,使能,运行时间段以及任务时序测量等成员
			2021/1/26		版本号: SmartCar _V0.11   TCB_Input
1.任务列表细化  ->  系统心跳任务  连续任务
2.任务列表配置函数   ->    Task_Load() -> TCB TaskList[] -> void(*SysBeatTask[])(void) && void(*ContinueTask[])(void);
3.Task_Load()本身作为初始化函数,Task_Reload()作为系统心跳任务的首个任务
4.SmartCar _V0.11 硬件平台测试通过
			2021/1/28		版本号: SmartCar _V0.12    Task_Reload
1.OpenMV色块筛选(长宽比例,颜色阈值)
2.Vofa+上位机驱动
3.wifi_service空文件
			2021/2/3		版本号: SmartCar _V0.17   OpenMV,Vofa+
1.增加矢量控制函数(未完成)
2.航向角基准修改函数
3.模块测试app
4.OpenMV二维码识别
			2021/2/5		版本号  SmartCar _V0.18   VectorMove_Set
1.矢量控制模块实机测试通过
2.航向角修正实机测试通过
3.矢量控制下取消最小速度限制
4.航向角修正速度 与 位置控制速度 可能会出Bug
			2021/2/7		版本号:  SmartCar _V0.19  VectorMove_Set-InHardware
1.OpenMV二维码识别(有的时候无法识别出二维码,find_qrcodes没有返回对象列表)
2.OpenMV图像矫正
3.MechanicalArm_Service重构
			2021/2/10		版本号:  SmartCar _V0.20  OpenMV_QrCode_Find
1.RGB565转二进制位图,阈值处理,加快二维码识别
2.OpenMV串口发送
			2021/2/12		版本号:  SmartCar _V0.20  OpenMV RGB565-> binary
1.MechanicalArm_Service完成Inc控制模式
2.机械臂基准脉宽测定‘
			2021/2/17		版本号:   SmartCar _V0.21  MechanicalArm_IncClr
1.修复了ResetWidth与初始Width不一致导致的机械臂失控
2.修复了Angle转Width返回0xffff的bug
3.增加了基于Angle的Inc机械臂控制模式
4.完成Inc控制模式的硬件平台测试
			2021/2/19		版本号:   SmartCar _V0.22  MechanicalArm_Inc Test
1.角度转脉宽验证举报正确
2.余弦定理控制有未知bug
3.MechanicalArm_Service基本框架确定
			2021/2/24		版本号:   SmartCar _V0.23 AngleToWidth Debug
1.余弦定理控制验证正确,但是有办法未知是死角,死角区域暂时没有确定
			2021/2/25		版本号:   SmartCar  _V0.24 CosinAngle_Config Debug
1.机械臂线性控制等待硬件平台测试
2.除OpenMV通信,WIFI,顶层控制,其余驱动和服务部分全部完成
			2021/3/1		版本号:    SmartCar _V0.25  Driver&Service  _BaceTest