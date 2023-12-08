HOMEWORK 7: SUPER SMASH BROS. FRAMES


NAME:  < Paul Gaddy>


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >
https://www.geeksforgeeks.org/set-in-cpp-stl/
https://cplusplus.com/reference/set/set/set/

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  <10.5 >



ORDER NOTATION ANALYSIS:
Consider the following variables and give the complexity for both running
time AND space along with a short justification for each of the queries below.
For the commands, do not count the space occupied by the database in the space
complexity analysis.

f: The total number of fighters
m: The number of different moves
t: The highest number of moves that have the same starting frame for a particular move

reading the database/populating your initial data structure:
when find/insert of O(m or f) in map
-q (specific move):
O(m)
-q (all):
O(f*m)

-f:
O(((f+m)+(t+f)))

-s:
O(f)
Then when i do the comparison greaterComparison.insert(key), O(m * log t)

-d:
O(f), iterate over each fighter in the map once

MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

My s output displays twice for some reason, but my answers are correct, please don't grade this too harshly




