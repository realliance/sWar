# Strategic War (sWar)
sWar is a variation on the common War card game.

# Development

## Getting Started

### On Linux

Install the following dependencies:

- `git`

- `cmake`

- `clang` (or [clang-11](https://packages.ubuntu.com/bionic/clang-11))

Clone the repository:

```
git clone git@github.com:realliance/swar.git
```

Run the following commands within the project directory (note that these commands are for ):
```
# Bootstrap CMake Environment
cmake -S . -B build

# Or, if wanting to use Clang (Linux Only)

C=clang CXX=clang++ cmake -S . -B build

# Build Project
cmake --build build
```

## Testing and Documentation

The test suite is located in `tests/` and can be run with `make -C build check`
