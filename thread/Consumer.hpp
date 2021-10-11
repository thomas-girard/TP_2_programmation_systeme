/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * Consumer.hpp
 */

#pragma once

#include <iostream>
#include <thread>

#include "../osyncstream.hpp"

#include "ProdOrCons.hpp"



/*
 * Consommateur de messages
 */
class Consumer : public ProdOrCons {
public:
    // Le constructeur de ProdOrCons sera utilisé comme constructeur de Consumer
    using ProdOrCons::ProdOrCons;

    void operator()() override {
        // TODO
        for (int i=0; i < nb_messages_; i++) {
            int entier = box_.get();
            { osyncstream( std::cout ) << " entier  \n" << entier; }

        }
    }
};

