#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

// 1.
void documentation();
// 2.
void enroll();
bool saveStudent(string, string, string, float);
// 3.
void issueBook();
void loadLibrary();
bool issueRecord(int, int);
// 4.
void finalAssessment();
// 5.
void events();

int main()
{
    char choice = '\0';

    cout << endl;
    cout << "        ------------------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << endl;
    cout << "                               *********************************************************" << endl
         << endl
         << endl;
    cout << "                                                    WELCOME TO THE" << endl;
    cout << "                                        UNIVERSITY OF ENGINEERING AND TECHNOLOGY" << endl;
    cout << endl
         << endl;
    cout << "                               *********************************************************" << endl;
    cout << "           Project made by = " << endl;
    cout << "               *Sumayyah Sayyed   " << endl;
    cout << "        ------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    system("pause");
    system("cls");

    cout << "           ------------------------------------------------------------------------------------------" << endl;
    cout << "                                    ------ Please select a choice =  ------" << endl
         << endl;
    cout << "                                           1. Admission Documentation" << endl;
    cout << "                                           2. Student Enrollment" << endl;
    cout << "                                           3. Library Management" << endl;
    cout << "                                           4. Final Assessment" << endl;
    cout << "                                           5. Events at UET" << endl;
    cout << "           ------------------------------------------------------------------------------------------" << endl;

    cout << endl
         << "                                           Enter your choice = ";
    cin >> choice;
    while (cin.fail() || choice < '1' || choice > '5')
    {
        cout << endl
             << endl;
        cout << "                          ------------ The choice should be 1 / 2 / 3 / 4 / 5 ------------" << endl;
        cout << endl
             << "                                       ------------ Enter again -------------" << endl;
        cout << endl
             << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl
             << "                                           Enter your choice = ";
        cin >> choice;
    }

    switch (choice)
    {
    case '1':
        documentation();
        break;
    case '2':
        enroll();
        break;
    case '3':
        issueBook();
        break;
    case '4':
        finalAssessment();
        break;
    case '5':
        events();
        break;
    default:
        break;
    }

    return 0;
}

// 1.
void documentation()
{
    system("CLS");

    cout << "           ------------------------------------------------------------------------------------------" << endl;
    cout << "                 ---------------- Welcome to the Documentation Section of UET ---------------- \n\n";
    cout << "                                           Eligibility Criteria" << endl;
    cout << "                                  Must have appeared in UET Entry Test,Lahore" << endl;
    cout << "                                  60% Marks in Intermediate / Equivalent" << endl;
    cout << "                            50% Aggregate Score (Inter / Equivalent + UET Entry Test)" << endl;
    cout << "           ------------------------------------------------------------------------------------------" << endl;
}

// 2.
void enroll()
{
    system("CLS");

    int choice;
    float aggregate;
    string student_name, father_name, gender;

    cout << "           ------------------------------------------------------------------------------------------" << endl;
    cout << "                   ---------------- Welcome to the Enrollment Section of UET ---------------- \n\n";

    cout << "                    We require your Name | Father Name | Gender | Aggregate for enrollment. \n\n";
    cout << "           ------------------------------------------------------------------------------------------" << endl;

    cin.clear();
    cin.ignore(1, '\n');
    cout << "                                          Enter your Full Name = ";
    getline(cin, student_name);
    cout << endl;

    cout << "                                          Enter your Father's Name = ";
    getline(cin, father_name);
    cout << endl;

    cout << "                                             1. Female" << endl;
    cout << "                                             2. Male" << endl;
    cout << "                                             3. Other" << endl;
    cout << "                                            Enter your Gender =  ";
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 3)
    {
        cout << endl
             << endl;
        cout << "                          ------------ The choice should be 1 / 2 / 3 ------------" << endl;
        cout << endl
             << "                                    ------------ Enter again -------------" << endl;
        cout << endl
             << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl
             << "                                                 Enter your choice = ";
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        gender = "Female";
        break;

    case 2:
        gender = "Male";
        break;

    case 3:
        gender = "Other";
        break;
    }

    cout << "                                            Enter your Aggregate = ";
    cin >> aggregate;
    while (cin.fail() || aggregate < 0 || aggregate > 100)
    {
        cout << endl
             << endl;
        cout << "                                    ------------ Wrong Input ------------" << endl;
        cout << endl
             << "                                    ------------ Enter again -------------" << endl;
        cout << endl
             << endl;
        cin.clear();
        cout << "                                            Enter your Aggregate = ";
        cin >> aggregate;
    }

    /* Checking Aggregate */
    if (aggregate >= 50)
    {

        if (saveStudent(student_name, father_name, gender, aggregate))
        {
            cout << "                       You are eligible for enrollment. Please wait as we save your data. \n\n";
            Sleep(10000);
            system("CLS");
            cout << "           ##########################################################################################" << endl;
            cout << " \n                        CONGRATULATIONS! " << student_name << " You have successfully enrolled in UET.\n\n";
        }
    }
    else
    {
        system("CLS");
        cout << "           ##########################################################################################" << endl;
        cout << "\n                      SORRY! Your aggregate was not enough. Better Luck next year!\n";
    }
    cout << endl
         << "           ##########################################################################################" << endl;
}

