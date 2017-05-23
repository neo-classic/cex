#include <stdio.h>

int main(int argc, char *argv[]) {
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    printf("You are %d miles away\n", distance);
    printf("You have %f levels of power\n", power);
    printf("You have %f awesome super power\n", super_power);
    printf("I have an initial %c\n", initial);
    printf("I have first name %s\n", first_name);
    printf("I have last name %s\n", last_name);
    printf("My whole name is %s %c. %s\n", first_name, initial, last_name);

    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f\n", bugs, bug_rate);

    long u_of_d = 1L * 1024L * 1024L + 1024L;
    printf("The entire universe has %ld bugs\n", u_of_d);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs\n", expected_bugs);

    double part_of_universe = expected_bugs / u_of_d;
    printf("That is only a %e portion of the universe\n", part_of_universe);

    char nul_byte = '\0';
    int care_perc = bugs * nul_byte;
    printf("Which means you should care %d%%\n", care_perc);

    printf("Null byte is %s\n", nul_byte);

    return 0;
}
