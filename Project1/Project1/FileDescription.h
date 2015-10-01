#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using namespace std; 

class FileDescription
{
private:
	string state;
	string form_name;
	string fileDescription;
public:
	FileDescription(string state, string form_name, string FileDescription);
	~FileDescription();
	string getState();
	string getFormName();
	string getFileDescription();
};

