# CMake generated Testfile for 
# Source directory: /home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests
# Build directory: /home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(SelSortRuntime.FindMin "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_runtime" "--gtest_filter=SelSortRuntime.FindMin")
add_test(SelSortRuntime.SelectionSort "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_runtime" "--gtest_filter=SelSortRuntime.SelectionSort")
add_test(FindMin.01_NullList "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.01_NullList")
add_test(FindMin.02_OneElement "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.02_OneElement")
add_test(FindMin.03_ThreeElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.03_ThreeElements")
add_test(FindMin.04_Uniform "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.04_Uniform")
add_test(FindMin.05_UniformLarge "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.05_UniformLarge")
add_test(FindMin.06_AlternatingElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.06_AlternatingElements")
add_test(FindMin.07_Descending "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.07_Descending")
add_test(FindMin.08_Ascending "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.08_Ascending")
add_test(FindMin.09_ExtremeValues "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=FindMin.09_ExtremeValues")
add_test(SelectionSort.01_NullList "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelectionSort.01_NullList")
add_test(SelectionSort.02_TwoElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelectionSort.02_TwoElements")
add_test(SelectionSort.03_Ascending "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelectionSort.03_Ascending")
add_test(SelectionSort.04_Descending "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelectionSort.04_Descending")
add_test(SelectionSort.05_Uniform "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelectionSort.05_Uniform")
add_test(SelectionSort.06_Repeating "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelectionSort.06_Repeating")
add_test(SelSortBasic.OneElementFindMin "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelSortBasic.OneElementFindMin")
add_test(SelSortBasic.ThreeElementFindMin "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelSortBasic.ThreeElementFindMin")
add_test(SelSortBasic.TenElementFindMin "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelSortBasic.TenElementFindMin")
add_test(SelSortBasic.ThreeElementSort "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelSortBasic.ThreeElementSort")
add_test(SelSortBasic.TenElementSort "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw2/hw2_tests/selection_sort_tests/selection_sort_test" "--gtest_filter=SelSortBasic.TenElementSort")
