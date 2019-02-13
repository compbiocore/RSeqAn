if(.Platform$OS.type != "windows") {
testthat::test_that("charstring wrapper",{
  sequence <- "ACTG"
  testthat::expect_equal(containment_test(sequence), "ACTG")
})
}