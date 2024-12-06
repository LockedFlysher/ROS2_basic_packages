//
// Created by lock on 2024/12/3.
//
#include "lock_utils/SaveParseCSV.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <limits>
#include <algorithm>

namespace {
// Internal helper function to process a chunk of the CSV file
    std::vector<std::vector<double>> processChunk(std::ifstream& file, size_t maxRows = 1000000)
    {
        std::vector<std::vector<double>> chunk;
        std::string line;
        size_t rowCount = 0;

        while (rowCount < maxRows && std::getline(file, line))
        {
            std::vector<double> row;
            std::istringstream ss(line);
            std::string cell;

            while (std::getline(ss, cell, ','))
            {
                try
                {
                    row.push_back(std::stod(cell));
                }
                catch (const std::exception& e)
                {
                    std::cerr << "Error parsing value: " << cell << ". Using 0.0 instead." << std::endl;
                    row.push_back(0.0);
                }
            }

            chunk.push_back(std::move(row));
            ++rowCount;
        }

        return chunk;
    }
} // anonymous namespace

std::vector<std::vector<double>> parseCSV(const std::string& filename)
{
    std::vector<std::vector<double>> data;
    std::ifstream file(filename, std::ios::in | std::ios::binary);

    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return data;
    }

    // Use a larger buffer for reading
    std::vector<char> buffer(1024 * 1024); // 1MB buffer
    file.rdbuf()->pubsetbuf(buffer.data(), buffer.size());

    while (!file.eof())
    {
        auto chunk = processChunk(file);
        data.insert(data.end(), chunk.begin(), chunk.end());
    }

    file.close();
    return data;
}

void saveAsCSV(const std::vector<std::vector<double>>& data, const std::string& filename)
{
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << " for writing" << std::endl;
        return;
    }

    // Use a larger buffer for writing
    std::vector<char> buffer(1024 * 1024); // 1MB buffer
    file.rdbuf()->pubsetbuf(buffer.data(), buffer.size());

    std::string row;
    row.reserve(1024 * 1024); // Pre-allocate 1MB for the row string

    for (const auto& dataRow : data)
    {
        row.clear();
        for (size_t i = 0; i < dataRow.size(); ++i)
        {
            row += std::to_string(dataRow[i]);
            if (i != dataRow.size() - 1)
            {
                row += ',';
            }
        }
        row += '\n';

        file.write(row.c_str(), row.length());
        if (file.fail())
        {
            std::cerr << "Error: Failed to write to file " << filename << std::endl;
            file.close();
            return;
        }
    }

    file.close();
    if (file.fail())
    {
        std::cerr << "Error: Failed to close file " << filename << std::endl;
        return;
    }
    std::cout << "CSV saved successfully at: " << filename << std::endl;
}
