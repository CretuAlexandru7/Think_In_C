#include <stdio.h>

// function prototypes
void function1(void);
void function2(void);
void function3(void);
void function4(void);

// state machine states
enum states {
	STATE_START,
	STATE_FUNCTION1,
	STATE_FUNCTION2,
	STATE_FUNCTION3,
	STATE_FUNCTION4,
	STATE_EXIT
};

int main(void) {
	// initialize state machine
	enum states current_state = STATE_START;

	// loop until exit state is reached
	while (current_state != STATE_EXIT) {
		// read integer input from keyboard
		int input;
		printf("Enter an integer (1-4 to call a function, 0 to exit): ");
		scanf_s("%d", &input);

		// transition to new state based on input
		switch (input) {
		case 0:
			current_state = STATE_EXIT;
			break;
		case 1:
			current_state = STATE_FUNCTION1;
			break;
		case 2:
			current_state = STATE_FUNCTION2;
			break;
		case 3:
			current_state = STATE_FUNCTION3;
			break;
		case 4:
			current_state = STATE_FUNCTION4;
			break;
		default:
			printf("Invalid input, please try again.\n");
			continue; // continue loop without changing state
		}

		// execute function associated with current state
		switch (current_state) {
		case STATE_FUNCTION1:
			function1();
			break;
		case STATE_FUNCTION2:
			function2();
			break;
		case STATE_FUNCTION3:
			function3();
			break;
		case STATE_FUNCTION4:
			function4();
			break;
		default:
			break;
		}
	}

	return 0;
}

void function1(void) {
	printf("Function 1 called.\n");
}

void function2(void) {
	printf("Function 2 called.\n");
}

void function3(void) {
	printf("Function 3 called.\n");
}

void function4(void) {
	printf("Function 4 called.\n");
}
