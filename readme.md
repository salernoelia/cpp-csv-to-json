## CSV to JSON converter

Simple c++ based CSV to JSON converter, stable enough for very big CSV files.

It uses the [this CSV Parser library](https://github.com/vincentlaucsb/csv-parser?tab=readme-ov-file#c-version) and [this JSON library](https://github.com/nlohmann/json)

To build use:

```bash
make
```

## Usage

```bash
./csv_to_json customers-100.csv
// ouputs a customers-100.json
```
