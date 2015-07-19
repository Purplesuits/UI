#include <iostream>
#include "FileSystem.h"
#include <assert.h>
#include <algorithm>

using namespace std;

int main() {
    //######################Test File Class##############################
    //First test regular File class
    //Here is a regular file named reg with contents blah and 111 perms
    cout<<"###############Test File Class: FileType = 0 (Reg)###############";
    cout<<endl;
    File *regFile = new File("reg","blah",std::vector<bool>{1,1,1});
    cout<<"Test File Class getFileName: ";
    assert("reg"==regFile->getFileName());
    cout<<"1"<<endl;
    cout<<"Test File Class setFileName: ";
    regFile->setFileName("newReg");
    assert("newReg"==regFile->getFileName());
    cout<<"1"<<endl;
    cout<<"Test File Class getFileType: ";
    assert(0==regFile->getFileType());
    cout<<"1"<<endl;
    cout<<"Test File Class setFileType: ";
    regFile->setFileType(1);
    assert(1==regFile->getFileType());
    cout<<"1"<<endl;
    regFile->setFileType(0);
    cout<<"Test File Class getContents: ";
    assert("blah"==regFile->getContents());
    cout<<"1"<<endl;
    cout<<"Test File Class setContents: ";
    regFile->setContents("blah blah");
    assert("blah blah"==regFile->getContents());
    cout<<"1"<<endl;
    std::vector<bool> foo={1,1,1};
    cout<<"Test File Class getPermissions: ";
    assert(foo==regFile->getPermissions());
    cout<<"1"<<endl;
    cout<<"Test File Class setPermissions: ";
    regFile->setPermissions(std::vector<bool>{0,1,1});
    std::vector<bool> bar={0,1,1};
    assert(bar==regFile->getPermissions());cout<<"1"<<endl;
    cout<<"###############Test File Class: FileType = 1 (Dir)###############";
    cout<<endl;
    std::vector<File*> subDir;
    File *dirFile= new File("dirF",subDir,foo);
    cout<<"Test File Class addDirElement: ";
    assert(1==dirFile->addDirElement(regFile));
    cout<<"1"<<endl;
    cout<<"Test File Class getDir: ";
    assert(1==dirFile->getDir().size());
    cout<<"1"<<endl;
    cout<<"Test File Class deleteDirElement: ";
    dirFile->deleteDirElement(regFile);
    assert(0==dirFile->getDir().size());
    cout<<"1"<<endl;


    //build single instance of FileSystem for testing
    FileSystem& fs = FileSystem::getInstance();
    //create blah file
    std::vector<bool> perms{1,0,0};
    std::string b="blah";std::string bb="blah blah";
    fs.fcreate(b,bb,perms);
    //fs.dcreate("blah");
    return 0;
}