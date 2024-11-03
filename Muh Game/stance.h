#pragma once

#include <string>

class Stance {
public:
    enum class isTag {
        Softness, Speed, Strength, Precision, Fluidity, Deception
    };

    enum class hasTag {
        Softness, Speed, Strength, Precision, Fluidity, Deception
    };

    Stance(const std::string& name, isTag type, hasTag countsAsType, const std::string& primaryStat, const std::string& secondaryStat);
    virtual ~Stance() = default;

    std::string getName() const;
    isTag getIsTag() const;
    hasTag getHasTag() const;
    std::string getPrimaryStat() const;
    std::string getSecondaryStat() const;

protected:
    std::string name;
    isTag tagType;
    hasTag hasTagType;
    std::string primaryStat;
    std::string secondaryStat;
};