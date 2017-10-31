# Install Clang
deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-5.0 main
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -

sudo apt update
sudo apt install clang-5.0 lldb-5.0 lld-5.0

# Install Clang-format
sudo apt install clang-format-5.0

# Install CMake
sudo apt purge cmake

mkdir ~/temp
cd ~/temp
wget https://cmake.org/files/v3.9/cmake-3.9.4.tar.gz
tar -xzvf cmake-3.9.4.tar.gz
cd cmake-3.9.4/

sudo ./bootstrap
sudo make
sudo make install

# Install gdbgui
sudo pip install gdbgui --upgrade