# DHOP
a method for hydrate nucleus

The program is referred to paper "Nucleation mechanism of clathrate hydrates of water-soluble guest molecules".
The following is the address of the original document:
https://aip.scitation.org/doi/10.1063/1.4996132

DHOP35du.cpp is the main program. liantong.pl is used to find the largest hydrate nucleus. these programs are suitable for calculating all-atomic water molecules rather than MW water. if you want to calculate mw water system, you should do some modification.

input panding.gro 550methane 3487tip4p_water example. If you need to change the system, you need to change it in DHOP35du.cpp.

step 0: g++ DHOP35du.cpp -o DHOP35du

step1: ./DHOP35du

output DHOP35du.txt (nucleus_size | water_index)

If you use the DHOP program, please cite the following refences: Unraveling nucleation pathway in methane clathrate formation
