{
  "targets": [
    {
      "target_name": "slatec",
      "type": "static_library",
      "sources": [
        "dchfev.f",
        "dpchfe.f",
        "dpchim.f",
        "dpchst.f",
        "fdump.f",
        "i1mach.f",
        "j4save.f",
        "xercnt.f",
        "xerhlt.f",
        "xermsg.f",
        "xerprn.f",
        "xersve.f",
        "xgetua.f",
        "xsetf.f"
      ],
      "rules": [
        {
          "rule_name": "build_fortran",
          "extension": "f",
          "action": ["gfortran", "-fPIC", "-c", "<(RULE_INPUT_PATH)", "-o", "<(INTERMEDIATE_DIR)/<(RULE_INPUT_ROOT).o"],
          "outputs": ["<(INTERMEDIATE_DIR)/<(RULE_INPUT_ROOT).o"],
          "process_outputs_as_sources": 1
        }
      ]
    }
  ]
}
