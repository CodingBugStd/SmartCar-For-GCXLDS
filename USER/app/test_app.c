#include "test_app.h"
#include <math.h>

#define val	3.14/180

void test_app_task(void)
{
	//TestPart1();
//	TestPart2();
//	TestPart2_1();
}

void TestPart1(void)
{
	//圆周运动
	static int Angle = 0;
	static uint16_t IncTime = 0;
	int Xspeed,Yspeed;
	if(IncTime==10)
	{
		Angle++;
		Xspeed = (int)(sin((double)(Angle*val))*150);
		Yspeed = (int)(cos((double)(Angle*val))*150);
		VectorMove_Set(Xspeed,Yspeed);
		IncTime =0;
	}
	IncTime++;
}
