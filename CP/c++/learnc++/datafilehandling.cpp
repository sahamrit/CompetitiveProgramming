#include <iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


int main() {
 ofstream fout;
 fout.open("Aschars",ios::out);
 char ch;int line=0;
 for(int i=33;i<128;i++)
 {
     fout.put((char )i);fout<<' ';
      if(!(i%8)){fout.put('\n');}
 }
 fout.close();
 ifstream fin;
 fin.open("Aschars",ios::in);
 while(fin){fin.get(ch); cout<<ch;}
 }


