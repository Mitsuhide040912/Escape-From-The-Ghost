#pragma once
#include "Engine/GameObject.h"
namespace 
{
	const double DEF_TIMER_TIME{ 1.0f };
}
class CoolTimer : public GameObject
{
	double CountDownTimer;
	double TIMER_INITAL_TIMER;
	bool isTimer_Run;
public:
	CoolTimer() : TIMER_INITAL_TIMER(DEF_TIMER_TIME), CountDownTimer(DEF_TIMER_TIME),
		isTimer_Run(true) {};
	CoolTimer(double _initTime) : TIMER_INITAL_TIMER(_initTime), CountDownTimer(_initTime),
		isTimer_Run(true) {};
	bool IsTimeOver();
	void ResetTimer();
	void StartTimer();
	void StopTimer();
	void Update();
	double GetTime() { return(CountDownTimer); }
};

