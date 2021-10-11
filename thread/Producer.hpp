/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * Producer.hpp
 */

#pragma once

#include <iostream>
#include <thread>

#include "../osyncstream.hpp"

#include "ProdOrCons.hpp"


//change
#include "../Random.hpp"
#include <chrono>
//end_change

/*
 * Producteur de messages
 */
class Producer : public ProdOrCons {
public:
    // Le constructeur de ProdOrCons peut être utilisé pour Producer
    using ProdOrCons::ProdOrCons;

    void operator()() override {
        // TODO : déposer dans box nb_messages nombres entiers positifs avec attente
        // aléatoire entre chaque. Afficher des messages pour suivre l'avancement.

        for (int i=0; i < nb_messages_; i++) {


            Random generator{ 500 };
            int alea = generator();

            box_.put(alea);


            using milliseconds = std::chrono::duration< int, std::milli >;
            //std::cout << "wait" << std::endl;
            //{ osyncstream( std::cout ) << " wait " << alea; }
            std::this_thread::sleep_for( milliseconds{ alea });

        };
    }
};

