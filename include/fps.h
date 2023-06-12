#ifndef FPS_H_
#define FPS_H_

#include <math.h>
#include "DxLib.h"

class Fps {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 60;	//設定したFPS

public:
	Fps();

	bool Update();

	void Draw();

	void Wait();
};

#endif // !FPS_H_