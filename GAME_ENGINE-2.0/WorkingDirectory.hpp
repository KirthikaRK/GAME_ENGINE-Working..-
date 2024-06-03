#pragma once
#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP
#include<string>

class WorkingDirectory
{
public:
    WorkingDirectory();

    inline const std::string& Get() 
    {
        return path;
    }
private:
    std::string path;
};

#endif
