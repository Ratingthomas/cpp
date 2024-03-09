#include <iostream>
#include "money_database.h"

int main() {
    money_database::MoneyDatabase db{};

    std::cout << "Enter a currency code, followed by an amount of money. Enter \"quit\" to stop.\n";

    auto should_quit = false;

    while (!should_quit)
    {
        std::string currency{};
        double amount{};

        std::cin >> currency;
        if (currency == "quit")
        {
            should_quit = true;
        }
        else if (currency.size() == 3)
        {
            std::cin >> amount;
            db.add(Deposit{currency, amount});
        }
    }

    std::cout << "The database contains " << db.size() << " entries.\n";

    std::cout << "The total amount of money in euros is " << db.total_of("EUR") << ".\n";


    return 0;
}
