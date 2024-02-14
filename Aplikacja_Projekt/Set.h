#ifndef SET_H
#define SET_H

#include <memory>
#include <fstream>
#include <iostream>

template<typename T>
class Set {
private:
    struct Zbior {
        T dane;
        std::shared_ptr<Zbior> kolejny_element;

        Zbior(const T& val) : dane(val), kolejny_element(nullptr) {}
    };

    std::shared_ptr<Zbior> pierwszy_element;

public:
    Set();
    Set(const Set<T>& lista1, const Set<T>& lista2);
    void wypisz(std::string nazwa_pliku);
    void kopiuj(const Set<T>& lista1, const Set<T>& lista2);
    bool sprawdzanie(const T& wartosc) const;
    void dodaj(const T& wartosc);
    void print() const;
    std::shared_ptr<Set<T>> czesc_wspolna(const Set<T>& other) const;
    std::shared_ptr<Set<T>> roznica(const Set<T>& other) const;
    bool szukaj(const T& wartosc) const;
    void sortowanie_babelkowe();
    std::shared_ptr<Zbior> operator->() const;
    Set<T>& operator=(const Set<T>& kopiowany_zbior);
};

#endif