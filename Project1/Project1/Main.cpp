#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "FileName.h"
#include "FileDescription.h"

using namespace std;

void file_intake(string& file_to_read, string& line, vector<FileName*>&file_name_list, vector<FileDescription*>&file_description_list)
{
	string state;
	string file_name;
	string form_name;
	int upload_choice = 0;
	string file_description;
	ifstream infile(file_to_read);
	cout << "Would you like to upload the file list or the description list?";
	cin >> upload_choice;
	if (upload_choice == 1)
	{
		if (infile.is_open())
		{
			while (getline(infile, line))
			{
				istringstream ss(line);
				ss >> state;
				ss >> file_name;
				getline(ss, file_description);
				FileName* newFile = new FileName(state, file_name, "N/A", form_name);
				file_name_list.push_back(newFile);
			}
		}
	}
	if (upload_choice == 2)
	{
		if (infile.is_open())
		{
			while (getline(infile, line))
			{
				istringstream ss(line);
				ss >> state;
				ss >> form_name;
				getline(ss, file_description);
				FileDescription* newFileDescription = new FileDescription(state, form_name, file_description);
				file_description_list.push_back(newFileDescription);
			}
		}
	}

}

void ProcessFiles(vector<FileName*>&file_name_list,  vector<FileName*>&files_already_processed, vector<FileDescription*>&file_description_list)
{
	
	int FileProcessed = 0;
	//Go through list of files
	for (int h = 0; h < file_name_list.size(); h++)
	{
		file_name_list[h]->set_FileName(file_name_list[h]->getFile_Name());

		//Go through the list of file descriptions
		for (int b = 0; b < file_description_list.size(); b++)
		{
			//If a file name contains the same characters as the file description list, then the program will set the filedescription to match. 
			string str1 = file_name_list[h]->getFile_Name();
			string str2 = file_description_list[b]->getFormName();
			string state1 = file_name_list[h]->getState();
			string state2 = file_description_list[b]->getState();
			int found = str1.find(str2);
			if (found != -1 && state1 == state2)
			{
				file_name_list[h]->set_fileDesciption(file_description_list[b]->getFileDescription());
				file_name_list[h]->set_FormName(file_description_list[b]->getFormName());
				files_already_processed.push_back(file_name_list[h]);
			}
			else
			{
				FileProcessed = -1;
			}
		}
		//Go back to the top of the loop and do not add the repeated file to the list
	}
}

void PrintMore(vector<FileName*>&files_already_processed, string& out_file)
{
	cout << "Which file would you like to save this into?";
	cin >> out_file;
	ofstream outfile(out_file);
	string appForm1 = "6420";
	string appForm2 = "6486";
	string appForm3 = "6404";
	outfile << "product_series" << "," << "state" << "," << "form_name" << "," << "file_name" << "," << "new_business" << "," << "customer_service" << "," << "individual_plan" << "," << "group_plan"
		<< "," << "standard" << "," << "order" << "," << "download" << "," << "description" << endl;
	for (int i = 0; i < files_already_processed.size(); i++)
	{
		string str = files_already_processed[i]->get_FormName();
		outfile << "Term" << "," << files_already_processed[i]->getState() << "," << files_already_processed[i]->get_FormName() << "," << files_already_processed[i]->getFile_Name()
			<< "," << "TRUE" << "," << "FALSE" << "," << "TRUE" << "," << "FALSE" << ",";
		int found_standardForm1 = str.find(appForm1);
		int found_standardForm2 = str.find(appForm2);
		int found_standardForm3 = str.find(appForm3);
		if (found_standardForm1 != -1 || found_standardForm2 != -1 || found_standardForm3 != -1)
		{
			outfile << "TRUE" << ",";
		}
		else
		{
			outfile << "FALSE" << ",";
		}
		outfile << i << "," << i << "," << files_already_processed[i]->getFile_Description() << endl;
	}
}
int main()
{
	string file_to_read;
	string out_file;
	bool uploadMoreFiles;
	vector <FileName*>file_name_list;
	vector<FileName*>files_already_processed;
	vector<FileDescription*>file_description_list;
	string line;
	while (true)
	{
		cout << "Would you like to add more files? (1-Yes 0- No)";
		cin >> uploadMoreFiles;
		if (uploadMoreFiles != true)
		{
			break;
		}	
		cout << "What file will be read in?";
		cin >> file_to_read;
		file_intake(file_to_read, line, file_name_list, file_description_list);
	}
	ProcessFiles(file_name_list, files_already_processed, file_description_list);
	PrintMore(files_already_processed, out_file);
	system("pause");
	return 0;
}