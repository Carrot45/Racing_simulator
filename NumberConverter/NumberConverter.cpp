#include "NumberConverter.h"

NumberConverter::NumberConverter() {
    words[0] = "";
    words[1] = "Áîòèíêè-âåçäåõîäû";
    words[2] = "Ìåòëà";
    words[3] = "Âåğáëşä";
    words[4] = "Êåíòàâğ";
    words[5] = "Îğ¸ë";
    words[6] = "Âåğáëşä-áûñòğîõîä";
    words[7] = "Êîâåğ-ñàìîë¸ò";
}

const char* NumberConverter::getWord(int num) {
    if (num >= 1 && num <= 7) {
        return words[num];
    }
    return "Îøèáêà âûçîâà";
}