Unipack
Unipack is a unified Linux package manager CLI app and nano-like terminal utility written in C++. Seamlessly manage installations and audits across all detected package managers (apt, dnf, yum, pacman) from a single tool.

Features
Detects installed Linux package managers automatically

Unified interface for listing, installing, and uninstalling packages

Audit mode: launches an ncurses, nano-inspired GUI to view and manage packages

Confirmation dialogs for critical actions (install/delete)

Simple installer script for easy setup

Installation
Automatic (recommended)
text
curl -sSL https://github.com/<yourusername>/unipack/raw/main/install.sh | bash
This script will:

Install build dependencies and ncurses

Clone the repository

Build and install Unipack to /usr/local/bin/

Manual
text
git clone https://github.com/<yourusername>/unipack.git
cd unipack
sudo apt-get install build-essential libncurses-dev
g++ -o unipack unipack.cpp -lncurses
sudo cp unipack /usr/local/bin/
Adjust the package installation command for your distribution if not on Debian/Ubuntu.

Usage
text
unipack <manager> <command> [package_name]
Examples:

unipack apt -list       List installed packages using apt

unipack dnf -install htop   Install htop using dnf

unipack pacman -uninstall nano   Uninstall nano using pacman

unipack yum -audit    Launches audit UI for yum

Audit Mode
Arrow keys to navigate package lists

Press ‘a’ to list all packages

Press Del to delete a package (confirmation dialog shown)

Press Enter on uninstalled packages to install (confirmation dialog shown)

Confirmation dialogs display in a blue UI:
“Do you want to install/delete? Yes / No”

Contribution
Fork this repository

Submit pull requests for bug fixes or new features

Open issues for feature requests or bug reports
