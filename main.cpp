/*
27/02/2017
Andrew Tran
Unit 3 Matchmaker
Mr. Trink

Description: A program that checsk the pairings of officers on duty.
If there is an odd number of officers on dury, output will say "Unable to pair up officers. There is an odd number of officers on duty."
If the partners are paired up properly, output will say "Good pairings!"
if the partners are not pared up properly, output will say "Bad pairings!"
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    //used for determing final output of pairings, if doesn't change to false output good
    bool isGood = true;

    //the number of officers
    int numNames =0;


    //opens the text file and reads the contents on it
    ifstream myFile("nameList.txt");


    string tempBuffer;

    //gets the string in the first line of text file
    getline(myFile,tempBuffer);

    //converts the string into an integer value
    numNames = atoi(tempBuffer.c_str());

    //the array for the first list of names
    string nameList1[numNames];

    //the array for the second list of names
    string nameList2[numNames];

    if(numNames%2 ==0)
    {


        //stores first set of names in indices
        for (int curName = 0; curName < numNames-1; curName++)
        {
            getline(myFile, nameList1[curName], ' ');

        }
        //stores last value in the array
        getline(myFile, nameList1[numNames-1]);

        //stores second set of names in indices
        for (int curName = 0; curName < numNames-1; curName++)
        {
            getline(myFile, nameList2[curName], ' ');

        }
        //stores the last value in the array

        getline(myFile, nameList2[numNames-1]);

        for (int curName = 0; curName < numNames; curName++)
        {

            //Checks to see if the first array has a name in the same position as the second array
            if(nameList1[curName] == nameList2[curName])
            {
                //output text to be red
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout<<"An officer cannot be partnered up with themselves.\n";
                isGood = false;
                break;

            }
            else
            {
                //checks to see how many values of nameList2 that are also in nameList1
                int indexList2 = distance(nameList1, find (nameList1, nameList1 + numNames, nameList2[curName]));


                //if the number of values in the first array are unequal to the number of values in the second array output this
                if (nameList1[curName] !=  nameList2[indexList2])
                {
                    //output text to be red
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout<<"There seems to be a problem, an officer seems to not be paired up.\n"<<endl;
                    isGood = false;
                    break;
                }
            }
        }
        if (isGood== false)
        {
            //output the text to be red
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"Bad pairings!\n\n";
            //output the text to be yellow
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

        }
        else
        {
            //output the text to be grey
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            //if all the officers are partnered up with different officers
            cout<<"Good pairings!\n\n";

            //change last line of output to yellow
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
    }
    else
    {
        //Output when number of officers is odd

        //output text to be red
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout<<"The current pairing of officers is invalid. There is an odd number of officers on duty.\n";

        //change last line of output to yellow
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    }
    return 0;
}
