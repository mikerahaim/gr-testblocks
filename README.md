# gr-testblocks
This repository stores simple versions of gnuradio blocks to show examples of how to create various block types.

To install, follow the steps below:

1-) cd to the gr-testblocks directory
2-) Create a build directory with 'mkdir build' and move into the directory with 'cd build/'
3-) Run cmake with the path to your local gnuradio installation (assuming installed via PyBOMBS):
	'cmake -DCMAKE_INSTALL_PREFIX=<path-to-target> ../'
4-) Run 'make'
5-) Test the build with 'make test' (shouldn't be any failures)
6-) Install with 'make install'
7-) Configure your linker/debugger with 'sudo ldconfig'
8-) Open gnuradio-companion and you should find a module for testblocks.
