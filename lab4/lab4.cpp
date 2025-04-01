#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <cmath>


void zd1();
void zd2();
void zd3();
void zd4();
bool isFirst(int number);

int main()
{
    zd1(); //Aby zadzia³a³o nale¿y odkomentowaæ
    zd2();
    zd3();
    zd4();
}

void zd1() {
    std::vector<int> liczby = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << "Wektor przed zmianami:" << std::endl;
    for (int i : liczby) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    auto view = liczby | std::views::filter([](int i) { return i % 2 != 0; }) | std::views::transform([](int i) { return i * i; });
    std::cout << "Widok po usuwaniu parzystych i podniesieniu do kwadratu:\n";
    for (int x : view) std::cout << x << " ";
    std::cout << "\n";

    liczby.push_back(196);
    liczby.push_back(169);
    liczby.push_back(112);

    std::cout << "Widok po dodaniu nowych liczb:\n";
    for (int x : view) std::cout << x << " ";
    std::cout << "\n";

}

void zd2() {
    std::string zdanie = "Uwielbiam zakresy w C++!!! Sa bardzo uzyteczne i pozwalaja pisac lepszy kod :)";
    auto view = zdanie | std::views::transform([](const char space) { return (space == ' ') ? '-' : space; }) | std::views::take_while([](char space) { return space != '!'; });

    std::cout << "Zmodyfikowane zdanie:\n";
    for (char c : view) std::cout << c;
    std::cout << "\n";
}

void zd3() {
    auto view = std::views::iota(1, 1000) | std::views::filter(isFirst);
    std::cout << "Liczby pierwsze mniejsze od 1000:\n";
    for (int x : view) std::cout << x << " ";
    std::cout << "\n";
}

bool isFirst(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

void zd4() {
    std::vector<std::string> imiona = {
        "anna", "maria", "jan", "piotr", "adam", "ewelina", "karol",
        "anna", "jan", "michal", "katarzyna", "karol", "barbara", "pawel",
        "tomasz", "mateusz", "aleksandra", "krzysztof", "monika", "agnieszka"
    };

    std::cout << "Przed wykonaniu zadania:\n";
    for (const auto& name : imiona) std::cout << name << " ";
    std::cout << "\n";

    std::sort(imiona.begin(), imiona.end());
    auto unique = std::unique(imiona.begin(), imiona.end());
    imiona.erase(unique, imiona.end());

    auto view = imiona | std::views::transform([](std::string s) {s[0] = std::toupper(s[0]);return s;});

    std::cout << "Po wykonaniu zadania:\n";
    for (const auto& name : view) std::cout << name << " ";
    std::cout << "\n";


}