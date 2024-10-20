#include "Item.h"

Item::Item(const std::string& desc, int val, int qty)
    : description(desc), value(val), quantity(qty) {}

// Getters
std::string Item::getDescription() const {
    return description;
}

int Item::getValue() const {
    return value;
}

int Item::getQuantity() const {
    return quantity;
}

// Setters
void Item::setQuantity(int qty) {
    quantity = qty;
}