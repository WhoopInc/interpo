{
  "targets": [
    {
      "target_name": "interpo",
      "link_settings": {
        "libraries": ["-lgfortran"]
      },
      "include_dirs" : [
        "<!(node -e \"require('nan')\")",
        "deps/slatec"
      ],
      "sources": [
        "src/interpo.cc",
        "src/pchip_interpolator.h",
        "src/pchip_interpolator.cc"
      ],
      "dependencies": [
        "deps/slatec/slatec.gyp:slatec"
      ]
    }
  ]
}
