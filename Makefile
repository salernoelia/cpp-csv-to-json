CC = g++
CFLAGS = -std=c++11 -arch arm64
TARGET = csv_to_json
SRC = CSVToJsonConverter.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
