#include <stdio.h>
#include <string.h>
#include <ctype.h>

int print_menu() {
	int choice = 0;

        printf("\nPassword Resilience Analyzer\n");
        printf("1. Test a new password\n");
        printf("2. View strength of the last tested password\n");
	printf("3. Exit\n");
        printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

int hasLowercase(char password[]) {
	int i;
	for (i = 0; i<strlen(password); i++) {
		if (islower(password[i])) {
			return 1;
		}
	} 
	return 0;
}

int hasUppercase(char password[]) {
        int i;
        for (i = 0; i<strlen(password); i++) {
                if (isupper(password[i])) {
                        return 1;
                }
        }
        return 0;
}

int hasDigit(char password[]) {
        int i;
        for (i = 0; i<strlen(password); i++) {
                if (isdigit(password[i])) {
                        return 1;
                }
        }
        return 0;
}

int hasSpecialChar(char password[]) {
        int i;
        for (i = 0; i<strlen(password); i++) {
                if (!isalpha(password[i])) {
                        return 1;
                }
        }
        return 0;
}


char* evaluateStrength(char password[]) {
	int score = 0;

	score += hasLowercase(password);
	score += hasUppercase(password);
	score += hasDigit(password);
	score += hasSpecialChar(password);
	if (strlen(password) >= 12) {
		score++;
	}
	
	if (score == 5) {
		return "Strong";	
	} else if (score >= 3) {
		return "Moderate";
	} else {
		return "Weak";	
	}
	
}



int main() {
	char password[101];
	char previous_strength[8];
	int choice = 0;

	while (choice != 3) {
		choice = print_menu();

		if (choice == 1) {
			printf("Enter the password: ");
			scanf("%s", password);
			if (strlen(password) >= 8) {
				printf("Password Strength: ");
				strcpy(previous_strength, evaluateStrength(password));
				printf("%s\n", previous_strength);
			} else {
				printf("Error: Password should be at least 8 characters long.\n");
			}
		} else if (choice == 2) {
			printf("Last tested password strength: ");
			printf("%s\n", previous_strength);
		} else if (choice == 3) {
			printf("Exiting...\n");
		} else {
			printf("Choice invalid. Choose 1, 2 or 3\n");
		}
	}
	return 0;
}
