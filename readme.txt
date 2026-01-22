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
(bug that occurs when multiple threads try to access the same 
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

t_data
============
philo_num
time_to_die
time_to_eat
time_to_sleep
meal_limit

forks
philosphers
start time
stop flag
finished eating_count

print mutex
data mutex

philo structs
============
int id
thread_id

left_fork
right_fork

meals_eaten
last_meal_time

data


==============
atomic
if philo full
last eat time
philo count



tests
============
 % valgrind --tool=helgrind ./philo 5 800 200 200 7
