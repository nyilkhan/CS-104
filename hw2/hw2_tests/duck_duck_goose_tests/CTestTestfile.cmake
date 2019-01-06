# CMake generated Testfile for 
# Source directory: /home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests
# Build directory: /home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(DDGRuntime.DDGRound "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_runtime" "--gtest_filter=DDGRuntime.DDGRound")
add_test(DDGRoundBasic.TwoPlayers "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGRoundBasic.TwoPlayers")
add_test(DDGBasic.FivePlayers "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGBasic.FivePlayers")
add_test(DDGRound.TwoPlayers "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGRound.TwoPlayers")
add_test(DDGRound.FivePlayers "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGRound.FivePlayers")
add_test(DDGRound.GooseSelectionProbability "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGRound.GooseSelectionProbability")
add_test(DDGRound.ChaseWinningProbability "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGRound.ChaseWinningProbability")
add_test(DDGRound.RandomStressTest "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGRound.RandomStressTest")
add_test(DDGProgram.TwoPlayers "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGProgram.TwoPlayers")
add_test(DDGProgram.TwentyPlayers "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGProgram.TwentyPlayers")
add_test(DDGProgram.TwoHundredPlayers "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/duck_duck_goose_tests/duck_duck_goose_test" "--gtest_filter=DDGProgram.TwoHundredPlayers")
