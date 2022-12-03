#include<iostream>
#include<fstream>
using namespace std;

class file
{
  public:
	  void writedata();
	  void readdata();
};
void file::writedata()
{
  fstream fp;
  char ch;
  fp.open("newfile.txt",ios::out);
  cin.get(ch);
  while (ch!='*')
  {
    fp.put(ch);
    cin.get(ch);
  }
  fp.close();
}

void file::readdata()
{
	fstream fp;
	char ch;
	fp.open("newfile.txt",ios::in);
  ch=fp.get();
  while(!fp.eof())
  {
    cout<<ch;
    ch=fp.get(); 
  }
    fp.close();
}

int main()
{
  file ob;
  int ch;
  do
  {
    cout<<"\n1.Write content in file : \n2.Read content in file : ";
    cout<<"\nEnter your choice from above options = ";
    cin>>ch;
    switch(ch)
    {
        case 1:
	      ob.writedata();
        break;
        case 2:
	      ob.readdata();
        break;
    }
  }
  while(ch<3);
  return 0;
}