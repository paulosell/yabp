[![License: GPL v3](https://img.shields.io/badge/license-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![build](https://github.com/paulosell/yabp/actions/workflows/build.yaml/badge.svg)](https://github.com/paulosell/yabp/actions/workflows/build.yaml)
[![tests](https://github.com/paulosell/yabp/actions/workflows/tests.yaml/badge.svg)](https://github.com/paulosell/yabp/actions/workflows/tests.yaml)
[![release](https://github.com/paulosell/yabp/actions/workflows/release.yaml/badge.svg)](https://github.com/paulosell/yabp/actions/workflows/release.yaml)

# Yet Another Base64URL Parser (YABP)

This repository offers a straightforward Base64 URL parser inspired by [RFC 4648](https://www.rfc-editor.org/rfc/rfc4648.html). I developed this project with the aim of making open-source contributions to initiatives associated with the [Dispositivo Autorizador Fiscal (DAF)](https://www.sef.sc.gov.br/servicos/servico/159). Consequently, the project is welcoming improvements and contributions from the community.

# Requisites

- [Conan](https://conan.io/) software package manager
- [CMake](https://cmake.org/)

# Building Instructions

- **Clone the repository**:
```shell
git clone https://github.com/paulosell/yabp.git
cd yabp
```

- **Install conan dependencies**:
```shell
make dependencies
```

- **Build library**:
```shell
make build
```

- **Build and run example**:
```shell
make run_example
```

- **Build and run tests**:
```shell
make run_tests
```

- **Build and install library**:
```shell
make install INSTALL_PREFIX=<install_path>
```

## Contributions
Contributions to this repository are welcome! If you have improvements, additional implementations, or bug fixes, feel free to submit a pull request. Please follow the contribution guidelines outlined in the [CONTRIBUTING.md](CONTRIBUTING.md) file.

## License
This repository is licensed under the [GNU v3.0](LICENSE)

----
Happy  coding!



