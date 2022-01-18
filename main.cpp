#include "main.h"

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void printColorManual()
{
    std::cout << "Color Pair Manual Mapping:" << std::endl;
    for (int i = 0; i < TelCoColorCoder::numberOfMajorColors; i++)
    {
        for (int j = 0; j < TelCoColorCoder::numberOfMinorColors; j++)
        {
            std::string colorPairMappingStr = TelCoColorCoder::MajorColorNames[i];
            colorPairMappingStr += "-";
            colorPairMappingStr += TelCoColorCoder::MinorColorNames[j];
            int colorMappingNumber = i + j + 1;
            std::cout << colorMappingNumber << " " << colorPairMappingStr << std::endl;
        }
    }
}

int main() {
    printColorManual();
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    return 0;
}
