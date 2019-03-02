#include "taskmanager.h"
#include<iostream>
#include<fstream>
#include<unordered_map>

using namespace std;
ifstream file;
fstream tm;
taskmanager::taskmanager()
{

}
//add new task function  
//*********************
void taskmanager::addfstream()
{
	unordered_map<string, node>::iterator ity = map_yes.begin();
	unordered_map<string, node>::iterator itn = map_no.begin();
	tm.open("mydata.txt", ios::out);
	if (!map_yes.empty())
	{
		for (; ity != map_yes.end(); ity++)
		{

			tm << ity->second.id << "\t\t";
			tm << ity->second.name << "\t\t";
			tm << ity->second.Description << "\n";
			tm << ity->second.year << "\t\t";
			tm << ity->second.month << "\t\t";
			tm << ity->second.day << "\t\t";
			tm << ity->second.finished << "\t\t";
		}
	}
	if (!map_no.empty())
	{
		for (; itn != map_no.end(); itn++)
		{

			tm << itn->second.id << "\n";
			tm << itn->second.name << "\n";
			tm << itn->second.Description << "\n";
			tm << itn->second.year << "\n";
			tm << itn->second.month << "\n";
			tm << itn->second.day << "\n";
			tm << itn->second.finished << "\n";
		}
	}
	tm.close();

}
void taskmanager::readstream()
{
	node objn;

	int idn, yn, mn, dn, fn;
	string n, d;
	file.open("mydata.txt");



	while (!file.fail())
	{
		file >> idn;
		objn.id = idn;
		file >> n;
		objn.name = n;
		file >> d;
		objn.Description = d;
		file >> yn;
		objn.year = yn;
		file >> mn;
		objn.month = mn;
		file >> dn;
		objn.day = dn;
		file >> fn;
		objn.finished = fn;
		if (objn.finished == 1)
		{
			map_yes.insert(make_pair(objn.name, objn));
		}
		else if (objn.finished==0)
		{
			map_no.insert(make_pair(objn.name, objn));
		}


	}

	file.close();
}
void taskmanager::add()
{
	node obj;
	cout << "Enter ID for this task :  ";
	cin >> obj.id;
	cout << "Enter NAME for this task :  ";
	cin >> obj.name;
	cout << "Enter Date for this task :: \n ";
	cout << "year : ";
	cin >> obj.year;
	cout << "month : ";
	cin >> obj.month;
	cout << "day : ";
	cin >> obj.day;
	cout << "Enter DESCRIPTION for this task :  ";
	cin.ignore();
	getline(cin, obj.Description);
	cout << "Do you want to input the state for this task : (1/0 )\n";
	int l;
	cin >> l;
	if (l == 1)
	{

		cout << "Enter FINISHED STATE for this task (1/0) :  ";
		cin >> obj.finished;

	}
	else
	{
		check(obj);
	}


	if (obj.finished == 1)
	{
		add_yes(obj);
	}
	else if (obj.finished == 0)
	{
		add_no(obj);
	}


}

int taskmanager::check(node &p)
{

	if (p.year>2017)
	{
		p.finished = 0;
		return 0;


	}
	else if (p.year<2017)
	{
		p.finished = 1;
		return 1;

	}

	if (p.year == 2017)
	{
		if (p.month < 5)
		{
			p.finished = 1;
			return 1;

		}


	}

	if (2017 == p.year)
	{
		if (p.month == 5)
		{
			if (p.day <= 5)
				p.finished = 1;
			return 1;
		}


	}

	else
	{
		p.finished = 0;
		return 0;
	}


}
void taskmanager::submit(string n)
{
	node ob;
	unordered_map<string, node>::iterator it = map_no.begin();
	if (map_no.empty())
	{
		cout << "sorry there is no task you can submit it \n";
		return;
	}
	it = map_no.find(n);
	
	ob = it->second;
	ob.finished = 1;
	map_yes.insert(make_pair(n, ob));
	map_no.erase(it);
	return;


}


void taskmanager::add_yes(node ob)
{
	map_yes.insert(make_pair(ob.name, ob));




}

void taskmanager::add_no(node ob)
{

	map_no.insert(make_pair(ob.name, ob));



}

//update function 
//***************

