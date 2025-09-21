#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Item {
private:
    std::string name;
    int quantity;
    float price;

public:
    Item(std::string name, int quantity, float price)
        : name(std::move(name)), quantity(quantity), price(price) {}

    std::string get_name() const { return name; }
    int get_quantity() const { return quantity; }
    void set_quantity(int new_quantity) { quantity = new_quantity; }
    float get_price() const { return price; }
    bool is_match(const std::string &other) { return name == other; }
};

class Inventory {
private:
    std::vector<std::unique_ptr<Item>> items; // vector instead of array
    float total_money = 0;

    static void display_data(Item &item) {
        std::cout << "\nItem name: " << item.get_name()
                  << "\nQuantity: " << item.get_quantity()
                  << "\nPrice: " << item.get_price() << "\n";
    }

public:
    void add_item() {
        std::string name;
        int quantity;
        float price;

        std::cin.ignore();
        std::cout << "\nEnter item name: ";
        std::cin >> name;
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        std::cout << "Enter price: ";
        std::cin >> price;

        items.push_back(std::make_unique<Item>(name, quantity, price));
    }

    void sell_item() {
        std::string item_to_check;
        std::cin.ignore();
        std::cout << "\nEnter item name: ";
        std::cin >> item_to_check;

        for (size_t i = 0; i < items.size(); i++) {
            if (items[i]->is_match(item_to_check)) {
                remove_item(i);
                return;
            }
        }
        std::cout << "\nThis item is not in your Inventory\n";
    }

    void remove_item(size_t index) {
        int input_quantity;
        Item *item = items[index].get();

        std::cout << "\nEnter number of items to sell: ";
        std::cin >> input_quantity;

        int quantity = item->get_quantity();
        if (input_quantity <= quantity) {
            float price = item->get_price();
            float money_earned = price * input_quantity;
            int new_quantity = quantity - input_quantity;

            if (new_quantity > 0) {
                item->set_quantity(new_quantity);
            } else {
                // remove item completely from vector
                items.erase(items.begin() + index);
                std::cout << "\nItem removed from inventory.";
            }

            std::cout << "\nItems sold";
            std::cout << "\nMoney received: " << money_earned << "\n";
            total_money += money_earned;
        } else {
            std::cout << "\nCannot sell more items than you have.\n";
        }
    }

    void list_items() {
        if (items.empty()) {
            std::cout << "\nInventory empty.\n";
            return;
        }

        for (auto &item : items) {
            display_data(*item);
        }
    }
};
