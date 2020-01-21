#CubeDiff

cube_diff is a C++ program that produce a [.cube file](http://paulbourke.net/dataformats/cube/), taking the difference between two .cube files. The program was elaborated for reading .cube files produced from the [CRYSTAL code](http://www.crystal.unito.it/), in which the second comment of the .cube has the cell parameters (a, b, c, alpha, beta, gamma).

##Compiling

Use a C++ capable compiler:

```console
$ g++ readCube.cpp main.cpp -o cube_diff
```

##Usage

You need two cube files (i.e. file1.cube and file2.cube). Execute as follows:

```console
$ ./cube_diff 
Enter name of first cube file
file1.cube
Enter name of second cube file
file2.cube
$
```
The program will produce a difference.cube file, which has the same header data as file1.cube (grid, cell and atoms information). The volumetric data will be the difference between the data from file1.cube and file2.cube as: file1.cube-file2.cube.

##Observations

Take in count the following:

* For now (and maybe this will not change) you can only use compatible grid cube files.
* The order is important, as substraction is non-conmutative.
* For now, the program will append the difference of volumetric data to difference.cube if this file already exists. Erase or change its name in if you don't want this.
* Because of the last point, you can write/customize a difference.cube file before execution, and the program will append the results to this.
* This is academic code, made for solving a problem and practice C++ programming. It might change in acordace to the problem or the practice necesities if the author.  
