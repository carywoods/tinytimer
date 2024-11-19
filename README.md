# Tiny Timer

Tiny Timer is a simple utility for logging timestamps periodically to help monitor how long a device remains powered on. This tool is particularly useful for testing the battery life of used laptops.

## Features
- Logs the current timestamp every 5 minutes.
- Log file name is generated based on the hostname of the machine.
- Designed to run in a CLI environment.

## Requirements
- C++11 or later.
- g++ compiler or any C++ compiler supporting C++11.

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/carywoods/tinytimer.git
   ```
2. Navigate to the project directory:
   ```sh
   cd tinytimer
   ```
3. Compile the code:
   ```sh
   g++ tinytimer.cpp -o tinytimer -std=c++11
   ```

## Usage
Run the utility from the command line:
```sh
./tinytimer &
```

The utility will create a log file named `<hostname>_tinytimer.log` and append a timestamp every 5 minutes.

## License
This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details.

## Contributing
Feel free to open issues and submit pull requests for improvements and features.

## Author
Cary Woods

## Version .1 