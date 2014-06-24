extern "C" {
  extern void dpchim_(int &n, const double *x, const double *f, double *d,
                      int &incfd, int &ierr);

  extern void dpchfe_(int &n, const double *x, const double *f, double *d,
                      int &incfd, int &skip, int &ne, double &xe, double &fe,
                      int &ierr);

  extern void xsetf_(int &kontrl);
}
