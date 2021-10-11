/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * Threads.cpp
 * c++ -std=c++20 Threads.cpp -o Threads -lpthread
 */

#include <iostream>
#include <sstream>
#include <thread>


#include "../Random.hpp"
#include "../osyncstream.hpp"

#include "Producer.hpp"
#include "Consumer.hpp"
#include "MessageBox.hpp"

//change
#include "../Random.hpp"
#include <chrono>
//end_change

/*
 * Test avec 1 producteur et 1 consommateur
 */
int main() {
    // Créer un générateur de nombres aléatoires
    // Créer une boîte à lettres
    // Créer un producteur et un consommateur
    // Créer les threads correspondants
    // Attendre la fin des threads

    Random generator{ 50 };
    int alea = generator();
    MessageBox boite_aux_lettres;
    Producer producteur(1, boite_aux_lettres, generator, 20 );
    Consumer consommateur(1, boite_aux_lettres, generator, 20 );

    //producteur.operator()();
    //pthread_cond_init( , NULL );

    std::thread c(consommateur);
    std::thread p(producteur);

    c.join();
    p.join();

    return 0;
}

