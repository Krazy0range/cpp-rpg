#ifndef lingual_hpp
#define lingual_hpp

#include <string>

struct LingualString
{
    LingualString(
        std::string *english,
        std::string *latin,
        std::string *tokipona
    ) :
        english(english),
        latin(latin),
        tokipona(tokipona)
    {};

    LingualString(
        std::string english,
        std::string latin,
        std::string tokipona
    ) :
        english(&english),
        latin(&latin),
        tokipona(&tokipona)
    {};

    LingualString(
        std::string english
    ) :
        english(&english),
        latin(nullptr),
        tokipona(nullptr)
    {};

    const std::string *english;
    const std::string *latin;
    const std::string *tokipona;
};

#endif