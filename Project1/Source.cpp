#include<iostream>
#include "taskmanager.h"
#include <unordered_map>
using namespace std;
#include<string>

void start()
{
	taskmanager task;
	string s = "1: Add New Task \n"
		"2: Update Task Date \n"
		"3: Submit Task as Finished \n"
		"4: Delete a Task \n"
		"5: Display the Task according to the Date \n"
		"6: Search Capability \n"
		"7: To Exit From program \n"
		"******************************************** \n"
		"******************************************** \n";

	task.readstream();

	cout << s;
	int n;

	while (true)
	{

		cout << "Enter your choice : \n";
		cin >> n;
		switch (n)
		{
		case 1:
			task.add();
			cout << "******************************************** \n";
				
			break;
		case 2:
			task.update();
			cout << "******************************************** \n";
				
			break;

		case 3:
			task.submit1();
			cout << "******************************************** \n";
				
			break;
		case 4:
			task.Delete();
			cout << "******************************************** \n";
				
			break;
		case 5:
			task.display();
			cout << "******************************************** \n";
				
			break;
		case 6:
			task.search();
			cout << "******************************************** \n";
				
			break;

		default :
			
			
			return;
			break;
		}

		

	}

}


int main()
{
	start();
	system("pause");
	return 0;
}
