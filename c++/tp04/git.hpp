#include <iostream>
#include <string>
#define N 100
#using namespace std



class Directory: class File
{
    Directory* parent;
    Directory list[N];
    int nb_sub;
    TextFile L[N];
    ExecFile E[N];
    Directory(Directory* x,Directory y[N],TextFile a[N],ExecFile b[N])
    {
        parent =x;


    }
};


class TextFile :: class File 
{
    TextFile(string directory){

    };
};

public abstract class ExecFile :: class TextFile
{
    ExecFile();

}

class File {
    string name;
    string location;
    string permessions; 
    string date_creation;
    File(string ,string ,string,string);
    
}

class shell {
    Directory ROOTDIR;
    Directory BINDIR;
    Directory currdir;
    shell();
}