#include <iostream>
#include <vector>
#include <windows.h>
#include <thread>



using namespace std;
using int32 = __int32;
using int64 = __int64;

/*
	thread 마다 자신만의 공간을 따로 갖게 된다.
	thread 마다 고유하게 들고 있어야만 하는 정보들을 넣어 활용할 수 있다.
*/
thread_local int32 LThreadId = 0;

void ThreadMain(int32 threadId)
{
	LThreadId = threadId;

	while (true)
	{
		cout << "Thread [" << threadId << "]" << endl;
		this_thread::sleep_for(1s);
	}
}

void main()
{
	vector<thread> threads;

	for (int32 i = 0; i < 10; i++)
	{
		int32 threadId = i + 1;
		threads.push_back(thread(ThreadMain, threadId));
	}

	for (thread& threadElem : threads)
	{
		threadElem.join(); // thread 합류
	}
}