#include<iostream>
#include<fstream>

using namespace std;
struct stud{int roll;
char name[100];};
int main()
{stud s1,s2;long pos;char ch='n';
    char choice='y';
    ofstream fout("file",ios::out|ios::binary);
    while(choice=='y')
    {
        cout<<"enter data\n";
        cin>>s1.roll>>s1.name;
        fout.write((char *)&s1,sizeof(s1));
        cout<<"do u want to enter more";
        cin>>choice;
    }
    fout.close();
    ifstream fin("file",ios::in|ios::binary);
      fout.open("temp",ios::out|ios::binary);
    cout<<"enter detail of student to be inserted ";
    cin>>s2.roll>>s2.name;
    while(!fin.eof())
    {pos=fin.tellg();
    fin.read((char *)&s1,sizeof(s1));
    if(s2.roll<s1.roll)
    {    ch='y';
        fout.write((char *)&s2,sizeof(s2));
    fin.seekg(pos);
        break;
    }else{if(!fin.eof())fout.write((char *)&s1,sizeof(s1));}

    }
if(ch=='n')
{fout.write((char *)&s2,sizeof(s2));
}else {while(!fin.eof())
{
    fin.read((char *)&s1,sizeof(s1));

    if(!fin.eof())
    fout.write((char *)&s1,sizeof(s1));
}
}

fin.close();
fout.close();
remove("file");
rename("temp","file");
fin.open("file",ios::in|ios::binary);

    while(!fin.eof())
{fin.read((char *)&s1,sizeof(s1));
if(fin.eof()){break;}
  cout<<s1.roll<<"\n"<<s1.name<<endl;
}
fin.close();
}






