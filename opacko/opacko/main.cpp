//
//  main.cpp
//  opacko
//
//  Created by Tereza Dohnalová on 20/10/2021.
//

#include <iostream>
#include <array>
#include <vector>
#include <fstream>

struct Position { //prevravka, zpusob jak predat vice atribut nekam, ma pouze atributy
    int x;
    int y;
};

void abc(Position position){}

class Foo {
public:
    Foo(int a){ // konstruktor}
    }
    void abc(){}
};

int main(int argc, const char * argv[]) {

    std::array<std::array<int, 10>, 10> pole; // matice 10x10
    std::vector<int> pole2; //genericke <>
    
    //prochazeni pole
    
    for (int i = 0; i < pole.size(); i++) {
        for (int j = 0; j < pole.at(i).size(); j++) {
            pole.at(i).at(j) = 0;
        }
    }

    for (std::array<int, 10> &i: pole) { //prochazime radky
        for (int &j: i) {
            j = 1; // nepridaji se tam takhle jednicky, pro upravu pole musime pouzit vrchni zapis, nebo pridat &
        }
    }

    
    Position position{1,5}; // instance a inicializace
    abc({1,4}); // preavani do metody
    
    
    Foo foo = Foo(493);
    foo.abc(); // staticka instance, c++ automaticky tuto instanci zrusi, do metod to kopirujeme
    //pouziti treba u structu
    
    Foo* foo2 = new Foo(4939); //vytvari se na heapu
    foo2->abc(); //do dalsich metod posilame pouze odkaz a nekopirujeme instanci, na konci se musi pouzit delete, jinak zustane v pameti
    // pouziti u vetsich objektu
    
    //metoda(&foo); // * odbaluje instanci, & zabaluje
    
    
    //nacitani souboru!!!
    
    std::ifstream in("map.txt");
    
    if (in.is_open()) {
        std::string row; //nacitani po radcich
        std::string word; //po slovu
        //while(in >> word){} // getline je univerzalnejsi, pote dale si to muzeme zpracovavat
        while (getline(in, row)) {
            
            std::cout << row << std::endl;
        }
        in.close();
        
    }else {
        std::cerr << "File cannot open" << std::endl;
    }
    
    return 0;
}

//pulsemestralka - bez sablony, navrhnout tridy, hlavickove
// bludiste, sudoku, zizalka, jednoduche hry, vetsinou byva matice, kterou nacitame ze souboru/vypisujeme, smycka, kde nacitame vstupy
//muze tam byt i regex
//internet i materialy
//naucit se struktury - matice, nacitani souboru, vstupy od uzivatelu
