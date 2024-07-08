# Philosophers

## Description of the project
This project is based on the Dining Philosophers Problem and basically is focused on training with simple algorithms and synchronization of repetitive tasks. This excerpt describes the problem in a simple way:
```Five philosophers dine together at the same table. Each philosopher has their own plate at the table. There is a fork between each plate. The dish served is a kind of spaghetti which has to be eaten with two forks. Each philosopher can only alternately think and eat. Moreover, a philosopher can only eat their spaghetti when they have both a left and right fork. Thus two forks will only be available when their two nearest neighbors are thinking, not eating. After an individual philosopher finishes eating, they will put down both forks. The problem is how to design a regimen (a concurrent algorithm) such that any philosopher will not starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think (an issue of incomplete information).```

Therefore, the limitations of the philosophers are as following:
- Philosophers can only eat when they have two forks available;
- Think while waiting for forks (not sleeping or eating);
- When both forks are held, eat for a fixed amount of time;
- Philosophers can only get forks that are to their right, beside their own;
- Philosophers CANNOT duplicate forks;

## Format of philosophers log
```timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

## Skills learned
- Multithreading;
- Mutexes;
- Data races;

## Usage
- Make the files with "make all";
- Run the program with ```./philo``` and entering four/five arguments:
	Number of philosophers (max 200);
	Time to die;
	Time to eat;
	Time to sleep;
	Number of times each philosopher must eat (optional);
- Observe time stamps;

## Result
- Status: Completed
- Result: 100%

## Contact
- Email: felipecaraballo91@hotmail.com
