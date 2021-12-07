//
//  Store.cpp
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "Store.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include "CustomerException.h"


Store::Store() {
}

void Store::addCustomer(const int memberId, const float age,
                        const std::string name, const std::string address) {
    // TODO
    
    Customer customer;
    customer.memberId = memberId;
    customer.age = age;
    customer.name = name;
    customer.address = address;
    customer.vipMember = false;
    
    m_customers.push_back(customer);
    
    //nebo
    //m_customers.push_back(Customer{memberId, age, false, name, address});
}

void Store::selectActiveCustomer(const int memberId) { // const - parametr se nemeni
    // TODO
    
    // lambda vyraz sablona: [promenna z venku](parametr labda vyrazu) -> typ {}
    auto iterator = std::find_if(
                                 m_customers.begin(),
                                 m_customers.end(),
                                 [memberId](const Customer &customer) -> bool {
                                    return customer.memberId == memberId;
                                });
    // vrati se nam prvni customer s shodnym id
    
    if (iterator != m_customers.end()) { // end ukaze na uplny konec, coz na m vrati find if pokud to nenajde zadneho zakaznika
        m_activeCustomer = iterator;
    }else {
        throw CustomerException("Zakaznik nebyl nalezen", memberId);
    }
    
    //nahrada za for cyklus:
//    for (int i = 0; i < m_customers.size(); i++) {
//        if(predicate()){
//            return;
//        }
//    }
}

void Store::addItemToBasket(const float price, const std::string description) {
    // TODO
//    Item item;
//    item.price = price;
//    item.description = description;
//    m_basket.push_back(item);
    
    //nebo
    
    m_basket.push_back(Item{description, price});
}

void Store::emptyBasket() {
    // TODO
    m_basket.clear();
}

void Store::placeOrder() {
    // TODO
    
    Order newOrder;
    
    newOrder.time = std::chrono::system_clock::now(); // ziskani aktualniho casu
    
    newOrder.items.resize(m_basket.size());
    std::copy(m_basket.begin(), m_basket.end(), newOrder.items.begin());
    
    newOrder.status = OrderStatus::New;
    
    m_orders.insert(std::pair<Customer*, Order>(&(*m_activeCustomer), newOrder));
    //objednavky jsou multimapa, ktera je vektor s klicema
    //[c1 => k1, c2 => k2, c3 => k3]
    //pote jsme schopni jednoduse pristoupit k prvku mapy
    //udela vektor, klice jsou cislovani zakazniku treba
    //kdyz insertujeme, musime insertovat par
    
    emptyBasket();
    setVipStatus();
}

void Store::sortCustomersByVipStatus() {
    // TODO
    std::sort(m_customers.begin(), m_customers.end(), [](Customer &first, Customer &second) -> bool {
        return (first.vipMember < second.vipMember);
            }
              );
    
    //sort vezme dvojici prvku a porovna je a prehodi je podle podminky
    
    std::stable_sort(m_customers.begin(), m_customers.end(), [](Customer &first, Customer &second) -> bool {
        return !(!first.vipMember and second.vipMember);
        
//        if (first.vipMember == false and second.vipMember == true) {
//            return false;
//        }else {
//            return true;
//        }
    });
    
    //stable sort zajisti pokud jsou prvky ve spravnem poradi, tak se neprehodi
    //u klasickeho sortu se nezaruci poradi
}

void Store::printAllCustomers() const {
    // TODO
    
    std::for_each(
                  m_customers.begin(),
                  m_customers.end(),
                  [](const Customer &c) -> void {
                    std::cout << "jmeno: " << c.name << "\tvek: " << c.age << "\tVIP: " << (c.vipMember ? "ano" : "ne") << std::endl << "adresa: " << c.address << std::endl << "ID" << c.memberId;
    });
}

void Store::printDatesOfNewOrders() {
    // TODO
    Order order;
    if (order.status == OrderStatus::New) {
        std::for_each(
                      m_orders.begin(),
                      m_orders.end(),
                      [](const Order &o) -> void {
            std::time_t now = std::chrono::system_clock::to_time_t(o.time - std::chrono::hours(24));
            std::cout << "datum objednavky: " << std::ctime(&now) << std::endl;
        });
    }
}


void Store::printBasketInfo() {
    // TODO
    std::for_each(
                  m_basket.begin(),
                  m_basket.end(),
                  [](const Item &item) -> void {
        std::cout << "description: " << item.description << "\tprice: " << item.price << std::endl;
    });
}

void Store::setVipStatus() {
    // TODO
    m_activeCustomer->vipMember = true;
}





