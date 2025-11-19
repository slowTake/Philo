mutex are used when going in and out of functions likes frees

locked and unlocked when entering and leaving

cap 200

Args:
=============
number of philos
time to die
time to eat
time to sleep
number of meals* optional entry

Output(state changes)
=============
time stamp in ms Philo X has taken a fork
time stamp in ms Philo X is eating
time stamp in ms Philo X is sleeping
time stamp in ms Philo X is thinking
time stamp in ms Philo X died

-should not overlap, mutex lock when going in and out
-death needs to be announced within 10ms of actual death
-philo should not die when successful

no data races
(bug that occurs when mutiple threads try to access the same 
memory location) happens while writing

Data Structures
============
Struct to store simulation params
Array of forks(Mutexes) equal size to philos
Sync mutexes to protect shared variables
Array of philo structs(containing t_philo)
control flag: flag to end simulation if death occurs

Variables
============
atomic booleans are bools meant to be safetly shared between threads

Memory allocs
============
number of philos
forks which is also number of philos

Monitor
============
run in the parent thread to not occupy threads/resources