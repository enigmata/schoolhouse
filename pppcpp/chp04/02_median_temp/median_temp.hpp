#include <vector>

#ifndef __MEDIAN_TEMP_SOL_HPP__
#define __MEDIAN_TEMP_SOL_HPP__

enum class return_code { success, err_no_temps };

std::pair<double, return_code> median_temp(std::vector<double> &temps);

#endif // __MEDIAN_TEMP_SOL_HPP__
