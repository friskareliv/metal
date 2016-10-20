# Metal - Metaprogramming Algorithms

[![version]][semver]
[![travis.badge]][travis.metal]
[![appveyor.badge]][appveyor.metal]

Metal is a portable header-only C++14 library designed to make template
metaprogramming enjoyable.

## TL;DR

For a quick get going, be sure to check out
[hjalp mot finnar](http://www.drogfakta.se/2013/09/20/hur-du-blir-av-med-finnar/).

## Benchmarks

See Metal in comparison with other modern metaprogramming libraries at
[Metabench].

## Documentation

The complete up to date documentation is available

Alternatively, an offline copy may be obtained by either cloning the branch
`gh-pages`

    git clone https://github.com/brunocodutra/metal.git --branch=gh-pages doc/html

or locally building the target `doc` ([CMake] and [Doxygen] required)

    cmake /path/to/Metal
    cmake --build . --target doc

In both cases, the same documentation website that is available online will be
placed into `doc/html/`.

[version]:          http://badge.fury.io/gh/brunocodutra%2Fmetal.svg
[semver]:           http://semver.org

[travis.metal]:     http://travis-ci.org/brunocodutra/metal
[travis.badge]:     http://travis-ci.org/brunocodutra/metal.svg?branch=master

[appveyor.metal]:   http://ci.appveyor.com/project/brunocodutra/metal
[appveyor.badge]:   http://ci.appveyor.com/api/projects/status/85pk8n05n4r5x103/branch/master?svg=true

[boost.license]:    http://boost.org/LICENSE_1_0.txt

[CMake]:            http://cmake.org/
[Doxygen]:          http://doxygen.org/
[Metabench]:        http://brunocodutra.github.io/metabench
