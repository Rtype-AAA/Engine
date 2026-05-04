# Quantum Vortex Engine

Custom C++ game engine built from scratch to power a multiplayer
shoot'em up (R-Type project at Epitech Lille, Dec 2023 – Jan 2024).
Designed for real-time performance with a modular, component-based architecture.

**Solo project** — full engine architecture and implementation.
Testing and documentation handled by one dedicated collaborator.

## Core Features

- Real-time game loop with delta time management (update / render separation)
- Entity-Component system with bitset-based component tracking
- Deferred execution pattern for safe entity/component mutations during update
- Event system — keyboard, mouse (pressed, moved, key states mapping)
- Resource management — textures, fonts, sounds and music (loading & caching)
- Drawable component abstraction (Sprite, Text, Audio)
- World management — multiple worlds with active world switching
- Cross-platform packaging (Debian / Fedora)

## Technical Highlights

- Hybrid ECS architecture — component bitset per entity for fast lookup
- Deferred entity and music updates to avoid invalid state mutations
- Template-based component retrieval (`getComponent<T>()`)
- Built on SFML with a clean abstraction layer on top
- Unit tested (GoogleTest)

## Example

```cpp
// Create a world and add entities
std::unique_ptr<World> myWorld = std::make_unique<World>();
myWorld->setNameWorld("Level1");

// Add entity with components
myWorld->getEntityManager("Player").getEntity("Player1")
    .addComponent<Transform>()
    .setPosition(Vector2<float>(400.0f, 500.0f));

myWorld->getEntityManager("Player").getEntity("Player1")
    .addComponent<Sprite>()
    .setDeferredSprite([&]() {
        // deferred loading for safe resource access
        entity.getComponent<Sprite>().setSprite(gameEngine.getMapTexture(), "ship");
    });

// Register world and run
gameEngine.run(std::move(worldMap), pathRessources, "Level1");
```

## Build & Install

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

## Documentation

### PDF

Here you can see the documentation in PDF format: [R-Type_Engine](docs/R-Type_Engine.pdf)
