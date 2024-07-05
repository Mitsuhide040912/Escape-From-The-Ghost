#include "CoolTimer.h"

bool CoolTimer::IsTimeOver()
{
	return(CountDownTimer <= 0);
}

void CoolTimer::ResetTimer()
{
	CountDownTimer = TIMER_INITAL_TIMER;
	StartTimer();
}

void CoolTimer::StartTimer()
{
	isTimer_Run = true;
}

void CoolTimer::StopTimer()
{
	isTimer_Run = false;
}

void CoolTimer::Update()
{
	/*if (isTimer_Run)
		CountDownTimer = CountDownTimer - DEF_TIMER_TIME::DeltaTime()*/
}
