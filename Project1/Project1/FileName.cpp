#include "FileName.h"



FileName::FileName(string state_in, string file_name_in, string file_description_in, string form_name_in)
{
	state = state_in;
	file_name = file_name_in;
	file_description = "N/A";
	form_name = "N/A";
}


FileName::~FileName()
{
}

string FileName::getState()
{
	return state;
}

string FileName::getFile_Name()
{
	return file_name;
}
string FileName::getFile_Description()
{
	return file_description;
}
void FileName::set_fileDesciption(string file_describe)
{
	file_description = file_describe;
}
string FileName::get_FormName()
{
	return form_name;;
}
void FileName::set_FormName(string form_name_input)
{
	form_name = form_name_input;
}
void FileName::set_FileName(string file_name_input)
{
	int found = file_name_input.find("_");
	if (found >= 0)
	{
		
		file_name.replace(found, 1, "-");
	}
}