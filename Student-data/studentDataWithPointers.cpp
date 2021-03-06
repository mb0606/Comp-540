// studentDataWithPointers.cpp : Takes a text file as input and sorts data according to user 
//                               specification and output to new file.
// Author: Marco Berardini
// Modified: 2/18/2018
// Version: .1

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Structure for students
struct STUDENT {
	string firstName;
	string lastName;
	string id;
	float gpa;
	string email;
};

// Function prototypes.
void userPrompt(int &sortBy, int &sortDirection);
void sortData(STUDENT *pStudents[], int records, int sortBy, int sortDirection);
void swap(STUDENT *pStudents[], int i, int j);
void printToFile(STUDENT *pStudents[], int records, ofstream &file_out, int sortBy);
void readFile(STUDENT students[], STUDENT *pStudents[], int &records, ifstream &file_in, string fileName, string xHeader);
void printToScreen(STUDENT *pStudents[], int records, int sortBy);

// Define const limit for array records.
const int LIMIT = 1000;

int main()
{
	// Declarations
	// Variables
	string xHeader; // removed header from input file
	int sortBy; // user choosen sort field
	int sortDirection; // user chooses ascending or descending order
	int recordCount = 0; // incrementor
	string fileName = "studentsData.txt";

	// Data Arrays
	STUDENT students[LIMIT];
	STUDENT *pStudents[LIMIT] = { nullptr };

	// File streams
	ifstream file_in;
	ofstream file_out;
	do {
		// Read input file.
		readFile(students, pStudents, recordCount, file_in, fileName, xHeader);

		// Prompt user to enter field to sortBy.
		userPrompt(sortBy, sortDirection);

		// Quit if sortBy == 6.
		if (sortBy != 6) {
			// Input data into sort function.
			if (sortBy == 1 || sortBy == 2 || sortBy == 3 || sortBy == 4 || sortBy == 5) {
				sortData(pStudents, recordCount, sortBy, sortDirection);
			}
			// Output to screen.
			printToScreen(pStudents, recordCount, sortBy);
			// Output to File
			printToFile(pStudents, recordCount, file_out, sortBy);
		}
	} while (sortBy != 6);
	system("pause");
    return 0;

}

// Functions
// Prompt user.
void userPrompt(int &sortBy, int &sortDirection) {
	// If invalid loop entry and prompt again.
	do {
		cout << "Please tell me how you would like the records sorted " << endl;
		cout << "Enter: \n 0- Unsorted \n 1- Sort First Name \n 2- Sort Last Name \n 3- Sort GPA \n 4- Sort Email \n 5- Sort ID \n 6- Quit Program" << endl;
		cin >> sortBy;
		cout << endl;

	} while (sortBy > 6 || sortBy < 0);
	// If user does not wish to quit prompt for sort order
	if (sortBy != 0 && sortBy != 6) {
		do {
			cout << "Would you like the records sorted in : \n 1- Descending  \n 2- Ascending" << endl;
			cin >> sortDirection;
			cout << endl;
		} while (sortDirection < 1 || sortDirection > 2);

	}
}

// Read Data File.
void readFile(STUDENT students[], STUDENT *pStudents[], int &recordCount, ifstream &file_in, string fileName, string xHeader) {
	// Check that the file has successfully opened.
	file_in.open(fileName);
	if (file_in.is_open()) {
		cout << fileName << " Has sucessfully open." << endl;
		cout << endl;
	}
	else {
		cout << "Error opening file " << fileName << "." << endl;
		exit(0);
	}
	// Read and remove input file header.
	getline(file_in, xHeader);

	// Loop file data till last record.
	while (!file_in.eof() && recordCount < LIMIT) {
		// Read input data and store in students array.
		file_in >> students[recordCount].firstName;
		file_in >> students[recordCount].lastName;
		file_in >> students[recordCount].gpa;
		file_in >> students[recordCount].id;
		file_in >> students[recordCount].email;
		file_in.ignore();

		// Pass memory address to pStudents array or memory addresses.
		pStudents[recordCount] = &students[recordCount];

		// Increment record.
		recordCount++;
	}
	// Close File input.
	file_in.close();
}

