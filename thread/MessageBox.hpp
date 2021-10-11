/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * MessageBox.hpp
 */

#pragma once

#include <array>
#include <algorithm>
#include <mutex>
#include <condition_variable>

#include "../BasicMessageBox.hpp"

std::mutex my_mutex;
int nb_data=0;

std::condition_variable boite_vide;
std::condition_variable boite_pleine;
/*
 * FIFO d'echange de messages entre producteurs et consommateurs
 * Version pour synchronisation entre threads
 */
class MessageBox : public BasicMessageBox {
public:
    void put( int message ) {

        std::unique_lock<std::mutex> my_lock(my_mutex);

        if (nb_data < box_size_) {
            // std::this_thread::sleep_for (std::chrono::seconds(1));
            basic_put( message );
            nb_data+=1;
            std::cout << "je remplit la boite : " << nb_data << std::endl;
            boite_vide.notify_all();
        }

        else {
            std::cout << "wait notif de boite_pleine" << std::endl;
            boite_pleine.wait(my_lock);
        }
    }

    int get() {
        // TODO : ajouter les mecanismes de synchronisation
        std::unique_lock<std::mutex> my_lock(my_mutex);
        while (nb_data <= 0) {
            std::cout << "wait notif de boite_vide" << std::endl;
            boite_vide.wait(my_lock);
        }
        int message{ basic_get() };
        nb_data-=1;
        std::cout << "je vide la boite : " << nb_data << std::endl;
        boite_pleine.notify_all();

        return message;
    }
private:
    // TODO : ajouter les objets de synchronisation
};

