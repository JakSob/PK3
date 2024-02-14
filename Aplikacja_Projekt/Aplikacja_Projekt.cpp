#include "Set.h"
#include "Set.cpp"
int main() {
    char option;

    Set<int> s1;
    s1.dodaj(2);
    s1.dodaj(2);
    s1.dodaj(3);
    s1.dodaj(4);
    s1.dodaj(4);

    Set<int> s2;
    s2.dodaj(1);
    s2.dodaj(2);
    s2.dodaj(3);
    s2.dodaj(5);
    s2.dodaj(5);

    Set<int> s3;

    s1.wypisz("plik.txt");
    s2.wypisz("plik.txt");

    while (true) {
        std::cout << "Wybierz opcje:" << std::endl;
        std::cout << "1. Dodaj element do zbioru s1" << std::endl;
        std::cout << "2. Dodaj element do zbioru s2" << std::endl;
        std::cout << "3. Czesc wspolna zbiorow s1 i s2" << std::endl;
        std::cout << "4. Wypisz roznice zbioru" << std::endl;
        std::cout << "5. Polaczenie zbiorow s1 i s2 w jeden" << std::endl;
        std::cout << "6. Szukanie wartosci w zbiorze s1" << std::endl;
        std::cout << "7. Szukanie wartosci w zbiorze s2" << std::endl;
        std::cout << "8. Wyjscie" << std::endl;
        std::cout << "Opcja: ";
        std::cin >> option;

        switch (option) {
        case '1': {
            int wartosc;
            std::cout << "Wpisz wartosc jaka chcesz dodac do zbioru s1: ";
            std::cin >> wartosc;
            s1.dodaj(wartosc);
            s1.print();
            break;
        }
        case '2': {
            int wartosc;
            std::cout << "Wpisz wartosc jaka chcesz dodac do zbioru s2: ";
            std::cin >> wartosc;
            s2.dodaj(wartosc);
            s2.print();
            break;
        }
        case '3': {
            std::cout << "Czesc wspolna zbioru 1 i 2: ";
            std::shared_ptr<Set<int>> czesc_wspolna = s1.czesc_wspolna(s2);
            czesc_wspolna->print();
            break;
        }
        case '4': {
            std::cout << "Roznica zbioru 1 i 2: ";
            std::shared_ptr<Set<int>> roznica = s1.roznica(s2);
            roznica->print();
            break;
        }
        case '5': {
            std::cout << "Dodawanie elementow zbiorow s1 i s2" << std::endl;
            std::cout << "Elementy dodane.";
            s3.kopiuj(s1, s2);
            s3.sortowanie_babelkowe();
            s3.print();
            break;
        case '6': {
            int wartosc;
            std::cout << "Wpisz jakiej wartosci szukasz w zbiorze s1: ";
            std::cin >> wartosc;
            if (s1.szukaj(wartosc)) {
                std::cout << "Element znajduje sie w zbiorze s1." << std::endl;
            }
            else {
                std::cout << "Element nie znaleziony w zbiorze s1." << std::endl;
            }
            break;
        }
        case '7': {
            int wartosc;
            std::cout << "Wpisz jakiej wartosci szukasz w zbiorze s2: ";
            std::cin >> wartosc;
            if (s2.szukaj(wartosc)) {
                std::cout << "Element znajduje sie w zbiorze s2." << std::endl;
            }
            else {
                std::cout << "Element nie znaleziony w zbiorze s2" << std::endl;
            }
            break;
        }
        case '8':
            std::cout << "Wyjscie z programu." << std::endl;
            return 0;
        default:
            std::cout << "Niepoprawna opcja, prosze sbrobuj jeszcze raz." << std::endl;
        }
        }
    }
    return 0;
}