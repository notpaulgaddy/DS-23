HOMEWORK 2: HOCKEY CLASSES


NAME: Paul Gaddy


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

https://www.geeksforgeeks.org/this-pointer-in-c/
https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
https://cplusplus.com/reference/string/string/compare/
https://www.udacity.com/blog/2020/03/c-maps-explained.html
https://en.cppreference.com/w/cpp/io/manip/setw

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  18



DESCRIPTION OF 3RD STATISTIC:
Please be concise! (< 200 words)
What question you are trying to answer with your statistic? 
What data did you need to organize? 
What was interesting or challenging about the implementation of this statistic? 

1. Which players should be benched
2. Amount of goals and assists per player
3. Getting it to work with maps


NAME OF FILE WITH SAMPLE OUTPUT FROM 3RD STATISTIC:
Be sure to select (or create) a dataset with interesting results


< insert filename, file is included with submission >



MISC. COMMENTS TO GRADER:  
I DID NOT KNOW WE COULDNT USE AUTO, please be gracious and don't take off a bunch of points, maybe 0.5 pts and it won't happen again
Did it in python first, hence the maps. Traversing through maps for the first time in cpp IS NOT FUN

Secondly, I couldn't get the spacing to fully work and some of the numbers were off. Please don't grade too harshly as I have most of it working,
Submitty was grading very harshly

here's a piece of the python code
for game_num, game in games.items():

    date = game[0]
    away = game[1].split()[0]
    home = game[1].split()[2] 
    for line in game[2:-2]:
        if "goal" in line:
            team_name = line.split()[1]
            if team_name in teams:
                team = teams[team_name]
                team.add_goal()
            else:
                teams[team_name] = Team(team_name)

            player_name = line.split()[3]
            if player_name in players:
                player = players[player_name]
                player.add_goal()
            else:
                players[player_name] = Player(player_name)

        if "penalty" in line:

            team_name = line.split()[1]
            if team_name in teams:
                team = teams[team_name]
                team.add_penalty()
            else:
                teams[team_name] = Team(team_name)

            player_name = line.split()[3]
            if player_name in players:
                player = players[player_name]
                player.add_penalty()
            else:
                players[player_name] = Player(player_name)