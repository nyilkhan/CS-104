# CMake generated Testfile for 
# Source directory: /home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests
# Build directory: /home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Fatalist.OneStudent "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.OneStudent")
add_test(Fatalist.AllEqual "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.AllEqual")
add_test(Fatalist.Higher170Grade "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.Higher170Grade")
add_test(Fatalist.Higher104Grade "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.Higher104Grade")
add_test(Fatalist.BothGradesHigher "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.BothGradesHigher")
add_test(Fatalist.NonConformantData "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.NonConformantData")
add_test(Fatalist.LargerConformantGroup "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.LargerConformantGroup")
add_test(Fatalist.LargerNonConformantGroup "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.LargerNonConformantGroup")
add_test(Fatalist.VeryNonConformantGroup "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=Fatalist.VeryNonConformantGroup")
add_test(FatalistStress.ConformantGroup "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=FatalistStress.ConformantGroup")
add_test(FatalistStress.NonConformantGroup "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_test" "--gtest_filter=FatalistStress.NonConformantGroup")
add_test(FatalistRuntime.FatalistHypothesis "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/fatalist_tests/fatalist_runtime_test" "--gtest_filter=FatalistRuntime.FatalistHypothesis")
