#include <iostream>
#include <thread>
using namespace std;

void LaunchPad();

static int totalRocketsLaunched;

static bool abortButton = false;

//Thread 0
int main()
{
	//Start with one thread: main

	cout << "*******Moon Base (Threading)********" << endl;


	cout << "Main Thread ID: " << this_thread::get_id() << endl;
	cout << "To start launching rockets, ";
	system("pause");


	int mcLaunchedRockets = 0;
	mcLaunchedRockets++;
	totalRocketsLaunched++;
	cout << "Launching rocket #" << mcLaunchedRockets << " from Mission Control." << endl;
	cout << "This is rocket #" << totalRocketsLaunched << " overall.\n";

	
	//Start a brand new thread
	thread thread_LaunchPad(LaunchPad);


	//Abort Button
	cout << "To abort rocket launch, press space bar.\n";
	system("pause");
	abortButton = true;
	cout << "\n\tLaunches Aborted\n";
	thread_LaunchPad.join();

	return 0;
}

void LaunchPad()
{
	int lpLaunchedRockets = 0;

	cout << "Launch Pad Thread ID: " << this_thread::get_id() << endl;

	while (abortButton != true)
	{
		cout << "Launching local rocket #" << ++lpLaunchedRockets << " from launch pad.\n";
		cout << "This is rocket #" << ++totalRocketsLaunched << " overall.\n";
		//Simulate waiting time
		this_thread::sleep_for(5s);
	}
}