// Sort data by given field.
void sortData(STUDENT *pStudents[], int records, int sortBy, int sortDirection) {
	for (int i = 0; i < records-1; i++) {
		bool swap = false;
		for (int j = i + 1; j < records; j++) {
			if (sortDirection == 1) {
				if (sortBy == 1) {
					swap = pStudents[i]->firstName > pStudents[j]->firstName;
				}
				else if ( sortBy == 2) {
					swap = pStudents[i]->lastName > pStudents[j]->lastName;
				}
				else if (sortBy == 3) {
					swap = pStudents[i]->gpa > pStudents[j]->gpa;
				}
				else if (sortBy == 4) {
					swap = pStudents[i]->email > pStudents[j]->email;
				}
				else if (sortBy == 5) {
					swap = pStudents[i]->id > pStudents[j]->id;
				}
			}
			else if (sortDirection == 2) {
				if (sortBy == 1) {
					swap = pStudents[i]->firstName < pStudents[j]->firstName;
				}
				else if (sortBy == 2) {
					swap = pStudents[i]->lastName < pStudents[j]->lastName;
				}
				else if (sortBy == 3) {
					swap = pStudents[i]->gpa < pStudents[j]->gpa;
				}
				else if (sortBy == 4) {
					swap = pStudents[i]->email < pStudents[j]->email;
				}
				else if (sortBy == 5) {
					swap = pStudents[i]->id > pStudents[j]->id;
				}
			}
			if (swap) {
				STUDENT *pTempStudent = nullptr;
				pTempStudent = pStudents[i];
				pStudents[i] = pStudents[j];
				pStudents[j] = pTempStudent;
			}
		}
	}

}

// Swap data when sortData conditions met.
void swap(STUDENT *pStudents[], int i, int j) {
	STUDENT *pTempStudent = nullptr;
	pTempStudent = pStudents[i];
	pStudents[i] = pStudents[j];
	pStudents[j] = pTempStudent;
}

// Print data to file.
void printToFile(STUDENT *pStudents[], int records, ofstream &file_out, int sortBy) {
	file_out.open("studentDataOutput.txt");
	if (sortBy == 2) {
		file_out << setw(15) << left << "Last"
			<< setw(12) << "First"
			<< setw(5) << "GPA"
			<< setw(13) << left << "Student Id"
			<< setw(30) << left << "Email"
			<< endl;
		for (int j = 0; j < records; j++) {
			file_out << setw(15) << left << pStudents[j]->lastName
				<< setw(12) << pStudents[j]->firstName
				<< setprecision(1) << fixed << showpoint
				<< setw(5) << pStudents[j]->gpa
				<< setw(13) << left << pStudents[j]->id
				<< setw(30) << left << pStudents[j]->email
				<< endl;
		}
		file_out << endl;
	}
	else if (sortBy == 3) {
		file_out << setw(5) << left << "GPA"
			<< setw(12) << "First"
			<< setw(15) << left << "Last"
			<< setw(13) << left << "Student Id"
			<< setw(30) << left << "Email"
			<< endl;
		for (int j = 0; j < records; j++) {
			file_out << setprecision(1) << fixed << showpoint
				<< setw(5) << left << pStudents[j]->gpa
				<< setw(12) << pStudents[j]->firstName
				<< setw(15) << left << pStudents[j]->lastName
				<< setw(13) << left << pStudents[j]->id
				<< setw(30) << left << pStudents[j]->email
				<< endl;
		}
		file_out << endl;
	}
	else if (sortBy == 3) {
		file_out << setw(5) << left << "GPA"
			<< setw(12) << "First"
			<< setw(15) << left << "Last"
			<< setw(13) << left << "Student Id"
			<< setw(30) << left << "Email"
			<< endl;
		for (int j = 0; j < records; j++) {
			file_out << setprecision(1) << fixed << showpoint
				<< setw(5) << left << pStudents[j]->gpa
				<< setw(12) << pStudents[j]->firstName
				<< setw(15) << left << pStudents[j]->lastName
				<< setw(13) << left << pStudents[j]->id
				<< setw(30) << left << pStudents[j]->email
				<< endl;
		}
		file_out << endl;
	}
	else if (sortBy == 4) {
		file_out << setw(30) << left << "Email"
			<< setw(12) << left << "First"
			<< setw(15) << "Last"
			<< setw(5) << "GPA"
			<< setw(13) << left << "Student Id"
			<< endl;
		for (int j = 0; j < records; j++) {

			file_out << setw(30) << left << pStudents[j]->email
				<< setw(12) << left << pStudents[j]->firstName
				<< setw(15) << pStudents[j]->lastName
				<< setprecision(1) << fixed << showpoint
				<< setw(5) << pStudents[j]->gpa
				<< setw(13) << left << pStudents[j]->id
				<< endl;
		}
		file_out << endl;

	}
	else {
		file_out << setw(12) << left << "First"
			<< setw(15) << "Last"
			<< setw(5) << "GPA"
			<< setw(13) << left << "Student Id"
			<< setw(30) << left << "Email"
			<< endl;
		for (int j = 0; j < records; j++) {
			file_out << setw(12) << left << pStudents[j]->firstName
				<< setw(15) << pStudents[j]->lastName
				<< setprecision(1) << fixed << showpoint
				<< setw(5) << pStudents[j]->gpa
				<< setw(13) << left << pStudents[j]->id
				<< setw(30) << left << pStudents[j]->email
				<< endl;
		}
		file_out << endl;
	}

	// Close file_out.
	file_out.close();
}

