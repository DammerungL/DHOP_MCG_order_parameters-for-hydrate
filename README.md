# DHOP
a method for hydrate nucleus

The program is referred to paper "Nucleation mechanism of clathrate hydrates of water-soluble guest molecules".
The following is the address of the original document:
https://aip.scitation.org/doi/10.1063/1.4996132

input panding.gro 550methane 3487tip4p_water example. If you need to change the system, you need to change it in DHOP35du.cpp.

step 0: g++ DHOP35du.cpp -o DHOP35du

step1: ./DHOP35du

output DHOP35du.txt (nucleus_size | water_index)

