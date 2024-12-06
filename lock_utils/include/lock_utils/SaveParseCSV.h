#ifndef SAVE_PARSE_CSV_H
#define SAVE_PARSE_CSV_H

#include <vector>
#include <string>

/**
 * @brief Parse a CSV file containing numeric data
 * @param filename Path to the CSV file to read
 * @return Vector of vectors containing the parsed double values
 */
std::vector<std::vector<double>> parseCSV(const std::string& filename);

/**
 * @brief Save numeric data to a CSV file
 * @param data Vector of vectors containing the double values to save
 * @param filename Path where the CSV file should be saved
 */
void saveAsCSV(const std::vector<std::vector<double>>& data, const std::string& filename);

#endif // SAVE_PARSE_CSV_H