void taskmanager::update()
{
	unordered_map<string, node>::iterator ity = map_yes.begin();
	unordered_map<string, node>::iterator itn = map_no.begin();
	string n, choice;
	cout << "Enter taks name wich you want to update  :";
	cin >> n;
	if (map_yes.empty())
	{
		if (map_no.empty())
		{
			cout << "Sorry There are no tasks you can update it \n";
			return;
		}
	}

	
	
	ity = map_yes.find(n);
	if (ity != map_yes.end())
	{


		if (ity != map_yes.end())
		{
			cout << "what Do you want to change (Date \ ID \ Descreption ) :";
			cin >> choice;
			if (choice == "date")
			{

				int d, m, y;
				cout << "Enter the new Date for this task : ";
				cout << "New year : "; cin >> y;
				cout << "New month : "; cin >> m;
				cout << "New dar :"; cin >> d;
				(*ity).second.day = d;
				(*ity).second.month = m;
				(*ity).second.year = y;
		

			}
			else if (choice == "id")
			{
				int d;
				cout << "Enter the new id : ";
				cin >> d;
				(*ity).second.id = d;
			}
			else if (choice == "description")
			{
				string d;
				cout << "Enter the new description : ";
				cin >> d;
				(*ity).second.Description = d;
			}



		}

	}
	else
	{
		itn = map_no.find(n);
		if (itn == map_no.end())
		{
			cout << "Sorry this task is not found \n";
			return;
		}
		if (itn != map_no.end())
		{
			cout << "what Do you want to change (Date \ ID \ Descreption ) :";
			cin >> choice;
			if (choice == "date")
			{
				int n, m, y;
				cout << "Enter the new Date for this task : ";
				cin >> n >> m >> y;
				(*itn).second.day = n;
				(*itn).second.month = m;
				(*itn).second.year = y;
				if (check(itn->second) == 1)
				{
					submit(itn->first);

				}
				else
				{
					return;
				}
				
				


			}
			else if (choice == "id")
			{
				int d;
				cout << "Enter the new id : ";
				cin >> d;
				(*itn).second.id = d;
			}
			else if (choice == "description")
			{
				string d;
				cout << "Enter the new description : ";
				cin >> d;
				(*itn).second.Description = d;
			}



		}
	}
}

void taskmanager::display()
{
	sortdate();
	unordered_map<string, node>::iterator ity = map_yes.begin();
	unordered_map<string, node>::iterator itn = map_no.begin();
	cout << "the information for tasks yes is : \n \n";
	if (!map_yes.empty())
	{
		for (ity = map_yes.begin(); ity != map_yes.end(); ity++)
		{

			cout <<"*Name : "<<ity->first << "  " <<"*ID : "<<ity->second.id << "    " <<"*Year : "<<ity->second.year << "    " <<"*Month : " <<ity->second.month << "   " <<"*Day : "<<ity->second.day << "    " <<"*State : "<<ity->second.finished << "\n";
		}
	}
	else
		cout << "its EMPTY \n";
	cout << "\n";
	
	cout << "the information for tasks no is : \n \n";
	if (!map_no.empty())
	{

		for (itn = map_no.begin(); itn != map_no.end(); itn++)
		{

			cout <<"*Name : "<<itn->first << "  " <<"*ID : "<<itn->second.id << "    "  <<"*Year : "<<itn->second.year << "    " <<"*Month : "<<itn->second.month << "   " <<"*Day : "<<itn->second.day << "    " <<"*State : "<<itn->second.finished << "\n";
		}
	}
	else
		cout << "its EMPTY \n";
	cout << "\n";
	return;
}

void taskmanager::submit1()
{
	string h;
	cout << "Enter  name of the task which you want to submit:  ";
	cin >> h;
	submit(h);
}
void taskmanager::Delete()
{
	string n;
	cout << "Enter name of the task you want to delete it ::  \n";
	cin >> n;
	unordered_map<string, node>::iterator ity = map_yes.begin();
	unordered_map<string, node>::iterator itn = map_no.begin();
	ity = map_yes.find(n);
	if (ity != map_yes.end())
	{
		map_yes.erase(ity);
		return;
	}
	else
	{
	
			itn = map_no.find(n);
			if (itn == map_no.end())
			{
				cout << "This taks not found \n";
				return;
			}
			map_no.erase(itn);
			
		return ;

	}
}

