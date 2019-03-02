#pragma once
#include<string>

#include<unordered_map>
using namespace std;
struct node
{
	int id = 0;
	string name = " ";
	int day = 0;
	int month = 0;
	int year = 0;
	string Description = " ";
	int finished = 0;

};
class taskmanager
{
	unordered_map<string, node> map_yes;
	unordered_map<string, node> map_no;

public:
	void add();
	void addfstream();
	void add_yes(node);
	void add_no(node);
	void update();
	void submit(string);
	void display();
	void submit1();
	void Delete();
	void search();
	void searchname();
	void searchdate();
	void searchstate();
	int check(node&);
	void readstream();
	void sortdate();
	taskmanager();
	~taskmanager();
};

