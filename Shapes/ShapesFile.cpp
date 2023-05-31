#include "ShapesFile.h"
#include <fstream>
#include "AddShapeFromOutside.h"

namespace experis
{

bool VecContain(const std::vector<char>& a_vec, const char a_c)
{
    for ( char c : a_vec)
    {
        if (c == a_c)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::string> Split(const std::string& a_toSplit, const std::vector<char>& a_howSplit)
{
	std::vector<std::string> partsOfString{};
	int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= a_toSplit.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (VecContain(a_howSplit, a_toSplit[i]) || i == a_toSplit.size()) {
            endIndex = i;
            std::string thePart;
            thePart.append(a_toSplit, startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            if (thePart == "")
            {
                continue;
            }
            partsOfString.push_back(thePart);
        }
    }
    return partsOfString;
}

void SavePainting(std::string a_filePath, Group a_painting)
{
	std::ofstream f{a_filePath};
	f << a_painting.ConvertToString();
	f.close();
}

Group LoadPainting(std::string a_filePath)
{
    Group toReturn{'*'};
    std::ifstream f{a_filePath};
    std::string shape{};
    while(std::getline(f, shape))
    {
        std::vector<std::string> shapeData = Split(shape, {':', ',', ' '});
        PARSE_SHAPES.at(shapeData.at(0))->Add(toReturn, shapeData);
    }
    return toReturn;
}

}