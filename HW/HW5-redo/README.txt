HOMEWORK 5: LINKED TRAIN CARS


NAME:  Paul Gaddy


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

Abishek
https://www.geeksforgeeks.org/merge-sort/
https://www.codesdope.com/blog/article/linked-list-traversal-using-loop-and-recursion-in-/


Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  16



DESCRIPTION OF IMPROVED SHIPFREIGHT ALGORITHM FOR EXTRA CREDIT 
Aiming for optimal (fastest train speed, most freight, fewest number
of engines used, and fewest resulting trains) for any input.  Note:
Student choice on how to prioritze between these goals.  Describe your
priorization and your implementation.



DESCRIPTION OF IMPROVED SEPARATE ALGORITHM FOR EXTRA CREDIT 
Aiming for optimally comfortable trains (smaller values for average
distance to dining and/or larger values for closest engine to sleeper)
and/or optimally handling cases with > 2 engines.  Student choice on how 
to prioritze between these goals.  Describe your priorization and your
implementation.


MISC. COMMENTS TO GRADER:  
Optional, please be concise!

Memory issue not fully fixed, but here's my output 


   ------222   ------223   ------224
 / ENGINE   |   45  |   |   90  |   |   35  |   |   90  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 410, speed on 2% incline = 68.6
     ~~~~                                                
    ||                                                   
   ---206   ------226   ------227   ------228   ------229
 / ENGINE   |   95  |   |   50  |   |   65  |   |   70  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 430, speed on 2% incline = 65.4
     ~~~~                        
    ||                           
   ---207   ------231   ------232
 / ENGINE   |   90  |   |   45  |
-oo---oo- + -oo---oo- + -oo---oo-
#cars = 3, total weight = 285, speed on 2% incline = 98.7
============================================================================
SHIP FREIGHT TEST, RANDOM SEED #4
Remaining Unused Engines:
     ~~~~
    ||   
   ---239
 / ENGINE
-oo---oo-
#cars = 1, total weight = 150, speed on 2% incline = 187.5
Prepared Trains for Shipment:
     ~~~~                                                            
    ||                                                               
   ---234   ------240   ------241   ------242   ------243   ------244
 / ENGINE   |   70  |   |   30  |   |   60  |   |   70  |   |   50  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 430, speed on 2% incline = 65.4
     ~~~~                                                
    ||                                                   
   ---235   ------246   ------247   ------248   ------249
 / ENGINE   |   85  |   |   50  |   |   35  |   |   40  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 360, speed on 2% incline = 78.1
     ~~~~                                    
    ||                                       
   ---236   ------251   ------252   ------253
 / ENGINE   |   65  |   |   90  |   |   95  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 400, speed on 2% incline = 70.3
     ~~~~                                                
    ||                                                   
   ---237   ------255   ------256   ------257   ------258
 / ENGINE   |   85  |   |   40  |   |   70  |   |   55  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 400, speed on 2% incline = 70.3
     ~~~~                                                
    ||                                                   
   ---238   ------260   ------261   ------262   ------263
 / ENGINE   |   85  |   |   30  |   |   45  |   |  100  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 410, speed on 2% incline = 68.6
============================================================================
SHIP FREIGHT TEST, RANDOM SEED #5
Remaining Unused Engines:
     ~~~~
    ||   
   ---270
 / ENGINE
-oo---oo-
#cars = 1, total weight = 150, speed on 2% incline = 187.5
Prepared Trains for Shipment:
     ~~~~                                                            
    ||                                                               
   ---265   ------271   ------272   ------273   ------274   ------275
 / ENGINE   |   50  |   |   30  |   |   80  |   |   35  |   |   70  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 415, speed on 2% incline = 67.8
     ~~~~                                                            
    ||                                                               
   ---266   ------277   ------278   ------279   ------280   ------281
 / ENGINE   |   70  |   |   30  |   |   30  |   |   95  |   |   30  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 405, speed on 2% incline = 69.4
     ~~~~                                                
    ||                                                   
   ---267   ------283   ------284   ------285   ------286
 / ENGINE   |   75  |   |   65  |   |   45  |   |   70  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
 sh -c make -s
 ./main
============================================================================
SIMPLE TRAIN TEST
     ~~~~                                                            
    ||                                                               
   ---100   ------101   ------102   ------103   ------104   ------105
 / ENGINE   |       |   |       |   |  dine |   |       |   | sleep |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 400, speed on 2% incline = 70.3, avg distance to dining = 1.3, closest engine to sleeper = 4
