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

using namespace std;

const int COLUMN = 7;

void initialize1(const int, const int, ifstream&, ofstream&);
float getfunction(float, ifstream&, char);
void initialize2(int[][COLUMN], ifstream&, const int);
void output(ofstream&);

int main()
{

    const int ROW = 500;
    ifstream csv, csvassign;
    ofstream csvmodified, csvoutput;
    string dummy;
    int mutualfund[ROW][COLUMN];

    csv.open("C:\\Users\\Student\\Documents\\22B\\Ass#3\\Ass#3\\VTSMX.csv");
    csvmodified.open("C:\\Users\\Student\\Documents\\22B\\Ass#3\\Ass#3\\VTSMXmodified.csv");
    csvassign.open("C:\\Users\\Student\\Documents\\22B\\Ass#3\\Ass#3\\VTSMXmodified.csv");
    csvoutput.open("");

    if(!csv && !csvmodified && !csvassign)
    {
        cout << "Can't Open File.";
        exit(0);
    }
    getline(csv,dummy);
    initialize1(ROW, COLUMN, csv, csvmodified);
    initialize2(mutualfund, csvassign, ROW);

    csv.close();
    csvmodified.close();
    csvassign.close();

    return 0;
}

void initialize1(const int R, const int C, ifstream& csv, ofstream& csvmodified)
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

void initialize2(int mf[][COLUMN], ifstream& csvassign, const int R)
{
    int value1;
    float value2, storage;
    do
    {
        for(int i = 0; i < R; i++)
        {
            if(csvassign.eof())
            {
                break;
            }
            csvassign >> value1;
            mf[i][0] = value1;
            if(csvassign.eof())
            {
                break;
            }
            cout << mf[i][0] << left << setw(10);
            for(int j = 1; j < COLUMN; j++)
            {
                csvassign >> value2;
                storage = value2 * 100.00;
                cout << setprecision(4);
                mf[i][j] = storage;
                cout << mf[i][j] << left << setw(10);
                if(csvassign.eof())
                {
                    break;
                }
            }
            cout << endl;
        }
    }
    while(!csvassign.eof());
}

float getfunction(float v, ifstream& csv, char d)
{
    char p[12];
    char ch;
    csv.get(p, sizeof(p), d);
    ch = csv.get();
    v = atof(p);
    return v;
}
