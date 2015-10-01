#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class FileName
{
private:
	string state;
	string file_name;
	string file_description;
	string form_name;

public:
	FileName(string state, string file_name, string file_description, string form_name);
	string getState();
	string getFile_Name();
	string getFile_Description();
	string get_FormName();
	void set_fileDesciption(string file_description);
	void set_FormName(string form_name_input);
	void set_FileName(string file_name_input);
	~FileName();
};

