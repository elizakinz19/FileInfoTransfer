//Nancy Reynoso 4:44 p.m. May 23, 2018
//GPA program read in and read out files
//Note: The code looks carefully structured due to tab character; names with
//      different lengths will be messy in the output file and this source file.

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

const int students = 5;

struct Format {

	string firstName;
	string lastName;
	double GPA;

};

int main() {

	int i, c;
	double sum;
	Format DisplayGPA[students];
	double avgGPAforClass;
	

	ifstream StudentFile;
	ofstream StudentOutFile;
	
	StudentFile.open("E:\\CS575 Files\\Week 16 5.23.2018\\StudentFile.txt"); //Works only with Drive E
	
	if (StudentFile.fail()) //Checking for fail state of StudentFile location 
	{
		cout << "There is a problem with opening the file location." << endl;
	}
	else
	{
		for (i = 0; i < students; i++) {

			StudentFile >> DisplayGPA[i].firstName //placing each piece of data into a variable of struct
				>> DisplayGPA[i].lastName
				>> DisplayGPA[i].GPA;
			cout << "Student's Name: " << DisplayGPA[i].firstName << "\t" << DisplayGPA[i].lastName
				<< "\n \t" << fixed << setprecision(2) << "Student's GPA" << "\t" << DisplayGPA[i].GPA
				<< endl << endl; //Proofreading the data from source file
		}
	}

	StudentFile.close();
	
	StudentFile.clear();


	StudentOutFile.open("E:\\CS575 Files\\Week 16 5.23.2018\\StudentOutFile.txt");
	if (StudentOutFile.fail()) //Checking for fail state of StudentFile location 
	{
		cout << "There is a problem with opening the file location." <<endl;
	}
	else
	{
		for (i = 0; i < students; i++) {

			StudentOutFile << DisplayGPA[i].firstName << "\t" // placing each piece of data 										  // into a variable of struct
				<< DisplayGPA[i].lastName << "\t" <<fixed <<setprecision(2)
				<< DisplayGPA[i].GPA << "\n";
		}
		
		sum = 0;
		c = 0;

		while (c < students) {
			sum = sum + DisplayGPA[c].GPA;
			//cout <<sum <<endl; //Test to see if the sum works
			c++;
		}

		avgGPAforClass = (static_cast<double>(sum) / students);
		StudentOutFile << "\nThe Average GPA for the five students in class are: " << avgGPAforClass 
			<<" (Average GPA is rounded to two decimal places.)" << endl;

	}
	

	system("pause");
	return 0;
}

/*

StudentFile content in Notepad

Alma Delany 3.01
Zachary	Recinos 3.00
Jenni Uranga 2.79
Daniel Celaya 4.00
Lionel Meyer 2.98

*/