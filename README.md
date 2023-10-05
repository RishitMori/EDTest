# EDTest
Mars Rover Programming Exercise

**Problem Statement**

Create a simulation for a Mars Rover that can navigate a grid-based terrain. Your Rover should be able to move forward, turn left, and turn 
right. You'll need to make sure that it avoids obstacles and stays within the boundaries of the grid. Remember to use pure Object-Oriented 
Programming, design patterns, and avoid using if-else conditional constructs.



Walkthrough through MarsRover code and the decisions made to ensure correctness, readability, and robustness :-

	•	This enum defines the cardinal directions that the MarsRover can face - North, East, South, and West. Using enum class makes the code more type-safe.
	
	•	The class encapsulates the state and behavior of the MarsRover. It has private data members for the rover's position, direction, grid size, and a set to store obstacle positions. Public methods provide an interface to control the rover.
	
	•	This method sets the size of the grid. It includes a check to ensure that the grid size is positive; otherwise, it throws an std::invalid_argument exception.
	
	•	The addObstacle method adds obstacles to the grid. It uses an unordered_set to efficiently store obstacle positions as strings.
	
	•	This method rotates the rover left or right based on the input character 'L' or 'R'. It uses modular arithmetic to cycle through the directions.
	
	•	The move method updates the rover's position based on its current direction. It checks for obstacles and grid boundaries before updating the position.
	
	•	This method returns a string representation of the rover's final position, direction, and whether obstacles were detected.
	
	•	The main function creates a MarsRover object, sets its grid size, adds obstacles, executes a series of commands, and prints the final position. It includes exception handling for potential errors.
	
	•	Exception Handling:
	
		o	The GridSize method throws an exception if the grid size is not positive.
		o	The FindPosition function throws an exception for an invalid command.
		o	In the main function, exceptions are caught and error messages are printed to std::cerr.
		
	•	The code includes checks for valid grid sizes, obstacle positions, and rover positions.
	•	Enumerations and constants are used to improve code readability and maintainability.










