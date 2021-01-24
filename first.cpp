#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
const int MAX_SIZE = 100;
string words[MAX_SIZE];
int count = 0;
int main()
{
    string fname, newWord;
    ifstream infile;
    //cout << "Enter the full pathname of input file: " << endl;
    //cout << " " << endl;
    //getline(cin, fname);
    //cout << " " << endl;
    infile.open("lab.txt");
    if(!infile.is_open())//end program if file is not opened
    {
        cout << "Failed to open file " << endl;
        return -1;
    }
    while(!infile.eof())//read file in, and create an array of which each element contains each word of the file
    {
        infile >> newWord;
        //cout << newWord << " ";
        words[count] = newWord;
        count++;
    }
    cout << "array size" << count << endl;
    cout << "-----------------" << endl;
    cout << "original file" << endl;
    cout << "-----------------" << endl;
    for(int f = 0; f < count; f++) //outputting original file to screen
    {
        cout << words[f] << " ";
    }
    string x, y;
    for(int i = 0; i < count; i++)//here we go through and check each word with the rest of the array to see if there is another,
    {                             //if there is we push it to the end and reduce the size of the array by 1
        x = words[i];
        for(int h = i+1 ; h < count; h++)
        {
            y = words[h];
            if(x == y)
            {
                for(int j = h; j < count; j++)
                {
                    words[j] = words[j+1];
                }
                count--;
            }
        }
    }
    cout << "-" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "words after romoval of non-unique numbers" << endl;
    cout << "---------------------------------------------" << endl;
    for(int l = 0; l < count; l++)
    {
        cout << words[l] << " ";
    }
    cout << "-" << endl;
    cout << "-----" << endl;
    while(1)
    {
	int switcher = 0;
        for(int p = 0; p < count-1; p++)
        {
            if(words[p] > words[p+1])
            {
                string s = words[p];
		words[p] = words[p+1];
		words[p+1] = s;
		switcher = 1;
            }
        }
        if(switcher == 0)
        {
            break;
        }
    }
    cout << "-------------" << endl;
    cout << "new file " << endl;
    cout << "-------------" << endl;
    for(int j = 0; j < count; j++)//output the new array(unique characters in alphabetical order from smallest to greatest) to the screen
    {
        cout << words[j] << endl;
    }
    cout << " " << endl;
    return 0;
    }

