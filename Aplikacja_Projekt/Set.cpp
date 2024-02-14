#include "Set.h"

template<typename T>
Set<T>::Set() : pierwszy_element(nullptr) {}

template<typename T>
Set<T>::Set(const Set<T>& lista1, const Set<T>& lista2) {
    std::shared_ptr<Zbior> biezacy1 = lista1.pierwszy_element;
    std::shared_ptr<Zbior> biezacy2 = lista2.pierwszy_element;
    while (biezacy1 != nullptr) {
        this->dodaj(biezacy1->dane);
        biezacy1 = biezacy1->kolejny_element;
    }
    while (biezacy2 != nullptr) {
        this->dodaj(biezacy2->dane);
        biezacy2 = biezacy2->kolejny_element;
    }
}

template<typename T>
void Set<T>::wypisz(std::string nazwa_pliku) {
    std::ofstream plik(nazwa_pliku);
    std::shared_ptr<Zbior> obecny = pierwszy_element;
    if (plik) {
        while (obecny) {
            plik << obecny->dane << ", ";
            obecny = obecny->kolejny_element;
        }
    }
}

template<typename T>
void Set<T>::kopiuj(const Set<T>& lista1, const Set<T>& lista2) {
    std::shared_ptr<Zbior> biezacy1 = lista1.pierwszy_element;
    std::shared_ptr<Zbior> biezacy2 = lista2.pierwszy_element;
    while (biezacy1 != nullptr) {
        this->dodaj(biezacy1->dane);
        biezacy1 = biezacy1->kolejny_element;
    }
    while (biezacy2 != nullptr) {
        this->dodaj(biezacy2->dane);
        biezacy2 = biezacy2->kolejny_element;
    }
}

template<typename T>
bool Set<T>::sprawdzanie(const T& wartosc) const {
    std::shared_ptr<Zbior> current = pierwszy_element;
    while (current) {
        if (current->dane == wartosc)
            return true;
        current = current->kolejny_element;
    }
    return false;
}

template<typename T>
void Set<T>::dodaj(const T& wartosc) {
    if (!sprawdzanie(wartosc)) {
        std::shared_ptr<Zbior> nowy_Zbior = std::make_shared<Zbior>(wartosc);
        nowy_Zbior->kolejny_element = pierwszy_element;
        pierwszy_element = nowy_Zbior;
    }
}

template<typename T>
void Set<T>::print() const{
    std::shared_ptr<Zbior> current = pierwszy_element;
    while (current) {
        std::cout << current->dane << " ";
        current = current->kolejny_element;
    }
    std::cout << std::endl;
}

template<typename T>
std::shared_ptr<Set<T>> Set<T>::czesc_wspolna(const Set<T>& other) const{
    std::shared_ptr<Set<T>> result = std::make_shared<Set<T>>();
    std::shared_ptr<Zbior> current = pierwszy_element;
    while (current) {
        if (other.sprawdzanie(current->dane)) {
            result->dodaj(current->dane);
        }
        current = current->kolejny_element;
    }
    return result;
}

template<typename T>
std::shared_ptr<Set<T>> Set<T>::roznica(const Set<T>& other) const{
    std::shared_ptr<Set<T>> result = std::make_shared<Set<T>>();
    std::shared_ptr<Zbior> current = pierwszy_element;

    while (current) {
        if (!other.sprawdzanie(current->dane)) {
            result->dodaj(current->dane);
        }
        current = current->kolejny_element;
    }

    current = other.pierwszy_element;
    while (current) {
        if (!sprawdzanie(current->dane)) {
            result->dodaj(current->dane);
        }
        current = current->kolejny_element;
    }

    return result;
}

template<typename T>
void Set<T>::sortowanie_babelkowe() {
    if (!pierwszy_element)
        return;

    bool swapped;
    std::shared_ptr<Zbior> ptr1;
    std::shared_ptr<Zbior> lptr = nullptr;

    do {
        swapped = false;
        ptr1 = pierwszy_element;

        while (ptr1->kolejny_element != lptr) {
            if (ptr1->dane > ptr1->kolejny_element->dane) {
                T temp = ptr1->dane;
                ptr1->dane = ptr1->kolejny_element->dane;
                ptr1->kolejny_element->dane = temp;
                swapped = true;
            }
            ptr1 = ptr1->kolejny_element;
        }
        lptr = ptr1;
    } while (swapped);
}

template<typename T>
bool Set<T>::szukaj(const T& wartosc) const{
    return sprawdzanie(wartosc);
}

template<typename T>
std::shared_ptr<typename Set<T>::Zbior> Set<T>::operator->() const {
    return pierwszy_element;
}

template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& kopiowany_zbior) {
    if (this == &kopiowany_zbior)
        return *this;

    pierwszy_element = nullptr;

    std::shared_ptr<Zbior> current = kopiowany_zbior.pierwszy_element;
    while (current) {
        dodaj(current->dane);
        current = current->kolejny_element;
    }

    return *this;
}

