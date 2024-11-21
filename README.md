# **FdF - Wireframe Viewer**

[![42 Badge](https://img.shields.io/badge/Score-125%2F100-brightgreen)](#)

![Interactive Map Preview](https://github.com/yettabaa/FdF/blob/master/assets/FdF.gif)

**FdF** is a 42 School project that visualizes a 3D wireframe map in a 2D space using custom projections. This project includes all mandatory requirements and bonus features, such as Z-axis scaling and gradient colors, delivering a dynamic and visually appealing application.

---

## **Table of Contents**
1. [Overview](#overview)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [Installation](#installation)
5. [Preview](#preview)
6. [Usage](#usage)
7. [Map Parsing](#map-parsing)
8. [Pixels and Memory Representation](#pixels-and-memory-representation)
9. [DDA Algorithm for Line Rendering](#dda-algorithm-for-line-rendering)
10. [Mathematical Concepts: Transformations](#mathematical-concepts:-transformations)
11. [Gradient Colors](#gradient-colors)
12. [Contributing](#contributing)
13. [License](#license)

---

## **1. Overview**
**FdF** is a project aimed at creating a lightweight 3D wireframe renderer. The program reads map files containing height data and renders them in a 2D window using **isometric projection**.

- **Validation Date**: January 31, 2023  
- **Score**: 125/100 (including bonus)  
- **Bonus Features**: 
    1. Extra projection.
    2. Zoom in and out.
    3. Translation.
    4. Rotation.
    5. Z-axis scaling.
    6. Gradient Colors.
    7. Change Colors.

---

## **2. Features**
- Reads and visualizes 3D wireframes from heightmap files.
- Supports dynamic **Z-axis scaling** for emphasizing terrain features.
- Includes **gradient color rendering** for height representation.
- Fully interactive with zoom, pan, and projection adjustments.
- Bonus: Supports additional projections and keyboard controls.

---

## **3. Technologies Used**
- **Language**: C
- **Graphics Library**: MiniLibX
- **Build Tool**: Makefile

---

## **4. Installation**
Clone the repository and compile the project:

```bash
git clone git@github.com:yettabaa/FdF.git
cd FdF
make
```

Run the program with a sample map:

```bash
./fdf test_maps/42.fdf
```

---

## **5. Preview**
### GIFs

1. **Z-Axis Scaling**  
   ![Z-Axis Scaling](https://github.com/yettabaa/FdF/blob/master/assets/FdF-Scale-Z.gif)  
   Adjusting the Z-axis scaling to emphasize height differences.

2. **Zoom in and out**  
   ![Gradient Colors](https://github.com/yettabaa/FdF/blob/master/assets/FdF-Zoom.gif)  
   Apply Scaling to the X and Y axes.

3. **Translation**  
   ![Interactive Controls](https://github.com/yettabaa/FdF/blob/master/assets/FdF-Translation.gif)  
   Apply Translation to the X and Y axes.

4. **Rotation**  
   ![Projection Switching](https://github.com/yettabaa/FdF/blob/master/assets/FdF-Rotation.gif)
If we want to rotate around an axis, we change the angle of the rotation matrix relative to this axis.

---

## **6. Usage**
- **`P`, `H`, `V`**: Extra projection.
- **`Scroll Mouse`**: Zoom in/out.
- **`2` / `8`**: Rotate on the X-axis.
- **`4` / `6`**: Rotate on the Y-axis.
- **`7` / `9`**: Rotate on the Z-axis.
- **`Arrow keys`**: Translation.
- **`+` / `-`**: Adjust Z-axis scaling.
- **`X` / `C`**: Toggle colors.
- **`Right Click Mouse`**: Basic Shape.
- **`Left Click Mouse`**: Move to the clicked point.

---

## **7. Map Parsing**
The map files are parsed in the following way:
- **Each point in the file is separated by a comma**.
- The left of the comma contains the **Z-axis value**, representing the height of the point.
- The right of the comma contains the **color of the point** in **TRGB format** (either in **hexadecimal** format like `#RRGGBB` or in **decimal TRGB format**).
- The position of each point in the map corresponds to its **X** (column) and **Y** (line) position in the grid.

---

## **8. Pixels and Memory Representation**
In the **FdF** project, rendering the map requires manipulation of individual **pixels** on the screen. Each pixel is represented in memory using **4 bytes** (32 bits), with the color encoded in **TRGB format**. This is essential for efficiently displaying the 3D wireframe and ensuring smooth rendering.

### **Pixel Manipulation and Memory Management**

To draw a pixel on the screen, the following function is used:

```c
void my_mlx_pixel_put(t_colect *v, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        dst = v->mlx.adr + (y * v->mlx.line + x * (v->mlx.bit_pxl / 8));
        *(unsigned int *)dst = color;
    }
}
```

In this function:

- **`x`** and **`y`** are the pixel coordinates.
- **`color`** is the pixel color in **TRGB format**.

The **`v->mlx.adr`** points to the first memory address of the image in the window. All image data is stored in a single long array. The function calculates the exact memory location of the pixel by adding an offset based on the pixel's **line** (`y`) and **column** (`x`). This offset is calculated using the **line width** (`v->mlx.line`) and **bits per pixel** (`v->mlx.bit_pxl`). 

The function writes the **color** to the computed memory address, ensuring that the pixel is updated within the **WIDTH** and **HEIGHT** boundaries of the image. This prevents segmentation faults by ensuring that the calculated address is within the valid memory range of the image.

---

## **9. DDA Algorithm for Line Rendering**
The **DDA (Digital Differential Analyzer)** algorithm is the primary method used to render lines between points in the wireframe. It works by incrementally calculating intermediate points along the line path between two endpoints, ensuring smooth and precise line rendering.

Here's a brief explanation of how the DDA algorithm is utilized in this project:
- Given two points, the DDA algorithm computes the pixel positions between them.
- It calculates the change in both **X** and **Y** coordinates, adjusting at each step to maintain a straight line.
- The **pixel colors** and **Z-axis heights** are updated according to the calculated positions.

The DDA algorithm is efficient and ensures that the lines between points are accurately rendered, making it ideal for displaying complex wireframe maps.

👉 [The best tutorial on the DDA algorithm.](https://www.youtube.com/watch?v=W5P8GlaEOSI&t=1010s&ab_channel=AbdulBari)

---
## **10. Mathematical Concepts: Transformations**

### 1. **Scaling**:
Scaling refers to adjusting the size of the map. In **FdF**, it specifically affects the **Z-axis** to emphasize the height differences in the 3D wireframe. The scaling transformation is applied using a scaling factor (`S`), which is multiplied by the height valu
e of each point to either magnify or shrink the map.
- **Formula for scaling**:  

  ``` 
  x' = x * S_x,  y' = y * S_y,  z' = z * S_z 
  ```
  Where `S_x`, `S_y`, and `S_z` are the scaling factors for the respective axes.

Resources: 👉 [https://en.wikipedia.org/wiki/Scaling_(geometry) ](https://en.wikipedia.org/wiki/Scaling_(geometry))

### 2. **Translation**:
Translation is the process of moving the map in 3D space without altering its shape or orientation. This allows the map to be shifted along the **X**, **Y**, and **Z** axes.
- **Formula for translation**:
  ``` 
  x' = x + T_x,  y' = y + T_y,  z' = z + T_z 
  ```
   Where `T_x`, `T_y`, and `T_z` are the translation values for each axis.

Resources: 👉 [https://en.wikipedia.org/wiki/Translation_(geometry)) ](https://en.wikipedia.org/wiki/Translation_(geometry)))
### 3. **Rotation**:
Rotation involves turning the map around one of its axes. For **FdF**, the map can be rotated around the **X**, **Y**, or **Z** axes using the appropriate rotation matrices.


- **Rotation around the X-axis**:
  ``` 
  x' = x,  y' = y * cos(θ) - z * sin(θ),  z' = y * sin(θ) + z * cos(θ) 
  ```
  - Where `θ` is the rotation angle.

- **Rotation around the Y-axis**:
  ``` 
  x' = x * cos(θ) + z * sin(θ),  y' = y,  z' = -x * sin(θ) + z * cos(θ) 
  ```

- **Rotation around the Z-axis**:
  ``` 
  x' = x * cos(θ) - y * sin(θ),  y' = x * sin(θ) + y * cos(θ),  z' = z 
  ```

These transformations are applied to every point in the 3D space before rendering it into the 2D window.

Resources: 👉 [https://en.wikipedia.org/wiki/Rotation_matrix ](https://en.wikipedia.org/wiki/Rotation_matrix)

---

## **11. Gradient Colors**
To achieve smooth color transitions across the rendered wireframe, the program uses a **gradient calculation** technique. This involves:

- **Extracting Individual Color Channels**:  
  Each color is represented in **TRGB format** (Transparency, Red, Green, Blue). The program separates these components for both the start and end colors using bitwise operations.

- **Calculating Color Percentages**:  
  For each pixel along a line, the algorithm determines its position as a percentage between the start and end points of the line. This percentage is used to blend the corresponding color components.

- **Interpolating Color Channels**:  
  The program computes each color channel (**Red**, **Green**, **Blue**, and **Transparency**) for the pixel based on its percentage. The new color is then reconstructed by combining these interpolated components.

This approach ensures visually appealing and smooth transitions, dynamically representing height or other map features. The gradient technique enhances the visual realism of the wireframe rendering.


## **12. Contributing**
Contributions are welcome! If you have suggestions for improving this project, feel free to fork the repository and submit a pull request.

1. **Fork the Repository**
2. **Create a Feature Branch**:
   ```bash
   git checkout -b feature-branch-name
   ```
3. **Commit Changes**:
   ```bash
   git commit -m "Description of changes"
   ```
4. **Push Changes**:
   ```bash
   git push origin feature-branch-name
   ```
5. **Open a Pull Request**

---

## **13. License**
This project is licensed under the [MIT License](LICENSE).  

---

