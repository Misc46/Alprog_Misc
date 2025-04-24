#include "FileSystemManager.hpp"
#include <iostream>
using namespace std;

FileSystemManager::FileSystemManager(Directory dir) : directory(dir) {}

void FileSystemManager::touch(string name)
{
    directory.addFile(name);
}

void FileSystemManager::echo(string content, string name, int mode)
{
    vector<File> &files = directory.getFiles();
    for (File &f : files)
    {
        if (f.getName() == name)
        {
            if (mode == 1)
                f.setContent(content);
            else if (mode == 2)
                f.appendContent(content);
        }
    }
}

void FileSystemManager::cat(string name)
{
    vector<File> &files = directory.getFiles();
    for (File &f : files)
    {
        if (f.getName() == name)
        {
            cout << f.getContent() << endl;
        }
    }
}

void FileSystemManager::ls()
{
    vector<File> &files = directory.getFiles();
    for (File &f : files)
    {
        cout << f.getName() << endl;
    }
}

void FileSystemManager::run()
{
    string command;
    while (true)
    {
        cout << "[" << directory.getName() << "]$ ";
        cin >> command;

        if (command == "touch")
        {
            string name;
            cin >> name;
            touch(name);
        }
        else if (command == "echo")
        {
            string content, name, option;
            cin >> content >> option >> name;
            if (option == ">")
                echo(content, name, 1);
            else if (option == ">>")
                echo(content, name, 2);
        }
        else if (command == "cat")
        {
            string name;
            cin >> name;
            cat(name);
        }
        else if (command == "ls")
        {
            ls();
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "Unknown command." << endl;
        }
    }
}