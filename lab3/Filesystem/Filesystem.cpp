#include <filesystem>
#include <iostream>
#include <string>

void zd1();
void zd2();
void zd3();
void zd4();

int main() {
    //zd1(); //Aby zadzia³a³o nale¿y odkomentowaæ
    //zd2();
    //zd3();
    //zd4();
}

void zd1() {
    std::filesystem::path s{"zd1.txt" };
    if (std::filesystem::exists(s)) {
        if (std::filesystem::is_regular_file(s)) {
            std::cout << "Jest to plik" << std::endl;
            double x = std::filesystem::file_size(s);
            std::cout << "Rozmiar pliku: " << x << std::endl;
        }
        else if (std::filesystem::is_directory(s)) {
            std::cout << "Jest to katalog" << std::endl;
            for (const auto& entry : std::filesystem::directory_iterator(s)) {
                std::cout << entry.path() << std::endl;
            }
        }
        else{std::cout << "Nie jest to ani plik ani katalog" << std::endl;}
    }
    else {
        std::cout << "Sciezka nie istnieje" << std::endl;
    }

    std::filesystem::path d{ "x64" };
    if (std::filesystem::exists(d)) {   
        if (std::filesystem::is_regular_file(d)) {
            std::cout << "Jest to plik" << std::endl;
            auto x = std::filesystem::file_size(d);
            std::cout << "Rozmiar pliku: " << x << std::endl;
        }
        else if (std::filesystem::is_directory(d)) {
            std::cout << "Jest to katalog" << std::endl;
            for (const auto& entry : std::filesystem::directory_iterator(d)) {
                std::cout << entry.path() << std::endl;
            }
        }
        else { std::cout << "Nie jest to ani plik ani katalog" << std::endl; }
    }
    else {
        std::cout << "Sciezka nie istnieje" << std::endl;
    }
}

void zd2() {
    std::filesystem::create_directories("Bartosz/Matyjaszewski/Piotrkow_Trybunalski");
    std::cout << "Stworzono sciezke" << std::endl;
    std::filesystem::copy("Bartosz/Matyjaszewski", "kopia_Matyjaszewski", std::filesystem::copy_options::recursive);
    std::cout << "Stworzono kopie" << std::endl;
    std::filesystem::remove_all("kopia_Matyjaszewski");
    std::cout << "Usunieto kopie" << std::endl;
}

void zd3() {
    std::filesystem::remove_all("symlink_do_zd3.txt");
    std::filesystem::remove_all("hardlink_do_zd3.txt");
    std::filesystem::create_symlink("zd3.txt", "symlink_do_zd3.txt");
    std::cout << "Stworzono symlink" << std::endl;
    std::filesystem::create_hard_link("zd3.txt", "hardlink_do_zd3.txt");
    std::cout << "Stworzono hardlink" << std::endl;

    std::cout << "Plik na ktory wskazuje symlink: " << std::filesystem::read_symlink("symlink_do_zd3.txt") << std::endl;
}

void zd4() {
    std::filesystem::path f{ "Bartosz" };
    std::cout << "Zawartosc katalogu Bartosz:" << std::endl;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(f))
    {
        std::cout << entry.path() << "\n";
    }
    std::filesystem::path p{ "x64" };
    std::cout << "Zawartosc katalogu x64:" << std::endl;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(p))
    {
        std::cout << entry.path() << "\n";
    }

    std::cout << "Absolutna sciezka:" << std::filesystem::absolute(p) << std::endl;
    auto a = std::filesystem::absolute(p).parent_path();
    std::cout << "Sciezka nadrzedna: " << std::filesystem::relative(a, p) << std::endl;
}