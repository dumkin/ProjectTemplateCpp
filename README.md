# Depends

### Install Clang

```sh
deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-5.0 main
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -

sudo apt update
sudo apt install clang-5.0 lldb-5.0 lld-5.0
```

### Install Clang-format

```sh
sudo apt install clang-format-5.0
```

### Install CMake

```sh
sudo apt purge cmake

mkdir ~/temp-cmake-3.9.4
cd ~/temp-cmake-3.9.4

wget https://cmake.org/files/v3.9/cmake-3.9.4.tar.gz
tar -xzvf cmake-3.9.4.tar.gz
rm ./cmake-3.9.4.tar.gz

cd cmake-3.9.4/

sudo ./bootstrap
sudo make
sudo make install

cd ../../
rm -r temp-cmake-3.9.4
```

### Install pip

```sh
sudo apt install python3-pip
```

### Install gdbgui

```sh
sudo pip install gdbgui --upgrade
```
