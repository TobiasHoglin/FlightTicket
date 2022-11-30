tickets: flightTickets.cpp flightManager.cpp bookingManager.cpp ticketManager.cpp Bookings.hh Flights.hh flightManager.hh bookingManager.hh ticketManager.hh
	g++ flightTickets.cpp flightManager.cpp bookingManager.cpp ticketManager.cpp -o tickets

run: tickets
	./ tickets -f fligths.csv -b bookings.csv
	
