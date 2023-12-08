/usr/bin/clang -fcolor-diagnostics -fansi-escape-codes -g "/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/roads.cpp" -o "/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/roads"
In file included from /Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/roads.cpp:6:
In file included from /Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/line.h:1:
/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/point.h:8:7: error: redefinition of 'Point'
class Point {
      ^
/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/roads.cpp:5:10: note: '/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/point.h' included multiple times, additional include site here
#include "point.h"
         ^
/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/line.h:1:10: note: '/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/point.h' included multiple times, additional include site here
#include "point.h"
         ^
/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/point.h:8:7: note: unguarded header; consider using #ifdef guards or #pragma once
class Point {
      ^
/Users/paul/Desktop/School/S4/Data Structures/Labs/Lab3/roads.cpp:17:10: warning: reference to stack memory associated with local variable 'roads' returned [-Wreturn-stack-address]
  return roads;
         ^~~~~
1 warning and 1 error generated.

Build finished with error(s).

I ADDED THE IFNDEF and DEFINE STATEMENTS to the point class to remove the declaration error