============================================================================
SHIP FREIGHT TEST, FIXED SEED
Remaining Unused Engines:
     ~~~~        ~~~~        ~~~~        ~~~~        ~~~~
    ||          ||          ||          ||          ||   
   ---111      ---112      ---113      ---114      ---115
 / ENGINE    / ENGINE    / ENGINE    / ENGINE    / ENGINE
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 750, speed on 2% incline = 187.5
Prepared Trains for Shipment:
     ~~~~                                                            
    ||                                                               
   ---106   ------116   ------117   ------118   ------119   ------120
 / ENGINE   |   90  |   |   40  |   |   35  |   |   50  |   |   60  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 425, speed on 2% incline = 66.2
     ~~~~                                    
    ||                                       
   ---107   ------122   ------123   ------124
 / ENGINE   |   80  |   |  100  |   |   80  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 410, speed on 2% incline = 68.6
     ~~~~                                                
    ||                                                   
   ---108   ------126   ------127   ------128   ------129
 / ENGINE   |   95  |   |   50  |   |   55  |   |   75  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 425, speed on 2% incline = 66.2
     ~~~~                                                
    ||                                                   
   ---109   ------131   ------132   ------133   ------134
 / ENGINE   |   65  |   |   55  |   |   80  |   |   90  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 440, speed on 2% incline = 63.9
     ~~~~                                                
    ||                                                   
   ---110   ------136   ------137   ------138   ------139
 / ENGINE   |   50  |   |   85  |   |   95  |   |   85  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 465, speed on 2% incline = 60.5
============================================================================
SHIP FREIGHT TEST, RANDOM SEED #1
Remaining Unused Engines:
     ~~~~
    ||   
   ---146
 / ENGINE
-oo---oo-
#cars = 1, total weight = 150, speed on 2% incline = 187.5
Prepared Trains for Shipment:
     ~~~~                                    
    ||                                       
   ---141   ------147   ------148   ------149
 / ENGINE   |   95  |   |   85  |   |   60  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 390, speed on 2% incline = 72.1
     ~~~~                                                            
    ||                                                               
   ---142   ------151   ------152   ------153   ------154   ------155
 / ENGINE   |   80  |   |   55  |   |   65  |   |   30  |   |   50  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 430, speed on 2% incline = 65.4
     ~~~~                                                            
    ||                                                               
   ---143   ------157   ------158   ------159   ------160   ------161
 / ENGINE   |  100  |   |   45  |   |   30  |   |   60  |   |   45  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 430, speed on 2% incline = 65.4
     ~~~~                                                            
    ||                                                               
   ---144   ------163   ------164   ------165   ------166   ------167
 / ENGINE   |   45  |   |   55  |   |   35  |   |   35  |   |   30  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 350, speed on 2% incline = 80.4
     ~~~~                        
    ||                           
   ---145   ------169   ------170
 / ENGINE   |   65  |   |   55  |
-oo---oo- + -oo---oo- + -oo---oo-
#cars = 3, total weight = 270, speed on 2% incline = 104.2
============================================================================
SHIP FREIGHT TEST, RANDOM SEED #2
Prepared Trains for Shipment:
     ~~~~                        
    ||                           
   ---172   ------178   ------179
 / ENGINE   |  100  |   |   95  |
-oo---oo- + -oo---oo- + -oo---oo-
#cars = 3, total weight = 345, speed on 2% incline = 81.5
     ~~~~                                    
    ||                                       
   ---173   ------181   ------182   ------183
 / ENGINE   |   55  |   |   95  |   |  100  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 400, speed on 2% incline = 70.3
     ~~~~                                                
    ||                                                   
   ---174   ------185   ------186   ------187   ------188
 / ENGINE   |   55  |   |   30  |   |   80  |   |   75  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 390, speed on 2% incline = 72.1
     ~~~~                                    
    ||                                       
   ---175   ------190   ------191   ------192
 / ENGINE   |   55  |   |   95  |   |   70  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 370, speed on 2% incline = 76.0
     ~~~~                                                
    ||                                                   
   ---176   ------194   ------195   ------196   ------197
 / ENGINE   |   95  |   |   55  |   |   80  |   |   40  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 420, speed on 2% incline = 67.0
     ~~~~                                    
    ||                                       
   ---177   ------199   ------200   ------201
 / ENGINE   |   60  |   |   85  |   |   65  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 360, speed on 2% incline = 78.1
============================================================================
SHIP FREIGHT TEST, RANDOM SEED #3
Prepared Trains for Shipment:
     ~~~~                                                
    ||                                                   
   ---203   ------209   ------210   ------211   ------212
 / ENGINE   |   90  |   |   60  |   |   40  |   |   90  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 430, speed on 2% incline = 65.4
     ~~~~                                    
    ||                                       
   ---204   ------214   ------215   ------216
 / ENGINE   |   70  |   |   95  |   |   90  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 405, speed on 2% incline = 69.4
     ~~~~                                                
    ||                                                   
   ---205   ------218   ------219   ------220   ------221
 / ENGINE   |   30  |   |   65  |   |   90  |   |   95  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 430, speed on 2% incline = 65.4
     ~~~~                                                
    ||                                                   
   ---206   ------223   ------224   ------225   ------226
 / ENGINE   |   50  |   |   75  |   |   45  |   |   75  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 395, speed on 2% incline = 71.2
     ~~~~                                    
    ||                                       
   ---207   ------228   ------229   ------230
 / ENGINE   |   60  |   |   95  |   |   90  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 395, speed on 2% incline = 71.2
     ~~~~            
    ||               
   ---208   ------232
 / ENGINE   |   30  |
