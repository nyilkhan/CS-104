# CMake generated Testfile for 
# Source directory: /home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests
# Build directory: /home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MSortTest.SortEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortEmpty")
add_test(MSortTest.SortSingleElement "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortSingleElement")
add_test(MSortTest.SortTwoElements_InOrder "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortTwoElements_InOrder")
add_test(MSortTest.SortTwoElements_OutOfOrder "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortTwoElements_OutOfOrder")
add_test(MSortTest.SortThreeElements_10_20_30 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortThreeElements_10_20_30")
add_test(MSortTest.SortThreeElements_10_30_20 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortThreeElements_10_30_20")
add_test(MSortTest.SortThreeElements_20_10_30 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortThreeElements_20_10_30")
add_test(MSortTest.SortThreeElements_20_30_10 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortThreeElements_20_30_10")
add_test(MSortTest.SortThreeElements_30_10_20 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortThreeElements_30_10_20")
add_test(MSortTest.SortThreeElements_30_20_10 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortThreeElements_30_20_10")
add_test(MSortTest.SortThreeElements_Greater "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortThreeElements_Greater")
add_test(MSortTest.SortStrings "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortStrings")
add_test(MSortTest.SortPairs "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.SortPairs")
add_test(MSortTest.Split_k_20 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.Split_k_20")
add_test(MSortTest.Split_k_50 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.Split_k_50")
add_test(MSortTest.Split_k_100 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.Split_k_100")
add_test(MSortTest.Split_k_200 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.Split_k_200")
add_test(MSortTest.Stress10Elements_Less "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.Stress10Elements_Less")
add_test(MSortTest.Stress100Elements_Less "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.Stress100Elements_Less")
add_test(MSortTest.Stress1000Elements_Less "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.Stress1000Elements_Less")
add_test(MSortTest.Stress10000Elements_Less "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_test" "--gtest_filter=MSortTest.Stress10000Elements_Less")
add_test(MergeSortRuntime.KEqual2 "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_runtime_test" "--gtest_filter=MergeSortRuntime.KEqual2")
add_test(MergeSortRuntime.KEqualN "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/msort_tests/msort_runtime_test" "--gtest_filter=MergeSortRuntime.KEqualN")
