#include "Conversions.h"
float fahrenheit_of(int temp_c)
{
	return 1.8f * temp_c + 32;
}

float absolute_value_of(int temp_c)
{
	return temp_c + 273.15f;
}