# philosophers

## Description:
This project main objective is to create threads and, consequentially, to do multithreading to demonstrate the philosophers dinner table problem. (insert later what is the problem)

## Skills learned:
- Multithreading: <PLACEHOLDER>

## Usage:
```
1. Make the files with "make all";
2. Run the program with ```./philo``` and entering four/five arguments:
	2.1. Number of philosophers (max 200);
	2.2. Time to die;
	2.3. Time to eat;
	2.4. Time to sleep;
	2.5. Number of times each philosopher must eat (optional);
3. Observe time stamps;
```
## Result:
- Status: <span style="color:red">Incomplete</span>
- Result: <span style="color:red">0%</span>

## Contact: 
- 42-email: <PLACEHOLDER>@student.hive.fi
- 42-profile: [https://profile.intra.42.fr/users/<INSERTUSERNAME>](https://profile.intra.42.fr/users/<INSERTUSERNAME>)

## Log:
```
28.05.2024
1. In parsing() the loop was not outputting the proper message for negative numbers being inputted. Took out the if statement that was blocking the message;
2. Git branches were outdated, got all branches up to date;
3. Tested for different positive integer cases of philosophers:
	3.1. One philosopher: OK
	3.2. Five philosophers: OK
	3.3. Zero before actual number of philos: OK (all cases)
	3.4. 200 philos: OK
	3.5. Negatives (error handling): OK
	3.6. Zeroes: OK
4. Added zero checks with ft_atoi() in parsing();
