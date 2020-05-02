#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class attendence
{
public:
    int present[201];
    attendence()
    {
        for(int k=1; k<=200; k++)
        {
            present[k]=0;
        }
    }
};
int main()
{
    attendence o[31][12];
    fstream file;
    file.open("STUDENT5",ios::in |ios::out|ios::app);
    file.close();
    if(file.eof())
    {
        file.open("STUDENT5",ios::in |ios::out|ios::app);
        for(int i=0; i<12; i++)
        {
            for(int j=0; j<31; j++)
            {
                file.write((char *) & o[j][i],sizeof(o[j][i]));
            }
        }
        file.close();
    }
    cout<<endl;
    cout<<"ENTER 1 TO VIEW ATTENDENCE"<<endl;
    cout<<"ENTER 2 TO VIEW ATTENDENCE"<<endl;
    cout<<endl;
    int w;
    while(cin>>w)
    {
        if(w==1)
        {
            file.open("STUDENT5",ios::in |ios::out);
            cout<<"*********************"<<endl;
            cout<<"GIVE A VALID DATE AND MONTH"<<endl;
            cout<<"*********************"<<endl;
            int date,month;
            int d=0;
            while(d==0)
            {
                cin>>date>>month;
                if(month ==1 ||month ==3 ||month ==5 ||month ==7 ||month ==8 ||month ==10 ||month ==12 )
                {
                    if(date<=31 && date>=1)
                    {
                        d=1;
                        break;
                    }
                }
                else  if(month ==4 ||month ==6 ||month ==9 ||month ==11  )
                {
                    if(date<=30 && date>=1)
                    {
                        d=1;
                        break;
                    }
                }
                else
                {
                    if(month==2)
                    {
                        if(date<=29 && date>=1)
                        {
                            d=1;
                            break;
                        }
                    }
                }
                cout<<"GIVE A VALID DATE AND MONTH"<<endl;
                cout<<"*********************"<<endl;
            }
            cout<<"ENTER TOTAL NUMBER OF STUDENT"<<endl;
            cout<<"//////////////////"<<endl;
            int student;
            cin>>student;
            cout<<" press 1-> present or 2 -> absent"<<endl;
            cout<<endl;
            for(int i=1; i<=student; i++)
            {
                cout<<"Roll    "<<i<<' ';
                cin>>o[date-1][month-1].present[i];
            }
            int p=((month-1)*30)+(date-1);
            file.seekp(p*sizeof(o[date-1][month-1]));
            file.write((char *) & o[date-1][month-1],sizeof(o[date-1][month-1]));
            file.close();
        }
        else if(w==2)
        {
            file.open("STUDENT5",ios::in |ios::out);
            cout<<"                                   "<<endl;
            cout<<"GIVE DESIRE AND MONTH AND THE STUDENT ID"<<endl;
            int date,month,id;
            cin>>date>>month>>id;
            double n=0;
            double p=0;
            for(int i=0; i<month; i++)
            {
                for(int j=0; j<date; j++)
                {
                    file.read((char *) & o[j][i],sizeof(o[j][i]));
                    //  cout<<o[j][i].present[id]<<endl;
                    if(o[j][i].present[id]==1)
                    {
                        p++;
                    }
                    if(o[j][i].present[id]!=0)
                    {
                        n++;
                    }
                    if(i+1==month&&j+1==date)
                    {
                        if(o[j][i].present[id]==1)
                        {
                            cout<<o[j][i].present[id]<<" id"<<endl;
                            cout<<' '<< id<<"present"<<endl;
                        }
                        else  if(o[j][i].present[id]==2)
                        {
                            cout<<o[j][i].present[id]<<endl;
                            cout<<" id"<<' '<< id<<"absent"<<endl;
                        }
                        else
                        {
                            cout<<"OFFDAY"<<endl;
                        }
                        cout<<"The persentage is ";
                        cout<<(p/n)*100<<"%"<<endl;
                    }
                }
            }
            file.close();
        }
    }
}
