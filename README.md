# interpo

<a href="https://travis-ci.org/WhoopInc/interpo">
  <img src="https://travis-ci.org/WhoopInc/interpo.svg?branch=master"
    alt="Build status" align="right">
</a>

Piecewise cubic hermite spline interpolating polynomials (pchips) for [Node.js].

## Usage

```js
var interpo = require("interpo");

var pchip = new interpo.Pchip(
  [1, 2,  3,  4,  5],
  [1, 7, 11, 14, 28]);

pchip.evaluate(3);   // 11
pchip.evaluate(4.2); // 15.464470588
```

## Details

Interpolates known data points with a monotonic cubic spline.

See [scipy's PchipInterpolator][scipy-pchip] for mathematical details. Note that
interpo does *not* use scipy's algorithm—you may observe slight differences
between scipy's interpolants and ours. We instead link against the [SLATEC
PCHIP][pchdoc] library.

### API

##### `new interpo.Pchip(x, f)`

Creates a new `PchipInterpolator` approximating some function *f(x)* defined
by the given data points.

* `x` *numeric array*  
 an array of strictly increasing *x* values for the known data points

* `f` *numeric array*  
 an array of *f(x)* values for the known data points

##### `PchipInterpolator#evaluate(x)`

* `x` *numeric*  
 an *x* value at which to evaluate the interpolant

## Installation

```
npm install interpo
```

interpo links against an ancient Fortran mathematical library, [SLATEC]. You'll
need GNU Fortran installed to compile this module.

Other Fortran compilers are not supported at this time. PRs welcome!

### GNU Fortran

#### Debian/Ubuntu

Just install the `gfortran` package and you're good to go:

```
sudo apt-get install gfortran
```

#### OS X

You'll need to get a version of `gfortran` that matches the version of your
`gcc`. The easiest way to do this is to use [Homebrew] to replace your entire
GCC stack:

```
brew install gcc
brew link --force gcc
```

## Changelog

### v1.0.1

*July 1, 2017.* Support for Node v0.12, v4, v5, v6, v7, and v8.

### v1.0.0

*June 24, 2017.* First release.

[homebrew]: http://brew.sh
[node.js]: http://nodejs.org
[pchdoc]: http://www.netlib.org/slatec/pchip/pchdoc.f
[scipy-pchip]: http://docs.scipy.org/doc/scipy-dev/reference/generated/scipy.interpolate.PchipInterpolator.html
[slatec]: http://www.netlib.org/slatec/
