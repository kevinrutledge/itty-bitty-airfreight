# Itty Bitty Airfreight Cargo Management

## Project Description
This project, titled "Itty Bitty Airfreight (IBA)", is designed to manage cargo loading operations for Boeing 737 and Boeing 767 aircraft. It includes an implementation of an abstract base class 'Cargo', from which two derived classes, 'Boeing737' and 'Boeing767', inherit. Each class represents specific characteristics and load capacities of the respective aircraft types. The program allows for reading cargo data from a file and processing it according to aircraft-specific constraints such as maximum load, ensuring appropriate distribution and weight management.

## Features
- Read cargo data from a file.
- Process cargo data based on aircraft type (Boeing 737 or Boeing 767).
- Check for maximum load constraints.
- Display processed cargo information.

## Installation
1. **Clone the repository**: Clone this repository to your local machine using:

```
git clone https://github.com/kevinrutledge/itty-bitty-airfreight.git
```

2. **Navigate to the project directory**:

```
cd itty-bitty-airfreight
```

## Usage
To use the application, compile the C++ source files and run the generated executable:

```
g++ -o cargo_management src/*.cpp
```

This will compile all the `.cpp` files in the `src` directory and link them into an executable named `cargo_management`. To run the application, use:

```
./cargo_management
```

Follow the on-screen prompts to input cargo data and view the processed information.

## License
This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.

## Author
Kevin Rutledge

## Contact
For any queries or suggestions, feel free to reach out at `kevin.rutledge.89@gmail.com`.

Last Edited: 12/15/2023