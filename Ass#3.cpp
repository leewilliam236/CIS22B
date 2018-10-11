/**
Ass#3
William Lee
Code::Blocks (Windows 10 Pro)
GNU GCC Compiler
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

const int COLUMN = 7;

void initialize1(ifstream&, ofstream&);
float getfunction(float, ifstream&, char);
void initialize2(int[][COLUMN], ifstream&, const int);
void csvoutput(ofstream&, int[][COLUMN], const int);

int main()
{

    const int ROW = 500;
    ifstream csv, csvassign;
    ofstream csvmodified, csvout;
    string dummy;
    int mutualfund[ROW][COLUMN];

    csv.open("C:\\Users\\Student\\Documents\\22B\\Ass#3\\VTSMX.csv");
    csvmodified.open("C:\\Users\\Student\\Documents\\22B\\Ass#3\\VTSMXmodified.csv");
    csvassign.open("C:\\Users\\Student\\Documents\\22B\\Ass#3\\VTSMXmodified.csv");
    csvout.open("C:\\Users\\Student\\Documents\\22B\\Ass#3\\output.txt");

    if(!csv && !csvmodified && !csvassign && !csvout)
    {
        cout << "Can't Open File.";
        exit(0);
    }
    getline(csv,dummy);
    initialize1(csv, csvmodified);
    initialize2(mutualfund, csvassign, ROW);
    csvoutput(csvout, mutualfund, ROW);
    csv.close();
    csvmodified.close();
    csvassign.close();
    csv.close();

    return 0;
}

void initialize1(ifstream& csv, ofstream& csvmodified)
{
    char punct;
    int year, month, day, sixth;
    float first;
    do
    {
        csv >> year >> punct;
        if(csv.eof())
        {
            break;
        }
        month = getfunction(month, csv, punct);
        punct = ',';
        day = getfunction(day, csv, punct);
        csvmodified << left << setw(10);
        csvmodified << (year * 10000) + (month * 100) + day;
        csvmodified << fixed << showpoint << setprecision(6);
        for(int i = 0; i < 5; i++)
        {
            first = getfunction(first, csv, punct);
            csvmodified << left << setw(10) << first;
        }
        csv >> sixth;
        csvmodified << left << setw(10) << sixth;
        csvmodified << endl;
    }
    while(!csv.eof());
}

float getfunction(float v, ifstream& csv, char d)
{
    char p[12];
    csv.get(p, sizeof(p), d);
    csv.get();
    v = atof(p);
    return v;
}

void initialize2(int mf[][COLUMN], ifstream& csvassign, const int R)
{
    int value1, storeitforlater;
    float value2, storage;
    while(!csvassign.eof())
    {
        for(int i = 0; i < R; i++)
        {
            csvassign >> value1;
            if(csvassign.eof())
            {
                break;
            }
            mf[i][0] = value1;
            for(int j = 1; j < COLUMN; j++)
            {
                csvassign >> value2;
                storage = value2 * 100.00;
                cout << setprecision(4);
                mf[i][j] = storage;
            }
        }
    }
}

void csvoutput(ofstream& o, int mf[][COLUMN], const int R)
{
    o << "Current Date: " << endl;
    o << "Current Close: $" << mf[R-1][1]/100.00 << endl << endl;
    o << "The latest five closes are:" << endl;
    for(int i = R-1; i > R-6; i--)
    {
        o << (mf[i][1]/100.00) << endl;
    }
}
