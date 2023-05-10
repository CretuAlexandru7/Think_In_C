#include <stdio.h>

enum Error_Codes {
	NOT_AN_ERROR = 0x000,
	NACK_TIMEOUT = 0x1001,
	NACK_INVALID_BAUDRATE = 0x1002,
	NACK_INVALID_POS = 0x1003,
	NACK_IS_NOT_USED = 0x1004,
	NACK_IS_ALREADY_USED = 0x1005,
	NACK_COMM_ERR = 0x1006,
};

struct error_map {
	int code;
	const char* name;
};

const struct error_map error_codes[] = {
	{NOT_AN_ERROR, "NOT_AN_ERROR"},
	{NACK_TIMEOUT, "NACK_TIMEOUT"},
	{NACK_INVALID_BAUDRATE, "NACK_INVALID_BAUDRATE"},
	{NACK_INVALID_POS, "NACK_INVALID_POS"},
	{NACK_IS_NOT_USED, "NACK_IS_NOT_USED"},
	{NACK_IS_ALREADY_USED, "NACK_IS_ALREADY_USED"},
	{NACK_COMM_ERR, "NACK_COMM_ERR"},
};

const char* get_error_name(int code) {
	for (int i = 0; i < sizeof(error_codes) / sizeof(error_codes[0]); i++) {
		if (error_codes[i].code == code) {
			return error_codes[i].name;
		}
	}
	return "UNKNOWN_ERROR";
}

int main() {
	int code = 0x1005;
	const char* name = get_error_name(code);
	printf("Error code 0x%x is %s\n", code, name);
	return 0;
}
