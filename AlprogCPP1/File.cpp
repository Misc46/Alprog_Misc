#include "File.hpp"

File::File(string name)
{
    this->name = name;
    this->content = "";
}

string File::getName()
{
    return name;
}

string File::getContent()
{
    return content;
}

void File::setContent(string newContent)
{
    content = newContent;
}

void File::appendContent(string extraContent)
{
    content += extraContent;
}
