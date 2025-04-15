# BridgeNet (DataStracture-Ex2)

BridgeNet is a C++ implementation of an Abstract Data Type (ADT) designed to manage a network of roads and bridges. It efficiently supports operations such as adding bridges, determining the best road for a vehicle of a given height, and printing bridge heights per road. It uses a custom MaxHeap to always keep track of the best road for safe passage.

## 📌 Features

- Initialize a road network with a fixed number of roads.
- Add a bridge with a given height to a specific road.
- Query which road can accommodate the tallest truck at a given moment.
- Print the list of bridge heights on a selected road.

## 📁 Project Structure

```
BridgeNet/
├── ds_ex2/
│   ├── Interaction.cpp / .h        # Handles user input and command processing
│   ├── InvalidInputException.cpp / .h # Custom exception for invalid inputs
│   ├── List.cpp / .h               # Singly linked list implementation
│   ├── Node.cpp / .h               # Node used in the linked list
│   ├── Pair.cpp / .h               # Road-Bridge pairing used in the heap
│   ├── Road.cpp / .h               # Road data model with bridge list
│   ├── RoadNetwork.cpp / .h       # Main logic and interface for road system
│   ├── MaxHeap.cpp / .h           # Custom max-heap implementation for bridge heights
│   └── main.cpp                   # Entry point
├── ds_ex2.vcxproj                 # Visual Studio project file
├── ds_ex2.vcxproj.filters         # Visual Studio filters
├── ds_ex2.sln                     # Visual Studio solution file
└── README.md
```

## 🧠 Technologies Used

- **C++17**
- Custom implementation of:
  - **Linked Lists**
  - **Max Heaps**
  - **ADT Structures**
- Built and tested using **Visual Studio**

## 🔧 Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/BridgeNet.git
   ```

2. Open the solution file `ds_ex2.sln` in Visual Studio.

3. Build the project (`Ctrl + Shift + B` or use the menu).

4. Run the project (`Ctrl + F5`) and follow the input instructions in the console.

## 🗂️ Example Use Case

```
Input:
2     ← Number of roads
3     ← Number of actions
a     ← Initialize
b 2.4 1 ← Add bridge of height 2.4 to road 1
c 2.3   ← Query the best road for a truck of height 2.3
d 1     ← Print all bridge heights on road 1

Output:
1
2.4000
```

## ⚠️ Error Handling

The system handles invalid input using custom exceptions and gracefully informs the user without crashing.

## 📃 License

This project is licensed under the MIT License.
README.md
3 KB
