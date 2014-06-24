var Pchip = require("../").Pchip;

describe("Pchip", function () {
  describe("new", function () {
    it("should reject invalid argument types", function () {
      (function () { new Pchip(); }).should.throw(/two array args/);
      (function () { new Pchip(1, 2); }).should.throw(/two array args/);
    });

    it("should reject arrays with non-numeric elements", function () {
      (function () { new Pchip(["a", "b"], ["c", "d"]); })
        .should.throw(/non-numeric elements/);
    });

    it("should reject arrays with less than two data points", function () {
      (function () { new Pchip([1], [2]); })
        .should.throw(/less than two data points/);
    });

    it("should reject arrays when x array is not increasing", function () {
      (function () { new Pchip([1, 1], [2, 4]); })
        .should.throw(/x array not strictly increasing/);
    });

    it("should reject arrays when x array is not strictly increasing", function () {
      (function () { new Pchip([1, 1], [2, 4]); })
        .should.throw(/x array not strictly increasing/);
    });

    it("should return a PchipInterpolator object on success", function () {
      new Pchip([1, 2], [3, 5]).constructor.name.should.equal("PchipInterpolator");
    });

    it("should work without new", function () {
      Pchip([1, 2], [3, 5]).constructor.name.should.equal("PchipInterpolator");
    });
  });

  describe("evaluate", function () {
    var pchip = new Pchip([1, 2, 3, 4, 5], [1, 7, 11, 14, 28]);

    it("should map input points", function () {
      pchip.evaluate(3).should.equal(11);
    });

    it("should interpolate non-input points", function () {
      pchip.evaluate(4.2).should.almost.equal(15.464470588235296);
    });

    it("should reject evaluation points outside of input domain", function () {
      (function () { pchip.evaluate(5.1); })
        .should.throw(/x out of range/);
    });
  });
});
