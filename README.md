# Engine

## Install package(s)

### Debian

- Install the following zip file: [debian.zip](packages/deb-package.zip)

- Unzip the package

- Install the package with the following command:

```bash
cd deb-package
sudo dpkg -i quantumvortex-engine_1.0.0-1_amd64.deb
```

### Fedora 38

- Install the following zip file: [fedora.zip](packages/rpm-package-fedora-38.zip)

- Unzip the package

- Install the package with the following command:

```bash
cd rpm-package-fedora-38
sudo dnf install quantumvortex-engine-fedora38.rpm
```

### Fedora Latest

- Install the following zip file: [fedora.zip](packages/rpm-package-fedora-latest.zip)

- Unzip the package

- Install the package with the following command:

```bash
cd rpm-package-fedora-latest
sudo dnf install quantumvortex-engine-fedora-latest.rpm
```

## Compilation

### Linux

Use the following command to compile the engine:

```bash
cmake -Bbuild
make -Cbuild
```

Use the following command to compile the engine and its tests:

```bash
cmake -Bbuild -DBUILD_TESTS=ON
make -Cbuild
```

Use the following command for create the package (.tgz or .zip) after compile:

```bash
cd build
cpack
```