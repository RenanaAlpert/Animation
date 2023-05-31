#pragma once
#include <string>
#include "Group.h"

namespace experis
{

void SavePainting(std::string a_filePath, Group a_painting);
Group LoadPainting(std::string a_filePath);

}