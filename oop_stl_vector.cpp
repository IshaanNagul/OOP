#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class student
{
    public:
    int rollno;
    string name;
    char mob[20];

    bool operator == (const student &student1)
    {
        return(rollno==student1.rollno);
    }
    friend ostream& operator << (ostream &out,const student &);
    friend istream& operator >> (istream &in,student &k);
};
ostream & operator << (ostream &out,const student &k)
{
    out<<"\n\t\t"<<k.rollno<<"\t\t"<<k.name<<"\t\t"<<k.mob;
    return out;
}
istream & operator >> (istream &in , student &k)
{
    cout<<"\nEnter Roll No : ";
    in>>k.rollno;
    cout<<"\nEnter Name : ";
    in>>k.name;
    cout<<"\nEnter mob : ";
    in>>k.mob;
    return in;
}
vector<student> read()
{
    int n;
    student k;
    vector<student> j;
    cout<<"\nEnter Total no. of Students : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        j.push_back(k);
    }
    return j;
}
void printfunction(const student &k)
{
    cout<<k;
}
void print(const vector<student> &j)
{
    cout<<"\n\t\tROLL NO\t\tNMAE\t\tMOBILE NUMBER";
    for_each(j.begin(),j.end(),printfunction);
}
void search(vector<student> &j)
{
    student k;
    cout<<"\nEnter Roll No. to Search : ";
    cin>>k.rollno;
    cout<<"\n\n\t\tROLL NO\t\tNAME\t\tDATE OF BIRTH";
    vector<student>::iterator p;
    p=find(j.begin(),j.end(),k);
    if(p!=j.end())
    cout<<*p;
    else
    cout<<"\nNot Found"; 
}
bool sort_func(const student &x , const student &y)
{
    return(x.rollno<y.rollno);
}
void sort(vector<student> &j)
{}

int main()
{
    vector<student> s;
    int ch;
    do
    {
        cout<<"\n\n\t\t*** Personal Record Database***";
        cout<<"\n\t\t1.Create Record";
        cout<<"\n\t\t2.Display Record";
        cout<<"\n\t\t3.Search Record";
        cout<<"\n\t\t4.Sort Record";
        cout<<"\n\t\t5.Quit Menu";
        cout<<"\n\t\tEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            s=read();
            break;

            case 2:
            print(s);
            break;

            case 3:
            search(s);
            break;
            
            case 4:
            sort(s);
            print(s);
            break; 

        }

    }
    while(ch!=5);
     
};
