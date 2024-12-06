# CSV Processor

## Overview

CSV Processor is a high-performance C++ library designed for efficient reading and writing of CSV (Comma-Separated Values) files. It's particularly optimized for handling large datasets, making it suitable for big data processing tasks.

## Features

- **High Performance**: Utilizes optimized I/O operations and memory management for fast processing.
- **Large File Support**: Capable of handling very large CSV files through chunk-based processing.
- **Flexible**: Maintains a simple interface while providing robust functionality.
- **Error Handling**: Includes comprehensive error checking and reporting.

## Requirements

- C++11 compatible compiler
- Standard C++ libraries

## Installation

This is a header-only library. Simply include the header file in your project:

```cpp
#include "csv_processor.hpp"
```

## Usage

### Reading a CSV File

```cpp
std::string filename = "input.csv";
auto data = parseCSV(filename);
```

### Writing a CSV File

```cpp
std::vector<std::vector<double>> data = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
std::string filename = "output.csv";
saveAsCSV(data, filename);
```

## API Reference

### `std::vector<std::vector<double>> parseCSV(const std::string& filename)`

Reads a CSV file and returns its contents as a vector of vectors of doubles.

- **Parameters**:
- `filename`: The path to the CSV file to be read.
- **Returns**: A 2D vector containing the CSV data.

### `void saveAsCSV(const std::vector<std::vector<double>>& data, const std::string& filename)`

Writes a 2D vector of doubles to a CSV file.

- **Parameters**:
- `data`: The 2D vector containing the data to be written.
- `filename`: The path where the CSV file will be saved.

## Performance Considerations

- The library uses a 1MB buffer for both reading and writing operations to optimize I/O performance.
- Large files are processed in chunks to manage memory usage effectively.
- For extremely large files (tens of GBs or larger), consider using a database or specialized big data tools.

## Error Handling

The library includes error handling for common issues such as:
- File open/close errors
- Parse errors for invalid number formats
- Write failures

Errors are reported to `std::cerr`.