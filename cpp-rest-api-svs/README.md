# C++ Rest API Sample Service

## Install Conan Packages

```bash
conan remove --locks
conan install . -pr .\profiles\win-vs2019-x64
```

## How to add Bincrafters Conan repo

```bash
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
conan user -p <APIKEY> -r bincrafters <USERNAME>
```
