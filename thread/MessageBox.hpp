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

/*
 * FIFO d'echange de messages entre producteurs et consommateurs
 * Version pour synchronisation entre threads
 */
class MessageBox : public BasicMessageBox {
public:
    void put( int message ) {

        std::unique_lock<std::mutex> my_lock(my_mutex);

        while (nb_data <= box_size_) {
            // std::this_thread::sleep_for (std::chrono::seconds(1));
            basic_put( message );
            nb_data+=1;
            boite_vide.notify_all();
        }
        // TODO : ajouter les mecanismes de synchronisation
    }

    int get() {
        // TODO : ajouter les mecanismes de synchronisation
        std::unique_lock<std::mutex> my_lock(my_mutex);
        boite_vide.wait(my_lock);
        int message{ basic_get() };
        nb_data-=1;
        return message;
    }
private:
    // TODO : ajouter les objets de synchronisation
};

