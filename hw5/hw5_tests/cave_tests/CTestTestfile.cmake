# CMake generated Testfile for 
# Source directory: /home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests
# Build directory: /home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Cave.OneMove "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.OneMove")
add_test(Cave.TwoMoves "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.TwoMoves")
add_test(Cave.OneTripEW "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.OneTripEW")
add_test(Cave.OneTripWE "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.OneTripWE")
add_test(Cave.OneTripNS "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.OneTripNS")
add_test(Cave.SmallLoop "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.SmallLoop")
add_test(Cave.LargeLoop "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.LargeLoop")
add_test(Cave.LoopRetrace "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.LoopRetrace")
add_test(Cave.Branching "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.Branching")
add_test(Cave.RightMovesWrongOrder "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=Cave.RightMovesWrongOrder")
add_test(CaveStress.TenThousandMoves "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=CaveStress.TenThousandMoves")
add_test(CaveStress.RandomMovements "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=CaveStress.RandomMovements")
add_test(CaveStress.RandomCorrectPath "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/cave_tests/cave_test" "--gtest_filter=CaveStress.RandomCorrectPath")
