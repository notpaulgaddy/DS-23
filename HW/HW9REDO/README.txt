HOMEWORK 9: MINIBLAST


NAME:  < Paul Gaddy >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >
http://www.partow.net/programming/hashfunctions/
https://cplusplus.com/reference/string/string/c_str/
https://stackoverflow.com/questions/20037963/rehashing-a-table
https://www.programiz.com/cpp-programming/library-function/cmath/pow
https://dev.to/muiz6/string-hashing-in-c-1np3

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 12 >


HASH FUNCTION DESCRIPTION

I used the hash function from http://www.partow.net/programming/hashfunctions/
Then made a hash num with the key to do quad probing to store that key then use it later
 I use their code to generate a hash number 


HASH TABLE IMPLEMENTATION

My hash table was pretty simple, used vector of kmer objs then did quad probing to find the corresponding index


ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)

L = length of the genome sequence
q - query length
p - number of different locations where key is found
k - key size (k-mer size)

How much memory will the hash table data structure require (order notation for memory use)?

O(k*L)

What is the order notation for performance (running time) of each of
the commands? What about for the hash table's insert, find, and resize?

occupancy is O(1)
genome is O(1)
table_size is O(1)
kmer is O(L*k*p)
query is O(p*(q-k))
quit is O(1)

EXTRA CREDIT
Add a new command to implement the database using one of the other
 data structures that we have covered so far in the course: 
vectors, lists, arrays etc. 

Compare the performance your alternative method to the homework method
by making a table of run times for each of the genomes and query 
sets provided with the homework  and compare the times to build
the index and the times to process the queries. 
Document any new commands you have added in your README file.

Not doing this

MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


