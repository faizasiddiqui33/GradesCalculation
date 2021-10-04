/*****************************************************************************************************************************
Module Name: Calculating Grades of Students 
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Student ID: 200473896
Purpose: CS 700 Assignment 1  
*****************************************************************************************************************************/

#include <iostream> //library for input output capabilities
#include <fstream>  //library for file streams
#include <string>   //library for string types & string functions
#include <sstream>  //library for string streams classes
#include <iomanip>  // library for manipulator functions

using namespace std;
string line;    //to store a line that is read from input file
string fname;   //to store first name of student
string lname;   //to store last name of student
string name;    //to store full name of student
double sum;     //to store sum of all exam scores
double average; //to store average of all exam scores
int var1, var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12;//to store exam scores of students
ofstream output("output.txt"); //creating an object to write the final result of all students


/*****************************************************************************************************************************
Module Name: Calculating Grades of Students 
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Purpose: Function for reading each element of the file 
No Arguments. This function returns the line read from the input file
*******************************************************************************************************************************/
string readFile()
{
    ifstream myfile("grades.txt"); //creating an object to read the grades text file

    //use condition to check if the file is still open
    if (myfile.is_open())
    {
        //loop through the rows of the text file
        while (getline(myfile, line))
        {
            //displaying the formatted data
            //declaring the variables to use for displaying the data
            istringstream iss(line); 

            //use tabs to assign the variables
            iss >> fname >> lname >> var1; //reading from the stringstream object iss
            
            //use if-else condition to ensure non-null values are only displayed
            if (var1 == 11)
            {  
                 //check if student has 11 subjects
                iss >> var2 >> var3 >> var4 >> var5 >> var6 >> var7 >> var8 >> var9 >> var10 >> var11 >> var12; //reading from the stringstream object iss
                sum = var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10 + var11 + var12;//Calculating sum of all exam scores
                average = sum / 11; //Calculating average of all exam scores
                name = fname + " " + lname; //Joining the first name and second name and storing it in name variable
            }

            else if (var1 == 10)
            {   
                //check if student has 10 subjects
                iss >> var2 >> var3 >> var4 >> var5 >> var6 >> var7 >> var8 >> var9 >> var10 >> var11; //reading from the stringstream object iss
                sum = var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10 + var11; //Calculating sum of all exam scores
                average = sum / 10; //Calculating average of all exam scores
                name = fname + " " + lname; //Joining the first name and second name and storing it in name variable
            }

            else if (var1 == 9)
            {
                //check if student has 9 subjects
                iss >> var2 >> var3 >> var4 >> var5 >> var6 >> var7 >> var8 >> var9 >> var10;  //reading from the stringstream object iss
                sum = var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10; //Calculating sum of all exam scores
                average = sum / 9; //Calculating average of all exam scores
                name = fname + " " + lname; //Joining the first name and second name and storing it in name variable
            }
            
            else if (var1 == 8)
            {
                //check if student has 8 subjects
                iss >> var2 >> var3 >> var4 >> var5 >> var6 >> var7 >> var8 >> var9;  //reading from the stringstream object iss
                sum = var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9; //Calculating sum of all exam scores
                average = sum / 8; //Calculating average of all exam scores
                name = fname + " " + lname; //Joining the first name and second name and storing it in name variable
            }

            else if (var1 == 7)
            {
                //check if student has 7 subjects
                iss >> var2 >> var3 >> var4 >> var5 >> var6 >> var7 >> var8;  //reading from the stringstream object iss
                sum = var2 + var3 + var4 + var5 + var6 + var7 + var8; //Calculating sum of all exam scores
                average = sum / 7; //Calculating average of all exam scores
                name = fname + " " + lname; //Joining the first name and second name and storing it in name variable
            }

            else if (var1 == 6)
            {
                //check if student has 6 subjects
                iss >> var2 >> var3 >> var4 >> var5 >> var6 >> var7;  //reading from the stringstream object iss
                sum = var2 + var3 + var4 + var5 + var6 + var7; //Calculating sum of all exam scores
                average = sum / 6; //Calculating average of all exam scores
                name = fname + " " + lname; //Joining the first name and second name and storing it in name variable
            } 

            else
            {
                //check if student has 5 subjects
                iss >> var2 >> var3 >> var4 >> var5 >> var6;  //reading from the stringstream object iss
                sum = var2 + var3 + var4 + var5 + var6; //Calculating sum of all exam scores
                average = sum / 5; //Calculating average of all exam scores
                name = fname + " " + lname; //Joining the first name and second name and storing it in name variable
            }

            //Start checking what letter grades to assign every student & display student name, number of exam scores, all the exam scores, average exam score, and letter grade
            if (average > 95 & average <= 100)
            {
                //Display grade 'A' if average is more than 95 and less than or equal to 100
                cerr << std::setprecision(8);
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "A" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "A" << endl;
            }

            else if (average > 91.67 && average <= 95)
            {
                //Display grade 'A-' if average is more than 91.67 and less than or equal to 95
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "A-" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "A-" << endl;
            }

            else if (average > 88.3 & average <= 91.67)
            {
                //Display grade 'B+' if average is more than 88.3 and less than or equal to 91.67
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "B+" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "B+" << endl;
            }

            else if (average > 85 & average <= 88.3)
            {
                //Display grade 'B' if average is more than 85 and less than or equal to 88.3
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "B" << endl;
                output << std::setw(20) << name << std::setw(20) << average << std::setw(20) << "B" << endl;
            }

            else if (average > 81.67 & average <= 85)
            {
                //Display grade 'B-' if average is more than 81.67 and less than or equal to 85
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "B-" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "B-" << endl;
            }

            else if (average > 78.33 & average <= 81.67)
            {
                //Display grade 'B-' if average is more than 78.33 and less than or equal to 81.67
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "C+" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "C+" << endl;
            }

            else if (average > 75 & average <= 78.33)
            {
                //Display grade 'C' if average is more than 75 and less than or equal to 78.33
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "C" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "C" << endl;
            }

            else if (average > 71.67 & average <= 75)
            {
                //Display grade 'C-' if average is more than 71.67 and less than or equal to 75
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "C-" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "C-" << endl;
            }

            else if (average > 68.33 & average <= 71.67)
            {
                //Display grade 'D+' if average is more than 68.33 and less than or equal to 71.67
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "D+" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "D+" << endl;
            }

            else if (average > 65 & average <= 68.33)
            {
                //Display grade 'D' if average is more than 65 and less than or equal to 68.33
                cerr << std::setprecision(8);//set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "D" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "D" << endl;
            }

            else if (average > 61.67 & average <= 65)
            {
                //Display grade 'D-' if average is more than 61.67 and less than or equal to 65
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "D-" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "D-" << endl;
            }

            else if (average > 0 & average <= 61.67)
            {
                //Display grade 'F' if average is more than 0 and less than or equal to 61.67
                cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
                //setw is used to have a well-formatted output with spacing of the specified width
                cerr << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "F" << endl;
                output << std::setw(20) << name << std::setw(20) << var1 << std::setw(20) << var2 << std::setw(5) << var3 << std::setw(5) << var4 << std::setw(5) << var5 << std::setw(5) << var6 << std::setw(5) << var7 << std::setw(5) << var8 << std::setw(5) << var9 << std::setw(5) << var10 << std::setw(5) << var11 << std::setw(5) << var12 << std::setw(20) << average << std::setw(20) << "F" << endl;
            }
        }
        //closing the file
        myfile.close();
    }
    //displays if the file cannot be opened
    else
        cout << "Unable to open the file";

    return line; //returns the line read from the input file
}


