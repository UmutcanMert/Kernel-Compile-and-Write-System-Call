#!/usr/bin/bash

# UBUNTU-DEBIAN deploy

# This causes the script to exit if an error occurs
set -eE -o functrace

# Compile the kernel
make -j4

# Compile and install modules
make -j4 modules_install

# Kernelin /boot ve grub menuye yuklenmesi
make install

