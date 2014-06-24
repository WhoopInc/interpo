// C++ bindings for the SLATEC PCHIP functions we need.
//
// Assumes f2c calling conventions. For our purposes, all that matters is that
// arguments are always passed by reference, even simple types, and function
// names are mangled with the addition of an underscore.
//
// See the Fortran source in deps/slatec for documentation. Each function listed
// here is defined in the file of the same name.

extern "C" {
  extern void dpchim_(int &n, const double *x, const double *f, double *d,
                      int &incfd, int &ierr);

  extern void dpchfe_(int &n, const double *x, const double *f, double *d,
                      int &incfd, int &skip, int &ne, double &xe, double &fe,
                      int &ierr);

  extern void xsetf_(int &kontrl);
}
