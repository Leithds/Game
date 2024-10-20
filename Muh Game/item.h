#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string description;
    int value;
    int quantity;

public:
    Item(const std::string& desc, int val, int qty);

    // Getters
    std::string getDescription() const;
    int getValue() const;
    int getQuantity() const;

    // Setters
    void setQuantity(int qty);
};

#endif