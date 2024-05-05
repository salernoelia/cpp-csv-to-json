#ifndef CSVTOJSONCONVERTER_HPP
#define CSVTOJSONCONVERTER_HPP

#include <string>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "include/csv.hpp" // CSV parsing library
#include "include/json.hpp" // JSON library

using namespace std;
using json = nlohmann::json;

class CSVToJsonConverter {
private:
    string csvFilePath;

public:
    explicit CSVToJsonConverter(const string& filePath) : csvFilePath(filePath) {}

    json convertToJSON() {
        // Open CSV file
        ifstream file(csvFilePath);
        if (!file.is_open()) {
            cerr << "Error: Unable to open CSV file " << csvFilePath << endl;
            exit(1);
        }

        // Parse CSV content
        csv::CSVReader csvReader(csvFilePath);
        auto headerNames = csvReader.get_col_names();

        // Convert CSV records to JSON
        json jsonArray;
        for (const auto& row : csvReader) {
            json jsonObject;
            for (size_t i = 0; i < row.size(); ++i) {
                jsonObject[headerNames[i]] = row[i].get<string>();
            }
            jsonArray.push_back(jsonObject);
        }

        return jsonArray;
    }

    void saveJSONToFile(const json& jsonArray, const string& outputPath) {
        ofstream outputFile(outputPath);
        if (!outputFile.is_open()) {
            cerr << "Error: Unable to open output file " << outputPath << endl;
            exit(1);
        }
        outputFile << jsonArray.dump(4); // Indent JSON with 4 spaces
        outputFile.close();
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <CSVFilePath>" << endl;
        return 1;
    }

    string csvFilePath = argv[1];
    CSVToJsonConverter converter(csvFilePath);

    // Convert CSV to JSON
    json jsonArray = converter.convertToJSON();

    // Save JSON to file
    string outputPath = "output.json"; // Default output filename
    converter.saveJSONToFile(jsonArray, outputPath);
    cout << "JSON file saved successfully: " << outputPath << endl;

    return 0;
}

#endif // CSVTOJSONCONVERTER_HPP