/*****************************************************************************************************************************
Module Name: Calculating Grades of Students 
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Purpose: Function for Processing the File
No Arguments or return values
******************************************************************************************************************************/
void processFile()
{
    readFile(); //Calling the read file function to read every element of the file
    cout << line << "\n";
}


/*****************************************************************************************************************************
Module Name: Calculating Grades of Students 
Author: Faiza Fatma Siddiqui
Date Created/Modified:4.10.2021
Purpose: Main Function 
No Arguments, 0 is the return value, if no error
******************************************************************************************************************************/
int main()
{
    cerr << std::setprecision(8); //set the decimal value of sum and average to 8 decimal digits
    //setw is used to have a well-formatted output with spacing of the specified width
    //To give headings of printed and processed values, such as Student Name, Number of Exam Scores, Exam Scores, Average & Grade for a well-formatted output
    cerr << std::setw(20) << "Student Name" << std::setw(29) << "Number of Exam Scores" << std::setw(35) << "Exam Scores" << std::setw(45) << "Average" << std::setw(20) << "Grade" << endl;
    output << std::setw(20) << "Student Name" << std::setw(29) << "Number of Exam Scores" << std::setw(35) << "Exam Scores" << std::setw(45) << "Average" << std::setw(20) << "Grade" << endl;

    readFile(); //Calling the read file function to read every element of the file
    processFile(); // Calling the function to process the file contents

    return 0; //return 0 if program executed successfully because main function is of type integer
}