-oo---oo- + -oo---oo-
#cars = 2, total weight = 180, speed on 2% incline = 156.2
============================================================================
SHIP FREIGHT TEST, RANDOM SEED #4
Remaining Unused Engines:
     ~~~~
    ||   
   ---239
 / ENGINE
-oo---oo-
#cars = 1, total weight = 150, speed on 2% incline = 187.5
Prepared Trains for Shipment:
     ~~~~                                                
    ||                                                   
   ---234   ------240   ------241   ------242   ------243
 / ENGINE   |   30  |   |   85  |   |   80  |   |   70  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 415, speed on 2% incline = 67.8
     ~~~~                                                
    ||                                                   
   ---235   ------245   ------246   ------247   ------248
 / ENGINE   |   40  |   |   60  |   |   85  |   |   45  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 380, speed on 2% incline = 74.0
     ~~~~                                                
    ||                                                   
   ---236   ------250   ------251   ------252   ------253
 / ENGINE   |   70  |   |   35  |   |   40  |   |   55  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 350, speed on 2% incline = 80.4
     ~~~~                                    
    ||                                       
   ---237   ------255   ------256   ------257
 / ENGINE   |   95  |   |   30  |   |   90  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 365, speed on 2% incline = 77.1
     ~~~~                                                
    ||                                                   
   ---238   ------259   ------260   ------261   ------262
 / ENGINE   |   65  |   |   40  |   |   70  |   |   75  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 400, speed on 2% incline = 70.3
============================================================================
SHIP FREIGHT TEST, RANDOM SEED #5
Remaining Unused Engines:
     ~~~~
    ||   
   ---270
 / ENGINE
-oo---oo-
#cars = 1, total weight = 150, speed on 2% incline = 187.5
Prepared Trains for Shipment:
     ~~~~                                                
    ||                                                   
   ---265   ------271   ------272   ------273   ------274
 / ENGINE   |   65  |   |   45  |   |   35  |   |   90  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 385, speed on 2% incline = 73.1
     ~~~~                                                
    ||                                                   
   ---266   ------276   ------277   ------278   ------279
 / ENGINE   |   95  |   |   50  |   |   35  |   |   80  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 410, speed on 2% incline = 68.6
     ~~~~                                                
    ||                                                   
   ---267   ------281   ------282   ------283   ------284
 / ENGINE   |   35  |   |   60  |   |   70  |   |   65  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 5, total weight = 380, speed on 2% incline = 74.0
     ~~~~                                                            
    ||                                                               
   ---268   ------286   ------287   ------288   ------289   ------290
 / ENGINE   |   35  |   |   95  |   |   35  |   |   30  |   |   55  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 6, total weight = 400, speed on 2% incline = 70.3
     ~~~~                                    
    ||                                       
   ---269   ------292   ------293   ------294
 / ENGINE   |   35  |   |   40  |   |   80  |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 4, total weight = 305, speed on 2% incline = 92.2
============================================================================
SEPARATE TRAINS #1
     ~~~~                                                                                ~~~~                                    
    ||                                                                                  ||                                       
   ---296   ------297   ------298   ------299   ------300   ------301   ------302      ---303   ------304   ------305   ------306
 / ENGINE   |       |   |       |   |  dine |   | sleep |   | sleep |   |       |    / ENGINE   |       |   |  dine |   |       |
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-
#cars = 11, total weight = 750, speed on 2% incline = 75.0, avg distance to dining = inf, closest engine to sleeper = 3
ERROR: One or more missing cars after Separate
Separate Statistics: num unlinks = 65, num links = 5096480, num shifts = 32766   Total Cost: 5129311
  left and right train speeds are equal to the original.
     ~~~~
    ||   
   ---296
 / ENGINE
-oo---oo-
#cars = 1, total weight = 150, speed on 2% incline = 187.5
     ~~~~
    ||   
   ---303
 / ENGINE
-oo---oo-
#cars = 1, total weight = 150, speed on 2% incline = 187.5
============================================================================
SEPARATE TRAINS #2
                                                                             ~~~~                                ~~~~
                                                                            ||                                  ||   
------307   ------308   ------309   ------310   ------311   ------312      ---313   ------314   ------315      ---316
|       |   |  dine |   | sleep |   |       |   |  dine |   |       |    / ENGINE   |       |   | sleep |    / ENGINE
-oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo- + -oo---oo-