void taskmanager::search()
{
	string n;
	cout << "Enter kind of data you want to search with (Date \ State \ Name ) : ";
	cin >> n;

	if (n == "name")
		searchname();
	else if (n == "date")
		searchdate();
	else if (n == "state")
		searchstate();

}
void taskmanager::searchname()
{
	string n;
	cout << "Enter name for task : \n";
	cin >> n;
	unordered_map<string, node>::iterator ity = map_yes.begin();
	unordered_map<string, node>::iterator itn = map_no.begin();
	ity = map_yes.find(n);
	if (ity != map_yes.end())
	{
		cout << "The information for this task is :  \n";
		cout << "*Name : " << ity->first << "  " << "*ID : " << ity->second.id << "    " << "*Year : " << ity->second.year << "    " << "*Month : " << ity->second.month << "   " << "*Day : " << ity->second.day << "    " << "*State : " << ity->second.finished << "\n";

		return;
	}
	else
	{
		itn = map_no.find(n);
		if (itn == map_no.end())
		{
			cout << "this task not found \n";
			return;
		}
		cout << "The information for this task is :  \n";
		cout << "*Name : " << ity->first << "  " << "*ID : " << ity->second.id << "    " << "*Year : " << ity->second.year << "    " << "*Month : " << ity->second.month << "   " << "*Day : " << ity->second.day << "    " << "*State : " << ity->second.finished << "\n";


		return;

	}



}
void taskmanager::searchdate()
{
	unordered_map<string, node>::iterator ity = map_yes.begin();
	unordered_map<string, node>::iterator itn = map_no.begin();
	int y, m, d,count=0;
	cout << "Enter year and month and day : \n ";
	cin >> y >> m >> d;
	cout << "The information for this task is :  \n";
	if (!map_yes.empty())
	{
		for (ity = map_yes.begin(); ity != map_yes.end(); ity++)
		{
			if (ity->second.year == y&&ity->second.month == m&&ity->second.day == d)
			{
				
				cout << "*Name : " << ity->first << "  " << "*ID : " << ity->second.id << "    " << "*Year : " << ity->second.year << "    " << "*Month : " << ity->second.month << "   " << "*Day : " << ity->second.day << "    " << "*State : " << ity->second.finished << "\n";
				count = 1;
			}
		}
		
	}
	
   if (!map_no.empty())
	{

		for (itn = map_no.begin(); itn != map_no.end(); itn++)
		{
			if (itn->second.year == y&&itn->second.month == m &&itn->second.day == d)
			{
				
				cout << "*Name : " << itn->first << "  " << "*ID : " << itn->second.id << "    " << "*Descreption : " << itn->second.Description << "    " << "*Year : " << itn->second.year << "    " << "*Month : " << itn->second.month << "   " << "*Day : " << itn->second.day << "    " << "*State : " << itn->second.finished << "\n";
				count = 1;
			}
		}
	}
    if (count==0)
	   cout << "no task have this date \n";
     
			return;
}
void taskmanager::searchstate()
{
	unordered_map<string, node>::iterator ity = map_yes.begin();
	unordered_map<string, node>::iterator itn = map_no.begin();
	string s;
	cout << "choice your state (yes/no) : \n";
	cin >> s;
	if (s == "yes")
	{
		if (!map_yes.empty())
		{
			for (ity = map_yes.begin(); ity != map_yes.end(); ity++)
			{
				cout << "*Name : " << ity->first << "  " << "*ID : " << ity->second.id << "    " << "*Year : " << ity->second.year << "    " << "*Month : " << ity->second.month << "   " << "*Day : " << ity->second.day << "    " << "*State : " << ity->second.finished << "\n";


			}
		}
		else
			cout << "its empety \n";
	}
	else if (s == "no")
	{
		if (!map_no.empty())
		{

			for (itn = map_no.begin(); itn != map_no.end(); itn++)
			{

				cout << "*Name : " << itn->first << "  " << "*ID : " << itn->second.id << "    " << "*Year : " << itn->second.year << "    " << "*Month : " << itn->second.month << "   " << "*Day : " << itn->second.day << "    " << "*State : " << itn->second.finished << "\n";

			}
		}
		else
			cout << "its empety \n";

	}


}


void taskmanager::sortdate()
{
	unordered_map<string, node>::iterator ity1 = map_yes.begin();
	unordered_map<string, node>::iterator itn1 = map_no.begin();
	unordered_map<string, node>::iterator ity2 = map_yes.begin();
	unordered_map<string, node>::iterator itn2 = map_no.begin();

	for (; ity1 != map_yes.end(); ity1++)
	{
		for (ity2 = ity1; ity2 != map_yes.end(); ity2++)
		{
			if (ity1->second.year > ity2->second.year)
			{


				swap(map_yes[ity1->first],map_yes[ity2->first]);

			}
		}
	}

}
taskmanager::~taskmanager()
{
	addfstream();

}


