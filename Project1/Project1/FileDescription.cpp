#include "FileDescription.h"



FileDescription::FileDescription(string state_in, string form_name_in, string fileDescription_in)
{
	state = state_in;
	form_name = form_name_in;
	fileDescription = fileDescription_in;
}


FileDescription::~FileDescription()
{
}

string FileDescription::getState()
{
	return state;
}
string FileDescription::getFileDescription()
{
	return fileDescription;
}
string FileDescription::getFormName()
{
	return form_name;
}