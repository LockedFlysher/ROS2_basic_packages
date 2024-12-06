# C++ Filters Library

This library provides a collection of digital filters implemented in C++. It currently includes Low-Pass, Median, and Mean filters.

## Features

- Abstract `Filter` base class for easy extension
- Low-Pass Filter
- Median Filter
- Mean Filter

## Requirements

- C++11 or later
- Standard Template Library (STL)

## Usage

To use these filters in your project, include the `Filters.h` header file in your source code.

```cpp
#include "Filters.h"
```

### Low-Pass Filter

```cpp
LowPassFilter lpf(10, 0.1);  // cutoff frequency: 10 Hz, sampling time: 0.1 seconds
double filtered_value = lpf.filter(input_value);
```

### Median Filter

```cpp
MedianFilter mf(5);  // window size: 5
double filtered_value = mf.filter(input_value);
```

### Mean Filter

```cpp
MeanFilter avf(5);  // window size: 5
double filtered_value = avf.filter(input_value);
```

## Example

```cpp
#include "Filters.h"
#include <iostream>

int main() {
    LowPassFilter lpf(10, 0.1);
    MedianFilter mf(5);
    MeanFilter avf(5);

    std::vector<double> input = {1, 2, 3, 10, 5, 6, 7, 8, 9, 10};

    std::cout << "Original\tLow Pass\tMedian\t\tMean" << std::endl;
    for (double value : input) {
        std::cout << value << "\t\t"
                  << lpf.filter(value) << "\t\t"
                  << mf.filter(value) << "\t\t"
                  << avf.filter(value) << std::endl;
    }

    return 0;
}
```
