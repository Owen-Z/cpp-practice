# cpp-practice

My own C++ practice project (C++20, CMake, GoogleTest).

## Layout

| Path | What goes there |
|---|---|
| `include/practice/` | Reusable headers |
| `src/` | Implementations for those headers (built into the `practice` library) |
| `apps/` | One `.cpp` per exercise; each file becomes its own executable |
| `tests/` | GoogleTest unit tests (all built into `practice_tests`) |

## Build & run

```bash
cmake --preset gcc-debug          # configure (Debug + ASan/UBSan)
cmake --build --preset gcc-debug  # build
./build/gcc-debug/hello           # run an exercise
ctest --preset gcc-debug          # run unit tests
```

Other presets: `gcc-release`, `clang-debug`, `clang-release`.

New exercise: add `apps/<name>.cpp`, rebuild, run `./build/gcc-debug/<name>`.

## 练习记录

回忆了一下怎么写c++的代码，知道了要用static_cast去做变量类型转换
