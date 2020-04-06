#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

void LaunchPad();

//Integer that holds the total number of rockets launched
static int totalRocketsLaunched;

static bool abortButton = false;

//Thread 0
int main()
{
	//Start with one thread: main

	cout << "*******Moon Base (Threading)********" << endl;

	//Tells the user the ID of the main thread
	cout << "Main Thread ID: " << this_thread::get_id() << endl;
	cout << "To start launching rockets, ";
	system("pause");

	//Integer that holds the total number of rockets launched from Mission Control
	int mcLaunchedRockets = 0;

	//Launches the first rocket
	cout << "Launching rocket #" << ++mcLaunchedRockets << " from Mission Control." << endl;
	cout << "\n\tThis is rocket #" << ++totalRocketsLaunched << " overall.\n\n";
	
	//Start a brand new thread
	thread thread_LaunchPad(LaunchPad);

	//Join the new thread
	thread_LaunchPad.join();

	cout << "\n\n\t\tThank you for using Missiles R Us";
	return 0;
}

void LaunchPad()
{
	//Integer that holds the total number of rockets launched from Launch Pad
	int lpLaunchedRockets = 0;

	//Tells the user the ID of the secondary thread
	cout << "Launch Pad Thread ID: " << this_thread::get_id() << endl << endl;

	//Abort Button Prompt
	cout << "\t***To abort rocket launch, press space bar***\n\n";

	while (abortButton != true)
	{
		//Continuously launches rockets until abort button is pressed
		cout << "Launching local rocket #" << ++lpLaunchedRockets << " from launch pad.\n";
		cout << "\n\tThis is rocket #" << ++totalRocketsLaunched << " overall.\n\n";

		//Simulate waiting time
		this_thread::sleep_for(3s);
		if (GetKeyState(VK_SPACE))
		{
			abortButton = true;
			cout << "\n\tLaunches Aborted\n";
		}
	}
}
