#!/bin/bash
set -e
# Requirements (Debian-based example)
sudo apt-get update
sudo apt-get install -y build-essential libncurses-dev git
# Clone and build
git clone https://github.com/<yourusername>/unipack.git
cd unipack
g++ -o unipack unipack.cpp -lncurses
sudo cp unipack /usr/local/bin/
echo "Unipack installed! Run 'unipack' from the command line."
