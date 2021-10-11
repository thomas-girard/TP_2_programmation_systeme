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
#include <mutex>
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

    Producer producteur_1(1, boite_aux_lettres, generator, 10);
    Producer producteur_2(1, boite_aux_lettres, generator, 10);
    Producer producteur_3(1, boite_aux_lettres, generator, 10);
    Producer producteur_4(1, boite_aux_lettres, generator, 10);

    Consumer consommateur_1(1, boite_aux_lettres, generator, 20);
    Consumer consommateur_2(1, boite_aux_lettres, generator, 20);

    //producteur.operator()();
    //pthread_cond_init( , NULL );

    std::thread c_1(consommateur_1);
    std::thread c_2(consommateur_2);

    std::thread p_1(producteur_1);
    std::thread p_2(producteur_2);
    std::thread p_3(producteur_3);
    std::thread p_4(producteur_4);

    c_1.join();
    c_2.join();

    p_1.join();
    p_2.join();
    p_3.join();
    p_4.join();

    return 0;
}

