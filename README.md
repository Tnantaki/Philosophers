# Philosophers
> In this project, you will learn the basics of threading a process via The Dining Philosophers Problem. You will see how to create threads and you will discover mutexes

---
## 📝Usage
The program takes at least 4 arguments to execute or 5 (for more options) as below.

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]
```

- **[number of philosophers] :** The number of philosophers and also the number of forks.
- **[time to die] (in milliseconds) :** If a philosopher didn’t start eating `time_to_die` since the beginning of their last meal or the beginning of the simulation, they die.
- **[time to eat] (in milliseconds) :** The time it takes for a philosopher to eat. during that time, they will need to hold two forks.
- **[time to sleep] (in milliseconds) :** The time a philosopher will spend sleeping.
- **[number of times each philosopher must eat] (optional argument) :** If all philosophers have eaten at least `number_of_times_each_philosopher_must_eat` times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

The program will be running and display the process of philosophers.


## 🔑Problem & solution
**1. Race Condition** : it may occur when you create 2 or more threads and change values in the same variable (Because the thread shares memory). thread are working in parallel and it may change the value at the same time, it will cause wrong results. So you can use `Mutex` to protect it if you wanna change or read the value of the same variable in a different thread.

**2. Deadlock** :
- it may occur when you use `Mutex` to lock threads twice without unlocking it first.
- it occurs when you create 2 `Mutex`, 2 threads, and each thread tries to lock `Mutex` that may another one had locked. So you have to check first that each `Mutex` is unlocked before lock it.
