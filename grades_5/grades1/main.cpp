/*****************************************************************************************************************************
Module Name: Calculating Grades of Students-Modified
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Student ID: 200473896 
Purpose: CS 700 Assignment 1 
*******************************************************************************************************************************/

#include <iostream> //library for input output capabilities
#include <fstream>  //library for file streams
#include <string>   //library for string types & string functions
#include <sstream>  //library for string streams classes
#include <iomanip>  // library for manipulator functions

using namespace std;
static double examAverage; //To store the average of exam performance by all students
double studentAverage; //To store the average score for each student
ofstream output("output.txt"); //creating an object to write the final result of all students


/*****************************************************************************************************************************
Module Name: Calculating Grades of Students-Modified
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Purpose: Creating a 2-D Array with Row Subscript as Student Number & Column Subscript as Exam Number
No Arguments, no return value
*******************************************************************************************************************************/
void createArray()
{
    //opening and reading the text file
    ifstream file("grades_Section2.txt");

    //  creating the 2-D array
    int myArray[25][10]{};
    //creating the superset layer of the array
    for (int i{}; i != 25; ++i) //using the for loop for 25 students
    {
        //the subset layer of the array
        for (int j{}; j != 10; ++j) //using the for loop for 10 exam scores of each student
        {
            file >> myArray[i][j]; //Read from the file ifstream object
        }
    }
}


/*****************************************************************************************************************************
Module Name: Calculating Grades of Students-Modified
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Purpose: Function to process the data
No Arguments, Function returns a double value that has average of exams
*******************************************************************************************************************************/
double readFile()
{
    string line; //to store a line read from the input file
    //reading the text file
    ifstream myfile("grades_Section2.txt"); //Creating an object myfile of ifstream class 

    //use condition to check if the file is still open
    if (myfile.is_open())
    {
        //variables that hold the sum of the scores
        static int sumvar1 = 0;
        static int sumvar2 = 0;
        static int sumvar3 = 0;
        static int sumvar4 = 0;
        static int sumvar5 = 0;
        static int sumvar6 = 0;
        static int sumvar7 = 0;
        static int sumvar8 = 0;
        static int sumvar9 = 0;
        static int sumvar10 = 0;
        int *arraya = new int[25]; //to create 2D Array

        //declare the variables to to hold the data
        int var1, var2, var3, var4, var5, var6, var7, var8, var9, var10;
        
        //use a while loop to read all lines of the text file
        while (getline(myfile, line))
        {
            //displaying the formatted data
            //declaring the variables to use for displaying the data
            istringstream iss(line);
            string fname, lname; //for first name and last name of student

            //reading from the stringstream object iss
            iss >> fname >> lname >> var1 >> var2 >> var3 >> var4 >> var5 >> var6 >> var7 >> var8 >> var9 >> var10;

            string name = fname + " " + lname; //Joining the first name and last name and storing it in name variable
            
            //calculating the number of scores for all students
            sumvar1 += var1;
            sumvar2 += var2;
            sumvar3 += var3;
            sumvar4 += var4;
            sumvar5 += var5;
            sumvar6 += var6;
            sumvar7 += var7;
            sumvar8 += var8;
            sumvar9 += var9;
            sumvar10 += var10; 

            //calculating the sum of the exam scores of all students
            double sumExam = var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10;

            //calculating the average score 
            studentAverage = sumExam / 10;

            double avg = 86.5; //average of total exams by all students

            if (studentAverage - avg > 15) //Check if student average minus average is more than 15
            {
                //If the grade is more than 15 points above the average, then give 'A' Grade
                cerr << std::setprecision(8);//set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "A" << endl;
                output << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "A" << endl;
            }

            else if (studentAverage - avg > 5 && studentAverage - avg < 15)
            {
                //If the grade is more than 5 points & less than 15 above the average, then give 'B' Grade
                cerr << std::setprecision(8);//set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "B" << endl;
                output << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "B" << endl;
            }

            else if (avg - studentAverage > 5 && avg - studentAverage < 15)
            {
                //If the grade is more than 5 points & less than 15 below the average, then give 'D' Grade
                cerr << std::setprecision(8);//set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "D" << endl;
                output << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "D" << endl;
            }

            else if (studentAverage - avg < 5)
            {
                //If the grade is more than 5 points & less than 15 above the average, then give 'C' Grade
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "C" << endl;
                output << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "C" << endl;
            }

            else
            {
                //If the grade is more than 15 points below the average, then give 'F' Grade
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "F" << endl;
                output << std::setw(20) << name << std::setw(20) << studentAverage << std::setw(20) << "F" << endl;
            }
        }
        //closing the file
        myfile.close();

        //creating the average variables and assigning them average of each subject
        double average1 = sumvar1 / 25 / 2;
        double average2 = sumvar2 / 25 / 2;
        double average3 = sumvar3 / 25 / 2;
        double average4 = sumvar4 / 25 / 2;
        double average5 = sumvar5 / 25 / 2;
        double average6 = sumvar6 / 25 / 2;
        double average7 = sumvar7 / 25 / 2;
        double average8 = sumvar8 / 25 / 2;
        double average9 = sumvar9 / 25 / 2;
        double average10 = sumvar10 / 25 / 2;

        //Calculating the sum of averages of all subjects
        double sumtotal = average1 + average2 + average3 + average4 + average5 + average6 + average7 + average8 + average9 + average10;

        //Calculating the average of the exams-the whole exams average
        examAverage = sumtotal / 10;

        return examAverage; //return examAverage after the function is called
    }
     //displays if the file cannot be opened
    else
        cout << "Unable to open the file";
}


/*****************************************************************************************************************************
Module Name: Calculating Grades of Students-Modified
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Purpose: Read the file contents
No Arguments, no return value
*******************************************************************************************************************************/
void averageScores()
{
    readFile();
}


/*****************************************************************************************************************************
Module Name: Calculating Grades of Students-Modified
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Purpose: Main Function
No Arguments, 0 is the return value if no error
/*******************************************************************************************************************************/
int main()
{
    cerr << std::setprecision(8);//set the decimal value of sum and average to 8 decimal digits
    //setw is used to have a well-formatted output with spacing of the specified width
    //To give headings of printed and processed values, such as Student Name, Student Average & Grade for a well-formatted output
    cerr << std::setw(20) << "Student Name" << std::setw(20) << "Student Average" << std::setw(20) << "Grade" << endl;
    output << std::setw(20) << "Student Name" << std::setw(20) << "Student Average" << std::setw(20) << "Grade" << endl;
    
    //calling the Array Function
    createArray();
    
    //calling the Readfile Function
    readFile();
    
    //calling the Average Scores Function
    averageScores();
    
    return 0; //return 0 if program executed successfully because main function is of type integer
}