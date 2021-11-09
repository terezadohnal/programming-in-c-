//
//  main.cpp
//  obchod
//
//  Created by Tereza Dohnalová on 03/11/2021.
//

#include <iostream>
#include "Store.h"

int main(int argc, const char *argv[]) {
    auto *store = new Store();

    store->addCustomer(1, 12, "Ivo", "adresa");
    store->addCustomer(2, 10, "Anna", "adresa2");
    store->printAllCustomers();
    std::cout << "------" << std::endl;

    store->sortCustomersByVipStatus();
    store->printAllCustomers();
    std::cout << "------" << std::endl;

    store->selectActiveCustomer(1);
    store->printBasketInfo();
    std::cout << "------" << std::endl;

    store->addItemToBasket(9999999, "Macbook");
    store->addItemToBasket(1000, "Chromebook");
    store->printBasketInfo();
    store->placeOrder();
    std::cout << "------" << std::endl;

    store->addItemToBasket(2.5, "Rohlik");
    store->printBasketInfo();
    store->placeOrder();
    std::cout << "------" << std::endl;

    store->printDatesOfNewOrders();
    std::cout << "------" << std::endl;

    store->sortCustomersByVipStatus();
    store->printAllCustomers();

    delete store;

    return 0;
}

