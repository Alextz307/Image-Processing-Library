# Image Processing Library

## Overview

This project is a basic Image Processing Library that focuses on handling grayscale images. Grayscale images are represented as 2D arrays of pixels, where each pixel has an intensity value ranging from 0 to 255. The value 0 represents black, 255 represents white, and values in between represent various shades of gray. The library includes several classes to manage image operations and associated geometric entities.

## Features

### Image Class
- **Purpose:** Represents a grayscale image as a 2D array of pixels.
- **Pixel Values:** Range from 0 (black) to 255 (white).
- **Supported Operations:** 
  - **Image Manipulation:** Functions to load, save, and modify images.
  - **Transformation:** Apply operations such as rotation, scaling, and translation.

### Size Class
- **Attributes:** 
  - `width` (unsigned int): The width of the object.
  - `height` (unsigned int): The height of the object.
- **Functions:**
  - **Constructors:** Default and parameterized constructors.
  - **Getters and Setters:** Access and modify width and height.
  - **Comparison Operators:** Overload `==`, `<`, `<=`, `>`, `>=` based on area.

### Point Class
- **Attributes:**
  - `x` (int): X-coordinate of the point.
  - `y` (int): Y-coordinate of the point.
- **Functions:**
  - **Constructors:** Default (initializes to (0,0)) and parameterized constructors.
  - **Getters and Setters:** Access and modify x and y coordinates.

### Rectangle Class
- **Attributes:**
  - `x` (int): X-coordinate of the top-left corner.
  - `y` (int): Y-coordinate of the top-left corner.
  - `width` (unsigned int): Width of the rectangle.
  - `height` (unsigned int): Height of the rectangle.
- **Functions:**
  - **Constructors:** Default and parameterized constructors.
  - **Getters and Setters:** Access and modify rectangle attributes.
  - **Operators:**
    - **Addition/Subtraction with Point:** Translate the rectangle.
    - **Intersection (`&`):** Compute the intersection of two rectangles.
    - **Union (`|`):** Compute the union of two rectangles.

## Implementation Details

- **Memory Management:** Ensure proper handling of dynamic memory through the implementation of the Rule of Three (Destructor, Copy Constructor, and Assignment Operator).
  
- **Error Handling:** Robust error checking to handle scenarios such as out-of-bounds pixel access or invalid dimensions.

## Testing

- **Unit Tests:** Comprehensive tests for each class and operation to ensure correctness, including:
  - Boundary checks for pixel values.
  - Validations for geometric transformations.
  - Memory management tests for potential leaks.
  
- **Sample Use Cases:** Examples demonstrating image loading, transformations, and geometric operations on images.
