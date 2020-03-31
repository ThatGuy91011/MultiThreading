#include <iostream>
#include <thread>
using namespace std;

void LaunchRocket();

//Thread 0
int main()
{
	//Start with one thread: main

	cout << "*******Moon Base (Threading)********" << endl;

	//Start a brand new thread
	thread thread_LaunchRocket(LaunchRocket);

	//Checks if thread 1 is still active
	if (thread_LaunchRocket.joinable())
	{
		//If thread 1 is still active, tell thread 0 to wait on thread 1 to finish before continuing on.
		thread_LaunchRocket.join();
	}


	return 0;
}

//Thread 1
void LaunchRocket()
{
	//Running on a new thread

	cout << "Launching Rocket..." << endl;
}