#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ncurses.h>

// Detect available package managers
std::vector<std::string> managers = {"apt", "dnf", "yum", "pacman"};
std::vector<std::string> availableManagers;

bool is_installed(const std::string& cmd) {
    return (system(("which " + cmd + " > /dev/null 2>&1").c_str()) == 0);
}

void list_packages(const std::string& manager) {
    if (manager == "apt") system("apt list --installed");
    else if (manager == "dnf") system("dnf list installed");
    else if (manager == "yum") system("yum list installed");
    else if (manager == "pacman") system("pacman -Q");
}

void install_package(const std::string& manager, const std::string& pkg) {
    if (manager == "apt") system(("sudo apt install " + pkg).c_str());
    else if (manager == "dnf") system(("sudo dnf install " + pkg).c_str());
    else if (manager == "yum") system(("sudo yum install " + pkg).c_str());
    else if (manager == "pacman") system(("sudo pacman -S " + pkg).c_str());
}

void uninstall_package(const std::string& manager, const std::string& pkg) {
    if (manager == "apt") system(("sudo apt remove " + pkg).c_str());
    else if (manager == "dnf") system(("sudo dnf remove " + pkg).c_str());
    else if (manager == "yum") system(("sudo yum remove " + pkg).c_str());
    else if (manager == "pacman") system(("sudo pacman -R " + pkg).c_str());
}

// Example minimal ncurses audit UI (actual GUI: much more code needed)
void audit_ui() {
    initscr(); // Init ncurses
    raw();
    keypad(stdscr, TRUE);
    noecho();
    printw("Audit mode (demo): use arrows; 'a' to list all; DEL to delete; ENTER to install\n");
    refresh();
    getch(); // Wait for keypress
    endwin();
}

int main(int argc, char* argv[]) {
    // Discover managers
    for (auto& m : managers) if (is_installed(m)) availableManagers.push_back(m);
    if (argc < 3) {
        std::cout << "Usage: unipack <manager> <-list|-install PKG|-uninstall PKG|-audit>" << std::endl;
        return 1;
    }
    std::string manager = argv[21], command = argv[22];
    if (std::find(availableManagers.begin(), availableManagers.end(), manager) == availableManagers.end()) {
        std::cout << manager << " not installed." << std::endl; return 2;
    }
    if (command == "-list") list_packages(manager);
    else if (command == "-install" && argc > 3) install_package(manager, argv[23]);
    else if (command == "-uninstall" && argc > 3) uninstall_package(manager, argv[23]);
    else if (command == "-audit") audit_ui();
    else std::cout << "Unknown command.\n";
    return 0;
}
