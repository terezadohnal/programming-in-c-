//
//  Store.h
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef __CPP_cviceni6_obchod__Store__
#define __CPP_cviceni6_obchod__Store__

#include <iostream>
#include <vector>
#include <map>
#include "Customer.h"
#include "Order.h"

/**
 Engine obchodu realizujici objenavky a dalsi operace
 */
class Store {

private:
    std::vector<Customer> m_customers;        ///< seznam zakazniku obchodu [C1, C2, C3]
    std::multimap<Customer *, Order> m_orders;           ///< seznam objednavek [C1 => O1, C2 => O2, C3 => O3]

    std::vector<Customer>::iterator m_activeCustomer;   ///< zakaznik prave pracujici s obchodem
    // ukazatel na konkretniho zakaznika
    std::vector<Item> m_basket;           ///< Nakupni kosik;
public:
    /// Konstruktor, pouze inicializuje atributy
    Store();

    /// Prida do vectoru zakaznika
    void addCustomer(const int memberId, const float age,
                     const std::string name, const std::string address);

    /* -----------------------------------------------------------------*/
    // Nasledujici metody by mely byt v samostatne tride - Nakupni kosik,
    // ale abychom cviceni nekomplikovali, jsou zde
    /* -----------------------------------------------------------------*/
    /// Zvoli zakaznika, ktery prave se systemem pracuje
    void selectActiveCustomer(const int memberId);

    /// Prida zbozi do kosiku
    void addItemToBasket(const float price, const std::string description);

    /// Vysype kosik
    void emptyBasket();

    /// Vypise informace o zbozi v kosiku
    void printBasketInfo();

    /// Vytvori objenavku ze zbozi v kosiku
    void placeOrder();
    /* -----------------------------------------------------------------*/

    /// Setrid zakazniky podle VIP statusu a nasledne podle abecedy
    /// Tj. nejdrive budou abecedne serazeni VIP a pak abecedne serazeny zbytek
    void sortCustomersByVipStatus();

    /// Vypise vsechny zakazniky
    void printAllCustomers() const;

    /// Vypise datumy objednani vsech dorucovanych objednavek
    void printDatesOfNewOrders();

private:
    /// Tato metoda je volana automaticky pri zadani kazde objednavky
    /// Pokud pocet objednavek presahne 3, ma zakaznik VIP status.
    void setVipStatus();
};

#endif /* defined(__CPP_cviceni6_obchod__Store__) */