bool saveStudent(string name, string fname, string gender, float aggregate)
{
    string filename = "Student.txt";

    // For Counting Entries
    string reader = "";
    int counter = 0;

    fstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Input Operation on file " << filename << " failed!";
        return false;
    }

    while (!fin.eof())
    {
        getline(fin, reader);
        if (reader != "")
        {
            cout << counter << endl;
            counter++;
        }
        reader = "";
    }

    fin.close();

    // For Storing Student
    fstream fout(filename, ios::out | ios::app);
    if (!fout)
    {
        cout << "There was a problem opening file: " << filename;
        return false;
    }
    fout << ++counter << ")  " << name << "      " << fname << "       " << gender << "         " << aggregate << endl;
    fout.close();
    return true;
}

// 3.
void loadLibrary()
{
    system("CLS");

    cout << "           ------------------------------------------------------------------------------------------" << endl;
    cout << "                  ---------------- Welcome to the Library Section of UET ---------------- \n\n";
    cout << "                                          Available Books are:\n\n";
    string filename = "Library.txt", reader = "";

    fstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Error Opening File: " << filename << " failed!";
    }

    int columns = 2;
    cout << "                                  ID\t\t\t             NAME\n";
    while (!fin.eof())
    {
        for (int i = 0; i < columns; i++)
        {
            fin >> reader;
            cout << "                                  " << reader;
            if (fin.peek() == -1)
            {
                break;
            }
        }
        cout << endl;
    }
    fin.close();
    cout << "           ------------------------------------------------------------------------------------------" << endl;
}

void issueBook()
{
    loadLibrary();

    /*** For Counting Entries ***/
    string reader = "";
    int student_counter = 0;
    int book_counter = 0;

    // Count Number of Students
    string filename = "Student.txt";
    fstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Input Operation on file: " << filename << " failed!";
    }

    while (!fin.eof())
    {
        getline(fin, reader);
        if (reader != "")
        {
            student_counter++;
        }
        reader = "";
    }
    fin.close();

    // Count Number of Books
    filename = "Library.txt";
    reader = "";
    fin.open(filename, ios::in);
    if (!fin)
    {
        cout << "Input Operation on file: " << filename << " failed!";
    }
    while (!fin.eof())
    {
        getline(fin, reader);
        if (reader != "")
        {
            book_counter++;
        }
        reader = "";
    }
    fin.close();

    // Taking Input
    int sid = 0, bid = 0;

    cout << "\n                       We require your Student-ID and Book-ID for issuing a book. \n\n";

    cout << "                                           Enter your Student-ID = ";
    cin >> sid;
    while (cin.fail() || sid < 1 || sid > student_counter)
    {
        cout << endl
             << endl;
        cout << "                                    ------------ Wrong Input ------------" << endl;
        cout << endl
             << "                                    ------------ Enter again -------------" << endl;
        cout << endl
             << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "                                           Enter your Student-ID = ";
        cin >> sid;
    }

    cout << "                                           Enter desired Book-ID = ";
    cin >> bid;
    while (cin.fail() || bid < 1 || bid > book_counter)
    {
        cout << endl
             << endl;
        cout << "                                    ------------ Wrong Input ------------" << endl;
        cout << endl
             << "                                    ------------ Enter again -------------" << endl;
        cout << endl
             << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "                                           Enter desired Book-ID = ";
        cin >> bid;
    }

    // Save in Record:
    if (issueRecord(sid, bid))
    {
        cout << "           ------------------------------------------------------------------------------------------" << endl;
        cout << "\n                         Book Number #" << bid << " successfully issued to Student Number #" << sid << "." << endl
             << endl;
        cout << "           ------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "\nThere was an error issuing the book.\n";
    }
}

bool issueRecord(int sid, int bid)
{
    string filename = "Record.txt";
    fstream fout(filename, ios::out | ios::app);
    if (!fout)
    {
        cout << "There was a problem opening file: " << filename;
        return false;
    }

    fout << sid << "            " << bid << endl;
    fout.close();

    return true;
}

// 4.
void finalAssessment()
{
    system("CLS");

    cout << "           ------------------------------------------------------------------------------------------" << endl;
    cout << "            ---------------- Welcome to the Final Assessment Section of UET ---------------- \n\n";
    cout << "                       Mid                                            = 30 marks " << endl;
    cout << "                       Final                                          = 40 marks " << endl;
    cout << "                       Assignments + Attendence + Class Participation = 30 marks " << endl;
    cout << "           ------------------------------------------------------------------------------------------" << endl;
}

// 5.
void events()
{
    system("CLS");

    cout << "           ------------------------------------------------------------------------------------------" << endl;
    cout << "                  ---------------- Welcome to the Events Section of UET ---------------- \n\n";
    cout << "                                      Welcome" << endl;
    cout << "                                      Bonfire" << endl;
    cout << "                                      Industrial Trips & Internships" << endl;
    cout << "                                      Social Events & Sports Gala" << endl;
    cout << "                                      Adventurous Tours" << endl;
    cout << "           ------------------------------------------------------------------------------------------" << endl;
}