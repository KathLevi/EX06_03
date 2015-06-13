////////////////////////
//Name: Kathleen Levi
//
//Project: EX06_03 (13.5)
//
//Date: 12 June, 2015
////////////////////////

//(The URL should be: http://www.socialsecurity.gov/OACT/babynames/. Also, you’ll need to use the interface to get the top 1000 names for a given year, then copy those into a text file.)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
    string year;
    char gender;
    string name;
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the gender(M or F): ";
    cin >> gender;
    cout << "Enter the year: ";
    cin >> year;

    //open the file of the given year
    string filename = "babynameranking"+year+".txt";
    ifstream babenames(filename, ios::beg | ios::in);
    if (babenames.fail()){
        cout << "Could not open file." << endl;
        return 0;
    }
    
    string rank;
    string tempBoy;
    string tempGirl;
    string junk;
    

    if (gender == 'm' || gender == 'f' || gender == 'M' || gender == 'F')
    {
        while (!babenames.eof())
        {
            babenames >> rank >> tempBoy >> junk >> tempGirl >> junk;
            if (name == tempBoy){
                cout << name << " is ranked " << rank << " in year " << year;
            }
            if (name == tempGirl){
                cout << name << " is ranked " << rank << " in year " << year;
            }
        }
    }
    else
        cout << "The name " << name << " is not ranked in year " <<year;
}