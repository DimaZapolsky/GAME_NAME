//
// Created by Dima Zapolsky on 2019/05/11.
//

#ifndef GAME_PROBABILITY_FUNCTIONS_H
#define GAME_PROBABILITY_FUNCTIONS_H

double normed_probability_function(double strength1, double strength2, double max_strength) {
    return (strength1 / (strength1 + strength2)) * strength1 / max_strength;
}

#endif //GAME_PROBABILITY_FUNCTIONS_H
