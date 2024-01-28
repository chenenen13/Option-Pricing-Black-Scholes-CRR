#include "MT.h"

MT::MT()  : generator(std::random_device()()){}
MT& MT::getInstance() {
     static MT instance; 
     return instance;
    }
double MT::rand_unif() {
     return getInstance().distribution_unif(getInstance().generator);
 }
double MT::rand_norm() {
    return getInstance().distribution_norm(getInstance().generator);
}