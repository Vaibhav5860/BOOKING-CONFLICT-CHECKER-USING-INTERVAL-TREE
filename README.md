# Room Booking Conflict System

This project is a C++ application for managing room bookings and detecting booking conflicts. It provides a simple interface to add bookings and checks for overlapping reservations.

## Features

- Add new room bookings
- Detect and report booking conflicts
- Simple user interface

## Getting Started

### Prerequisites

- C++17 or later
- [nlohmann/json](https://github.com/nlohmann/json) library 

### Build Instructions

1. Clone the repository:
    ```sh
    git clone https://github.com/Vaibhav5860/BOOKING-CONFLICT-CHECKER-USING-INTERVAL-TREE
    cd booking_conflict_cpp
    ```

2. Compile the project:
    ```sh
    g++ src/server.cpp -o server.exe -Iinclude -lws2_32
    ```

3. Run the application:
    ```sh
    ./server.exe 
    ```

### Usage

Follow the user interface to add bookings and check for conflicts.

## Project Structure

```
booking_conflict_cpp/
├── include/         # Header files (e.g., json.hpp)
├── src/             # Source files (main.cpp)
├── index.html       # Optional web interface
├── README.md        # Project documentation
└── LICENSE          # License information
```

## License

This project is licensed under the MIT License.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

##

