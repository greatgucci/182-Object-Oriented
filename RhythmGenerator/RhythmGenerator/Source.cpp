#pragma comment(lib,"winmm")
#pragma warning(disable:4996)
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <MMsystem.h>
using namespace std;

void WriteFile(int last, char rhythm[]);

int main()
{
	int time = 0, last = 0;			// time : Current time / last : Save the last time of music.
	char rhythm[2500] = {0};		// rhythm[~]: Save the rhythm. Its size is 2500 because the length of music is 200s.
	bool bIsKeyPressed = false, bIsEnded = false;
	clock_t previousTime = 0, currentTime = 0;

	system("pause");
	PlaySoundA("music.wav", NULL, SND_ASYNC);
	previousTime = clock();

	// Start generator
	while(!bIsEnded)
	{
		currentTime = clock();
		// When key is pressed
		if(_kbhit())
		{
			if(GetAsyncKeyState(32)) {bIsKeyPressed = true;}
			else if(GetAsyncKeyState(13) && time > 5)
			{
				last=time, bIsEnded = true;
			}
		}

		// Iterate every 0.1s
		if(currentTime - previousTime >= 100)
		{
			if(bIsKeyPressed)
			{
				if(time > 1 && rhythm[time-1] == 0 && rhythm[time-2] == 0) {rhythm[time] = 1;}
			}
			previousTime = clock();
			bIsKeyPressed = false;
			cout << time << "\t" << rhythm[time] << endl;
			time++;
		}
	}

	// Save to file
	WriteFile(last, rhythm);

	system("pause");
	return 0;
}

void WriteFile(int last, char rhythm[])
{
	FILE* fp;
	int time = 0; //0~last까지의 time 값에 따른 리듬 데이터를 모두 파일에 저장하기 위해 0으로 초기화.
	
	fp = fopen("rhythm.txt", "w+");
	if(fp==NULL) {return;}

	while (time < last) //파일에 리듬 데이터 저장.
	{
		fputc(rhythm[time], fp);
		//fputs("\n", fp);
		time++;
	}
	fclose(fp);
}