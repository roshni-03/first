#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class attendence
{
public:
    int present[201];
    attendence()
    {
        for(int i=0; i<=200; i++)
        {
            present[i]=0;
        }
    }
};
int main()
{
    attendence o[31][12];
    fstream file;
      file.open("STUDENT",ios::in |ios::out);
    /*if(file.eof())
    {
        file.open("STUDENT",ios::in |ios::out|ios::app);
        for(int i=0; i<12; i++)
        {
            for(int j=0; j<31; j++)
            {
                file.write((char *) & o[j][i],sizeof(o[j][i]));
            }
        }
        file.close();
    }
    cout<<"Enter 1 to update attedence"<<endl;
    cout<<"Enter 2 to view attendence"<<endl;
    int n;
    cin>>n;
    if(n==1)
    {
        file.open("STUDENT",ios::in |ios::out);
        cout<<"Give a valid date & Month"<<endl;
        int date,month;
        cin>>date>>month;
        cout<<"Enter total number of student"<<endl;
        int student;
        cin>>student;
        for(int i=1; i<=student; i++)
        {
            cin>>o[date-1][month-1].present[i];
        }
        int p=((month-1)*30)+(date-1);
        file.seekp(p*sizeof(o[date-1][month-1]));
        file.write((char *) & o[date-1][month-1],sizeof(o[date-1][month-1]));
        file.close();
    }
    else if(n==2)
    {
        file.open("STUDENT",ios::in |ios::out);
        cout<<"Give desire date and month and student id"<<endl;
        int date,month,id;
        cin>>date>>month>>id;
        for(int i=0; i<month; i++)
        {
            for(int j=0; j<date; j++)
            {
                file.read((char *) & o[j][i],sizeof(o[i][j]));
                //cout<<o[j][i].present[id];
                if(i+1==month&&j+1==date)
                {
                    cout<<o[j][i].present[id];
                }
            }
        }*/
        file.close();
    }
