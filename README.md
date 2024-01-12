# Engine

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