# CMake generated Testfile for 
# Source directory: /home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests
# Build directory: /home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(FunctorSimple.Numbers "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorSimple.Numbers")
add_test(FunctorSimple.CapitalLetters "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorSimple.CapitalLetters")
add_test(FunctorSimple.Word1 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorSimple.Word1")
add_test(FunctorSimple.Word2 "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorSimple.Word2")
add_test(FunctorSimple.RepeatedCharacter "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorSimple.RepeatedCharacter")
add_test(FunctorSimple.LongWord "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorSimple.LongWord")
add_test(FunctorSimple.ExactValue "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorSimple.ExactValue")
add_test(FunctorTiebreaker.SimpleLexicographic "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorTiebreaker.SimpleLexicographic")
add_test(FunctorTiebreaker.ComplexLexicographic "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorTiebreaker.ComplexLexicographic")
add_test(FunctorTiebreaker.NotLexicographic "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorTiebreaker.NotLexicographic")
add_test(FunctorTiebreaker.Equal "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorTiebreaker.Equal")
add_test(FunctorUnknownChars.TreatedAsZero "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorUnknownChars.TreatedAsZero")
add_test(FunctorUnknownChars.EmptyString "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104/hw-nyilkhan/hw5/hw5_tests/functor_tests/functor_test" "--gtest_filter=FunctorUnknownChars.EmptyString")
