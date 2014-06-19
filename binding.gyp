{
  "targets": [
    {
      "target_name": "interpo",
      "link_settings": {
        "libraries": ["-lgfortran"]
      },
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "sources": [
        "src/interpo.cc",
        "src/pchip_interpolator.h",
        "src/pchip_interpolator.cc"
      ],
      "dependencies": [
        "slatec"
      ]
    },
    {
      "target_name": "slatec",
      "type": "static_library",
      "sources": [
        "src/slatec/dchfev.f",
        "src/slatec/dpchfe.f",
        "src/slatec/dpchim.f",
        "src/slatec/dpchst.f",
        "src/slatec/fdump.f",
        "src/slatec/i1mach.f",
        "src/slatec/j4save.f",
        "src/slatec/xercnt.f",
        "src/slatec/xerhlt.f",
        "src/slatec/xermsg.f",
        "src/slatec/xerprn.f",
        "src/slatec/xersve.f",
        "src/slatec/xgetua.f",
        "src/slatec/xsetf.f"
      ],
      "rules": [
        {
          "rule_name": "build_fortran",
          "extension": "f",
          "action": ["gfortran", "-c", "<(RULE_INPUT_PATH)", "-o", "<(INTERMEDIATE_DIR)/<(RULE_INPUT_ROOT).o"],
          "outputs": ["<(INTERMEDIATE_DIR)/<(RULE_INPUT_ROOT).o"],
          "process_outputs_as_sources": 1
        }
      ]
    }
  ]
}
