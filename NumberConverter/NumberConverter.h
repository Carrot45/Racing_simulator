#ifndef NUMBERCONVERTER_H
#define NUMBERCONVERTER_H

#ifdef NUMBERCONVERTER_EXPORT
#define NUMBERCONVERTER_API __declspec(dllexport)
#else
#define NUMBERCONVERTER_API __declspec(dllimport)
#endif

class NUMBERCONVERTER_API NumberConverter {
private:
    const char* words[8];  // ← const char* вместо std::string

public:
    NumberConverter();
    const char* getWord(int num);  // ← возвращаем const char*
};

#endif