# final-assignment
Final Assignment C/C++
```
FlighTicket.cpp
```

## The ticket program

```
These files will create a program that takes two arguments.
The first argument is a file with flight information.
The second argument is a file with booking information.
This program should will create files with a ticket for each booking.
```


**Compiling the program**

```
make
```

**Example running the program:**
```
./main -f flights.csv -b booking.csv

or

make run
```





Will produce tickets like following example
```
BOOKING:1000
FLIGHT:308 DEPARTURE:GOT DESTINATION:LGW 2022-10-27 06:30
PASSENGER Kalle Kula CLASS: first
ROW: 1 SEAT 1
```

Will produce .txt file showing canceled flights
```
Flight nr 304 06:30 is canceled
Flight nr 304 07:30 is canceled
```

will produce seatmaps for each flight
```
Economy class
[0][0] [0][0][0] [0][0]
[0][0] [0][0][0] [0][0]
```
## Output:

The tickets should be written to files with the following filename format:

```
ticket-{bookingnumber}.txt
```

Each file should contain the following information in this format: 

```
BOOKING:{bookingnumber} 
FLIGHT:{flight} DEPARTURE:{dep} DESTINATION: {dest} {date} {time}
PASSENGER {firstname} {surname}
CLASS: {seatclass}
ROW {row} SEAT {seatnumber}
```







