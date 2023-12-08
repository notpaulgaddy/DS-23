HOMEWORK 4: TOOL RENTAL LISTS


NAME:  < Paul Gaddy >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >
https://cplusplus.com/reference/cctype/isdigit/
https://www.tutorialkart.com/cpp/cpp-string-equals/
https://cplusplus.com/doc/tutorial/files/
https://www.geeksforgeeks.org/arrow-operator-in-c-c-with-examples/

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 20 >



ORDER NOTATION:
Use these variables to analyze each phase of computation.  Briefly
justify your answer for each part.


i = # of different inventory items
c = # of different customers
p = # of pending customers
q = max quantity of a particular tool owned by the store
r = max # of tools rented or requested by a customer at one time
p = total # of pending tool rentals
e = # of rental or return events


Load inventory file: Load Invenotry file : O(i) depends on teh amount of items displayed in the file.

Rental event: O(i) since we're using a linked list, and we're only adding a node to the front or end of the list with P,E,I,C,R and Q.

Return event - no pending customer(s): O(1) since the return function only needs to find and update the item in the inventory.

Return event - with pending customer(s): O(n) where n is the amount of customers in the waiting list(P), but it'd be O(1) if it was the first item in the linked list

Entire program: The order notation of the entire program would be O(n) in the worst case due to all the linked list implementation, and these linked lists all have lengths higher than 1, which in that case, it'd be O(1). O( i+e+i^2 + p + c * p + I^2 + c^2)
The program has has many linked list that are populated in random order. They have to be sorted after populating the list and then looped over to output.


MISC. COMMENTS TO GRADER:
(optional, please be concise!)
Most of the outputs are showing up somewhat correctly in output but displaying weird in the file output

New test case for customer
C3662 rent 0915 2 T2934 Elmer_Friesen
C3231 rent 0930 3 T4892 Elaina_Keplinger
C4456 rent 0936 1 T7229 Kathrin_Schreier
C1809 rent 0951 5 T4671 Walker_Hayden
C5423 rent 0972 2 T3349 Goldie_Mcclain
C7551 rent 0998 1 T9067 Tawanda_Hertzog
C9369 rent 1006 3 T2837 Ayanna_Willbanks
C4011 rent 1032 2 T4203 Jolie_Jacoby
C4822 rent 1067 1 T8781 Lashawnda_Loftin
C2567 rent 1090 4 T2127 Rufus_Tobler
C8564 rent 1102 2 T2065 Gerardo_Bernard
C6581 rent 1116 1 T5071 Inez_Mckinnon
C7438 rent 1125 5 T6611 Cristine_Bianchi
C5576 rent 1151 2 T6583 Ivan_Mcclellan
C6890 rent 1177 1 T5296 Marianna_Woolfolk
C3945 rent 1205 5 T7582 Freddie_Beckner
C7697 rent 1234 2 T3469 Tressie_Fernandes
C1290 rent 1248 1 T3825 Tawanna_Jeffreys
C6669 rent 1263 3 T1831 Pearlene_Heath
C1913 rent 1291 2 T1013 Mervin_Kirsch
C4095 rent 1322 4 T4616 Racheal_Hoch
C2385 rent 1335 1 T4769 Marlena_Gregorio
C6455 rent 1348 2 T2736 Deloras_Kopf
C7928 rent 1366 3 T6151 Terese_Craft
C1175 rent 1392 4 T6813 Isidra_Capron
C3379 rent 1424 1 T5942 Reena_Chambliss
C9175 rent 1435 5 T6958 Tari_Mccollum
C8399 rent 1460 1 T1901 Marcel_Benton
C1902 rent 1477 2 T1289 Catarina_Kieffer