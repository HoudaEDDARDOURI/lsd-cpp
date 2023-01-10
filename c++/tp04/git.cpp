#include <iostream>
#include <GIT.hpp>

#using namespace std



Shell:: Shell ()
{ 
    ROOTDIR.name = "home";
    BINDIR.name = "bin";
}

TextFile :: TextFile(string directory){
            location = directory;
    }

ExecFile :: ExecFile
{
    location = "home/bin";
}

File:: File(string a ,string b,string c,string d)
{
    name=a;
    location=b;
    permessions=c; 
    date_creation=d;

}

int main()
{

    return 0;
}