// Print data to screen.
void printToScreen(STUDENT *pStudents[], int records, int sortBy) {
	if (sortBy == 2) {
		cout << setw(15) << left << "Last"
			<< setw(12) << "First"
			<< setw(5) << "GPA"
			<< setw(13) << left << "Student Id"
			<< setw(30) << left << "Email"
			<< endl;
		for (int j = 0; j < records; j++) {
			cout << setw(15) << left << pStudents[j]->lastName
				<< setw(12) << pStudents[j]->firstName
				<< setprecision(1) << fixed << showpoint
				<< setw(5) << pStudents[j]->gpa
				<< setw(13) << left << pStudents[j]->id
				<< setw(30) << left << pStudents[j]->email
				<< endl;
		}
		cout << endl;
	}
	else if (sortBy == 3) {
		cout << setw(5) << left << "GPA"
			<< setw(12) << "First"
			<< setw(15) << left << "Last"
			<< setw(13) << left << "Student Id"
			<< setw(30) << left << "Email"
			<< endl;
		for (int j = 0; j < records; j++) {
			cout << setprecision(1) << fixed << showpoint
				<< setw(5) << left << pStudents[j]->gpa
				<< setw(12) << pStudents[j]->firstName
				<< setw(15) << left << pStudents[j]->lastName
				<< setw(13) << left << pStudents[j]->id
				<< setw(30) << left << pStudents[j]->email
				<< endl;
		}
		cout << endl;
	}
	else if (sortBy == 4) {
		cout << setw(30) << left << "Email"
			<< setw(12) << left << "First"
			<< setw(15) << "Last"
			<< setw(5) << "GPA"
			<< setw(13) << left << "Student Id"
			<< endl;
		for (int j = 0; j < records; j++) {

			cout << setw(30) << left << pStudents[j]->email 
				<< setw(12) << left << pStudents[j]->firstName
				<< setw(15) << pStudents[j]->lastName
				<< setprecision(1) << fixed << showpoint
				<< setw(5) << pStudents[j]->gpa
				<< setw(13) << left << pStudents[j]->id
				<< endl;
		}
		cout << endl;

	}
	else if (sortBy == 5) {
		cout << setw(13) << left << "Student Id"
			<< setw(30) << left << "Email"
			<< setw(12) << left << "First"
			<< setw(15) << "Last"
			<< setw(5) << "GPA" 
			<< endl;
		for (int j = 0; j < records; j++) {

			cout << setw(13) << left << pStudents[j]->id
				<< setw(30) << left << pStudents[j]->email
				<< setw(12) << left << pStudents[j]->firstName
				<< setw(15) << pStudents[j]->lastName
				<< setprecision(1) << fixed << showpoint
				<< setw(5) << pStudents[j]->gpa
				<< endl;
		}
		cout << endl;

	}
	else {
		cout << setw(12) << left << "First"
			<< setw(15) << "Last"
			<< setw(5) << "GPA"
			<< setw(13) << left << "Student Id"
			<< setw(30) << left << "Email"
			<< endl;
		for (int j = 0; j < records; j++) {
			cout << setw(12) << left << pStudents[j]->firstName
				<< setw(15) << pStudents[j]->lastName
				<< setprecision(1) << fixed << showpoint
				<< setw(5) << pStudents[j]->gpa
				<< setw(13) << left << pStudents[j]->id
				<< setw(30) << left << pStudents[j]->email
				<< endl;
		}
		cout << endl;
	}
}
